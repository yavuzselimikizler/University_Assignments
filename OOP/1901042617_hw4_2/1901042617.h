#include <ostream>
using namespace std;


namespace setnamespace{
 


class DayofYearSet{
 
  

  public:
  
  
  DayofYearSet();
  bool add_elements(int the_day,int the_month);
  bool remove_elements(int the_day,int the_month);
  void print();
  int get_numberofelements()const;
  int get_setnumber()const;
  friend std::ostream & operator << (ostream & ,DayofYearSet & );
  friend bool operator == ( const DayofYearSet & ,const DayofYearSet & );
  friend bool operator != (DayofYearSet & ,DayofYearSet & );
   friend DayofYearSet operator+(const DayofYearSet & ,const DayofYearSet & );
   friend DayofYearSet operator-(DayofYearSet & ,DayofYearSet & );
   friend DayofYearSet operator^(const DayofYearSet & ,const DayofYearSet & );
   friend DayofYearSet operator !(const DayofYearSet & );
   
  //friend DayofYearSet  operator[](int index);
   class DayofYear{

     public:
      
      void set_the_day(int );
      void set_the_month(int );
      int get_the_day()const;
      int get_the_month()const;
    
     private:
      int Day;
      int Month;


   };
   //DayofYearSet  ::DayofYear & operator [](const int index);
   static int numberset;

  private:
   
   DayofYear * dates;
   int number_of_elements;

  




};

}