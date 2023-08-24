
#include <iostream>
#include <stdio.h>

using namespace std;

struct A
{
   char* data;

   explicit A(const char* msg = 0)
      : data(nullptr)
   {
      if (msg)
      {
         auto len = strlen(msg) + 1; 
         data = new char[len];
         strcpy_s(data, len, msg);
      }
   }

   A(const A& rhs)
   {
      if (rhs.data)
      {
         auto len = strlen(rhs.data) + 1;
         data = new char[len];
         strcpy_s(data, len, rhs.data);
      }
   }

   A& operator = (const A& rhs)
   {
      if (this != &rhs)
      {
         delete[] this->data;    // no need to check for nullptr
         this->data = nullptr;

         if (rhs.data)
         {
            auto len = strlen(rhs.data) + 1;
            data = new char[len];
            strcpy_s(data, len, rhs.data);
         }
      }
      return *this;
   }

   virtual void say()
   {
      std::cout << "A::say=" << data << std::endl;
   }

   virtual ~A()
   {
      // no need to check data
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

int main(int, char**)
{
   A* a = new A("hello");
   B* b = new B();

   b->say();

   //b* = a*; error
   *a = *b; // OK

   b->say();

   delete a;
   delete b;

   return 0;
}

