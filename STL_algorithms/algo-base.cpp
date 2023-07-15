
// https://en.cppreference.com/w/cpp/algorithm/equal

template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!(*first1 == *first2))
            return false;
 
    return true;
}

template<class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, BinaryPredicate p)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!p(*first1, *first2))
            return false;
 
    return true;
}

/////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iomanip>
#include <iostream>
 
constexpr bool is_palindrome(const std::string& s)
{
    return std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin());
}
 
void test(const std::string& s)
{
    std::cout << std::quoted(s)
              << (is_palindrome(s) ? " is" : " is not")
              << " a palindrome\n";
}
 
int main()
{
    test("radar");
    test("hello");
}
