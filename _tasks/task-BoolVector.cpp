
#include <iostream>

class CBoolVector
{
protected:

   unsigned char* mMemory;
   size_t mBoolCapacity;

public:

   CBoolVector()
      : mMemory(0)
      , mBoolCapacity(0)
   {
   }

   CBoolVector(const CBoolVector& boolVector)
      : mMemory(0)
      , mBoolCapacity(boolVector.mBoolCapacity)
   {
      if (mBoolCapacity)
      {
         const size_t sz = boolVector.size() / 8 + 1;
         mMemory = new unsigned char [sz];
         memcpy(mMemory, boolVector.mMemory, sz);
      }
   }

   void push_back(bool value)
   {
      const size_t new_sz = mBoolCapacity + 1;
      if (mBoolCapacity % 8 == 0)
      {
         unsigned char* newMemory = new unsigned char[new_sz/8 + 1];

         if (mMemory)
         {
            memcpy(newMemory, mMemory, mBoolCapacity / 8);
            memset(&newMemory[new_sz/8], 0, 1);
            delete[] mMemory;
         }

         mMemory = newMemory;
      }
      ++mBoolCapacity;
      if (value)
         set(mBoolCapacity-1);
      else
         reset(mBoolCapacity-1);
   }

   bool get(const size_t id) const
   {
      const unsigned char* bptr = &mMemory[id / 8];
      unsigned char result = *bptr & static_cast<unsigned char>(1 << (id % 8));
      return (result != 0);
   }

   void set(size_t id) const
   {
      unsigned char* bptr = &mMemory[id / 8];

      *bptr |= unsigned char(1 << (id % 8));
   }

   void reset(size_t id) const
   {
      unsigned char* bptr = &mMemory[id / 8];

      *bptr &= ~(unsigned char(1 << (id % 8)));
   }

   size_t size() const
   {
      return mBoolCapacity;
   }

   ~CBoolVector()
   {
      if (mMemory) delete[] mMemory;
   }

};

