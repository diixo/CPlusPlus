// http://scrutator.me/post/2013/01/18/template-innovations.aspx

#include <iostream>

template<typename... Args>
struct A
{
    static const size_t number = sizeof...(Args);
};
 
int main()
{
    std::cout << A<bool, int, int, int, int, int>::number;
}

///////////////
// unpacking to tuple:

template<typename... Args>
struct A
{
    typedef std::tuple<Args...> Tuple_t;
};
