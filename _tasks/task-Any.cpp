#include <memory>

class HashBase
{
public:
   virtual intptr_t addr() = 0;
   virtual bool empty() = 0;
};

template <typename T>
class Hash : public HashBase
{
   using value_type = T;
   using type = Hash; // using injected-class-name

   static const int _addr = 0;

public:
   std::unique_ptr<T> value;
   Hash() = default;

   Hash(const T& v) : value(new T(v))
   {}

   intptr_t addr() override
   {
      return reinterpret_cast<intptr_t>(&_addr);
   }
   bool empty() override { return value == nullptr;  }
};

class Any
{
public:

   std::unique_ptr <HashBase> hashBase;

   template <typename T>
   Any& operator = (const T& t)
   {
      hashBase.reset(new Hash<T>(t));
      return *this;
   }

   template <typename T>
   bool is() const
   {
      if (hashBase && !hashBase->empty())
      {
         Hash<T> hash;
         return hash.addr() == hashBase->addr();
      }
      return 0;
   }

   template <typename T>
   T& as() const
   {
      //
   }
};

int main(int, char**)
{
   Any any;
   bool is = any.is<char>();
   any = (int)5;
   is = any.is<char>();
   if (any.is<int>())
   {
      auto value = any.as<int>();
   }
   return 0;
}
