#include <iostream>   // Include iostream for input/output operations.
#include <cstdlib>    // Include cstdlib for system functions like clearing the screen.
#include <ctime>      // Include ctime for random number seeding.
using namespace std;
enum enQusitionLevel {
	Easy = 1,
	Medium = 2,
	Hard = 3,
	MixLevel = 4,
};
enum enOperator {
	Addition = 1,
	Subtraction = 2,
	Multiplication = 3,
	Division = 4,
	MixOperator = 5
};

struct stQusiton {
	int Number1;
	int Number2;
	enQusitionLevel QustionLeve;
	enOperator  Op;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};
struct stQuizz {
	stQusiton QustionList[100];
	int NumberOfQustion;
	enQusitionLevel QustionLeve;
	enOperator  Op;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool isPass = false;
};
int ReadHomwManyQuestion() {
	int NumberOfQustion;
	do {
		cout << "How many questions do you want to answer? (1-10): ";
		cin >> NumberOfQustion;
	} while (NumberOfQustion < 1 || NumberOfQustion > 10);
	return NumberOfQustion;
}
enQusitionLevel ReadQustionLeve() {
	int QustionLeve;
	do {
		cout << "Choose the question level (1- Easy, 2- Medium, 3- Hard, 4- Mix): ";
		cin >> QustionLeve;
	} while (QustionLeve < 1 || QustionLeve > 4);
	return (enQusitionLevel)QustionLeve;
}
enOperator ReadOp() {
	int Op;
	do {
		cout << "Choose the operator (1- Addition, 2- Subtraction, 3- Multiplication, 4- Division, 5- Mix): ";
		cin >> Op;
	} while (Op < 1 || Op > 5);
	return (enOperator)Op;
}
int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}
enOperator GetRandomOpType() {
	int Op = RandomNumber(1, 4);
	return (enOperator)Op;
}
int SimpleCalculation(int Number1, int Number2, enOperator op) {
	switch (op)
	{
	case enOperator::Addition:
		return Number1 + Number2;
	case enOperator::Subtraction:
		return Number1 - Number2;
	case enOperator::Multiplication:
		return Number1 * Number2;
	case enOperator::Division:
		return (Number2 != 0) ? Number1 / Number2 : 0; // Avoid division by zero.
	default:
		return 0;
	}
}
stQusiton GeneratQusion(enQusitionLevel level, enOperator op) {
	stQusiton Qustion;
	if (level == enQusitionLevel::MixLevel) {
		level = (enQusitionLevel)RandomNumber(1, 3);
	}
	if (op == enOperator::MixOperator) {
		op = GetRandomOpType();
	}
	Qustion.Op = op;
	switch (level)
	{
	case enQusitionLevel::Easy:
		Qustion.Number1 = RandomNumber(1, 10);
		Qustion.Number2 = RandomNumber(1, 10);
		Qustion.CorrectAnswer = SimpleCalculation(Qustion.Number1, Qustion.Number2, Qustion.Op);
		Qustion.QustionLeve = level;
		return Qustion;
	case enQusitionLevel::Medium:
		Qustion.Number1 = RandomNumber(10, 50);
		Qustion.Number2 = RandomNumber(10, 50);
		Qustion.CorrectAnswer = SimpleCalculation(Qustion.Number1, Qustion.Number2, Qustion.Op);
		Qustion.QustionLeve = level;
		return Qustion;
	case enQusitionLevel::Hard:
		Qustion.Number1 = RandomNumber(50, 10);
		Qustion.Number2 = RandomNumber(50, 100);
		Qustion.CorrectAnswer = SimpleCalculation(Qustion.Number1, Qustion.Number2, Qustion.Op);
		Qustion.QustionLeve = level;
		return Qustion;
	}
	return Qustion;
}
void GeneratQuzizQusion(stQuizz& quizz) {
	for (short Qusitionindex = 0; Qusitionindex < quizz.NumberOfQustion; Qusitionindex++) {
		quizz.QustionList[Qusitionindex] = GeneratQusion(quizz.QustionLeve, quizz.Op);
	}

}
string GetOpSymbol(enOperator op) {
	switch (op)
	{
	case enOperator::Addition:
		return " + ";
	case enOperator::Subtraction:
		return " - ";
	case enOperator::Multiplication:
		return " * ";
	case enOperator::Division:
		return " / ";
	default:
		return " Mix ";	
	}
}
void PrintQusion(stQuizz& quizz, int QustionNumber)

{
	cout << "\n" << endl;
	cout << "Qusiton [" << QustionNumber + 1 << "] : /" << quizz.NumberOfQustion << endl;
	cout << quizz.QustionList[QustionNumber].Number1 << endl;
	cout << quizz.QustionList[QustionNumber].Number2 << endl;
	cout << GetOpSymbol(quizz.QustionList[QustionNumber].Op) << endl;
	cout << "------------" << endl;


}
int ReadQuszionAnswer() {
	int Answer;
	cout << "Your Answer : ";
	cin >> Answer;
	return Answer;
}
void CorrectTheQustionAnser(stQuizz& quizz, int QustionNumber) {
	if (quizz.QustionList[QustionNumber].PlayerAnswer != quizz.QustionList[QustionNumber].CorrectAnswer)
	{
		quizz.QustionList[QustionNumber].AnswerResult = false;
		quizz.NumberOfWrongAnswers++;
		cout << "Wrong Answer! The correct answer is: " << quizz.QustionList[QustionNumber].CorrectAnswer << endl;
	}
	else {
		quizz.QustionList[QustionNumber].AnswerResult = true;
		quizz.NumberOfRightAnswers++;
		cout << "Correct Answer!" << endl;
	}
}
void AskAndAnswerQusition(stQuizz& quizz)
{
	for (int i = 0; i < quizz.NumberOfQustion; i++)
	{
		PrintQusion(quizz, i);
		quizz.QustionList[i].PlayerAnswer = ReadQuszionAnswer();
		CorrectTheQustionAnser(quizz, i);
	}
	quizz.isPass = (quizz.NumberOfRightAnswers >= quizz.NumberOfWrongAnswers);
}
string GetQustionLevel(enQusitionLevel Levle) {
	string arr[4] = { "Easy","MedLevel","Hard","MixExam" };
	return arr[Levle - 1];
}
void PrintQuizResult(stQuizz quizz) {
	cout << "\nQuiz Result:\n";
	cout << "Total Questions: " << quizz.NumberOfQustion << endl;
	cout << "Correct Answers: " << quizz.NumberOfRightAnswers << endl;
	cout << "Wrong Answers: " << quizz.NumberOfWrongAnswers << endl;
	cout << "Qusion Level: " << GetQustionLevel(quizz.QustionLeve) << endl;
	cout << "Operation Type" << GetOpSymbol(quizz.Op) << endl;
	cout << (quizz.isPass ? "Congratulations! You passed the quiz!" : "Sorry, you did not pass the quiz. Better luck next time!") << endl;
}
void PlayMathGame() {
	stQuizz quizz;
	quizz.NumberOfQustion = ReadHomwManyQuestion();
	quizz.QustionLeve = ReadQustionLeve();
	quizz.Op = ReadOp();
	GeneratQuzizQusion(quizz);
	AskAndAnswerQusition(quizz);
	PrintQuizResult(quizz);
};
void ResetSecreen() {
	system("cls"); // Clear the console screen (works on Windows).
	system("color 0F"); // Set the console text color to green (works on Windows).
}
void startGame()
{
	char PalyAgein = 'Y';
	do {
		ResetSecreen();
		PlayMathGame();
		cout << endl << "Do you want to play again? (Y/N) : ";
		cin >> PalyAgein;
	} while (PalyAgein == 'y' || PalyAgein == 'Y');
}
int main() {
	srand((unsigned)time(NULL)); // Seed the random number generator with the current time.	
	startGame();
}