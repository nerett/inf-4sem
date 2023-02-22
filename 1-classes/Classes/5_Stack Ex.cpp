#include <iostream>
using namespace std;

#define SIZE 100

class stack 
// Добавить возможность создавать стек заданной параметром конструктора глубины.
// Добавить в класс контроль переполнения, cоздавая исключительную ситуацию throw при переполнении.
// В программе перехватить созданную исключительную ситуацию try{} catch(type value){}

{
  int stck[SIZE];
  int tos;
public:
  stack();  // constructor
  ~stack(); // destructor
  void push(int i);
  int pop();
};

stack::stack()
{
  tos = 0;
  cout << "Stack Initialized\n";
}

stack::~stack()
{
  cout << "Stack Destroyed\n";
}

void stack::push(int i)
{
  if(tos==SIZE)
  {
    cout << "Stack is full.\n";
    return;
  }
  stck[tos] = i;
  tos++;
}

int stack::pop()
{
  if(tos==0) 
  {
    cout << "Stack underflow.\n";
    return 0;
  }
  tos--;
  return stck[tos];
}

////
int main()
{
  stack a, b;  

  a.push(1);
  b.push(2);

  a.push(3);
  b.push(4);

  cout << a.pop() << " ";
  cout << a.pop() << " ";
  cout << b.pop() << " ";
  cout << b.pop() << "\n";

  return 0;
}
 
