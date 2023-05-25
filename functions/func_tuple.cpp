#include <tuple>
#include <string>
#include <iostream>

using namespace std;

tuple<int, string, double> f()
{
    int i{ 108 };
    string s{ "Some text" };
    double d{ .01 };
    return { i,s,d };
}
struct S
{
    string name;
    int num;
};

S g()
{
    string t{ "hello" };
    int u{ 42 };
    return { t, u };
}

int main()
{
   // for C++17:
   auto[x, y, z] = f(); // init from tuple

   auto[a, b] = g(); // init from POD struct

   /////////////////////////////////////////

   std::tuple<int, double, string> tp { 10, 20.5, "hello" };

   // for C++17:
   //std::tuple tp { 10, 20.5, "hello" };

   // iterate:
   for (auto& elem : tp)
      std::cout << elem << ", ";


   std::cout << std::get<0>(tp) << ", ";
   std::cout << std::get<1>(tp) << ", ";
   std::cout << std::get<2>(tp) << ", ";

   return 0;
}
