
// for_each example
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myfunction(int i)
{
   // function:
   std::cout << ' ' << i;
}

struct myclass
{
   // function object type:
   void operator() (int i) { std::cout << ' ' << i; }
} myobject;

int main()
{
   vector<int> myvector{10, 20, 30};

   for_each(myvector.begin(), myvector.end(), myfunction);

   for_each(myvector.begin(), myvector.end(), myobject);

   for_each(std::begin(myvector), std::end(myvector), [](int value) { /* */ });

   ///////////////////////////////////////////////////////////////////////////
   int arr[] = { 10, 20, 30 };
   int summ = 0;
   for_each(arr, arr + 3, [&summ](int v) { summ += v; });

   for_each(std::begin(arr), std::begin(arr) + 3, [&summ](int v) { summ += v; });

   return 0;
}
