// RAII-principles: resource acquisition is initialization

#include <memory>
#include <iostream>
using namespace std;

class widget
{
private:
   std::unique_ptr<int[]> data;
   int sz = 0;

public:

   widget(const int size) { 
      data = std::make_unique<int[]>(size); 
      sz = size;
   }

   void do_something() {}

   widget& operator=(const widget& w)
   {
      if (this == &w)
      {
         return *this;
      }
      data.reset();  // destruct old data
      data = std::make_unique<int[]>(w.sz);
      std::copy(w.data.get(), w.data.get() + w.sz, data.get());
      sz = w.sz;
      return *this;
   }

   widget& operator=(widget&& w)
   {
      if (this == &w)
      {
         return *this;
      }
      sz = 0;
      data.reset();  // destruct old data

      std::swap(data, w.data);
      std::swap(sz, w.sz);

      return *this;
   }

   widget(widget&& w)
   {
      std::swap(data, w.data);
      std::swap(sz, w.sz);
   }
};

void functionUsingWidget()
{
   widget w(1000000);
   // ...
   w.do_something();
   // ...
}

int main()
{
   widget w1(100);

   widget w2(100);

   w1 = w2;

   return 0;
}
