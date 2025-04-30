#include<stdio.h>

//criado o tabuleiro
char board[3][3];

//jpgadpr atual
char currentPlayer = 'X';

// o/o/o
// o/o/o
// o/o/o

void initializeBoard() {
  for (int i= 0; i < 3; i++)
    for(int j=0; j < 3; j++)
      board[i][j] = ' ';
}

//tabuleiro depois da função
//  | |
//  | |
//  | |

void printBoardWithOptions(){
  printf("\nTabuleiro:\n");
  for (int i=0; i<3; i++){
    for(int j=0 ; j<3; j++){
      int pos = i * 3 + j +1 ;

      if(board[i][j] == ' ')
        printf(" %d ",pos );

      else
        printf(" %c" , board[1][j]);

      if ( j<2 )
        printf("|");

    }
    if (i < 2 )
      printf("\n-----------\n");
  }
printf("\n");
}

int isWinner() {
  for (int i =0; i<3 ; i++){
    //verificar que alguem completou uma linha;
    if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2]  == currentPlayer )
      return 1;

    if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i]  == currentPlayer )
      return 1;

    if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2]  == currentPlayer )
      return 1;

    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2]  == currentPlayer )
      return 1;

    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0]  == currentPlayer )
      return 1;
  }
}

int main() {

  initializeBoard();
  printBoardWithOptions();

return 0;
}

