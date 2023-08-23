// https://metanit.com/cpp/tutorial/15.4.php

#include <iostream>
#include <functional>   // для std::function
 
class Sum
{
public:
   int operator()(int a, int b){ return a + b;}
};

int subtract(int a, int b){ return a - b; }

int main()
{
   std::function<int(int,int)> operation;

   operation = Sum{};
   std::cout << operation(10, 6) << std::endl;     // 16

   operation = subtract;
   std::cout << operation(10, 6) << std::endl;     // 4

   auto multiply = [](int a, int b){ return a * b; };
   operation = multiply;
   std::cout << operation(10, 6) << std::endl;     // 60

   return 0;
}
