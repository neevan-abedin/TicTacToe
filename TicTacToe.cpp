/******************************************************************************

Tic Tac Toe by Nabhan Abedin
3.7.2021
2 Player Tic Tac Toe game using user array index inputs

*******************************************************************************/
#include <iostream>
using namespace std;

//function prototypes
void drawBoard(int grid[3][3]);
bool checkWin(int player, int grid[3][3]);
bool checkTie(int grid[3][3]);
void clearBoard(int grid[3][3]);

int main()
{
    int grid[3][3] = {};
    int xMove = 1; //assign numbers to switch between turns
    int oMove = 2;
    int turn = xMove; //keep track of whose turn it is
    int xWins = 0;
    int oWins = 0;
    int ties = 0;
    int row, col; //placeholder from inputted array index
    char col_c; //column index (A,B or C)    
    
    
    bool stillPlaying = true;
    
    while (stillPlaying = true) {
        while (checkWin(xMove, grid) != true && checkWin(oMove, grid) != true && checkTie(grid) != true) {
            drawBoard(grid); //draw board
            if (turn == xMove) {
                cout << "Enter a letter followed by a number: " << endl;
                cin >> col_c >> row;
                //convert input into integer index for int array
                if (col_c == 'a' || col_c == 'A') {
                    col = 0;
                }
                else if (col_c == 'b' || col_c == 'B') {
                    col = 1;
                }
                else if (col_c == 'c' || col_c == 'C') {
                    col = 2;
                } else {
                    cout << "Invalid input! Please input either a, b, or c for your column choice." << endl;
                    //validMove = false;
                }
                //out of bounds row index
                if (row < 0 || row > 2 ) {
                    cout << "Invalid input! Please input either 0, 1, or 2 for your row choice." << endl;
                    //validMove = false;
                }
                //if square is already taken
                if (grid[row][col] != 0) {
                    cout << "Invalid input! Please choose an empty square." << endl;
                    //validMove = false;
                }
                grid[row][col] = xMove; //place X at index position
                turn = oMove;
            } else {
                cout << "Enter a letter followed by a number: " << endl;
                cin >> col_c >> row;
                //convert input into integer index for int array
                if (col_c == 'a' || col_c == 'A') {
                    col = 0;
                }
                else if (col_c == 'b' || col_c == 'B') {
                    col = 1;
                }
                else if (col_c == 'c' || col_c == 'C') {
                    col = 2;
                } else {
                    cout << "Invalid input! Please input either a, b, or c for your column choice." << endl;
                    //validMove = false;
                }
                //out of bounds row index
                if (row < 0 || row > 2 ) {
                    cout << "Invalid input! Please input either 0, 1, or 2 for your row choice." << endl;
                    //validMove = false;
                }
                //if square is already taken
                if (grid[row][col] != 0) {
                    cout << "Invalid input! Please choose an empty square." << endl;
                    //validMove = false;
                }
                grid[row][col] = oMove; //place X at index position
                turn = xMove;
            }
            if (checkWin(xMove, grid) == true) {
                xWins++;
                cout << "Player 1 wins! They now have " << xWins << " wins." << "\n";
                clearBoard(grid);
                turn = xMove;
            } else if (checkWin(oMove, grid) == true) {
                oWins++;
                cout << "Player 2 wins! They now have " << oWins << " wins." << "\n";
                clearBoard(grid);
                turn = xMove;
            } else if (checkTie(grid) == true) {
                ties++;
                cout << "Tie game! Number of ties: " << ties << "\n";
                clearBoard(grid);
                turn = xMove;
            }
        }    
    }
}

//draw board
void drawBoard(int grid[3][3]) {
  cout << "  " << "  A   B   C" << endl; //column index (letters)
  cout << "  " << "+---+---+---+" << endl;
  for (int row = 0; row < 3; row++) {
    cout << row << " "; //row index (numbers)
    for (int col = 0; col < 3; col++) {
      switch (grid[row][col]) { //print out X when grid index = 1, O when grid index = 2
        case 0: cout << "| " << "E" << " "; break;
        case 1: cout << "| " << "X" << " "; break;
        case 2: cout << "| " << "O" << " "; break;
        default: cout << "| " << grid[row][col] << " "; break;
      }
    }
    cout << "|" << endl;
    cout << " " << " " << "+---+---+---+" << endl;
  }    
}


//check every possibility for 3 same marks in a row in the array
bool checkWin(int player, int grid[3][3]) {
    if (player == grid[0][0] && grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) {
        return true;
    } else if (player == grid[0][1] && grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) {
        return true;
    } else if (player == grid[2][0] && grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {
        return true;
    } else if (player == grid[0][0] && grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) {
        return true; 
    } else if (player == grid[1][0] && grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) {
        return true;
    } else if (player == grid[2][0] && grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {
        return true;
    } else if (player == grid[0][0] && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return true;
    } else if (player == grid[2][0] && grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) {
        return true;
    } else {
        return false;
    }
}

//check tie (if any space is blank, return false)
bool checkTie(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

//clear board by setting everything to 0 again
void clearBoard(int grid[3][3]) {
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = 0;
        }
    }
}
