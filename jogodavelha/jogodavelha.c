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
        printf(" %c " , board[i][j]);

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
 return 0;
  }
}
int isDraw() {
  for(int i =0; i <3 ; i++)
    for(int j =0; j<3 ; j++)
      if (board[i][j]== ' ')
        return 0;
  return 1;
}

void switchPlayer(){
  if (currentPlayer == 'X')
    currentPlayer = 'O';
  else
    currentPlayer = 'X';
}

void makeMove() {
  int pos;
  while (1){
    printf("jpgador %c,escolha uma posição entre 1-9: ",currentPlayer);
    
    scanf("%d", &pos);

    if (pos >= 1 && pos <=9){
      int row = (pos - 1)/3;
      int col = (pos - 1) % 3;

      if (board[row][col] == ' '){
        board[row][col] = currentPlayer;
        break;
      }else
        printf("essa posição já está ocupada.\n");
    }else
      printf("A posição %d é invalida, por favor tente denovo");
  }
}

int main() {

  initializeBoard();
  while(1){
    
  
  printBoardWithOptions();
  makeMove();
    if(isWinner()){
      printBoardWithOptions();
      printf("jogador %c Venceu!\n ",currentPlayer);
      break;
    if (isDraw())  {
      printBoardWithOptions();
      printf("VELHA!");
        break;
    };
    }
    switchPlayer();
  }
return 0;
}

