#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char> > &board);
bool updateBoard(vector<vector<char> > &board, int row, int col, char player);
bool checkForWin(const vector<vector<char> > &board, char player);
bool checkForDraw(const vector<vector<char> > &board);
void switchPlayers(char &currentPlayer);

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << "'s turn. Enter row (1-3) and column (1-3) separated by space: ";
        cin >> row >> col;

        // Adjust for zero-based indexing
        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (!updateBoard(board, row, col, currentPlayer)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        gameWon = checkForWin(board, currentPlayer);
        gameDraw = checkForDraw(board);
        if (gameWon || gameDraw)
            break;

        switchPlayers(currentPlayer);
    }

    displayBoard(board);

    if (gameWon)
        cout << "Player " << currentPlayer << " wins!" << endl;
    else if (gameDraw)
        cout << "It's a draw!" << endl;

    return 0;
}

// Function to display the current state of the board
void displayBoard(const vector<vector<char> > &board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to update the board with the player's move
bool updateBoard(vector<vector<char> > &board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Function to check if the current player has won
bool checkForWin(const vector<vector<char> > &board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Function to check if the game is a draw
bool checkForDraw(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to switch players
void switchPlayers(char &currentPlayer) {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}


