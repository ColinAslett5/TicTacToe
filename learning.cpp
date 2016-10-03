#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;
void board(char num[3], int square[3][3], int turn);
bool checkwin(int player, int square[][3]);
//void boardreset();

int main(){
  int square[3][3];
  for(int i = 0; i < 3;i++){
    for(int b = 0; b < 3;b++){
      square[i][b] = 2;//means nothing is there
    }
  }
  int turn = 0;// 0 is player 1, 1 is player 2
  bool result = checkwin(turn, square);
  if(result == false){
    cout << "No Winner yet" << endl;
  }
  else if(result == true){
    cout << "Winner!" << endl;
  }
  while(result == false){
    char input[3];
    cout << "choose a square" << endl;
    cin >> input;
    board(input, square, turn);
    bool result = checkwin(turn,square);
    if(result == false){
    }
    else if(result == true){
      cout << "Winner!" << endl;
      cout << "Do you want to play again?" << endl;
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

void board(char num[3], char square[][3], int t){
  cout << num << endl;
  //have to see which turn it is by making an if statement,
  if(strcmp(num,"a1") == 0 && square[0][0] == 2){
    if(t == 0){
      square[0][0] = 0;
    }
    else{
      square[0][0] = 1;
    }
  }
  else{
  }
  if(strcmp(num,"a2") == 0 && square[0][1] == 2){
    if(t == 0){
      square[0][1] = 0;
    }
    else{
      square[0][1] = 1;
    }
  }
  else{
  }
  if(strcmp(num,"a3") == 0 && square[0][2] == 2){
    if(t == 0){
      square[0][2] = 0;
    }
    else{
      square[0][2] = 1;
    }
  }
  if(strcmp(num,"b1") == 0 && square[1][0] == 2){
    if(t == 0){
      square[1][0] = 0;
    }
    else{
      square[1][0] = 1;
    }
  }
  if(strcmp(num,"b2") == 0 && square[1][1] == 2){
    if(t == 0){
      square[1][1] = 0;
    }
    else{
      square[1][1] = 1;
    }
  }
  if(strcmp(num, "b3") == 0 && square[1][2] == 2){
    if(t == 0){
      square[1][2] = 0;
    }
    else{
      square[1][2] = 1;
    }
  }
  if(strcmp(num, "c1") == 0 && square[2][0] == 2){
    if(t == 0){
      square[2][0] = 0;
    }
    else{
      square[2][0] = 1;
    }
  }
  if(strcmp(num, "c2") == 0 && square[2][1] == 2){
    if(t == 0){
      square[2][1] = 0;
    }
    else{
      square[2][1] = 1;
    }
  }
  if(strcmp(num, "c3") == 0 && square[2][2] == 2){
    if(t == 0){
      square[2][2] = 0;
    }
    else{
      square[2][2] = 1;
    }
  }
  cout << "  1 2 3" << endl;
  cout << "a " << square[0][0] << " " << square[0][1] << " " << square[0][2] << endl << "b " << square[1][0] << " " << square[1][1] << " " << square[1][2] << endl << "c " << square[2][0] << " " << square[2][1] << " " << square[2][2] << endl;
  //print out squares
  //change turn number
  //check checkwin in int main
}
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
  if(square[0][3] == player && square[1][1] == player && square[0][3] == player){
    return true;
  }
  return false;
}
