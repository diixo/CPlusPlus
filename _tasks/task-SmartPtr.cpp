
class RefCounter
{
private:
   int count;
public:
   RefCounter() : count(1) {}
   void AddRef()
   {
      count++;
   }

   int DelRef()
   {
      return --count;
   }
};

template <class T>
class UPtr
{
private:

   T*          pData;
   RefCounter* pRef;

public:

   UPtr() : pData(0), pRef(0) {}

   UPtr(T* pValue) : pData(pValue), pRef(new RefCounter()) {}

   ~UPtr()
   {
      if (pRef && pRef->DelRef() == 0)
      {
         delete pData;
         delete pRef;
      }
   }

   T& operator*()
   {
      return *pData;
   }

   T* operator->()
   {
      return pData;
   }

   T* get() const
   {
      return pData;
   }

   void reset(T* ptr)
   {
      if (pRef && pRef->DelRef() == 0)
      {
         delete pData;
         delete pRef;
      }
      pData = ptr;
      pRef = new RefCounter();
   }

   UPtr<T>& operator = (const UPtr<T>& sp)
   {
      if (this != &sp)
      {
         // Decrement the old reference count
         // if reference become zero delete the old data
         if (pRef && pRef->DelRef() == 0)
         {
            delete pData;
            delete pRef;
         }

         // Copy the data and reference pointer
         // and increment the reference count
         pData = sp.pData;
         pRef = sp.pRef;
         pRef->AddRef();
      }
      return *this;
   }
};


template <class T>
class UPtr<T[]>
{
public:
};


int main()
{
   return 0;
}
