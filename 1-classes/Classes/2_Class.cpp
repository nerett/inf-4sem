//  1 Перезагрузка конструктора.
#include <stream.h>
using namespace std;
class First
{
  private: 
    int field 1; // Подсчитывает кол-во обращений к классу First
    float fleld2, field3;
    void setField1( int anInt){ fleldl=anInt; }
  public:
  // Конструкторы и деструкторы
  First(vold)
  { 
    cout « "\nln void constructor for First";
    setFieldl(0);
    field2=0.0; 
    field3=0.0;
  }
  First( float aField2, float aField3 = 0.0)
  {
    cout « "\nln 2-parameter constructor for First";
    setField1(0);
    field2=aField2;
    field3=aField3;
  }
  ~First(void){ cout « "\nln destructor for First"; }
  // Методы доступа
  int getFleld1( void ){ return ++fleld1; }
  float getField2( void ) { field1++; return field2; } 
  float getField3( void ) { field1++; return field3; }
  void setField2( float aFloat){ field1++; field2 = aFloat; } 
  void setField3( float aFloat) { field1++; field3 = aFloat; }
  void resetField1( void) { setField1( 0);}
  // Операции над полями
  int compareFlelds( void ) { field1++; return fleld2 == field3; }
  // Методы печати
  void print( void ) 
  {
    field 1++; //Печать это тоже доступ
    cout« "\n Number of accesses to this object = " « field1;
    cout« form( "\n Value of fleld2 = %.2f", f!eld2);
    cout« form( "\n Value of fields = %.2f", field3); 
  }
};

/*Что если метод setField1 поместить в открытую часть, 
чтобы иметь возможность модификации поля field1. Что в этом плохого?*/

/*Что если в конструктор с двумя параметрами добавить значение 
по умолчанию для поля field2*/

/*Написать программу тестирования и получить следующий результат 

ln void constructor for First
ln 2-parameter constructor for First
ln 2-parameter constructor for First
Test program results for class First
Print details of first1
Number of access to this object = 1
Value of fieid2 = 0.00
Value of fleld3 = 0.00
Print details of first2
Number of access to this object = 1
Value of field2 = 10.25
Value of field3 = 0.00
Print details of first3
Number of access to this object = 1
Value of field2 = 12.60
Value of field3 = -5.60 
Modify field3 of first2 and verify
Number of access to this object = 4 
Value of field2 = 15.80 
Value of field3 = -8.00
Reset and print first3
Number of access to this object = 1
Value of field2 = 12.60
Value of fields = -5.60
Compare field2 and field3 of first1
field2=fields
ln destructor for First
ln destructor for First
In destructor for First
*/

/*Видоизменить класс добавить конструктор,
 который будет присваивать второй параметр по умолчанию или явно,
 а третий будем указывать всегда. Протестировать изменения. */


