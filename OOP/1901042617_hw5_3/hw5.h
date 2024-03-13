#include <ostream>
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
 
 namespace my_namespace{

 

class BoardGame2D{
  
  public:
  
  BoardGame2D(int ,int );
  BoardGame2D();
  

  virtual void initialize() = 0;
  virtual void print()=0;
  virtual void playAuto()=0;
  virtual void playUser(string)=0;
  virtual void playUser()final;
  virtual bool endGame()=0;
  virtual void PlayAutoAll()final;
  virtual int BoardScore()=0;
  class cell{
    public:
    int get_celltype()const;
    void set_celltype(int );
    private:
    int the_cell;
  };

  protected:
 int x;
 int y;
 vector<vector<cell>> cells;
 int point;


};

class PegSolitaire:public BoardGame2D{

public:
 PegSolitaire();
 void initialize();
 //friend  ostream & operator <<(ostream & out ,BoardGame2D & prnt);
 void print();
 void playAuto();
 bool check_movement(int d,int yy,int xx);
 bool endGame();
 int BoardScore();
 void playUser(string);
 void move(int,int,int);
 
};
class EightPuzzle:public BoardGame2D{

    public:
    EightPuzzle();
    void initialize();
    void print();
    void playAuto();
    bool include(vector<int> & set,int element);
    bool check_movement(int d,int yy,int xx);
    
    void playUser(string);
    int BoardScore();
    void move(int,int,int);
    bool endGame();

};

class Klotski:public BoardGame2D{
    
    public:
    Klotski();
    void initialize() ;
   void print();
   void playAuto();
   void playUser(string);
   int BoardScore();
   bool endGame();
   void move(int,int,int);
   bool check_movement(int,int,int);
};
 void playVector(vector<BoardGame2D *>  & all_thegame);
 }