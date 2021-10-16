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


// the board
void draw()  {

 
  std::cout << "  " << board[1] << "  |  " << board[2] << "  |   " << board[3] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[4] << "  |  " << board[5] << "  |   " << board[6] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[7] << "  |  " << board[8] << "  |   " << board[9] << "\n";
  std::cout << "     |     |      \n";

}

char turn() {

  if (moves % 2 == 0) {
  
    return player1;
  
  } else {

    return player2;
  }

}

void occupied() {
   
  std::cout << "This place is already occupied! choose another one\n";
  draw();
  selection();

}

// how you select the place where to put X or 0
void selection() {
 
  while ((play == true)  && (moves < 9)) {
    
  std::cout << turn() << " select a place between 0 and 8: ";
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

//end game play again
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

