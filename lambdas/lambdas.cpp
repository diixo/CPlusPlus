// https://senior.ua/articles/vse-o-lyambdafunkciyah-v-c-
// (part-2)

#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////
// General lambda:
const auto l = [](auto a, auto b, auto c) {};

// is equivalent to
struct anonymous
{
    template <class T0, class T1, class T2>
    auto operator()(T0 a, T1 b, T2 c) const
    {
    }
};

/////////////////////////////////////////////////////////
// Variadic universal lambda:

void print() {}

template <typename First, typename... Rest>
void print(const First &first, Rest &&... args)
{
    std::cout << first << std::endl;
    print(args...);
}

int main()
{
    auto variadic_generic_lambda = [](auto... param) {
        print(param...);
    };
    variadic_generic_lambda(1, "lol", 1.1);
}

/////////////////////////////////////////////////////////
// Mutable lambda:
[]() mutable {}

// is equivalent to

struct anonymous
{
    auto operator()()  // call operator
    {
    }
};

/////////////////////////////////////////////////////////
// return lambda of lambda:
const auto less_than = [](auto x) {
    return [x](auto y) {
        return y < x;
    };
};

int main(void)
{
    auto less_than_five = less_than(5);
    std::cout << less_than_five(3) << std::endl;
    std::cout << less_than_five(10) << std::endl;
    return 0;
}

/////////////////////////////////////////////////////////
// constexpr lambda (from c++17):
constexpr auto sum = [](const auto &a, const auto &b) { return a + b; };
/*
    is equivalent to
    constexpr struct anonymous
    {
        template <class T1, class T2>
        constexpr auto operator()(T1 a, T2 b) const
        {
            return a + b;
        }
    };
*/
constexpr int answer = sum(10, 10);
