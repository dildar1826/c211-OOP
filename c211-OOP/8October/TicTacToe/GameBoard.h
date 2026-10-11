#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
using namespace std;

enum PlayerTurn { FIRST_PLAYER = 1, SECOND_PLAYER = 2 };
enum GameStatus { DRAW, WIN, IN_PROGRESS };

class GameBoard {
private:
    char data[3][3]; 
    GameStatus gameStatus;
    int validMovesCount;

public:
    GameBoard() {
        // Initialize the board with numbers '1' through '9'....
        char count = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] = count++;
            }
        }
        gameStatus = IN_PROGRESS;
        validMovesCount = 0;
    }

    void displayBoard() {
        cout << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void markBoard(char pos, char playerSymbol) {
        // Map grid position ('1'-'9') to 2D array indices
        int index = pos - '1';
        int row = index / 3;
        int col = index / 3 ? (index % 3) : index; // Fix calculation for column index
        // Cleaner conversion:
        row = (pos - '1') / 3;
        col = (pos - '1') % 3;

        data[row][col] = playerSymbol;
        validMovesCount++;

        // Check for Win conditions
        // Rows & Columns
        for (int i = 0; i < 3; i++) {
            if (data[i][0] == data[i][1] && data[i][1] == data[i][2]) {
                gameStatus = WIN;
                return;
            }
            if (data[0][i] == data[1][i] && data[1][i] == data[2][i]) {
                gameStatus = WIN;
                return;
            }
        }
        // Diagonals
        if (data[0][0] == data[1][1] && data[1][1] == data[2][2]) {
            gameStatus = WIN;
            return;
        }
        if (data[0][2] == data[1][1] && data[1][1] == data[2][0]) {
            gameStatus = WIN;
            return;
        }

        // Check for Draw condition (9 valid moves total)
        if (validMovesCount == 9) {
            gameStatus = DRAW;
        }
    }

    bool isValidPosition(char pos) {
        return (pos >= '1' && pos <= '9');
    }

    bool isAlreadyMarked(char pos) {
        int index = pos - '1';
        int row = index / 3;
        int col = index % 3;
        // If it contains a number character '1'-'9', it's not marked yet
        return (data[row][col] == 'X' || data[row][col] == 'Y');
    }

    int getValidMovesCount() {
        return validMovesCount;
    }

    GameStatus getGameStatus() {
        return gameStatus;
    }
};

#endif