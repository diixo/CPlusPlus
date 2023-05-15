// https://senior.ua/articles/vse-o-lyambdafunkciyah-v-c-

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
////////////////////////////////////////////////////////

struct print
{
    void operator()(int element)
    {
        std::cout << element << endl;
    }
};
int main(void)
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::for_each(v.begin(), v.end(), print());
    return 0;
}

////////////////////////////////////////////////////////
std::for_each(v.begin(), v.end(), [](int element) { cout << element << endl; });
////////////////////////////////////////////////////////

//Construction:
// [&i] ( ) { std::cout << i; }

// is equivalent to:

struct anonymous
{
    int &m_i;
    anonymous(int &i) : m_i(i) {}
    inline auto operator()() const
    {
       std::cout << i;
    }
};

////////////////////////////////////////////////////////
// pass lambda as parameter:

template <typename Functor>
void f(Functor functor)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
/* Or alternatively you can use this
void f(std::function<int(int)> functor)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
} 
*/

int g() { static int i = 0; return i++; }
int main()
{
    auto lambda_func = [i = 0]() mutable { return i++; };
    f(lambda_func); // Pass lambda
    f(g);           // Pass function
}

////////////////////////////////////////////////////////
// [=] access class-members is OK
// [this] access class-members is OK
// [&] access class-members is OK
////////////////////////////////////////////////////////

// 1. Capturing using [=] is OK:
class Example
{
public:
    Example() : m_var(10) {}
    void func()
    {
        [=]() { std::cout << m_var << std::endl; }(); // IIFE
    }
private:
    int m_var;
};

// 2. Capture using [this] is OK:
class Example
{
public:
    Example() : m_var(10) {}
    void func()
    {
        [this]() { std::cout << m_var << std::endl; }(); // IIFE
    }
private:
    int m_var;
};

// 3. Capture using [&] is OK:
class Example
{
public:
    Example() : m_var(10) {}
    void func()
    {
        [&]() { std::cout << m_var << std::endl; }(); // IIFE
    }
private:
    int m_var;
};

int main()
{
    Example e;
    e.func();
}
