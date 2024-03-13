import java.io.*;
import java.util.*;
import java.lang.*;
import java.lang.System;
import java.io.IOException;
import java.io.File;
import java.awt.Color;
import java.awt.FlowLayout;  
import javax.swing.JButton;  
import javax.swing.JFrame;  
import javax.swing.JLabel;  
import javax.swing.JPanel;  
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.File;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import java.util.Random;

 public class PegSolitaire extends JFrame implements ActionListener,Cloneable {
    JPanel windowContent;
    JRadioButton board1;
    JRadioButton board2;
    JRadioButton board3;  
    JRadioButton board4;
    JRadioButton board5; //defination of all game items
    JLabel warning;
    
    JButton [][]buttons;
    JButton reset,save,load,undo,auto;
    JPanel pl,p1,p2,p3;
    
     PegSolitaire(){
     this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     this.setLayout(new GridLayout(2,2));
     this.getContentPane().setBackground(Color.BLACK);
     this.getContentPane().setForeground(Color.RED);
     
     board1=new JRadioButton("board1");
     board2= new JRadioButton("board2");
     board3= new JRadioButton("board3");
     board4=new JRadioButton("board4");
     board5 = new JRadioButton("board5");
     p2=new JPanel();
     pl=new JPanel();
     p3=new JPanel();
     reset=new JButton("RESET");
     save=new JButton("SAVE");
     load=new JButton("LOAD");
     undo=new JButton("UNDO");
     auto=new JButton("AUTO");
     reset.setBackground(Color.GREEN);
     undo.setBackground(Color.ORANGE);
     auto.setBackground(Color.YELLOW);
     save.setBackground(Color.MAGENTA); //set all the operation buttons such as save load undo auto reset .
     load.setBackground(Color.WHITE);
     p3.setBackground(Color.CYAN);
     p3.add(save);
     p3.add(load);
     p3.add(reset);
     p3.add(undo);
     p3.add(auto);
     
     p3.setBounds(0, 260, 500, 500);
     pl.setBounds(0,0,200,100);
     p2.setBounds(0, 150, 100, 100);
     board1.setBackground(Color.CYAN);
     board2.setBackground(Color.CYAN); 
     board3.setBackground(Color.CYAN);
     board4.setBackground(Color.CYAN);
     board5.setBackground(Color.CYAN);
     pl.add(board1);
     pl.add(board2);
     pl.add(board3);   //ads buttons panels then adds the panels which filled with buttons to jframe.
     pl.add(board4);
     pl.add(board5);
     pl.setBackground(Color.CYAN);
     //board1.addActionListener(this);
     
     this.add(pl);
     this.add(p3);
     warning =new JLabel("invalid movement");

     p2.add(warning);
     p2.setBackground(Color.CYAN);
     warning.setVisible(false);
     this.add(p2);
     ButtonGroup group=new ButtonGroup();
     group.add(board1);
     group.add(board2);
     group.add(board3);
     group.add(board4);
     group.add(board5);
     board1.addActionListener(this);
     board2.addActionListener(this);
     board3.addActionListener(this);
     board4.addActionListener(this); // add the buttons to action listener tı be imlemented.
     board5.addActionListener(this);
     reset.addActionListener(this);
     save.addActionListener(this);
     load.addActionListener(this);
     undo.addActionListener(this);
     auto.addActionListener(this);
     this.pack();
     this.setVisible(true);
     } // 3 different type constructure .
    
     public void actionPerformed(ActionEvent e){
         if(e.getSource()==board1){//if the radio button board1 clicked initialize the board1.
          
          if(game_counter!=0){ // when we initialize the new board the old one will remove.
            this.remove(p1);
          }
          game_counter++;
          board_type=1;
          warning.setText("invalid movement");// fill the warning text as this message.
                          warning.setVisible(false);//then makes it unvisible.
          p1=new JPanel();
            size=7;
            p1.setBounds(300,300,500,500);
             //newwindow= new JFrame();
            
             buttons=new JButton[size][size]; //set 2 D buttons.
             
             p1.setLayout(new GridLayout(size,size)); //set a layout for p1 size: size x size.
             
             /*for(int i=0;i<size;i++){
                 buttons[i]=new JButton[size];
             }*/
             for(int i=0;i<size;i++){
  
                
                for(int j=0;j<size;j++){
                 
                    
                    
               
                 if((j>0 && j<6) && (i>0 && i<6))
                       buttons[i][j]=new JButton("P"); // fill their text regarding location to obtain our board.
                     else if(((i==0 || i==6) && j>1 && j<5) || ((j==0 || j==6) && i>1 && i<5))// _ char means empty cell . means wall cell P means filled cell.
                        buttons[i][j]=new JButton("P");
                     else
                        buttons[i][j]=new JButton(".");    
                 
                   
                  
                }
            
               
           
             }
             buttons[3][3]=new JButton("_"); 
             
             for(int i=0;i<size;i++){
  
                
                   for(int j=0;j<size;j++){
                    
                     p1.add(buttons[i][j]); 
                     
                   }
               
                 
              
                }
         this.add(p1);       
    //set the size of the window to be big enough to accomodate all controls.
        this.pack();
        
    //Finnaly, display the window
        this.setVisible(true);
        for(int i=0;i<size;i++){

            for(int j=0;j<size;j++){

                 
                    
                    buttons[i][j].addActionListener(this); // adds the array buttons to action listener.
                
            }
         }
        
        buttons[3][3].setText("_");
        
             System.out.println("accesed");

             

         }
         else if(e.getSource()==board2){
          if(game_counter!=0){
            this.remove(p1);
          }
          game_counter++;
          board_type=2;
          warning.setText("invalid movement"); //all the rules same as board1 adapted itself.
          warning.setVisible(false);
            size=9;
            p1=new JPanel();
            p1.setBounds(300,300,500,500);
             //newwindow= new JFrame();
            
             buttons=new JButton[size][size];
             
             p1.setLayout(new GridLayout(size,size));
             
              
              for(int i=0;i<size;i++){
            
              
        
              for(int j=0;j<size;j++){
                  if((i>2 && i<6) || (j>2 && j<6)){
                     buttons[i][j]=new JButton("P");
                   
                  }
                   
                  else{
                    buttons[i][j]=new JButton(".");
                     
                  }
                     
              }
        
         }
          buttons[4][4].setText("_");
          for(int i=0;i<size;i++){
  
                
            for(int j=0;j<size;j++){
             
              p1.add(buttons[i][j]); 
              
            }
        
          
       
         }
          this.add(p1);       
    //set the size of the window to be big enough to accomodate all controls.
        this.pack();
        
    //Finnaly, display the window
        this.setVisible(true);
        for(int i=0;i<size;i++){

            for(int j=0;j<size;j++){

                 
                    
                    buttons[i][j].addActionListener(this);
                
            }
         }


         }
        else if(e.getSource()==board3){
          if(game_counter!=0){
            this.remove(p1);
          }
          game_counter++;
          board_type=3;
          warning.setText("invalid movement");
                          warning.setVisible(false);
            size=8;
            p1=new JPanel();
            
            p1.setBounds(300,300,500,500);
             //newwindow= new JFrame();
            
             buttons=new JButton[size][size];
             
             p1.setLayout(new GridLayout(size,size));

            for(int i=0;i<size;i++){
           
             
       
             for(int j=0;j<size;j++){
                 if((i>2 && i<6) || (j>1 && j<5)){
       
                 
                   buttons[i][j]=new JButton("P");
                  
                 }
                 else{
       
                 
                   buttons[i][j]=new JButton(".");
                   
                 }  
             }
       
        }
        buttons[4][3].setText("_");
        for(int i=0;i<size;i++){
  
                
            for(int j=0;j<size;j++){
             
              p1.add(buttons[i][j]); 
              
            }
        
          
       
         }
          this.add(p1);       
    //set the size of the window to be big enough to accomodate all controls.
        this.pack();
        
    //Finnaly, display the window
        this.setVisible(true);
        for(int i=0;i<size;i++){

            for(int j=0;j<size;j++){

                 
                    
                    buttons[i][j].addActionListener(this);
                
            }
         }

        }
        else if(e.getSource()==board4){
          if(game_counter!=0){
            this.remove(p1);
          }
          game_counter++;
          board_type=4;
          warning.setText("invalid movement");
                          warning.setVisible(false);

            size=7;
            p1=new JPanel();
            
            p1.setBounds(300,300,500,500);
             //newwindow= new JFrame();
            
             buttons=new JButton[size][size];
             
             p1.setLayout(new GridLayout(size,size));
     for(int i=0;i<size;i++){
    
      

      for(int j=0;j<size;j++){
          if((i>1 && i<5) || (j>1 && j<5)){

          
            buttons[i][j]=new JButton("P");
           
          }
          else{

          
           buttons[i][j]=new JButton(".");
            
          }
      }

 }
 buttons[3][3].setText("_");
 for(int i=0;i<size;i++){
  
                
    for(int j=0;j<size;j++){
     
      p1.add(buttons[i][j]); 
      
    }

  

 }
  this.add(p1);       
//set the size of the window to be big enough to accomodate all controls.
this.pack();

//Finnaly, display the window
this.setVisible(true);
for(int i=0;i<size;i++){

    for(int j=0;j<size;j++){

         
            
            buttons[i][j].addActionListener(this);
        
    }
 }

        }
    else if(e.getSource()==board5){
      if(game_counter!=0){
        this.remove(p1);
      }
      game_counter++;
      board_type=5;
      warning.setText("invalid movement");
                          warning.setVisible(false);
        size=9;
        p1=new JPanel();
            
            p1.setBounds(300,300,500,500);
             //newwindow= new JFrame();
            
             buttons=new JButton[size][size];
             
             p1.setLayout(new GridLayout(size,size));
        
        for (int i=0;i<size;i++){
     
     
      
     for(int j=0;j<size;j++){
         if((j>1 && j<7) && (i>1 && i<7)){
   
         
           buttons[i][j]=new JButton("P");
               
         }
         else if(((i==1 || i==7) && j>2 && j<6) || ((j==1 || j==7) && i>2 && i<6)){
   
         
           buttons[i][j]=new JButton("P");
              
         }
         else if((i==4 && j==0) || (j==4 && i==0) || (i==8 && j==4) || (j==8 && i==4)){
   
         
           buttons[i][j]=new JButton("P");
               
         }
         
         else{
   
         
           buttons[i][j]=new JButton(".");
              
         }
     }
        
    }
    buttons[4][4]=new JButton("_");
    
    for(int i=0;i<size;i++){
  
                
        for(int j=0;j<size;j++){
         
          p1.add(buttons[i][j]); 
          
        }
    
      
    
     }
      this.add(p1);       
    //set the size of the window to be big enough to accomodate all controls.
    this.pack();
    
    //Finnaly, display the window
    this.setVisible(true);
    for(int i=0;i<size;i++){
    
        for(int j=0;j<size;j++){
    
             
                
                buttons[i][j].addActionListener(this);
            
        }



    }
}

if(e.getSource()==reset){//make cells like the initialised version the current board by of  setting text .

  if(board_type==1){
    for(int i=0;i<size;i++){
  
                
      for(int j=0;j<size;j++){
       
          
          
     
       if((j>0 && j<6) && (i>0 && i<6))
             buttons[i][j].setText("P");
           else if(((i==0 || i==6) && j>1 && j<5) || ((j==0 || j==6) && i>1 && i<5))
              buttons[i][j].setText("P");
           else
              buttons[i][j].setText(".");    
       
         
        
      }
  
     
 
   }
   buttons[3][3].setText("_");

  }
  if(board_type==2){
    for(int i=0;i<size;i++){
            
              
        
      for(int j=0;j<size;j++){
          if((i>2 && i<6) || (j>2 && j<6)){
             buttons[i][j].setText("P");
           
          }
           
          else{
            buttons[i][j].setText(".");
             
          }
             
      }

 }
  buttons[4][4].setText("_");
  }
  if(board_type==3){
   
    for(int i=0;i<size;i++){
           
             
       
      for(int j=0;j<size;j++){
          if((i>2 && i<6) || (j>1 && j<5)){

          
            buttons[i][j].setText("P");
           
          }
          else{

          
            buttons[i][j].setText(".");
            
          }  
      }

 }
 buttons[4][3].setText("_");

  }
  if(board_type==4){
   
    for(int i=0;i<size;i++){
    
      

      for(int j=0;j<size;j++){
          if((i>1 && i<5) || (j>1 && j<5)){

          
            buttons[i][j].setText("P");
           
          }
          else{

          
           buttons[i][j].setText(".");
            
          }
      }

 }
 buttons[3][3].setText("_");

  }
  if(board_type==5){
   
    for (int i=0;i<size;i++){
     
     
      
      for(int j=0;j<size;j++){
          if((j>1 && j<7) && (i>1 && i<7)){
    
          
            buttons[i][j].setText("P");
                
          }
          else if(((i==1 || i==7) && j>2 && j<6) || ((j==1 || j==7) && i>2 && i<6)){
    
          
            buttons[i][j].setText("P");
               
          }
          else if((i==4 && j==0) || (j==4 && i==0) || (i==8 && j==4) || (j==8 && i==4)){
    
          
            buttons[i][j].setText("P");
                
          }
          
          else{
    
          
            buttons[i][j].setText(".");
               
          }
      }
         
     }
     buttons[4][4].setText("_");

  }

  
}

if(e.getSource()==undo){// undo the movement for one step by sending it to move function as reversed .to explain if the movement location1 -> location2 send function by changing parameteers place it becomes location2 -> location1.

  if(counter==0){
    move(indexx2,indexy2,indexx1,indexy1);
    if(indexx2==indexx1 ){
      buttons[(indexy1+indexy2)/2][indexx1].setText("P");
    }
    if(indexy1==indexy2){
      buttons[indexy1][(indexx1+indexx2)/2].setText("P");
    }
  }
  else{
    warning.setVisible(true);
  }
}

if(e.getSource()==save){//writes texts of current buttons to text file .only one save can be implemented.

  try {
    File myObj = new File("filename.txt");
    if (myObj.createNewFile()) {
      System.out.println("File created: " + myObj.getName());
    } else {
      System.out.println("File already exists.");
    }
  } catch (IOException a) {
    System.out.println("An error occurred.");
    a.printStackTrace();
  }
  try {
    FileWriter myWriter = new FileWriter("filename.txt");
    for(int i=0;i<size;i++){

      for(int j=0;j<size;j++){
         myWriter.write(buttons[i][j].getText());
      }
    }
    myWriter.close();
    System.out.println("Successfully wrote to the file.");
  } catch (IOException a) {
    System.out.println("An error occurred.");
    a.printStackTrace();
  }
}
if(e.getSource()==load){//reads filnemae txt and assign the readed char to buttons text . 
  char[] totallen = new char[size*size];
  try {
    File myObj = new File("filename.txt");
    Scanner myReader = new Scanner(myObj);
    while (myReader.hasNextLine()) {
      String data = myReader.nextLine();
      System.out.println(data);
      for(int i=0;i<data.length();i++){
        totallen[i]=data.charAt(i);
      }
      
    }
    for(int i=0;i<size;i++){

      for(int j=0;j<size;j++){
        if(totallen[i*size+j]=='P')
         buttons[i][j].setText("P");
         if(totallen[i*size+j]=='.')
         buttons[i][j].setText(".");
         if(totallen[i*size+j]=='_')
         buttons[i][j].setText("_");
      }
    }
    myReader.close();
  } catch (FileNotFoundException a) {
    System.out.println("An error occurred.");
    a.printStackTrace();
  }
 
  for(int i=0;i<size;i++){

    for(int j=0;j<size;j++){
       System.out.println(buttons[i][j].getText());
    }
  }
  

}
if(e.getSource()==auto){

  boolean posib=true;
  int randx1=0,randx2=0,randy1=0,randy2=0;
  Random random=new Random();
  boolean finished_game=false;
  if(end_game()){//firs check if the game over or not .
    finished_game=true;                    
    warning.setText("game over");
    warning.setVisible(true);
    this.remove(p1);
    
  }
  while(posib && !(finished_game)){ // until the movement posible and the game is not finished sets random interes between 0 to size.
    indexx1=random.nextInt(size);
    indexx2=random.nextInt(size);
    indexy1=random.nextInt(size);
    indexy2=random.nextInt(size);
    posib=check_movement_possibility(indexx1, indexy1, indexx2, indexy2);

  }
  
  System.out.println(randx1);
  System.out.println(randy1);
  System.out.println(randx2);
  System.out.println(randy2);
 move(indexx1, indexy1, indexx2, indexy2);//if the operation out of the while loop the movement can be applied.

}

         for(int i=0;i<size;i++){

            for(int j=0;j<size;j++){

                 if(e.getSource()==buttons[i][j]){// playing system is applied here. you chose one button forom screen the program sign it as clicked and you chose another button thats the location to move 
                     counter++;                 //first it check the movement is possible or not regarding the locations you chose then if the movement possible applies the desired movement if its not prints warning message to screen.
                     if(counter==1){
                         indexx1=j;
                         indexy1=i;
                         System.out.println(i);
                         System.out.println(j);
                         buttons[i][j].setEnabled(false);
                         warning.setVisible(false);
                     }
                    if(counter==2){
                      buttons[indexy1][indexx1].setEnabled(true);
                        indexx2=j;
                        indexy2=i;
                        System.out.println(i);
                         System.out.println(j);
                      counter=0;
                      System.out.println(check_movement_possibility(indexx1,indexy1,indexx2,indexy2));
                      if(!check_movement_possibility(indexx1,indexy1,indexx2,indexy2)){
                        move(indexx1,indexy1,indexx2,indexy2);
                        if(end_game()){
                          
                          warning.setText("game over");
                          warning.setVisible(true);
                          this.remove(p1);
                          
                        }
                      }
                      else{
                         warning.setVisible(true);
                      }

                      
                    }
                    
                   
                }
            }
         }
         
     }

     PegSolitaire(int board_ty){

     }
    
     public void move(int xx,int yy,int xx2,int yy2){//applies the move by changing text .
         buttons[yy][xx].setText("_");
         buttons[yy2][xx2].setText("P");
         if(xx2==xx+2){
            buttons[yy][xx+1].setText("_");
         }
         if(xx2==xx-2){
            buttons[yy][xx-1].setText("_");
         }
         if(yy2==yy+2){
            buttons[yy+1][xx].setText("_");
         }
         if(yy2==yy-2){
            buttons[yy-1][xx].setText("_");
         }
     }
    public boolean check_movement_possibility(int xx,int yy,int xx2,int yy2){
 
        if(xx2==xx+2 && yy2==yy && xx2<size && yy2<size){ //if direction right for all the conditions to move 
       
          if((xx+2)<=size && buttons[yy][xx+2].getText()=="_" && buttons[yy][xx+1].getText()=="P" && buttons[yy][xx].getText()=="P")
           return false;
          else
           return true;
        }
        if(xx2==xx-2 && yy2==yy && xx2>=0 && yy2>=0){
       
          if((xx-2)>=0 && buttons[yy][xx-2].getText()=="_" && buttons[yy][xx-1].getText()=="P" && buttons[yy][xx].getText()=="P")
           return false;
          else
           return true;
        }
        if(yy2==yy+2 && xx==xx2 && xx2<size && yy2<size){
       
          if((yy+2)<=size && buttons[yy+2][xx].getText()=="_" && buttons[yy+1][xx].getText()=="P" && buttons[yy][xx].getText()=="P")
           return false;
          else
           return true;
        }
        if(yy2==yy-2 && xx==xx2 && xx2>=0 && yy2>=0){
       
          if((yy-2)>=0 && buttons[yy-2][xx].getText()=="_" && buttons[yy-1][xx].getText()=="P" && buttons[yy][xx].getText()=="P")
           return false;
          else
           return true;
        }
       
        return true;
       
       }
     
       public PegSolitaire clone()throws CloneNotSupportedException{
        PegSolitaire b = (PegSolitaire)super.clone();
        return b;
        }
      public boolean end_game(){//try all the cells to find if there any possible movement location if it dont find any .returns true.

       for(int i=0;i<size;i++){

        for(int j=0;j<size;j++){
          if(!check_movement_possibility(j,i,j+2,i)){
            return false;
          }
          if(!check_movement_possibility(j,i,j-2,i)){
            return false;
          }
          if(!check_movement_possibility(j,i,j,i+2)){
            return false;
          }
          if(!check_movement_possibility(j,i,j,i-2)){
            return false;
          }
        }
       }

       return true;
      }
     void show_table(){

     } //to show the table .
     
      
     int counter=0;
      int board_type;
      int size;
      // 2d cell object vector.
      int empty_cellnumber;
      int peg_number;
      int taken_peg;
      int user_type;
      int indexx1,indexy1;
      int indexx2,indexy2;
      int game_counter=0;
      static int all_thepeg;
    }