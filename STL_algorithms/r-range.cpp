
#include <iostream>
#include <utility>
#include <stdexcept>

template<typename T, bool reverse = false> struct Range final
{
    struct Iterator final
    {
        T value;
        Iterator(const T & v) : value(v) {}
        const Iterator & operator++() { reverse ? --value : ++value; return *this; }
        bool operator!=(const Iterator & o) { return o.value != value; }
        T operator*() const { return value; }
    };
    T begin_, end_;
    Range(const T & b, const T & e)  : begin_(b), end_(e) {
        if(b > e) throw std::out_of_range("begin > end");
    }

    Iterator begin() const { return reverse ? end_ -1 : begin_; }
    Iterator end() const { return reverse ? begin_ - 1: end_; }

    Range() = delete;
    Range(const Range &) = delete;
};

using UIntRange = Range<unsigned, false>;
using RUIntRange = Range<unsigned, true>;

int main()
{
    std::cout << "Reverse : ";
    for(auto i : RUIntRange(0, 10)) std::cout << i << ' ';
    std::cout << std::endl << "Normal : ";
    for(auto i : UIntRange(0u, 10u)) std::cout << i << ' ';
    std::cout << std::endl;
}
