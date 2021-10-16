#include <iostream>
#include <vector>
#include "tttf.h"


std::vector<char> board= {' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' '};
int moves = 0;
bool play = true;
int place;
char again;
char player1 = 'X';
char player2 = '0';


// the board
void draw()  {

 
  std::cout << "  " << board[0] << "  |  " << board[1] << "  |   " << board[2] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[3] << "  |  " << board[4] << "  |   " << board[5] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[6] << "  |  " << board[7] << "  |   " << board[8] << "\n";
  std::cout << "     |     |      \n";

}

void occupied() {
   
  std::cout << "This place is already occupied! choose another one\n";
  draw();
  selection();

}

// how you select the place where to put X or 0
void selection() {
 
  while (play && moves < 9) {
    
    if (moves % 2 == 0) {
      
      std::cout <<"Player 1 select a place between 0 and 8: ";
      std::cin >> place;
      if (board[place] == ' ') {

      board[place] = player1;
      draw();
      

     } else {

      occupied();
      
     }
    } else  {

      std::cout <<"Player 2 select a place between 0 and 8: ";
      std::cin >> place;
      if (board[place] == ' ') {
      
      board[place] = player2;
      draw();
      
      } else {

      occupied();
      
     }
    }
    game();
    moves += 1;
   } 
   
   if (moves == 9) {
     std::cout << "It's a tie!!\n";
     endgame();
  }
} 

// check if someone won
void game() {
  
    if (((board[0] == board[1] && board[1] == board[2] )
     || (board[0] == board[3] && board[3] == board[6] ) 
     || (board[0] == board[4] && board[4] == board[8] )) 
     && (board[0] != ' ')) {

    std::cout << "Congratulation player " << board[0] << ", you won the game!!\n";
    endgame();
  } 
   
  if (((board[6] == board[4] && board[4] == board[2] )
    || (board[6] == board[7] && board[7] == board[8] ))
    && (board[6] != ' '))  {
      
    std::cout << "Congratulation player " << board[6] << ", you won the game!!\n";
    endgame();
  }
  
  if (((board[1] == board[4] && board[4] == board[7] ) 
    || (board[3] == board[4] && board[4] == board[5])) 
    && (board[4] != ' ')) {
    
    std::cout << "Congratulation player " << board[4] << ", you won the game!!\n";
    endgame();
   
  }  
  if ((board[2] == board[5] && board[5] == board[8]) && (board[2] != ' '))  {
      
    std::cout << "Congratulation player " << board[2] << ", you won the game!!\n";
    endgame();
     
  }
} 

//end game play again
void endgame() {

  std::cout << "Would you like to play again? y/n: ";
  std::cin >> again;
  if (again == 'y') {

    resetboard();
    draw();
    selection();
  
  } else {

    play = false;
  }
}

//restart board
void resetboard() {

  for (int i = 0; i < board.size(); i++) {
    
    moves = 0;
    board[i] = ' ';
  }
}

