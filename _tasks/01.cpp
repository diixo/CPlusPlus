
#include <iostream>
#include <stdio.h>

using namespace std;

struct A
{
   char* data;

   explicit A(const char* msg = 0)
      : data(new char[msg ? strlen(msg) : 0 + 1])
   {
      if (msg)
      {
         memcpy(data, msg, strlen(msg));
      }
   }

   virtual void say()
   {
      std::cout << "A::say=" << data << std::endl;
   }

   virtual ~A()
   {
      delete[] data;
   }
};

struct B : public A
{
   int* data;

   B()
      : A()
      , data(new int(0))
   {}

   virtual void say()
   {
      std::cout << "B::say=" << *data << std::endl;
   }

   ~B()
   {
      delete data;
   }
};

int main(int, char**) try
{
   A* a = new A("hello");
   B* b = new B();

   b->say();

   b* = a*;

   b->say();

   delete a;
   delete b;

   return 0;
}
catch (std::exception& const ex)
{
   std::cout<< ex.what() << std::end;
}
