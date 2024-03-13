#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum row_locations{ //decleration of x axis of board as enum type.
a,b,c,d,e,f,g,h,i


};



enum movement_type{ //decleration of movement type as enum.
   
   R,
   L,
   D,
   U


};


enum class cell_type{ //cell types.

    peg,
    empty,
    wall
};

movement_type convert_enum4(int d_type){ //converts integer variables that recieved from user to enum direction type.

  switch(d_type){
    
    case 0:
     return R;
     break;
  
    case 1:
     return L;
     break;
    case 3:
     return U;
     break;
    case 2:
     return D;
     break;
  }
 
 return R;

}

movement_type convert_enum2(char l){ // from char to enum.
  switch (l)
  {
  case 'R':
    return R;
    break;
  
  case 'L':
    return L;
    break;
  case 'U':
    return U;
    break;
  case 'D':
    return D;
    break;
  
  }
 return R;
}
row_locations convert_enum3(int x_loc){ //from int to enum.

  switch(x_loc){
    
    case 0:
     return a;
     break;
    
    case 1:
     return b;
     break;
    
    case 2:
     return c;
     break;

    case 3:
     return d;
     break;

    case 4:
     return e;
     break;

    case 5:
     return f;
     break;

    case 6:
     return g;
     break;

    case 7:
     return h;
     break;

    case 8:
     return i;
     break; 
     

  }
  return a;
}

row_locations convert_enum(char letter){ //from char to enum

  switch(letter){

    case 'a':
     return a;
     break;
    
    case 'b':
     return b;
     break;
    
    case 'c':
     return c;
     break;

    case 'd':
     return d;
     break;

    case 'e':
     return e;
     break;

    case 'f':
     return f;
     break;

    case 'g':
     return g;
     break;

    case 'h':
     return h;
     break;

    case 'i':
     return i;
     break; 
    
    
  }
 return a;
}
bool check_movement_possibility2(const row_locations &xx2,int yy2,const movement_type &turn_type2,vector<vector<cell_type>> & table_test2,int height2,int weight2){
   
   if(turn_type2==0){ //if direction right all the conditions to move 

   if((xx2+4)<weight2 && table_test2[yy2][xx2+4]==cell_type::empty && table_test2[yy2][xx2+2]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
    return false;
   else
    return true;
 }
 if(turn_type2==1){

   if((xx2-4)>0 && table_test2[yy2][xx2-4]==cell_type::empty && table_test2[yy2][xx2-2]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
    return false;
   else
    return true;
 }
 if(turn_type2==2){

   if((yy2+2)<height2 &&(xx2-2)>0 && table_test2[yy2+2][xx2-2]==cell_type::empty && table_test2[yy2+1][xx2-1]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
    return false;
   else if((yy2+2)<height2 &&(xx2+2)<weight2 && table_test2[yy2+2][xx2+2]==cell_type::empty && table_test2[yy2+1][xx2+1]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
    return false;
    else
    return true;
 }
 if(turn_type2==3){

   if((yy2-2)>=0 &&(xx2-2)>=0 && table_test2[yy2-2][xx2-2]==cell_type::empty && table_test2[yy2-1][xx2-1]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
    return false;
   else if((yy2-2)>=0 &&(xx2+2)<weight2 && table_test2[yy2-2][xx2+2]==cell_type::empty && table_test2[yy2-1][xx2+1]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
    return false;
   else
    return true;
 }

 return true;



}


bool check_movement_possibility(const row_locations &xx,int yy,const movement_type &turn_type,vector<vector<cell_type>> & table_test,int board_size){ //to check if the movements commend recieved from pc or user are valid or not 

 if(turn_type==0){ //if direction right all the conditions to move 

   if((xx+2)<board_size && table_test[yy][xx+2]==cell_type::empty && table_test[yy][xx+1]==cell_type::peg && table_test[yy][xx]==cell_type::peg)
    return false;
   else
    return true;
 }
 if(turn_type==1){

   if((xx-2)>0 && table_test[yy][xx-2]==cell_type::empty && table_test[yy][xx-1]==cell_type::peg && table_test[yy][xx]==cell_type::peg)
    return false;
   else
    return true;
 }
 if(turn_type==2){

   if((yy+2)<board_size && table_test[yy+2][xx]==cell_type::empty && table_test[yy+1][xx]==cell_type::peg && table_test[yy][xx]==cell_type::peg)
    return false;
   else
    return true;
 }
 if(turn_type==3){

   if((yy-2)>0 && table_test[yy-2][xx]==cell_type::empty && table_test[yy-1][xx]==cell_type::peg && table_test[yy][xx]==cell_type::peg)
    return false;
   else
    return true;
 }

 return true;
}

bool check_commend_validity(const string comm){ //to check if the recieved commend is valid like b4-L otherwise print an error message

 
  if(comm.length()>4){ //compare the string lenght 

   cout<<"invalid lenght command";
   return true;
 }
  else if(comm[2]!='-'){//if the - exist
    cout<<"- char must be used";
    return true;
  }
   else if(!(comm[0]>96 && comm[0]<106)){ //x axes code is valid or not.
     cout<<"invalid row code";
     return true;
   }
  else if(!(comm[1]>48 && comm[1]<58)){ //collumn code is valid or not
    cout<<"invalid collumn code";
  }
  else if(!(comm[3]==76 || comm[3]==82 || comm[3]==85 || comm[3]==68 )){
    cout<<"invalid movement code";
    return true;
  }
  else 
   return false;
 
 return false;
}

void show_table2(vector<vector<cell_type>> const &tab_6,const int table_height,int table_weight){ //to visualise the current table

 string row_2="abcdefghi";
 string collumn_2="123456789";

    for(int i=0;i<table_height;i++){
        
       
     if(i==0){
         cout<<" ";
         for(int k=0;k<table_weight;k++){
             cout<<" "<<row_2[k];
         }
     }
     
     cout<<"\n"; 
     cout<<collumn_2[i];  
        for(int j=0;j<table_weight;j++){


            if(tab_6[i][j]==cell_type::peg)
              cout<<" P";
            else
              cout<<"  ";
        }
    }
  cout<<endl;

}

void show_table(vector<vector<cell_type>> const &tab_1,const int table_size){

 string row="abcdefghi";
 string collumn="123456789";

    for(int i=0;i<table_size;i++){
        
       
     if(i==0){
         cout<<" ";
         for(int k=0;k<table_size;k++){
             cout<<" "<<row[k];
         }
     }
     
     cout<<"\n"; 
     cout<<collumn[i];  
        for(int j=0;j<table_size;j++){


            if(tab_1[i][j]==cell_type::peg)
              cout<<" P";
            else
              cout<<"  ";
        }
    }
  cout<<endl;
}

bool check_user(char user_t){//check if the entered user type is valid or not.

switch(user_t){

    case '1':
     
     return false;
    

     break;
    case '2':
     
     return false;
    

     break;
    default:
    
     cout<<"invalid user type\n";
     return true;

}


}

void move2(const row_locations &x2,int y2,const movement_type &turn2,vector<vector<cell_type>> &table2){

  switch(turn2){

    case R: //if its R direction change the cell_type as showed below
     table2[y2][x2]=cell_type::empty;
     table2[y2][x2+2]=cell_type::empty;
     table2[y2][x2+4]=cell_type::peg;
     break;

    case L:
     table2[y2][x2]=cell_type::empty;
     table2[y2][x2-2]=cell_type::empty;
     table2[y2][x2-4]=cell_type::peg;
     break;
    case D:
     if(table2[y2+2][x2-2]==cell_type::empty){
       table2[y2][x2]=cell_type::empty;
       table2[y2+1][x2-1]=cell_type::empty;
       table2[y2+2][x2-2]=cell_type::peg;
     }
     else{
       table2[y2][x2]=cell_type::empty;
       table2[y2+1][x2+1]=cell_type::empty;
       table2[y2+2][x2+2]=cell_type::peg;
     }
     break;
    case U:
     
     if(table2[y2-2][x2-2]==cell_type::empty){
        
        table2[y2][x2]=cell_type::empty;
        table2[y2-1][x2-1]=cell_type::empty;
        table2[y2-2][x2-2]=cell_type::peg;

     }
     else{
       
        table2[y2][x2]=cell_type::empty;
        table2[y2-1][x2+1]=cell_type::empty;
        table2[y2-2][x2+2]=cell_type::peg;

     }
     
     break;
  }
}


void move(const row_locations &x,int y,const movement_type &turn,vector<vector<cell_type>> & table){ // to apply desired movement

   switch(turn){

    case R: //if its R direction change the cell_type as showed below
     table[y][x]=cell_type::empty;
     table[y][x+1]=cell_type::empty;
     table[y][x+2]=cell_type::peg;
     break;

    case L:
     table[y][x]=cell_type::empty;
     table[y][x-1]=cell_type::empty;
     table[y][x-2]=cell_type::peg;
     break;
    case D:
     table[y][x]=cell_type::empty;
     table[y+1][x]=cell_type::empty;
     table[y+2][x]=cell_type::peg;
     break;
    case U:
     table[y][x]=cell_type::empty;
     table[y-1][x]=cell_type::empty;
     table[y-2][x]=cell_type::peg;
     break;



   }
}
void board_2(int &p2){
 vector<vector<cell_type>> table_6={{cell_type::wall,cell_type::wall,cell_type::wall,cell_type::wall,cell_type::empty,cell_type::wall,cell_type::wall,cell_type::wall,cell_type::wall},
                                    {cell_type::wall,cell_type::wall,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::wall,cell_type::wall},
                                     {cell_type::wall,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::wall},
                                     {cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall},
                                     {cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg}};
 bool user_type_flag=true,end_of_the_game=true,check_commend2=true,check_movement2=true;
 char user_type2;
 int command2,check_the_end=0,rand_x2,rand_y2,rand_d2,check_finish2=0;
 string move_com;
 row_locations vert;
 movement_type dire,dire2;
 
 while(user_type_flag){

  cout<<"\nis this a human player game(1) or computer game(2)";
  cin>>user_type2;
  user_type_flag=check_user(user_type2);
  

 }
 while(end_of_the_game){
   cout<<"move(1) or exit (2)";
   cin>>command2;
   check_finish2=0;
   show_table2(table_6,table_6.capacity(),table_6[0].capacity());
  if(command2==1){
   cout<<"ready to move"<<endl;
   if(user_type2=='1'){

    cout<<"enter the coordinates and movement type g4-U , e1-D"<<endl;
    
    /*do{
      cin>>move_com;
      check_commend2=check_commend_validity(move_com);
      
    
    }
    while(check_commend2);*/
    cin>>move_com;
    vert=convert_enum(move_com[0]);
    dire=convert_enum2(move_com[3]);
    check_movement2=check_movement_possibility2(vert,((int)move_com[1]-1)-48,dire,table_6,table_6.capacity(),table_6[0].capacity());
    if(check_movement2==false){
        move2(vert,((int)move_com[1]-1)-48,dire,table_6);
        show_table2(table_6,table_6.capacity(),table_6[0].capacity());
        p2--;
    }
    else{
      cout<<"\n"<<"invalid movement"<<endl;
    }
    
    
   } 
   else if(user_type2=='2'){
    
     show_table2(table_6,table_6.capacity(),table_6[0].capacity());
    while(check_movement2){

       rand_x2=rand()%(table_6[0].capacity()); //take codes randomliy and check until its valid move type.
       rand_y2=rand()%(table_6.capacity());
       rand_d2=rand()%4;
       
       vert=convert_enum3(rand_x2);
       dire=convert_enum4(rand_d2);
       check_movement2=check_movement_possibility2(vert,rand_y2,dire,table_6,table_6.capacity(),table_6[0].capacity());
      }
      check_movement2=true;
      move2(vert,rand_y2,dire,table_6);
      show_table2(table_6,table_6.capacity(),table_6[0].capacity());
      p2--;
   }

 }
 else if(command2==2){
   end_of_the_game=false;
 }
 for(int i=0;i<table_6.capacity();i++){ // check all the moves via 3 nested loop if there any possible movement if there is no left then the game finished exit from loop

    for(int j=0;j<table_6[0].capacity();j++){

      for(int k=0;k<4;k++){

        vert=convert_enum3(j);
        dire=convert_enum4(k);
        if(check_movement_possibility2(vert,i,dire,table_6,table_6.capacity(),table_6[0].capacity())==false)
           check_finish2+=1;
      }
    }
  }
  if(check_finish2==0){
    end_of_the_game=false;
  }

}
}
 
 void operate_table(vector<vector<cell_type>> & the_table,char user_tp,int &p){
  
  string movement;
  bool end_game=true,check_commend=true,check_movement=true; //bool variables those to check user input validity or the game finished or not.
  int command,check_finish=0,rand_x,rand_y,rand_d; //rand variables assigned by rand functions for playing with computer.
  row_locations ver; // x axes code to send the functions.
  movement_type dir; // direction code.

  while(end_game){ //while end game bool variable true the game contine.

  cout<<"move(1) or exit (2)"; //to move or exit the game.
  cin>>command;
  check_finish=0;

  if(command==1){
   cout<<"ready to move"<<endl;
   if(user_tp=='1'){ // if user type human.

    cout<<"enter the coordinates and movement type ex a4-L , c5-U"<<endl;
    show_table(the_table,the_table.capacity()); //read the movement code from user.
    do{
      cin>>movement;
      check_commend=check_commend_validity(movement); //check the codes validity if not give an errors message.
      
    
    }
    while(check_commend);
    
    ver=convert_enum(movement[0]); //take specified part from string then convert them to enum type and assign it to ver veriable
    dir=convert_enum2(movement[3]);
    check_movement=check_movement_possibility(ver,((int)movement[1]-1)-48,dir,the_table,the_table.capacity()); //to check if the movement valid if not ask again to enter.
    
    if(check_movement==false){
      move(ver,((int)movement[1]-1)-48,dir,the_table);
      p--;
      show_table(the_table,the_table.capacity());
    }
    else{
      cout<<"invalid movement";
    }
   } 
    else if(user_tp=='2'){ // if the user is computer
      
      show_table(the_table,the_table.capacity());
      while(check_movement){

       rand_x=rand()%(the_table.capacity()); //take codes randomliy and check until its valid move type.
       rand_y=rand()%(the_table.capacity());
       rand_d=rand()%4;
       
       ver=convert_enum3(rand_x);
       dir=convert_enum4(rand_d);
       check_movement=check_movement_possibility(ver,rand_y,dir,the_table,the_table.capacity());
      }
      check_movement=true;
      move(ver,rand_y,dir,the_table);
      cout<<"\n"<<ver<<rand_y+1<<"-"<<dir<<endl;
      show_table(the_table,the_table.capacity());
      p--; //decrease the peg numbers 
    }
    

  }
   
   else if(command==2){ //for quitting  from game use 2.
    end_game=false;
  }

  for(int i=0;i<the_table.capacity();i++){ // check all the moves via 3 nested loop if there any possible movement if there is no left then the game finished exit from loop

    for(int j=0;j<the_table.capacity();j++){

      for(int k=0;k<the_table.capacity();k++){

        ver=convert_enum3(j);
        dir=convert_enum4(k);
        if(check_movement_possibility(ver,i,dir,the_table,the_table.capacity())==false)
           check_finish+=1;
      }
    }
  }
  if(check_finish==0){
    end_game=false;
  }
 }

 }


void board_1(int type,int &point){ //to set the boards.

 char user_type;
 bool user_flag=true;
 

 srand(time(NULL));
 vector<vector<cell_type>> table_1;
 vector<vector<cell_type>> table_2;
 vector<vector<cell_type>> table_3;
 vector<vector<cell_type>> table_4;
 vector<vector<cell_type>> table_5;
 

 table_1.reserve(7); //reserve allocation for boards
 table_2.reserve(9);
 table_3.reserve(8);
 table_4.reserve(7);
 table_5.reserve(9);
 

 for (int i=0;i<7;i++){ //to fill the boards 
  
  table_1[i].reserve(7);
   
  for(int j=0;j<7;j++){
      if((j>0 && j<6) && (i>0 && i<6))
        table_1[i][j]=cell_type::peg;
      else if(((i==0 || i==6) && j>1 && j<5) || ((j==0 || j==6) && i>1 && i<5))
        table_1[i][j]=cell_type::peg;
      else
        table_1[i][j]=cell_type::wall;
  }
     
 }
 
 for(int i=0;i<table_2.capacity();i++){
    
      table_2[i].reserve(table_2.capacity());

      for(int j=0;j<table_2.capacity();j++){
          if((i>2 && i<6) || (j>2 && j<6))
            table_2[i][j]=cell_type::peg;
          else
            table_2[i][j]=cell_type::wall;  
      }

 }

 for(int i=0;i<table_3.capacity();i++){
    
      table_3[i].reserve(table_3.capacity());

      for(int j=0;j<table_3.capacity();j++){
          if((i>2 && i<6) || (j>1 && j<5))
            table_3[i][j]=cell_type::peg;
          else
            table_3[i][j]=cell_type::wall;  
      }

 }
 
 for(int i=0;i<table_4.capacity();i++){
    
      table_4[i].reserve(table_4.capacity());

      for(int j=0;j<table_4.capacity();j++){
          if((i>1 && i<5) || (j>1 && j<5))
            table_4[i][j]=cell_type::peg;
          else
            table_4[i][j]=cell_type::wall;  
      }

 }
 
 for (int i=0;i<table_5.capacity();i++){
  
  table_5[i].reserve(table_5.capacity());
   
  for(int j=0;j<table_5.capacity();j++){
      if((j>1 && j<7) && (i>1 && i<7))
        table_5[i][j]=cell_type::peg;
      else if(((i==1 || i==7) && j>2 && j<6) || ((j==1 || j==7) && i>2 && i<6))
        table_5[i][j]=cell_type::peg;
      else if((i==4 && j==0) || (j==4 && i==0) || (i==8 && j==4) || (j==8 && i==4))
        table_5[i][j]=cell_type::peg;
      
      else
        table_5[i][j]=cell_type::wall;
  }
     
 }

 
 table_1[3][3]=cell_type::empty; // give empty space at the center of the boards
 table_2[4][4]=cell_type::empty;
 table_3[4][3]=cell_type::empty;
 table_4[3][3]=cell_type::empty;
 table_5[4][4]=cell_type::empty;
 //to fill the tables cells
 
 
 /*show_table(table_1,table_1.capacity());
 show_table(table_2,table_2.capacity());
 show_table(table_3,table_3.capacity());
 show_table(table_4,table_4.capacity());
 show_table(table_5,table_5.capacity());*/
 //ask the user gamer type

 while(user_flag){ //calls the functions due to desired board.

  cout<<"\nis this a human player game(1) or computer game(2)";
  cin>>user_type;
  user_flag=check_user(user_type);
 
 
 }
  if(type==1){
  
  operate_table(table_1,user_type,point);
  
 
 
  }
 else if(type==2){
  
  operate_table(table_2,user_type,point);


 }
 else if(type==3){
   operate_table(table_3,user_type,point);
  }
 else if(type==4){
    operate_table(table_4,user_type,point);
  }
  else if(type==5){
    operate_table(table_5,user_type,point);
  }

}

int main(){

 char board_type;
 bool board_flag=true;
 int board_number;
 int score=0;

 while(board_flag){ //until the user enter a valid board number ask the user the board type
  
  cout <<"enter the board type";
  cin >> board_type;
  //chose the board type
  switch(board_type){ //call board 1 and the send the boad type with the beggining score.
   

   case '1':
    
    board_flag=false; 
    board_number=1;
    score=36;
    board_1(board_number,score);
    break;
  
   case '2':
    
    board_flag=false;
    board_number=2;
    score=44;
    board_1(board_number,score);
    break;

   case '3':
    
    board_flag=false;
    board_number=3;
    score=35;
    board_1(board_number,score);
    break;

   case '4':
    board_flag=false; 
    board_number=4;
    score=32;
    board_1(board_number,score);
    
    break;

   case '5':
    board_flag=false;
    board_number=5;
    score=40;
    board_1(board_number,score);
    break;

   case '6':
    score=14;
    board_2(score);
    board_flag=false;
    
    break;

   default:

  cout<<"invalid choose try again";        
   
  }







 }

 cout<<"\n"<<"the score: "<<score; // at the end of the game print the score






    return 0;
}