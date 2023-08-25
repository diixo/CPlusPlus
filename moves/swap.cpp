// https://habr.com/ru/articles/568306/

// std::move vs. std::forward

template<class T>
class vector {
    // ...
    vector(const vector&);            // copy constructor
    vector(vector&&) noexcept;        // move constructor
    vector& operator=(const vector&); // copy assignment
    vector& operator=(vector&&);      // move assignment
};

template<class T>
void swap(T& a, T& b)
{
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

// Функция std::move не выполняет никаких перемещений, она выполняет приведение типа к rvalue-ссылке
/*
template<typename T>
T&& forward(T&& param)
{
    if (is_lvalue_reference<T>::value)
        return param;
    else
        return move(param);
}
*/
