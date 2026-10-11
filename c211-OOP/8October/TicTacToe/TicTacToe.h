#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "GameBoard.h"

class TicTacToe {
private:
    bool isValidPlayerSymbol(char symbol) {
        return !(symbol >= '1' && symbol <= '9'); // Symbol shouldn't be a digit
    }

public:
    void playGame() {
        GameBoard board;
        PlayerTurn currentPlayer = FIRST_PLAYER;

        char player1Symbol;
        char player2Symbol;
        bool validSymbol = false;

        do {
            cout << "Enter Player 1 Symbol: ";
            cin >> player1Symbol;
            validSymbol = isValidPlayerSymbol(player1Symbol);
            if (!validSymbol)
                cout << "Not a Valid Symbol\n";
        } while (!validSymbol);

        do {
            cout << "Enter Player 2 Symbol: ";
            cin >> player2Symbol;
            validSymbol = isValidPlayerSymbol(player2Symbol);
            if (!validSymbol || player2Symbol == player1Symbol)
                cout << "Not a Valid Symbol\n";
        } while (!validSymbol || player2Symbol == player1Symbol);

        char cellNumber;
        char currentPlayerSymbol = player1Symbol;

        do {
            board.displayBoard();
            bool validMove = false;
            do {
                cout << "\nPlayer " << currentPlayer << " Turn: Enter Position: ";
                cin >> cellNumber;
                
                if (board.isValidPosition(cellNumber) && !board.isAlreadyMarked(cellNumber)) {
                    board.markBoard(cellNumber, currentPlayerSymbol);
                    validMove = true;
                } else {
                    cout << "Invalid or already marked cell! Try again.\n";
                }
            } while (!validMove);

            if (board.getGameStatus() == WIN) {
                board.displayBoard();
                cout << "\nGame Won by Player : " << currentPlayer << "\n";
            } else if (board.getGameStatus() == DRAW) {
                board.displayBoard();
                cout << "\nGame Draw\n";
            } else {
                // Switch player
                if (currentPlayer == FIRST_PLAYER) {
                    currentPlayer = SECOND_PLAYER;
                    currentPlayerSymbol = player2Symbol;
                } else {
                    currentPlayer = FIRST_PLAYER;
                    currentPlayerSymbol = player1Symbol;
                }
            }

        } while (board.getGameStatus() == IN_PROGRESS);
    }
};

#endif