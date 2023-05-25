// https://learn.microsoft.com/ru-ru/cpp/cpp/constructors-cpp?view=msvc-170

// https://learn.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170

// The std::move function converts the lvalue other to an rvalue.

#include <iostream>
#include <algorithm>

class MemoryBlock
{
public:

   explicit MemoryBlock(size_t length)
      : _length(length)
      , _data(new int[length])
   {}

   ~MemoryBlock()
   {
      if (_data != nullptr)
      {
         delete[] _data;
      }
   }

   MemoryBlock(const MemoryBlock& other)
      : _length(other._length)
      , _data(new int[other._length])
   {
      std::copy(other._data, other._data + _length, _data);
   }

   MemoryBlock& operator=(const MemoryBlock& other)
   {
      if (this != &other)
      {
         delete[] _data;

         _length = other._length;
         _data = new int[_length];
         std::copy(other._data, other._data + _length, _data);
      }
      return *this;
   }

   size_t Length() const
   {
      return _length;
   }

private:
   size_t _length;  // The length of the resource.
   int* _data;      // The resource.
};

// Move constructor.
MemoryBlock(MemoryBlock&& other) noexcept
   : _data(nullptr)
   , _length(0)
{
   *this = std::move(other);
}

// Move constructor. The same:
/*
MemoryBlock(MemoryBlock&& other) noexcept
   : _data(nullptr)
   , _length(0)
{
   _data = other._data;
   _length = other._length;

   other._data = nullptr;
   other._length = 0;
}
*/

// Move assignment operator.
MemoryBlock& operator=(MemoryBlock&& other) noexcept
{
   if (this != &other)
   {
      delete[] _data;

      _data = other._data;
      _length = other._length;

      other._data = nullptr;
      other._length = 0;
   }
   return *this;
}

int main()
{
   // Create a vector object and add a few elements to it.
   vector<MemoryBlock> v;
   v.push_back(MemoryBlock(25));
   v.push_back(MemoryBlock(75));

   // Insert a new element into the second position of the vector.
   v.insert(v.begin() + 1, MemoryBlock(50));
}
