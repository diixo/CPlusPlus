
#include <set>

///////////////////////////////////////////
// 1. Modern C++20 solution:

auto cmp = [](int a, int b) { return ...; };
std::set<int, decltype(cmp)> s;

///////////////////////////////////////////
// 2. Modern C++11 solution:

auto cmp = [](int a, int b) { return ...; };
std::set<int, decltype(cmp)> s(cmp);

///////////////////////////////////////////
// 3. Similar to first solution, but with function instead of lambda:

bool cmp(int a, int b) {
    return false;
}

// Then use it, either this way:
std::set<int, decltype(cmp)*> s(cmp);

// or this way:
std::set<int, decltype(&cmp)> s(&cmp);

///////////////////////////////////////////
// 4. Old solution using struct with () operator:
struct cmp {
    bool operator() (int a, int b) const {
        return ...;
    }
};

// ...
// later
std::set<int, cmp> s;

