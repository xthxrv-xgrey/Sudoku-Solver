# 🧩 Sudoku Solver — C++ (CLI Based)

A fast and reliable **Sudoku Solver written in C++**, using **backtracking** and **constraint validation**.  
This project is designed as a **command-line application** and focuses on correctness, usability, and portability.

---

## ✨ Features

- Solves any valid 9×9 Sudoku puzzle
- Uses `0` to represent empty cells
- Validates the initial Sudoku configuration before solving
- Detects unsolvable puzzles
- Clean, readable ASCII grid output
- Works on **Windows, Linux, and macOS**
- Beginner-friendly input format
- GitHub-ready project structure

---

## ⚠️ Important Note (Please Read)

❌ **Do NOT paste Sudoku input inside IDE terminals**  
(VS Code, CodeBlocks, CLion, etc.)

Some IDE terminals **terminate input early** when pasting multi-line data.

✅ **Use instead:**
- Command Prompt (Windows)
- PowerShell (Windows)
- Terminal (Linux / macOS)

If you don't know how to open these, scroll down to **How to Run the Project**.

---

## 📥 Input Format

- Enter **9 rows**, each containing **9 numbers**
- Use numbers **1–9**
- Use **0** for empty cells
- Numbers must be space-separated

### Example Input

```
0 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

---

## 🤖 AI Prompt (For Sudoku Images)

If you have a **screenshot or photo of a Sudoku**, use this prompt in any AI:

```
Convert the Sudoku image into 9 rows of 9 numbers.
Use 0 for empty cells.
Return ONLY numbers.
NO explanations, NO extra text.
Each row on a new line.
```

Then paste the output directly into the terminal.

---

## 🧪 Test Cases

This repository includes a **testcase file** containing example Sudoku boards:

- Valid solvable Sudoku
- Invalid configuration
- Unsolvable Sudoku

📁 Example:
```
testcases.txt
```

You can copy-paste any test case from this file directly into the terminal when running the program.

---

## 🛠 How to Run the Project

### ✅ Prerequisites
- C++ compiler (`g++` recommended)
- Basic knowledge of terminal commands

---

### 🪟 Windows (Command Prompt / PowerShell)

1. Open **Command Prompt** or **PowerShell**
2. Navigate to the project folder:
   ```bash
   cd path\to\project
   ```
3. Compile the program:
   ```bash
   g++ sudoku.cpp -o sudoku
   ```
4. Run:
   ```bash
   sudoku
   ```

---

### 🐧 Linux / 🍎 macOS

1. Open **Terminal**
2. Navigate to the project directory:
   ```bash
   cd path/to/project
   ```
3. Compile the program:
   ```bash
   g++ sudoku.cpp -o sudoku
   ```
4. Run:
   ```bash
   ./sudoku
   ```

---

## 🧠 Algorithm Used

**Backtracking**

- Recursive depth-first search
- Constraint checks:
  - Row validity
  - Column validity
  - 3×3 sub-grid validity

The solver fills empty cells one by one and backtracks if a conflict occurs.

---

## 📂 Project Structure

```
Sudoku-Solver/
│
├── sudoku.cpp        # Main C++ source file
├── testcases.txt     # Sample Sudoku test cases
└── README.md         # Project documentation
```

---

## 🚀 Future Improvements

- Count number of valid solutions
- Step-by-step solving visualization
- File input support
- Performance optimization with bitmasks
- GUI version (Qt / Web)

---

## 📌 Why This Project?

This project demonstrates:

- Strong understanding of recursion & backtracking
- Defensive programming
- Clean CLI design
- Real-world usability considerations
- Interview-relevant problem solving

---

## ⭐ If You Like This Project

- Consider giving it a ⭐ on GitHub
- Feedback and improvements are always welcome!

---

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!  
Feel free to check the [issues page](../../issues).

---

**Made with ❤️ by Atharv Agrey**
