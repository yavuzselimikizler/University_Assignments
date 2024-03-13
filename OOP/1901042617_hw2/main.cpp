#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>


using namespace std;

enum row_locations{ //decleration of x axis of board as enum type.
a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p


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

    case 9:
     return j;
     break; 

    case 10:
     return k;
     break; 

    case 11:
     return l;
     break; 
    
    case 12:
     return m;
     break; 
    
    case 13:
     return n;
     break; 
    
    case 14:
     return o;
     break; 

    case 15:
     return p;
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
    
    case 'j':
     return j;
     break; 

    case 'k':
     return k;
     break; 

    case 'l':
     return l;
     break; 
    
    case 'm':
     return m;
     break; 
    
    case 'n':
     return n;
     break; 
    
    case 'o':
     return o;
     break; 

    case 'p':
     return p;
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

   if((xx2-4)>=0 && table_test2[yy2][xx2-4]==cell_type::empty && table_test2[yy2][xx2-2]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
    return false;
   else
    return true;
 }
 if(turn_type2==2){

   if((yy2+2)<height2 &&(xx2-2)>=0 && table_test2[yy2+2][xx2-2]==cell_type::empty && table_test2[yy2+1][xx2-1]==cell_type::peg && table_test2[yy2][xx2]==cell_type::peg)
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


bool check_movement_possibility(const row_locations &xx,int yy,const movement_type &turn_type,vector<vector<cell_type>> & table_test,int board_height,int board_weight){ //to check if the movements commend recieved from pc or user are valid or not 

 if(turn_type==0){ //if direction right all the conditions to move 

   if((xx+2)<board_weight && table_test[yy][xx+2]==cell_type::empty && table_test[yy][xx+1]==cell_type::peg && table_test[yy][xx]==cell_type::peg)
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

   if((yy+2)<board_height && table_test[yy+2][xx]==cell_type::empty && table_test[yy+1][xx]==cell_type::peg && table_test[yy][xx]==cell_type::peg)
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

 if(comm=="LOAD"){
   return false;
 }
  else if(comm=="SAVE")
   return false;
  else{

  
  if(comm.length()>4){ //compare the string lenght 

   cerr<<"invalid lenght command";
   return true;
 }
  else if(comm[2]!='-'){//if the - exist
    cerr<<"- char must be used";
    return true;
  }
   else if(!(comm[0]>96 && comm[0]<106)){ //x axes code is valid or not.
     cerr<<"invalid row code";
     return true;
   }
  else if(!(comm[1]>48 && comm[1]<58)){ //collumn code is valid or not
    cerr<<"invalid collumn code";
  }
  else if(!(comm[3]==76 || comm[3]==82 || comm[3]==85 || comm[3]==68 )){
    cerr<<"invalid movement code";
    return true;
  }
  else 
   return false;
  }
 return false;
}

void show_table2(vector<vector<cell_type>> const &tab_6,const int table_height,int table_weight){ //to visualise the current table

 string row_2="abcdefghijklmnop";
 string collumn_2="123456789abcde";

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
bool check_list(const  string mains,const string subs){

if (mains.find(subs) != string::npos) {
    return false;
}
 cerr<<"there is no load named"<<subs<<endl;
 return true;
}
void show_table(vector<vector<cell_type>> const &tab_1,const int table_size,int weight4){

 string row="abcdefghijklmnop";
 string collumn="123456789abcde";

    for(int i=0;i<table_size;i++){
        
       
     if(i==0){
         cout<<" ";
         for(int k=0;k<weight4;k++){
             cout<<" "<<row[k];
         }
     }
     
     cout<<"\n"; 
     cout<<collumn[i];  
        for(int j=0;j<weight4;j++){


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
    
     cerr<<"invalid user type\n";
     return true;

}


}

void move2(const row_locations &x2,int y2,const movement_type &turn2,vector<vector<cell_type>> &table2){


int rand_move;
rand_move=rand()%2;
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
     if(table2[y2+2][x2-2]==cell_type::empty ){
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
     
     if(table2[y2-2][x2-2]==cell_type::empty ){
        
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
 
 decltype(y) j= y+2;
 decltype(y) k=y+1;
 decltype(y) l=y-2;
 decltype(y) z=y-1;
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
     table[k][x]=cell_type::empty;
     table[j][x]=cell_type::peg;
     break;
    case U:
     table[y][x]=cell_type::empty;
     table[z][x]=cell_type::empty;
     table[l][x]=cell_type::peg;
     break;



   }
}
void new_size(string fil_name,int &x_coor,int &y_coor){

string lines;
x_coor=0;
y_coor=0;
ifstream the_file;

the_file.open(fil_name);

getline(the_file,lines);

while(getline(the_file,lines)){
  
  x_coor=lines.length();
  y_coor++;
}
y_coor=y_coor-1;
the_file.close();

}
void save_the_game(const vector<vector<cell_type>> & my_board,int height,int weight,const int the_user,const int move_number,const string f_n){

 ofstream game_file;

 game_file.open(f_n);
 game_file<<the_user<<" "<<move_number<<" "<<endl;
 
  for(int i = 0;i<height;i++){
    for(int j=0;j<weight;j++){
      if(my_board[i][j]==cell_type::wall)
       game_file<<'.';
      else if(my_board[i][j]==cell_type::peg)
       game_file<<'P';
      else if(my_board[i][j]==cell_type::empty)
       game_file<<'_';
    }
       game_file<<endl;
  }

 game_file.close();
 

}
void load_the_game(vector<vector<cell_type>> & board_to_load,int & height,int & weight,char & user_type,int & curr_point,const string f_name){
   
   ifstream FILE;
   string line;
   char end_line;
   int number_of_moves,user_ty,counter=0,row_counter=0,counter2=0,counter3=0;
   FILE.open(f_name);
   
   FILE>>user_ty;
   FILE>>curr_point;
   FILE.close();
   FILE.open(f_name);
   getline(FILE,line);
   cout<<line<<endl;
   while(getline(FILE,line)){ // read line by line to understand row and collumn size
     
     if( line.length() >row_counter){
       row_counter=line.length();
     }
     
     counter++;
   }
   cout<<counter<<" "<<row_counter<<endl;
   cout<<user_ty<<curr_point<<" "<<counter<<line.length()<<endl;
   user_type=char(user_ty+48);
   FILE.close();
   
   
     board_to_load.resize(counter);
   
   for(int i=0;i<counter;i++){
       board_to_load[i].resize(row_counter);

   }
   
   
   height=counter;
   weight=row_counter-1;


   FILE.open(f_name);
   getline(FILE,line); //to ignore the first line (table info part point vs)
    for(int i=0;i<counter;i++){
      
      getline(FILE,line);
      
      
      for(counter2=0;counter2<row_counter;counter2++){ //read line by line the file  and assign the vector.
        
        if(line[counter2]=='P'){
          board_to_load[i][counter2]=cell_type::peg;
        }
        else if(line[counter2]=='_'){
           board_to_load[i][counter2]=cell_type::empty;
        }
        else if(line[counter2]=='.'){
          board_to_load[i][counter2]=cell_type::wall;
        }
      }
       
      }
     
   

   FILE.close();

}
bool finish_the_game2(vector<vector<cell_type>> & curr_table2,int height4,int weight4){
    bool move_posib;
     row_locations verti;
     movement_type direc;  
     int check_finish2=0;  
       for(int i=0;i<height4;i++){ // check all the moves via 3 nested loop if there any possible movement if there is no left then the game finished exit from loop

       for(int j=0;j<weight4;j++){

       for(int k=0;k<4;k++){

        verti=convert_enum3(j);
        direc=convert_enum4(k);
        move_posib=check_movement_possibility2(verti,i,direc,curr_table2,height4,weight4);
        if(move_posib==false)
           check_finish2+=1;
      }
    }
  }
  
  if(check_finish2==0){
     return false;
  }
 return true;
}

void board_2(int &p2){ //there is no load svae part for table6 since the algorithm dşfference calling board1 or calling from board 1 caused some troubles then ı couldnt add it .
 vector<vector<cell_type>> table_6={{cell_type::wall,cell_type::wall,cell_type::wall,cell_type::wall,cell_type::empty,cell_type::wall,cell_type::wall,cell_type::wall,cell_type::wall},
                                    {cell_type::wall,cell_type::wall,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::wall,cell_type::wall},
                                     {cell_type::wall,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::wall},
                                     {cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall},
                                     {cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg,cell_type::wall,cell_type::peg}};
 bool user_type_flag=true,end_of_the_game=true,check_commend2=true,check_movement2=true;
 char user_type2;
 int command2,check_the_end=0,rand_x2,rand_y2,rand_d2,check_finish2=0,y_ax=table_6.capacity(),x_ax=table_6[0].capacity();
 string move_com;
 row_locations vert;
 movement_type dire,dire2;
 
 while(user_type_flag){

  cout<<"\nis this a human player game(1) or computer game(2)";
  cin>>user_type2;
  user_type_flag=check_user(user_type2);
  

 }
 while(end_of_the_game){
  
   show_table2(table_6,table_6.capacity(),table_6[0].capacity());
  
   
   if(user_type2=='1'){

    cout<<"enter the coordinates and movement type g4-U , e1-D"<<endl;
    
    do{
      cin>>move_com;
      check_commend2=check_commend_validity(move_com);
      
    
    }
    while(check_commend2);
    check_commend2=true;
    
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

 
 
 end_of_the_game=finish_the_game2(table_6,y_ax,x_ax);

}
}
 bool finish_the_game(vector<vector<cell_type>> & curr_table,int height3,int weight3){
   
   bool move_pos;
   int check_finish=0;
   row_locations ver;
   movement_type dir;

   for(int i=0;i<height3;i++){ // check all the moves via 3 nested loop if there any possible movement if there is no left then the game finished exit from loop

    for(int j=0;j<weight3;j++){

      for(int k=0;k<4;k++){

        ver=convert_enum3(j);
        dir=convert_enum4(k);
        move_pos=check_movement_possibility(ver,i,dir,curr_table,height3,weight3);
        if(move_pos==false)
           check_finish+=1;
      }
    }
  }
 if(check_finish==0){
   return false;
 }
 return true;
 }


 void operate_table(vector<vector<cell_type>> & the_table,char user_tp,int &p){
  
  string movement,load_save,file_name,loaded_list;
  bool end_game=true,check_commend=true,check_movement=true,save_menu=true,check_file_name=true; //bool variables those to check user input validity or the game finished or not.
  int command,check_finish=0,rand_x,rand_y,rand_d; //rand variables assigned by rand functions for playing with computer.
  row_locations ver; // x axes code to send the functions.
  movement_type dir; // direction code.
  ofstream game_file;
  ifstream game_file2;
  int max_point=p,x_axes=the_table[0].capacity(),y_axes=the_table.capacity(),number_of_move;
  
  game_file2.open("loaded_games.txt"); // to read saved folders and assign to a string 
  getline(game_file2,loaded_list);
  game_file2.close();

  while(end_game){ //while end game bool variable true the game contine.

  

  
   cout<<"ready to move"<<endl;
   if(user_tp=='1'){ // if user type human.

    cout<<"enter the coordinates and movement type ex a4-L , c5-U , to load the game (LOAD) or to save (SAVE)"<<endl;
    show_table(the_table,y_axes,x_axes); //read the movement code from user.
    do{
      cin>>movement;
      

      check_commend=check_commend_validity(movement); //check the codes validity if not give an errors message.
      
    
    }
    while(check_commend);
    check_commend=true;
    if(movement=="LOAD"){
      game_file2.open("loaded_games.txt");
           getline(game_file2,loaded_list);
           cout<<loaded_list<<endl;  //show saved file list 
           game_file2.close();
           
           while(check_file_name){

             cout<<"please enter the file name board1.txt"<<endl;
             cin>>file_name;
             check_file_name=check_list(loaded_list,file_name); // to check if the filename exist.
           }
           check_file_name=true;
         

           new_size(file_name,x_axes,y_axes);
           /*the_table.resize(y_axes);
           for(int i=0;i<y_axes;i++){
             the_table[i].resize(x_axes);
           }*/

           load_the_game(the_table,y_axes,x_axes,user_tp,p,file_name);
           
    }
    else if(movement=="SAVE"){
         cout<<"please enter saved file name ex: board1.txt"<<endl; //recieve the name from user
            cin>>file_name;
            game_file.open("loaded_games.txt",ios::app); //add the new file name to saved list 
            game_file<<file_name<<" ";
            game_file.close();
        save_the_game(the_table,y_axes,x_axes,(int)user_tp-48,p,file_name);
        cout<<"SAVED";
    }
    else{

    
    ver=convert_enum(movement[0]); //take specified part from string then convert them to enum type and assign it to ver veriable
    dir=convert_enum2(movement[3]);
    check_movement=check_movement_possibility(ver,((int)movement[1]-1)-48,dir,the_table,y_axes,x_axes); //to check if the movement valid if not ask again to enter.
    
    if(check_movement==false){
      move(ver,((int)movement[1]-1)-48,dir,the_table);
      p--;
      show_table(the_table,y_axes,x_axes);
   }
    else{
      cerr<<"invalid movement";
    }
    }
   } 
    else if(user_tp=='2'){ // if the user is computer
      
      while(save_menu){
        
         show_table(the_table,y_axes,x_axes);
         cout<<"enter for moving (MOVE) or (1),for saving (SAVE) ,for load menu(LOAD)"<<endl;
         cin>>load_save;
        
        if(load_save=="MOVE" || load_save=="1"){
            while(check_movement){
       

             rand_x=rand()%(x_axes); //take codes randomliy and check until its valid move type.
             rand_y=rand()%(y_axes);
             rand_d=rand()%4;
       
             ver=convert_enum3(rand_x);
             dir=convert_enum4(rand_d);
             check_movement=check_movement_possibility(ver,rand_y,dir,the_table,y_axes,x_axes);
           }
            check_movement=true;
           
            move(ver,rand_y,dir,the_table);
            cout<<"\n"<<ver<<rand_y+1<<"-"<<dir<<endl;
            show_table(the_table,y_axes,x_axes);
            p--; //decrease the peg numbers 
           
            save_menu=false;
          
          }
         else if(load_save=="SAVE"){
            cout<<"please enter saved file name ex: board1.txt"<<endl;
            cin>>file_name;
            game_file.open("loaded_games.txt",ios::app);
            game_file<<file_name<<" ";
            game_file.close();
            save_the_game(the_table,y_axes,x_axes,(int)user_tp-48,p,file_name);
            save_menu=false;
         }
         else if(load_save=="LOAD"){
           game_file2.open("loaded_games.txt");
           getline(game_file2,loaded_list);
           cout<<loaded_list<<endl;
           game_file2.close();
           
           while(check_file_name){

             cout<<"please enter the file name board1.txt"<<endl;
             cin>>file_name;
             check_file_name=check_list(loaded_list,file_name);
           }
           check_file_name=true;
           new_size(file_name,x_axes,y_axes);
           the_table.resize(y_axes);
           for(int i=0;i<y_axes;i++){
             the_table[i].resize(x_axes);
           }

           load_the_game(the_table,y_axes,x_axes,user_tp,p,file_name);
           
         }
         else{
           cerr<<"invalid command";
         }
      }
      
      save_menu=true;
      

      
    }
    

  
   end_game=finish_the_game(the_table,y_axes,x_axes);
   

  
  
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