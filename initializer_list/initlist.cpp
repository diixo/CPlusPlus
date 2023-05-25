
#include <initializer_list>
#include <iostream>
#include <string>
using namespace std;

class Box
{
    initializer_list<string> m_contents;
    int m_width = 0;
    int m_height = 0;
    int m_length = 0;

Box(initializer_list<string> list, int w = 0, int h = 0, int l = 0)
        : m_contents(list), m_width(w), m_height(h), m_length(l)
{   
}
};
