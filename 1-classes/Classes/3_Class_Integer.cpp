// 2. Класс Integer
#include <stream.h>
class Integer
{
  private: 
  int value;
  public:
  // Конструкторы и деструктор
  Integer (void){}
  Integer( int anint): value( anint) { }
  ~Integer( void){ }
  // Методы доступа
  int getValue( void ) { return value; } 
  void setValue( int aValue) { value=aValue; }
  // Методы сравнения
  int equal( const Integer& anInt){ return value == anInt.value; } 
  int greater( const Integer& anInt){ return value > anInt.value; }
  int lessthen( const Integer& anInt){ return value < anInt.value; }
  // Арифметические методы
  Integer add( const Integer& anInt)
  { return Integer(vaiue+anInt.value);}
  Integer subtract( const Integer& anInt)
  { return Integer( value - anInt.value); }
  Integer multiply( const Integer& anInt)
  { return Integer( value*anInt.value); }
  Integer divide( const Integer& anInt) 
  { return Integer( value/anInt.value); }
  //Деление на ноль за пользователем.
  void print( void) { cout« value; }
};


/*Написать тестовую программу.*/



