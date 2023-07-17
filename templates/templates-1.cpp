// https://learn.microsoft.com/ru-ru/cpp/cpp/templates-cpp?view=msvc-140

// https://learn.microsoft.com/ru-ru/cpp/cpp/typename?view=msvc-140

template<typename... Arguments> class vtclass;

vtclass< > vtinstance1;
vtclass<int> vtinstance2;
vtclass<float, bool> vtinstance3;

/////////////////////////////////////////////////////////////////////////
// specialization:

template <typename K, typename V>
class MyMap{/*...*/};

// partial specialization for string keys
template<typename V>
class MyMap<string, V> {/*...*/};
...
MyMap<int, MyClass> classes; // uses original template
MyMap<string, MyClass> classes2; // uses the partial specialization

///////////////////////////////////////////////////////////////////////////

template <class T>
class C1 : typename T::InnerType // Error - typename not allowed.
{};
template <class T>
class C2 : A<typename T::InnerType>  // typename OK.
{};

/////////////////////////////////////////////////////////////////////////////

// typename.cpp
template<class T> class X
{
   typename T::Y m_y;   // treat Y as a type
};

int main()
{
}
