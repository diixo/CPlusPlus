#include <iostream>
using namespace std;

struct r_iterator
{
   long int value;

   r_iterator(long int _v)
      : value(_v)
   {}

   operator long int () const { return value; }
   operator long int& ()      { return value; }
   long int operator* () const { return value; }
};

template <long int _begin, long int _end>
struct range
{
   range() = delete;
   range(const range &) = delete;

   r_iterator begin() const {return _begin;}
   r_iterator end  () const {return _end;}
};

int main()
{
   for(auto i: range<0,10>())
   {
      cout << i << endl;
   }
   return 0;
}
