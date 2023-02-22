#include <cstdlib>
#include <iostream>
using namespace std;

#define  MAXSIZE 100

class IntArray
{
    private:
        int* data;
        unsigned size;
        
    protected:
        void error( void ){ throw "ERROR!\n"; };
        
    public:
        IntArray();
        IntArray( unsigned size );
        void put( unsigned i, int value );
        int get( unsigned i );
        int operator []( unsigned i );
        // добавить оператор дружественный классу ostream, печатающий весь массив
        
        friend ostream& operator << ( ostream& o, IntArray intArray );
};

ostream& operator << ( ostream& o, IntArray intArray )
{
    for( int i = 0; i < intArray.size; i++ )
    {
        o << intArray[i] << endl;
    }
    
    return o;
}

IntArray::IntArray( void )
{
    size = MAXSIZE;
    data = new int[size];
    for( int i = 0; i < size; i++ ){ data[i] = 0; };
};

IntArray::IntArray( unsigned size )
{
    this->size = size;
    data = new int[size];
    for ( int i = 0; i < size; i++ ){ data[i] = 0; };
};

void IntArray::put( unsigned i, int value )
{
    if( i >= size ) error(); 
    data[i] = value;
};

int IntArray::get( unsigned i )
{
  if( i >= size ) error(); 
  return data[i];
};

int IntArray::operator []( unsigned i )
{
  if( i >= size ) error(); 
  return data[i];
};


/*
 * 
 */
int main( int argc, char** argv )
{
    IntArray a;
    a.put( 1, 20 );
    cout << a.get( 1 );
    try
    {        
        a.put( 300, 300 );
    }
    catch( char const * q )
    {
        cout << q;
    };
    cout << a[1];
    // Почему в определении перезагрузки данного оператора два параметра,
    // а при использовании один
    //cout << a;
    
    cout << endl;
    cout << "New test" << endl;
    
    IntArray testArray( 10 );
    for( int i = 0; i < 10; i++ )
    {
        testArray.put( i, i * ( i + 1 ) );
    }
    
    cout << testArray << endl;
    return 0;
}

