//COlin Aslett, C++, Period 07
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;
void board(char num[3], int (&square)[3][3], int turn);
bool checkwin(int player, int square[][3]);
void boardreset(int (&square)[3][3]);
bool checktie(int (&square)[3][3]);

int main(){
  //main array for the board
  int square[3][3];
  //setting the board to 2's or no values
  for(int i = 0; i < 3;i++){
    for(int b = 0; b < 3;b++){
      square[i][b] = 2;//means nothing is there
    }
  }
  int turn = 0;// 0 is player 1, 1 is player 2
  bool result = false;
  bool tie = false;
  //results for X's and O's
  int xwins = 0;
  int owins = 0;
  while(result == false){
    char input[3];
    cout << "choose a square" << endl;
    cin >> input;
    //making sure input is valid
    while(!(input[0] == 'a' || input[0] == 'b' || input[0] == 'c') || !(input[1] == '1' || input[1] == '2' || input[1] == '3')){
      cout << "Not a valid response, it should be a1,a2,a3,b1,b2,b3,c1,c2,c3";
      cin >> input;
    }
    board(input, square, turn);
    bool result = checkwin(turn,square);
    bool tie = checktie(square);
    if(tie == true){
      char answer1[1];
      cout << "Tie!" << endl;
      cout << "Xwins: " << xwins << endl << "O wins: " << owins << endl;
      cout << "Do you want to play again?(y or n)" << endl;
      cin >> answer1;
      if(strcmp(answer1,"y") == 0){
	boardreset(square);
	turn = 0;
      }
      else{
	cout << "Goodbye!";
	return 0;
      }
    }
    if(result == true){
      if(turn == 1){
	owins++;
      }
      else{
	xwins++;
      }
      char answer[1];
      cout << "Winner!" << endl;
      cout << "X wins: " << xwins << endl << "O wins: " << owins << endl;
      cout << "Do you want to play again?(y or n)" << endl;
      cin >> answer;
      if(strcmp(answer,"y") == 0){
	boardreset(square);
	turn = 0;
      }
      else{
	cout << "Goodbye";
	return 0;
      }
    }
    if(turn == 0){
      turn = 1;
    }
    else if(turn == 1){
      turn = 0;
    }
  }
  return 0;
 
}
//changes board and the values
void board(char num[3], int (&square)[3][3], int t){
  cout << num << endl;
  char squarenum[9];
  for(int i = 0; i < 3;i++){
    for(int b = 0; b < 3;b++){
      if(square[i][b] == 0){
	squarenum[i*3+b] = 'X';
      }
      if(square[i][b] == 1){
	squarenum[i*3+b] = 'O';
      }
      if(square[i][b] == 2){
	squarenum[i*3+b] = ' ';
      }
    }
  }
  //changes board
  if(strcmp(num,"a1") == 0 && square[0][0] == 2){
    if(t == 0){
      square[0][0] = 0;
      squarenum[0] = 'X';
    }
    else{
      square[0][0] = 1;
      squarenum[0] = 'O';
    }
  }
  if(strcmp(num,"a2") == 0 && square[0][1] == 2){
    if(t == 0){
      square[0][1] = 0;
      squarenum[1] = 'X';
    }
    else{
      square[0][1] = 1;
      squarenum[1] = 'O';
    }
  }
  if(strcmp(num,"a3") == 0 && square[0][2] == 2){
    if(t == 0){
      square[0][2] = 0;
      squarenum[2] = 'X';
    }
    else{
      square[0][2] = 1;
      squarenum[2] = 'O';
    }
  }
  if(strcmp(num,"b1") == 0 && square[1][0] == 2){
    if(t == 0){
      square[1][0] = 0;
      squarenum[3] = 'X';
    }
    else{
      square[1][0] = 1;
      squarenum[3] = 'O';
    }
  }
  if(strcmp(num,"b2") == 0 && square[1][1] == 2){
    if(t == 0){
      square[1][1] = 0;
      squarenum[4] = 'X';
    }
    else{
      square[1][1] = 1;
      squarenum[4] = 'O';
    }
  }
  if(strcmp(num, "b3") == 0 && square[1][2] == 2){
    if(t == 0){
      square[1][2] = 0;
      squarenum[5] = 'X';
    }
    else{
      square[1][2] = 1;
      squarenum[5] = 'O';
    }
  }
  if(strcmp(num, "c1") == 0 && square[2][0] == 2){
    if(t == 0){
      square[2][0] = 0;
      squarenum[6] = 'X';
    }
    else{
      square[2][0] = 1;
      squarenum[6] = 'O';
    }
  }
  if(strcmp(num, "c2") == 0 && square[2][1] == 2){
    if(t == 0){
      square[2][1] = 0;
      squarenum[7] = 'X';
    }
    else{
      square[2][1] = 1;
      squarenum[7] = 'O';
    }
  }
  if(strcmp(num, "c3") == 0 && square[2][2] == 2){
    if(t == 0){
      square[2][2] = 0;
      squarenum[8] = 'X';
    }
    else{
      square[2][2] = 1;
      squarenum[8] = 'O';
    }
  }
  //printing out the board
  cout << "  1 2 3" << endl;
  cout << "a " << squarenum[0] << " " << squarenum[1] << " " << squarenum[2] << endl << "b " << squarenum[3] << " " << squarenum[4] << " " << squarenum[5] << endl << "c " << squarenum[6] << " " << squarenum[7] << " " << squarenum[8] << endl;
  //print out squares
  //change turn number
  //check checkwin in int main
}
//checking for a win for each of the 8 different ways
bool checkwin(int player, int square[][3]){
  if(square[0][0] == player && square[0][1] == player && square[0][2] == player){
    return true;
  }
  if(square[1][0] == player && square[1][1] == player && square[1][2] == player){
    return true;
  }
  if(square[2][0] == player && square[2][1] == player && square[2][2] == player){
    return true;
  }
  if(square[0][0] == player && square[1][0] == player && square[2][0] == player){
    return true;
  }
  if(square[0][1] == player && square[1][1] == player && square[2][1] == player){
    return true;
  }
  if(square[0][2] == player && square[1][2] == player && square[2][2] == player){
    return true;
  }
  if(square[0][0] == player && square[1][1] == player && square[2][2] == player){
    return true;
  }
  if(square[0][2] == player && square[1][1] == player && square[2][0] == player){
    return true;
  }
  return false;
}
//reseting the board
void boardreset(int (&square)[3][3]){
  for(int i = 0; i < 3;i++){
    for(int b = 0; b < 3;b++){
      square[i][b] = 2;
    }
  }
}
//checking for ties
bool checktie(int (&square)[3][3]){
  int blocks = 0;
  for(int i = 0; i < 3;i++){
    for(int b = 0; b < 3;b++){
      if(square[i][b] == 1 || square[i][b] == 0){
	blocks++;
      }
    }
  }
  if(blocks == 9){
    return true;
  }
  return false;
}
