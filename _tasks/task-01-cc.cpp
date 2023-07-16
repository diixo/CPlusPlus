
#include <iostream>
#include <stdio.h>
#include <memory>
#include <iterator>

using namespace std;

struct A
{
   std::unique_ptr<char[]> data;

   explicit A(const char* msg = 0)
      : data(std::make_unique<char[]>(msg ? strlen(msg) + 1 : 1))
   {
      if (msg)
      {
         std::copy(msg, msg + strlen(msg) + 1, data.get());
         // std::copy(std::begin(src), std::end(src), std::begin(dest));
      }
      else
      {
         *data.get() = 0;
      }
   }

   A(const A& a)
   {
      data.reset();
      data = std::make_unique<char[]>(strlen(a.data.get()) + 1);
      std::copy(a.data.get(), a.data.get() + strlen(a.data.get()) + 1, data.get());
   }

   A& operator =(const A& a)
   {
      if (this != &a)
      {
         data.reset();
         data = std::make_unique<char[]>(strlen(a.data.get()) + 1);
         std::copy(a.data.get(), a.data.get() + strlen(a.data.get()) + 1, 
                     data.get());
      }
      return *this;
   }

   A& operator =(A&& a) noexcept
   {
      if (this != &a)
         data = std::move(a.data);
      return *this;
   }

   A(A&& a)
   {
      data = std::move(a.data);
   }

   virtual void say()
   {
      std::cout << "A::say=" << data.get() << std::endl;
   }

   virtual ~A()
   {}
};

struct B final : public A
{
   int* data;

   B()
      : A()
      , data(new int(0))
   {}

   explicit B(int value)
      : A()
      , data(new int(value))
   {}

   B(const B& b)
      : A()
      , data(new int(*b.data))
   {}

   B& operator=(const B& b)
   {
      if (this != &b)
      {
         *data = *b.data;
      }
      return *this;
   }

   B(B&& b)
      : A(std::move(b))
   {
      data = b.data;
      b.data = nullptr;
   }

   B& operator=(B&& b) noexcept
   {
      if (this != &b)
      {
         delete data;
         data = b.data;
         b.data = nullptr;
         A::operator=(std::move(b));
      }
      return *this;
   }

   virtual void say() override
   {
      std::cout << "B::say=" << *data << std::endl;
   }

   explicit operator int() const
   {
      return *data;
   }

   explicit operator int&()
   {
      return *data;
   }

   ~B()
   {
      if (data)
         delete data;
   }
};

B&& test(B&& b)
{
   return move(b);
}

int main(int, char**)
{
   A* a = new A("hello");
   B* b = new B();

   B t(23);

   // call operator=(&&)
   t = test(B(125));
   t = B(23);

   // int cast
   (int)t = 47;
   int value = (int)t;


   a->say();

   b->say();

   delete a;
   delete b;
   return 0;
}
