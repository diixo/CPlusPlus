
// https://learn.microsoft.com/ru-ru/cpp/cpp/lambda-expressions-in-cpp?view=msvc-140

#include <iostream>
#include <functional>
#include <memory>
#include <vector>

using namespace std;

////////////////////////////////////////////
struct S {
    void f(int i);
};

void S::f(int i) {
    [&, i]{};      // OK
    [&, &i]{};     // ERROR: i preceded by & when & is the default
    [=, this]{};   // ERROR: this when = is the default
    [=, *this]{ }; // OK: captures this by value. See below.
    [i, i]{};      // ERROR: i repeated
}

/////////////////////////////////////////////
// variadic template for lambda:

template<class... Args>
void f(Args... args) {
    auto x = [args...] { return g(args...); };
    x();
}

/////////////////////////////////////////////
// Generalized capture (C++ 14):
auto pNums = make_unique<vector<int>>(nums);
//...
auto a = [ptr = move(pNums)]()
{
    // use ptr
};

/////////////////////////////////////////////

auto y = [] (int first, int second)
{
    return first + second;
};

// C++14:
auto u = [] (auto first, auto second)
{
    return first + second;
};
/////////////////////////////////////////////
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
/* Output:
   5
   0
*/

// autoinitializing with auto-calling
int increment(int n)
{
   return [n] { return n + 1; }();
}

// create pointer to function:
auto Increment = [](int n)
{
    return n + 1;
};

constexpr int(*inc)(int) = Increment;

/////////////////////////////////////////////
int main()
{
    int a = 1;
    function<int()> func = [a](){  return a + 1; }; // a is direct initialized
    int n = func();
}
