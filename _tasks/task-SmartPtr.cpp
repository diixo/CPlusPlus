
class RefCounter
{
private:
   int count;
public:
   void AddRef()
   {
      count++;
   }

   int Release()
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

   UPtr(T* pValue) : pData(pValue)
   {}

   ~UPtr()
   {
      if (pRef->Release() == 0)
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

   UPtr<T>& operator = (const UPtr<T>& sp)
   {
      if (this != &sp)
      {
         // Decrement the old reference count
         // if reference become zero delete the old data
         if (pRef->Release() == 0)
         {
            delete pData;
            delete reference;
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
