#include <iostream>
#include <vector>
#include "tttf.h"


      
std::vector<char> board= {'n',' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' '};
int moves = 0;
bool play = true;
int place;
char again;
char player1 = 'X';
char player2 = '0';

//description of the game and rules
void description() {
std::cout << "This is a game for two player who take turns marking the spaces in a 3x3 grid with X or 0, \n";
std::cout << "you will be able to choose the space between 1 and 9 (starting from the upper-left side).\n";
std::cout << "The player who succeeds in placing 3 of their marks in a horizontal, vertical or diagonal row is the winner.\n";
std::cout << "Good luck ;)\n\n";}

// the board
void draw()  {

  std::cout << "\n  " << board[1] << "  |  " << board[2] << "  |   " << board[3] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[4] << "  |  " << board[5] << "  |   " << board[6] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[7] << "  |  " << board[8] << "  |   " << board[9] << "\n";
  std::cout << "     |     |      \n\n";

}

//change turn
char turn() {

  if (moves % 2 == 0) {
  
    return player1;
  
  } else {

    return player2;
  }

}

// if place is already occupied
void occupied() {
   
  std::cout << "This place is already occupied! choose another one\n";
  draw();
  selection();

}

// how you select the place where to put X or 0
void selection() {
 
  while (play == true && moves < 9) {
    
  std::cout << "Player " << turn() << " select a place between 1 and 9: ";
  std::cin >> place;
  
  if (board[place] == ' ') {

    board[place] = turn();
    draw();
    game();
    moves += 1;

  } else {

    occupied();
    game();
    moves += 1;
    }
   
   } 
   
  if (moves == 9) {
     std::cout << "It's a tie!!\n";
     endgame();
  }
} 

// check if someone won
void game() {
  if (play == true) {
    if (((board[1] == board[2] && board[2] == board[3] )
     || (board[1] == board[4] && board[4] == board[7] ) 
     || (board[1] == board[5] && board[5] == board[9] )) 
     && (board[1] != ' ')) {

    std::cout << "Congratulation player " << board[1] << ", you won the game!!\n";
    endgame();
  } 
   
  if (((board[7] == board[5] && board[5] == board[3] )
    || (board[7] == board[8] && board[8] == board[9] ))
    && (board[7] != ' '))  {
      
    std::cout << "Congratulation player " << board[7] << ", you won the game!!\n";
    endgame();
  }
  
  if (((board[2] == board[5] && board[5] == board[8] ) 
    || (board[4] == board[5] && board[5] == board[6])) 
    && (board[5] != ' ')) {
    
    std::cout << "Congratulation player " << board[5] << ", you won the game!!\n";
    endgame();
    
  }  
  if ((board[3] == board[6] && board[6] == board[9]) && (board[3] != ' '))  {
      
    std::cout << "Congratulation player " << board[3] << ", you won the game!!\n";
    endgame();
     
    }
  }
} 

//end game and play again
void endgame() {

  std::cout << "Would you like to play again? y/n: ";
  std::cin >> again;
  if (again == 'y') {

    resetboard();
    draw();
    selection();
  
  } else if (again == 'n') {

    play = false;
  }
}

//restart board
void resetboard() {

  for (int i = 1; i < board.size(); i++) {
    
    moves = 0;
    board[i] = ' ';
  }
}

