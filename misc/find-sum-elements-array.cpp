// https://www.techiedelight.com/find-sum-elements-cpp-array/
// Find sum of elements in a C++ array

///////////////////////////////////////
// 1. Using STL’s accumulate() function:

#include <iostream>
#include <numeric>
 
int main()
{
    int arr[] = { 5, 3, 7, 9, 2 };
 
    int sum = std::accumulate(std::begin(arr), std::end(arr), 0, std::plus<int>());
    std::cout << sum;
 
    return 0;
}

/////////////////////////////////////// 
// 3. Using STL’s for_each() function:

#include <iostream>
#include <algorithm>

int main()
{
    int arr[] = { 5, 3, 7, 9, 2 };
 
    int sum = 0;
    std::for_each(std::begin(arr), std::end(arr),
                [&] (int &i) {
                    sum += i;
                });
 
    std::cout << sum;
 
    return 0;
}

///////////////////////////////////////
// 4. For-loop:

#include <iostream>
 
int main()
{
    int arr[] = { 5, 3, 7, 9, 2};
    int n = sizeof(arr) / sizeof(int);
 
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
 
    std::cout << sum;
    return 0;
}

///////////////////////////////////////
// Range-based for-loop:
#include <iostream>
 
int main()
{
    int arr[] = { 5, 3, 7, 9, 2 };
 
    int sum = 0;
    for (int i: arr) {
        sum += i;
    }
    std::cout << sum;
    return 0;
}

///////////////////////////////////////
// 5. Using valarray sum() function:
#include <iostream>
#include <valarray>
 
int main()
{
    int arr[] = { 5, 3, 7, 9, 2 };
    int n = sizeof(arr) / sizeof(int);
 
    std::valarray<int> valarray (arr, n);
    std::cout << valarray.sum();
 
    return 0;
}

///////////////////////////////////////
// 6. C++17 – Fold Expressions:

#include <iostream>

template<typename ...T>
auto sum(T ...args) {
    return (args + ...);
}

int main()
{
    std::cout << sum( 5, 3, 7, 9, 2 ); 
    return 0;
}
