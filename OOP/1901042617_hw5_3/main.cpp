#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <limits>
#include <ios>
#include <thread>         
#include <chrono>
#include <fstream>
using namespace std;
#include "hw5.h"
using namespace my_namespace;
using namespace std;


int main(){
 
 ofstream file("test.txt");
 int operation,game_type;
 bool menu=true,end=false;
 string move_command;
 vector<BoardGame2D *> games;


 BoardGame2D *ptr=new PegSolitaire();
games.push_back(ptr);

 
 BoardGame2D * ptr2=new EightPuzzle(); //set new games 2 objects of each class.
 BoardGame2D * ptr3=new Klotski();
 
 BoardGame2D *ptr4=new PegSolitaire();
 BoardGame2D *ptr5=new EightPuzzle();
 BoardGame2D *ptr6=new Klotski();
 BoardGame2D *ptr7=new PegSolitaire();

 
 games.push_back(ptr2);
 games.push_back(ptr3); //puts them into vector.
 games.push_back(ptr4);
 games.push_back(ptr5);
 games.push_back(ptr6);
 games[0]->initialize();
 
 games[1]->initialize();
 
 
 games[2]->initialize(); //initialzie all of them.
 games[3]->initialize();
 
 
 games[4]->initialize();
 games[5]->initialize();
 
 
 
 cout<<"please enter the game type"<<"pegsolitaire (1) , eightpuzzle(2) klotski(3)"<<endl; //first take the input from userthat  which game to play.
 cin>>game_type;

 if(game_type==1 || game_type ==3 || game_type==2){
   
   while(menu){
  end=games[game_type-1]->endGame(); //menu run until the end of the game.
  if(end==true){
    menu=false;
  }
  cout<<"enter the operation \n"<<" 1 :print the current game on the screen\n"<<" 2 : move  for one movement by computer\n"<<" 3 : move for one movement manuely\n"<<" 4 : print the current score of the current  game\n"<<" 5 : play the current game until the end by computer\n"<<" 6 : play all the games .\n"<<" 7 : play the game until the end manually\n"<<" 8 : exit "<<endl;
  cin>>operation; //reads the operations.

  switch(operation){

      case 1:
       games[game_type-1]->print();

        break;

      case 2:

       games[game_type-1]->playAuto();

       break;

      case 3:

      cout<<"enter the movement code"<<endl;
      cout<<"if the game is eight puzzle enter the code  ex 2B-Up, 3C-Down"<<endl<<"if the game is pegsoltiare enter the code ex 2B-Up, 3C-Down etch"<<endl<<"if the game is klotski please enter the movement code ex ys-r1 yellow square right for one step \n"<<endl<<"colors:green(g) yellow(y) red(r) blue(b) purple(p) "<<endl<<"direction right(r) left(l) up(u) down(d) "<<endl<<"step: 1 or 2"<<endl<<"shape: square(s) rectangle(r) big square(b)"<<endl;
    
      cin>>move_command;
      games[game_type-1]->playUser(move_command);
      break;

      case 4:

      cout<<"score: "<<games[game_type-1]->BoardScore()<<endl;

      break;

       case 5:
        games[game_type-1]->PlayAutoAll();
        break;

       case 6:
        playVector(games);
        break;
       case 7:
       games[game_type-1]->playUser();
        break;
      case 8:
       menu=false;

        break; 
      default:
       cout<<"invalid operation";

       break;
  }

 }

 }
 else{
     cerr<<"invalid gametype"<<endl;
 }
 
 cout<<endl<<"the score is: "<<games[game_type-1]->BoardScore();
 
 if(!file.is_open()){ 

     cout<<"file could not open";
   }
 else {

   if(game_type==1){
    file<<"pegsolitaire\n";
   }
   if(game_type==2){
     file<<"eightpuzzle\n"; //writes to test file the game type the point and if the game finished or not.
   }
   if(game_type==3){
    file<<"klotski\n";
   }
   

   file<<"the  score is "<<games[game_type-1]->BoardScore()<<endl;
   end=games[game_type-1]->endGame();
   if(end==true){
     file<<"the game finished\n";
   }
   else{
     file<<"the game has not finished\n";
   }
 }
  file.close();


    return 0;
}
