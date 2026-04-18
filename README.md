# 🎮 Math Quiz Game (C++)

Welcome to my **Math Quiz Game**! This project is a fun, interactive console-based application built to help users practice their mental math skills. It is one of my first projects where I focused on writing **clean, modular, and professional C++ code**.

## 📝 Project Overview
The game allows users to customize their quiz experience by choosing:
- **Number of Questions:** From 1 to 10.
- **Difficulty Level:** Easy, Medium, Hard, or a Mix of all.
- **Operation Type:** Addition, Subtraction, Multiplication, Division, or a Random Mix.

At the end of the quiz, the program evaluates the player's performance and displays a final results dashboard.

---

## ✨ Features
- **Dynamic Question Generation:** Questions are created randomly based on the selected level.
- **Smart Logic:** Includes protection against division by zero.
- **Instant Feedback:** Tells you if your answer is right or wrong immediately.
- **Final Results Dashboard:** Shows total questions, right/wrong answers, and overall pass/fail status.
- **Replayability:** Option to restart the game and try a different challenge.

---

## 🏗️ Technical Highlights (How it works)
I applied the **"Divide and Conquer"** strategy to make the code easy to read and maintain:

1. **Data Structures (Structs & Enums):** Used to keep the data organized (e.g., storing all question details in one place).
2. **Modular Functions:** Each function has a specific job (one for reading input, one for calculation, one for printing).
3. **Boolean Logic:** Used `bool` flags to track whether a question was answered correctly and to determine the final passing status.

---

## 🚀 How to Run the Game
1. Make sure you have a C++ compiler installed (like **Visual Studio**, **Code::Blocks**, or **CLion**).
2. Download or copy the `main.cpp` file from this repository.
3. Compile and run the project.
4. Follow the instructions on the screen!

## 📸 Sample Output
```text
Qusiton [1] : /5
12
5
 + 
------------
Your Answer : 17
Correct Answer!



/>



