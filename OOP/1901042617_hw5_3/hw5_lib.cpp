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
using namespace std;
#include "hw5.h"

namespace my_namespace{
void EightPuzzle::move(int direction ,int y_coor,int x_coor){
  int temp;

  if(direction==0){ //move the elements in board by switching them switching right side or left side etch determined by the direction .
  temp=cells[y_coor][x_coor].get_celltype();
  cells[y_coor][x_coor].set_celltype(cells[y_coor][x_coor+1].get_celltype());
  cells[y_coor][x_coor+1].set_celltype(temp);
 }
else if(direction==1){
  temp=cells[y_coor][x_coor].get_celltype();
  cells[y_coor][x_coor].set_celltype(cells[y_coor][x_coor-1].get_celltype());
  cells[y_coor][x_coor-1].set_celltype(temp);
}
else if(direction==2){
  temp=cells[y_coor][x_coor].get_celltype();
  cells[y_coor][x_coor].set_celltype(cells[y_coor-1][x_coor].get_celltype());
  cells[y_coor-1][x_coor].set_celltype(temp);
}
else if(direction==3){
  temp=cells[y_coor][x_coor].get_celltype();
  cells[y_coor][x_coor].set_celltype(cells[y_coor+1][x_coor].get_celltype());
  cells[y_coor+1][x_coor].set_celltype(temp);
}
print();
}

void PegSolitaire::move(int direction,int y_coor,int x_coor){ //move by changing the values of cells vectors the_cell variables 
 if(direction==0){
  cells[y_coor][x_coor].set_celltype(0);
  cells[y_coor][x_coor+1].set_celltype(0);
  cells[y_coor][x_coor+2].set_celltype(1);
 }
else if(direction==1){
  cells[y_coor][x_coor].set_celltype(0);
  cells[y_coor][x_coor-1].set_celltype(0);
  cells[y_coor][x_coor-2].set_celltype(1);
}
else if(direction==2){
  cells[y_coor][x_coor].set_celltype(0);
  cells[y_coor-1][x_coor].set_celltype(0);
  cells[y_coor-2][x_coor].set_celltype(1);
}
else if(direction==3){
  cells[y_coor][x_coor].set_celltype(0);
  cells[y_coor+1][x_coor].set_celltype(0);
  cells[y_coor+2][x_coor].set_celltype(1);
}
print();
}

bool EightPuzzle::include(vector<int> & set,int element){

vector<int>::iterator it;

it=find(set.begin(), set.end(), element);

if(it==set.end()){
    set.push_back(element);
    
    return true;
}

return false;
}

EightPuzzle::EightPuzzle():BoardGame2D(3,3){} //constructures

PegSolitaire::PegSolitaire():BoardGame2D(9,9){

} 
Klotski::Klotski():BoardGame2D(4,7){}

bool Klotski::endGame(){
    for(auto i=0;i<5;i++){

        for(auto j=0;j<4;j++){
            if(i>2 && i<5 && j>0 && j<3 && cells[i][j].get_celltype()!=0){ //game end if all the elements of big red square in specified point.
                return false;
            }
        }
    }
    return true;
}


bool Klotski::check_movement(int figure,int direction,int step_number){
    
    int op_indexx,op_indexy;
    int op_indexx2,op_indexy2;
    
    if(step_number>2){
        return false;
    }
    if(figure==5){
       
        if(direction==0){ //check if the movement possible .the statements change figure to figure for ex if the figure vertical rectangle and the movement up or down only check one pixel of the rectangle .checking rules rae as before desired movement location is empty or not.  
     
         if(step_number==1){ 
          
           for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==5){ //find location of choosed figure
                       if(j+step_number>3){ //then check desired movement possible or not
                           return false;
                       }
                       if(cells[i][j+step_number].get_celltype()==10){
                           return true;
                       }
                        else {return false;}   
                       
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==5){
                       if(j+step_number>3){
                           return false;
                       }
                       if(cells[i][j+step_number].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }
        }
     if(direction==1){
        
        if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==5){
                       if(j-step_number<0){
                           return false;
                       }
                       if(cells[i][j-step_number].get_celltype()==10){
                           return true;
                       }
                        else {return false;}   
                       
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==5){
                       if(j-step_number<0){
                           return false;
                       }
                       if(cells[i][j-step_number].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }

     }
     if(direction==2){

         if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==5){
                       if(i-step_number<0){
                           return false;
                       }
                       if(cells[i-step_number][j].get_celltype()!=10){
                           return false;
                          
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==5){
                       if(i-step_number<0){
                           return false;
                       }
                       if(cells[i-step_number][j].get_celltype()!=10 || cells[i-step_number+1][j].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }
     }
     if(direction==3){
        
        if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==5){
                       if(i+step_number>4){
                           return false;
                       }
                       if(cells[i+step_number][j].get_celltype()!=10){
                           return false;
                          
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==5){
                       if(i+step_number>4){
                           return false;
                       }
                       if(cells[i+step_number][j].get_celltype()!=10 || cells[i+step_number-1][j].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }


     }
    }
    else if(figure == 6 || figure== 7 || figure == 8 || figure ==9){
      
       if(direction==0){
     
         if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(j+step_number>3){
                           return false;
                       }
                       if(cells[i][j+step_number].get_celltype()!=10){
                          return false;  
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(j+step_number>3){
                           return false;
                       }
                       if(cells[i][j+step_number].get_celltype()!=10 || cells[i][j+step_number-1].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }
        }
     if(direction==1){
        
        if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==figure){
                       if(j+step_number>3){
                           return false;
                       }
                       if(cells[i][j-step_number].get_celltype()!=10 ){
                         return false;  
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(j-step_number>3){
                           return false;
                       }
                       if(cells[i][j-step_number].get_celltype()!=10 || cells[i][j-step_number+1].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }

     }
     if(direction==2){

         if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==figure){
                       if(i-step_number<0){
                           return false;
                       }
                       if(cells[i-step_number][j].get_celltype()!=10){
                           return false;
                          
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(i-step_number<0){
                           return false;
                       }
                       if(cells[i-step_number][j].get_celltype()!=10 || cells[i-step_number+1][j].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }
     }
     if(direction==3){
        
        if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==figure){
                       if(i+step_number>4){
                           return false;
                       }
                       if(cells[i+step_number][j].get_celltype()!=10){
                           return false;
                          
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(i+step_number>4){
                           return false;
                       }
                       if(cells[i+step_number][j].get_celltype()!=10 || cells[i+step_number-1][j].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }


     }
        
    }
    else if(figure==1 || figure ==2 ||figure ==3 || figure==4){
         if(direction==0){
     
         if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(j+step_number>3){
                           return false;
                       }
                       if(cells[i][j+step_number].get_celltype()!=10){
                           return false;
                          
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(j+step_number>3){
                           return false;
                       }
                       if(cells[i][j+step_number].get_celltype()!=10 || cells[i][j+step_number-1].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }
        }
     if(direction==1){
        
        if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==figure){
                       if(j-step_number<0){
                           return false;
                       }
                       if(cells[i][j-step_number].get_celltype()!=10){
                           return false;
                          
                       }
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(j-step_number<0){
                           return false;
                       }
                       if(cells[i][j-step_number].get_celltype()!=10 || cells[i][j-step_number+1].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }

     }
     if(direction==2){

         if(step_number==1){
          
           for(auto i=0;i<5;i++){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==figure ){
                       if(i-step_number<0){
                           return false;
                       }
                       if(cells[i-step_number][j].get_celltype()==10){
                           return true;
                       }
                        else {return false;}
                          
                       
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=3;j>=0;j--){
                   if(i-step_number<0){
                           return false;
                       }
                   if(cells[i][j].get_celltype()==figure){
                       if(cells[i-step_number][j].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }
     }
     if(direction==3){
        
        if(step_number==1){
          
           for(auto i=4;i>=0;i--){
               for(auto j=0;j<4;j++){
                   if(cells[i][j].get_celltype()==figure){
                       if(i+step_number>4){
                           return false;
                       }
                       if(cells[i+step_number][j].get_celltype()==10){
                           return true;
                       }
                        else {return false;}
                   }
               }
           }
        }
      else if(step_number==2){
          for(auto i=0;i<5;i++){
               for(auto j=4;j>=0;j--){
                   if(cells[i][j].get_celltype()==figure){
                       if(i+step_number>4){
                           return false;
                       }
                       if(cells[i+step_number][j].get_celltype()!=10){
                           return false;
                        
                       }
                   }
               }
           }

      }


     }
    }
    else if(figure==0){
      if(step_number>1){
          return false;
      }
      if(direction==0){
        for(auto i = 0;i<5;i++){ //for big square figure the rules some different .to explain first find the last pixel of the figure counting type depends on direction ex if its right loop start from 0 to 5 another ex for upper direction from 5 to 0
          for(auto j=0;j<4;j++){
            if(cells[i][j].get_celltype()==figure){
                op_indexx=j;
                op_indexy=i;
            }
          }
      }
      
      op_indexx2=op_indexx; //then find beside pixel .
      op_indexy2=op_indexy-1;
      if(op_indexx+1>3){
          return false;
      }
      if(cells[op_indexy][op_indexx+1].get_celltype() != 10 || cells[op_indexy2][op_indexx2+1].get_celltype()!=10){ //check if the desired locations empty for either pixels so empty or not.
          return false;
      }

      }
      if(direction==1){
          for(auto i = 4;i>=0;i--){
          for(auto j=3;j>=0;j--){
            if(cells[i][j].get_celltype()==figure){
                op_indexx=j;
                op_indexy=i;
            }
          }
      }
      
      op_indexx2=op_indexx;
      op_indexy2=op_indexy+1;
      if(op_indexx-1<0){
          return false;
      }
      if(cells[op_indexy][op_indexx-1].get_celltype() != 10 || cells[op_indexy2][op_indexx2-1].get_celltype()!=10){
          return false;
      }
      }
      if(direction==2){
        
        for(auto i = 4;i>=0;i--){
          for(auto j=3;j>=0;j--){
            if(cells[i][j].get_celltype()==figure){
                op_indexx=j;
                op_indexy=i;
            }
          }
      }
      
      op_indexx2=op_indexx+1;
      op_indexy2=op_indexy;
      if(op_indexy-1<0){
          return false;
      }
      if(cells[op_indexy-1][op_indexx].get_celltype() != 10 || cells[op_indexy2-1][op_indexx2].get_celltype()!=10){
          return false;
      }

      }
       
       if(direction==3){
         
         for(auto i = 0;i<5;i++){
          for(auto j=0;j<4;j++){
            if(cells[i][j].get_celltype()==figure){
                op_indexx=j;
                op_indexy=i;
            }
          }
      }
      
      op_indexx2=op_indexx-1;
      op_indexy2=op_indexy;
      if(op_indexy>4){
          return false;
      }
      if(cells[op_indexy+1][op_indexx].get_celltype() != 10 || cells[op_indexy2+1][op_indexx2].get_celltype()!=10){
          return false;
      }

       }
    }
    else {return false;}

    
 
 return true;
}

void Klotski::move(int figure,int direction,int s_number){

int temp;
    if(direction==0){ //firs find prior pixel regarding the direction type then switch it with element of desired location 
       for(auto i=0;i<5;i++){ //if we dont find prior pixel ,the program shift wrong pixel first then it could be shift with its own element

        for(auto j=4;j>=0;j--){
            if(cells[i][j].get_celltype()==figure){
               temp=cells[i][j+s_number].get_celltype();
               cells[i][j+s_number].set_celltype(cells[i][j].get_celltype());
               cells[i][j].set_celltype(temp);
            }
        }
    }
    }
    if(direction==1){
       
       for(auto i=0;i<5;i++){

        for(auto j=0;j<4;j++){
            if(cells[i][j].get_celltype()==figure){
               temp=cells[i][j-s_number].get_celltype();
               cells[i][j-s_number].set_celltype(cells[i][j].get_celltype());
               cells[i][j].set_celltype(temp);
            }
        }
    }
    }
    if(direction==2){
       
       for(auto i=0;i<5;i++){

        for(auto j=0;j<4;j++){
            if(cells[i][j].get_celltype()==figure){
               temp=cells[i-s_number][j].get_celltype();
               cells[i-s_number][j].set_celltype(cells[i][j].get_celltype());
               cells[i][j].set_celltype(temp);
            }
        }
    }
    }
     if(direction==3){
       
       for(auto i=5;i>=0;i--){

        for(auto j=0;j<4;j++){
            if(cells[i][j].get_celltype()==figure){
               temp=cells[i+s_number][j].get_celltype();
               cells[i+s_number][j].set_celltype(cells[i][j].get_celltype());
               cells[i][j].set_celltype(temp);
            }
        }
    }

    }
    print();
}
    
void Klotski::initialize() { //all the numbers from 0 to 12 represent different figures ex 0 represent big square,1 represent vertical rectangle initialize them in desired location of the vector.

cells.resize(y);

for(auto i=0;i<y;i++){
    cells[i].resize(x);
}
   
   for(auto i=0;i<y;i++){

       for(auto j=0;j<x;j++){
           if(j==0 && i>=0 && i<2){
               cells[i][j].set_celltype(1);
           }
           if(j==0 && i>=2 && i<4){
               cells[i][j].set_celltype(3);
           }
           if(j==0 && i==4){
               cells[i][j].set_celltype(8);
           }
           if(j==3 && i>=0 && i<2){
               cells[i][j].set_celltype(2);
           }
           if(j==3 && i>=2 && i<4){
               cells[i][j].set_celltype(4);
           }
           if(j==3 && i==4){
               cells[i][j].set_celltype(9);
           }
           if(j>0 && j<3 && i>=0 && i<2){
               cells[i][j].set_celltype(0);
           }
           if(j>0 && j<3 && i==2 ){
               cells[i][j].set_celltype(5);
           }
           if(j==1 && i==3){
               cells[i][j].set_celltype(6);
           }
           if(j==2 && i==3)cells[i][j].set_celltype(7);
           
           if(i==4 && j>0 && j<3) cells[i][j].set_celltype(10);
           
           if((j==0 || j==3) && i>4) cells[i][j].set_celltype(11);

           if(j<3 && j>0 & i>4) cells[i][j].set_celltype(12);
       }
   }


}
   void Klotski::print(){
     this_thread::sleep_for (std::chrono::seconds(1));
     cout<<"\033c"; //resets terminal
     for(auto i=0;i<y;i++){
         cout<<endl;
         for(auto j=0;j<x;j++){ //som color codes for printing different figures with different colors.

             if(cells[i][j].get_celltype()==1)cout<<" \033[44;1;5m$\033[0m ";
             if(cells[i][j].get_celltype()==0)cout<<" \033[31;1;4m$\033[0m ";
             else if(cells[i][j].get_celltype()==2)cout<<" \033[41;1;5m$\033[0m ";
             else if(cells[i][j].get_celltype()==3) cout<<" \033[42;1;5m$\033[0m ";
             else if(cells[i][j].get_celltype()==4) cout<<" \033[43;1;5m$\033[0m ";
             else if(cells[i][j].get_celltype()==5) cout<<" \033[45;1;5m$\033[0m ";
             else if(cells[i][j].get_celltype()==6) cout<<" \033[34;1;4m$\033[0m ";
             else if(cells[i][j].get_celltype()==7) cout<<" \033[35;1;4m$\033[0m ";
             else if(cells[i][j].get_celltype()==8) cout<<" \033[33;1;4m$\033[0m ";
             else if(cells[i][j].get_celltype()==9) cout<<" \033[32;1;4m$\033[0m ";
             else if(cells[i][j].get_celltype()==10) cout<<" . ";
         }
     }
   }
   void Klotski::playAuto(){
        int direction,element,step_rand;
    bool possible_movement=false;
    int temp;
    while(!possible_movement){ //assign random figure step number and direction of desired location then send it check_movement function if the movement possible if not does the operation again. 

  direction=rand()%4;
  element=rand()%10 ;
  step_rand=rand()%2 +1;
  
  possible_movement=check_movement(element,direction,step_rand);
  
 }
 cout<<element<<" "<<direction<<" "<<step_rand<<endl;
 move(element,direction,step_rand); //if the program out of the loop movement code possible sends it to move function.
   }
   void Klotski::playUser(string move_command){
    
    string board_element;
    string direction;
    int element,dir,step;
    bool movement_possibility;
    
    if(move_command[2]!='-'){ //first check if the command devided by - char location and figure type.if its not write an error message then return 
        return ;
    }
    
    int dividing_index=move_command.find("-"); //divides the command sring to sub strings .
    direction=move_command.substr(dividing_index+1);
    board_element=move_command.substr(0,dividing_index);
    transform(direction.begin(), direction.end(), direction.begin(), ::tolower); //converts them lowercase to ignor upper or lower case errors.
    transform(board_element.begin(), board_element.end(), board_element.begin(), ::tolower);
    
    step=(int)direction[1] -48;
    if(direction[0]=='r') dir=0;
    else if(direction[0]=='l') dir=1; //check sub strings if its suit for rules of the program if they suits converts substrings to valid int values for check movement funct.
    else if(direction[0]=='u') dir=2;
    else if(direction[0]=='d') dir=3;
    else{
        cerr<<endl<<"ERROR! invalid direction try again \n\n";
        return;
    }
    
    if(board_element=="br") element=1;
    else if(board_element=="rr") element=2;
    else if(board_element=="gr") element=3;
    else if(board_element=="yr") element=4;
    else if(board_element=="pr") element=5;
    else if(board_element=="bs") element=6;
    else if(board_element=="ps") element=7;
    else if(board_element=="ys") element=8;
    else if(board_element=="gs") element=9;
    else if(board_element=="rb") element=0;
    else {cout<<endl<<"ERROR ! invalid elemet\n";}
    cout<<endl<<dir<<step<<element;
    movement_possibility=check_movement(element,dir,step); //check the movement possible or not.
    if(!movement_possibility){
      cout<<endl<<"ERROR! the movement is not possible try again \n\n";
    }
    else{move(element,dir,step);}
   }
   void BoardGame2D::playUser(){
     
     string board_element;
    string direction;
    int element,dir,step;
    bool end_of_thegame=false;
    string move_command;

    while(!end_of_thegame){ //takes movement commnd from user then calls playUser function again and again until the game finished.

    cout<<"if the game is eight puzzle enter the code  ex 2B-Up, 3C-Down"<<endl<<"if the game is pegsoltiare enter the code ex 2B-Up, 3C-Down etch"<<endl<<"if the game is klotski please enter the movement code ex ys-r1 yellow square right for one step \n"<<endl<<"colors:green(g) yellow(y) red(r) blue(b) purple(p) "<<endl<<"direction right(r) left(l) up(u) down(d) "<<endl<<"step: 1 or 2"<<endl<<"shape: square(s) rectangle(r) big square(b)"<<endl;
    cin>>move_command;
    
    
    playUser(move_command);
    end_of_thegame=endGame();
    
    }
   }
   



void EightPuzzle::playUser(string movement_code){
  string location;
    string direction;
    vector<string> dir_list={"right","left","up","down"}; //direction list.
    int x_coordinate,y_coordinate,dir;

    bool movement_possibility;
    if(movement_code[2]!='-'){
        cerr<<" ERROR! - char is missing please enter again\n"<<endl;
        return;
    }
    int dividing_index=movement_code.find("-"); //same as klotski.
    
    direction=movement_code.substr(dividing_index+1);
    location=movement_code.substr(0,dividing_index);
   
    transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
    transform(location.begin(), location.end(), location.begin(), ::tolower);
     if(direction!="down" && direction!="up" && direction!="right" && direction!="left"){
         cout<<" ERROR! invalid direction please enter command again"<<endl;
         return;
     }
    
     for(auto i=0;i<dir_list.size();i++){
         if(direction==dir_list[i]){ //searchs from list and assign index number of the list that correspond direction code ex for right index 0, 0 correspond right
             dir=i;
         }
     }
     
     y_coordinate=(int)location[0] -48; //converts char int 
     x_coordinate=(int)location[1]-97;
     
     
   movement_possibility= check_movement(dir,y_coordinate,x_coordinate);
     if(movement_possibility==true){
       move(dir,y_coordinate,x_coordinate);
     }
     else{
         cerr<<endl<<"ERROR invaldi movement please enter again \n"<<endl;
     }

}




void PegSolitaire::playUser(string movement_code){

    string location;
    string direction;
    vector<string> dir_list={"right","left","up","down"};
    int x_coordinate,y_coordinate,dir;

    bool movement_possibility;
    
    if(movement_code[2]!='-'){
        cerr<<" ERROR! - char is missing please enter again\n"<<endl;
        return;
    }
    int dividing_index=movement_code.find("-");
    direction=movement_code.substr(dividing_index+1);
    location=movement_code.substr(0,dividing_index);
   
    transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
    transform(location.begin(), location.end(), location.begin(), ::tolower);
     if(direction!="down" && direction!="up" && direction!="right" && direction!="left"){ //same as eight puzzle.
         cout<<" ERROR! invalid direction please enter command again"<<endl;
         return;
     }
    
     for(auto i=0;i<dir_list.size();i++){
         if(direction==dir_list[i]){
             dir=i;
         }
     }
     
     y_coordinate=(int)location[0] -48;
     x_coordinate=(int)location[1]-97;
     
     
   movement_possibility= check_movement(dir,y_coordinate,x_coordinate);
     if(movement_possibility==true){
       move(dir,y_coordinate,x_coordinate);
       point--;
     }
     else{
         cerr<<endl<<"ERROR! invalid movement"<<endl;
     }
}


bool PegSolitaire::check_movement(int d,int yy,int xx){ //0r 1l 2u 3d.

if(d==0){ //if direction right all the conditions to move 
    if(xx+2>=x){ //checks the desired locations valid or not
        return false;
    }
   if( cells[yy][xx+2].get_celltype()==0 && cells[yy][xx+1].get_celltype()==1 && cells[yy][xx].get_celltype()==1) //then desired locations empty or not 
    return true;
   else
    return false; //return true if the movements possible.
 }
 if(d==1){
    if(xx-2<0){
        return false;
    }
   if( cells[yy][xx-2].get_celltype()==0 && cells[yy][xx-1].get_celltype()==1 && cells[yy][xx].get_celltype()==1)
    return true;
   else
    return false;
 }
 if(d==2){
   if(yy-2<0){
        return false;
    }
   if( cells[yy-2][xx].get_celltype()==0 && cells[yy-1][xx].get_celltype()==1 && cells[yy][xx].get_celltype()==1)
    return true;
   else
    return false;
 }
 if(d==3){
    if(yy+2>=y){
        return false;
    }
   if( cells[yy+2][xx].get_celltype()==0 && cells[yy+1][xx].get_celltype()==1 && cells[yy][xx].get_celltype()==1)
    return true;
   else
    return false;
 }

 return false;
}

bool EightPuzzle::check_movement(int d,int yy,int xx){ //same as pegsolitaire.

 if(d==0){
     if((xx+1)>=x){
         return false;
     }
  if((xx+1)<x && cells[yy][xx+1].get_celltype()==0  && cells[yy][xx].get_celltype()!=0)
    return true;
   else
    return false;
 }
 if(d==1){
      if((xx-1)<0){
         return false;
     }
 if((xx-1)>=0 && cells[yy][xx-1].get_celltype()==0  && cells[yy][xx].get_celltype()!=0)
    return true;
   else
    return false;

 }
 if(d==2){
  if((yy-1)<0){
         return false;
     }
  if((yy-1)>=0 && cells[yy-1][xx].get_celltype()==0  && cells[yy][xx].get_celltype()!=0)
    return true;
   else
    return false;
 }
 if(d==3){
  if((yy+1)>=y){
         return false;
     }
  if((yy+1)<y && cells[yy+1][xx].get_celltype()==0  && cells[yy][xx].get_celltype()!=0)
    return true;
   else
    return false;

 }
 return false;
}

void EightPuzzle::playAuto(){
    int direction,x_coor,y_coor;
    bool possible_movement=false;
    int temp;
    while(!possible_movement){

  direction=rand()%4;
  x_coor=rand()%x;
  y_coor=rand()%y;
  possible_movement=check_movement(direction,y_coor,x_coor);
 }
 
 move(direction,y_coor,x_coor);
 
 
}

void PegSolitaire::playAuto(){

 int direction,x_coor,y_coor;
 bool possible_movement=false;
 
 while(possible_movement==false){

 direction=rand()%4;
 x_coor=rand()%x;
 y_coor=rand()%y;
 
 possible_movement=check_movement(direction,y_coor,x_coor);
 }
 cout<<x_coor<<y_coor<<direction<<endl;
 move(direction,y_coor,x_coor);
 point--;
}
bool PegSolitaire::endGame(){ //three dimentional nested loop to check all the movement codes to find if there any possible movement fi there is no counter has not incremented thats mean 0 in that case returns 0.
 int counter=0;
 bool possible_movement=false;
    for(auto i=0;i<y;i++){

        for(auto j=0;j<x;j++){

            for(auto l=0;l<4;l++){

                possible_movement=check_movement(l,i,j);
                if(possible_movement==true){
                    counter++;

                }
                
            }
        }
    }

    if(counter==0){
        return true;
    }

 return false;
}
void BoardGame2D::PlayAutoAll(){

    bool end_game=false;
    int counter=0;
    while(!(end_game) && counter<100){ //trys 100 movement if the game still ends print couldnt soled message.
        playAuto();
        end_game=endGame();
        counter++;
        cout<<100-counter<<" move left"<<endl;
    }
  if(counter>99){

      cout<<"couldnt solved \n"<<endl;
  }
}
int Klotski::BoardScore(){ //if its end of the game return 0.

   bool end_of_thegame;
end_of_thegame=endGame();
if(end_of_thegame==true){
    return 0;
}
    return 6;
}
int PegSolitaire::BoardScore(){//othervise return point number that decrease when any movement took

bool end_of_thegame;
end_of_thegame=endGame();
if(end_of_thegame==true){
    return 0;
}
 return point;
}

int EightPuzzle::BoardScore(){ //eight puzzle points regarding closest board of finished board the point will be 0 when the game finished .

bool end_of_thegame;
end_of_thegame=endGame();
if(end_of_thegame==true){
    return 0;
}
point=8;
    for(auto i=0;i<y;i++){
        for(auto j=0;j<x;j++){

            if(cells[i][j].get_celltype()== i*3 +j +1){
                point--;
            }
        }
    }
 return point;
}
bool EightPuzzle::endGame(){

    int counter=0;
 bool possible_movement=false;
 vector<int>elements;

 for(auto i=0;i<y;i++){
     for(auto j=0;j<x;j++){
         elements.push_back(cells[i][j].get_celltype());
     }
 }

  for(auto i=0;i<elements.size()-1;i++){ //until the last element all the elements bigger previous index thats mean the game has finished.
   if(elements[i]<elements[i+1]){
       counter++;
   }
  }  

    if(counter==7 && cells[y-1][x-1].get_celltype()==0){
        return true;
    }

 return false;
}

/*ostream operator<<(ostream & out ,BoardGame2D & prnt){

    for(auto i=0;i<this->y;i++){
        out<<endl;
        for(auto j=0;this->x;j++){
            
            if(this->cells[i][j].get_celltype()==peg){
             out<<"P";
            }
            else if(this->cells[i][j].get_celltype()==wall){
                out<<".";
            }
            else{
                out<<" ";
            }
        }
    }
 return out;
}*/
void EightPuzzle::print(){
   
   this_thread::sleep_for (std::chrono::seconds(1));
   cout<<"\033c";
   cout<<endl<<" ";
   for(auto i=0 ;i<x;i++){
     cout<<" "<<(char)(i +97)<<"  ";
 }
 cout<<endl;
    for(auto i=0;i<y;i++){
      for(auto l=0;l<x;l++){
          cout<<" ___ ";
      } 
        cout<<endl;
        cout<<i<<""<<"|";
        for(auto j=0;j<x;j++){
            
            if(cells[i][j].get_celltype()==0){
             cout<<"   ";
            }
            
            else{
                cout<<" "<<cells[i][j].get_celltype()<<" ";
            }
           cout<<"|";
        }
      cout<<endl;
     
    
    }
    for(auto l=0;l<x;l++){
          cout<<" ___ ";
      }
 
  cout<<endl;
}

void PegSolitaire::print(){
this_thread::sleep_for (std::chrono::seconds(1));
cout<<"\033c";
cout<<" ";
 for(auto i=0 ;i<x;i++){
     cout<<" "<<(char)(i +97)<<" ";
 }
 cout<<endl;
    for(auto i=0;i<y;i++){
        cout<<endl;
        cout<<i;
        for(auto j=0;j<x;j++){
            
            if(cells[i][j].get_celltype()==1){
             cout<<" P ";
            }
            else if(cells[i][j].get_celltype()==2){
                cout<<" . ";
            }
            else{
                cout<<" _ ";
            }
        }
    }

 cout<<endl;
}

void PegSolitaire::initialize(){

cells.resize(y);
point=44;
for(auto i=0;i<y;i++){

    cells[i].resize(x);
}

for(auto i=0;i<y;i++){


    for(auto j=0;j<x;j++){

        if((i>2 && i<6) || (j>2 && j<6)){
            cells[i][j].set_celltype(1);
        }
        else{
            cells[i][j].set_celltype(2);
        }
    }
    
    cells[4][4].set_celltype(0);

}

}
void EightPuzzle::initialize(){
 
 bool exist=false;
 srand(time(NULL));
 vector<int> element_list;
 int the_element;
 cells.resize(y);
 vector<int>::iterator it;
 for(auto i=0;i<y;i++){

    cells[i].resize(x);
}

for(auto i=0;i<y;i++){ //initialize the board randomly.

    for(auto j=0;j<x;j++){
      
      while(exist==false){
         the_element=rand()%9 ;
         exist=include(element_list,the_element); //if the number include the game dont chose that again
         
      }
      
    

      
      exist=false;
      
      element_list.push_back(the_element);
      cells[i][j].set_celltype(the_element);  
        
         } 
          
      }
     point=8;
    for(auto i=0;i<y;i++){
        for(auto j=0;j<x;j++){

            if(cells[i][j].get_celltype()== i*3 +j +1){
                point--;
            }
        }
    }
    
    
    }



void playVector(vector<BoardGame2D *> & all_thegame){ //takes vector of boardgames objects as parametre 
 
 for(int i=0;i<6;i++){
     all_thegame[i]->PlayAutoAll(); //plays play auto games one by one.and print their scores.
     all_thegame[i]->BoardScore();
 }

}


void BoardGame2D::cell::set_celltype(int space){
     the_cell=space;
} 
int  BoardGame2D::cell::get_celltype()const{
     return the_cell;
} 

BoardGame2D::BoardGame2D(int x_axes,int y_axes){
    x=x_axes;
    y=y_axes;
}
}