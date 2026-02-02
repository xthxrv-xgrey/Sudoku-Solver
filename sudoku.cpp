#include <iostream>
#include <vector>
using namespace std;

// Function Declarations
bool solveSudoku(vector<vector<int>>& grid, int index);
bool placable(int num, vector<vector<int>>& grid, int row, int col);
void printGrid(vector<vector<int>>& grid);
bool isValidInitialGrid(vector<vector<int>>& grid);

int main() {

    // -------- USER MESSAGE --------
    cout << "=========================================\n";
    cout << "        SUDOKU SOLVER - C++\n";
    cout << "=========================================\n\n";

    cout << "IMPORTANT:\n";
    cout << "This program is designed to run in:\n";
    cout << "  - Command Prompt (Windows)\n";
    cout << "  - PowerShell (Windows)\n";
    cout << "  - Terminal (Linux / Mac)\n\n";

    cout << "DO NOT paste input inside IDE terminals (VS Code, CodeBlocks, "
            "etc.),\n";
    cout << "as they may terminate input unexpectedly.\n\n";

    cout << "If you don't know how to open Command Prompt or PowerShell,\n";
    cout << "please read the README.md file included with this project.\n\n";

    cout << "-----------------------------------------\n";
    cout << "INPUT FORMAT:\n";
    cout << " - Enter a 9x9 Sudoku grid\n";
    cout << " - Use numbers 1 to 9\n";
    cout << " - Use 0 for empty cells\n";
    cout << "-----------------------------------------\n\n";

    cout << "AI PROMPT (use if you have a Sudoku image):\n";
    cout << "-----------------------------------------\n";
    cout << "Convert the Sudoku image into 9 rows of 9 numbers.\n";
    cout << "Use 0 for empty cells.\n";
    cout << "Return ONLY numbers.\n";
    cout << "NO explanations, NO extra text.\n";
    cout << "Each row on a new line.\n\n";
    cout << "Example:\n";
    cout << "0 3 0 0 7 0 0 0 0\n";
    cout << "6 0 0 1 9 5 0 0 0\n";
    cout << "-----------------------------------------\n\n";

    vector<vector<int>> grid(9, vector<int>(9));
    cout << "Enter the Sudoku grid below:\n";

    // -------- INPUT --------
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!(cin >> grid[i][j]) || grid[i][j] < 0 || grid[i][j] > 9) {
                cout << "❌ Invalid input detected. Program terminated.\n";
                return 0;
            }
        }
    }

    // -------- INITIAL VALIDATION --------
    if (!isValidInitialGrid(grid)) {
        cout << "Invalid Sudoku configuration. Program terminated.\n";
        return 0;
    }

    // -------- SOLVE --------
    if (solveSudoku(grid, 0)) {
        cout << "\nSudoku Solved Successfully:\n";
        printGrid(grid);
    } else {
        cout << "Sudoku is unsolvable.\n";
    }

    return 0;
}

// -------- SOLVER --------
bool solveSudoku(vector<vector<int>>& grid, int index) {
    if (index == 81)
        return true;

    int row = index / 9, col = index % 9;

    if (grid[row][col] != 0)
        return solveSudoku(grid, index + 1);

    for (int num = 1; num <= 9; num++) {
        if (placable(num, grid, row, col)) {
            grid[row][col] = num;
            if (solveSudoku(grid, index + 1))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

// -------- PLACEMENT CHECK --------
bool placable(int num, vector<vector<int>>& grid, int row, int col) {

    for (int j = 0; j < 9; j++)
        if (grid[row][j] == num)
            return false;

    for (int i = 0; i < 9; i++)
        if (grid[i][col] == num)
            return false;

    int stRow = (row / 3) * 3, stCol = (col / 3) * 3;

    for (int i = stRow; i < stRow + 3; i++)
        for (int j = stCol; j < stCol + 3; j++)
            if (grid[i][j] == num)
                return false;

    return true;
}

// -------- INITIAL GRID VALIDITY --------
bool isValidInitialGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] != 0) {
                int temp = grid[i][j];
                grid[i][j] = 0;
                if (!placable(temp, grid, i, j))
                    return false;
                grid[i][j] = temp;
            }
        }
    }
    return true;
}

// -------- PRINT GRID --------
void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < 9; i++) {

        if (i % 3 == 0)
            cout << "+-------+-------+-------+\n";

        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
                cout << "| ";

            if (grid[i][j] == 0)
                cout << ". ";
            else
                cout << grid[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "+-------+-------+-------+\n";
}
