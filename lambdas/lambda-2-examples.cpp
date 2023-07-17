// https://learn.microsoft.com/ru-ru/cpp/cpp/examples-of-lambda-expressions?view=msvc-140

#include <functional>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    // Assign the same lambda expression to a function object.
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };

    cout << f2(3, 4) << endl;
}

/***********
5
7
***********/

int main()
{
   int i = 3;
   int j = 5;

   // The following lambda expression captures i by value and
   // j by reference.
   function<int (void)> f = [i, &j] { return i + j; };

   // Change the values of i and j.
   i = 22;
   j = 44;

   // Call f and print its result.
   cout << f() << endl;
}

/***********
47
***********/
///////////////////////////////////////////////////////////////////////
int main()
{
   int n = [] (int x, int y) { return x + y; }(5, 4);
   cout << n << endl;
}

///////////////////////////////////////////////////////////////////////
int main(int, char**)
{
   list<int> numbers{1, 5, 42, 46, 99};

   // Use the find_if function and a lambda expression to find the
   // first even number in the list.
   const list<int>::const_iterator result =
      find_if(numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });

   // Print the result.
   if (result != numbers.end()) {
      cout << "The first even number in the list is " << *result << "." << endl;
   }
   else {
      cout << "The list contains no even numbers." << endl;
   }
   return 0;
}

///////////////////////////////////////////////////////////////////////
// higher_order_lambda_expression.cpp
// compile with: /EHsc /W4
int main()
{
    // The following code declares a lambda expression that returns
    // another lambda expression that adds two numbers.
    // The returned lambda expression captures parameter x by value.
    auto addtwointegers = [](int x) -> function<int(int)> {
        return [=](int y) { return x + y; };
    };

    // The following code declares a lambda expression that takes another
    // lambda expression as its argument.
    // The lambda expression applies the argument z to the function f
    // and multiplies by 2.
    auto higherorder = [](const function<int(int)>& f, int z) {
        return f(z) * 2;
    };

    // Call the lambda expression that is bound to higherorder.
    auto answer = higherorder(addtwointegers(7), 8);

    // Print the result, which is (7+8)*2.
    cout << answer << endl;
}

///////////////////////////////////////////////////////////////////////
// Negates each element in the vector object. Assumes signed data type.
template <typename T>
void negate_all(vector<T>& v)
{
    for_each(v.begin(), v.end(), [](T& n) { n = -n; });
}
