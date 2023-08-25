
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int x = 0;

class A
{
public:
   A()
   {
      cout << "a";
      if (x++ == 0)
      {
         throw std::exception();
      }
   }
   ~A()
   {
      cout << "A";
   }
};

class B : public A
{
public:
   B()
   {
      cout << "b";
   }
   ~B()
   {
      cout << "B";
   }
   A a;
};

void foo()
{
   static B b;
}

int main()
{
   try
   {
      foo();
   }
   catch (std::exception& )
   {
      cout << "c";
      foo();
   }
   return 0;
}
