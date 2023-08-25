
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
   {}

   CBoolVector(const CBoolVector& boolVector)
      : mMemory(0)
      , mBoolCapacity(boolVector.mBoolCapacity)
   {
      if (mBoolCapacity)
      {
         const size_t sz = boolVector.size() / 8 + 1;
         mMemory = new unsigned char[sz];
         memcpy(mMemory, boolVector.mMemory, sz);
      }
   }

   void push_back(bool value)
   {
      const size_t new_sz = mBoolCapacity + 1;
      if (mBoolCapacity % 8 == 0)
      {
         unsigned char* newMemory = new unsigned char[new_sz / 8 + 1];

         if (mMemory)
         {
            memcpy(newMemory, mMemory, mBoolCapacity / 8);
            memset(&newMemory[new_sz / 8], 0, 1);
            delete[] mMemory;
         }

         mMemory = newMemory;
      }
      ++mBoolCapacity;

      set(value, mBoolCapacity - 1);
   }

   bool get(const size_t id) const
   {
      const unsigned char* bptr = &mMemory[id / 8];
      unsigned char result = *bptr & static_cast<unsigned char>(1 << (id % 8));
      return (result != 0);
   }

   void set(bool value, size_t id) const
   {
      unsigned char* bptr = &mMemory[id / 8];

      // set
      if (value)
      {
         *bptr |= unsigned char(1 << (id % 8));
      }
      // reset
      else
      {
         *bptr &= ~(unsigned char(1 << (id % 8)));
      }
   }

   size_t size() const
   {
      return mBoolCapacity;
   }

   ~CBoolVector()
   {
      if (mMemory) delete[] mMemory;
   }

   //////////////////////////////////////////////////////////////////////////

   class CRef
   {
      CRef();

   public:

      const CBoolVector& mVector;
      size_t mId;

      CRef(const CBoolVector& boolVec, size_t id)
         : mVector(boolVec)
         , mId(id)
      {}

      CRef& operator = (const bool value)
      {
         mVector.set(value, mId);
         return *this;
      }

      operator bool() const
      {
         return mVector.get(mId);
      }
   };

   //////////////////////////////////////////////////////////////////////////

   const CRef operator[](size_t id) const
   {
      return CRef(*this, id);
   }

   CRef operator[](size_t id)
   {
      return CRef(*this, id);
   }

};

int main()
{
   CBoolVector bv;

   bool b = true;
   bv.push_back(b);

   bv[0] = true;
   bv[5] = true;

   b = bv[0];
   b = bv[5];

   return 0;
}
