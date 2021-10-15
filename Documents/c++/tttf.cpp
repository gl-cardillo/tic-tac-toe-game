#include <iostream>
#include <vector>
#include "tttf.h"


std::vector<char> board= {' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' '};

void draw() {

  std::cout << "  " << board[0] << "  |  " << board[1] << "  |   " << board[2] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[3] << "  |  " << board[4] << "  |   " << board[5] << "\n";
  std::cout << "_____|_____|_____\n";
  std::cout << "  " << board[6] << "  |  " << board[7] << "  |   " << board[8] << "\n";
  std::cout << "     |     |      \n";

}

void description() {
  std::cout << "=============================\n";
  std::cout << "welcome to a tic tac toe game\n";
  std::cout << "=============================\n\n";
  std::cout << "I guess you know the rules ;)\n\n";
}

int moves = 0;
void game() {

  int place;
  char player1 = 'X';
  char player2 = '0';

  while (moves <9) {
    
    if (moves % 2 == 0) {
      
     
      std::cout <<"Player1 select a place between 0 and 8: ";
      std::cin >> place;
      if (board[place] == ' ') {

      board[place] = player1;
      draw();
      

     } else {

      std::cout << "This place is already occupied! choose another one\n";
      draw();
      game();
      

     }
    } else {

      std::cout <<"Player2 select a place between 0 and 8: ";
      std::cin >> place;
      if (board[place] == ' ') {
      
      board[place] = player2;
      draw();
      
      
      } else {

      std::cout << "This place is already occupied! choose another one\n";
      draw();
      game();
      

     }
    }moves += 1;
    

  }
}
