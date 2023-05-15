
#include <iostream>

using namespace std;

auto y = [] (int first, int second)
{
    return first + second;
};

auto u = [] (auto first, auto second)
{
    return first + second;
};

int main()
{
   int m = 0;
   int n = 0;
   [&, n] (int a) mutable
   {
      m = ++n + a;
   }(4);

   cout << m << endl << n << endl;
}
