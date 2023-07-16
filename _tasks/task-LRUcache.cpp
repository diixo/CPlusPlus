

#include <iostream>
#include <map>
#include <list>

struct item
{
   int key;
   int value;

   item() = default;
   item(const item&) = default;
   item& operator=(const item&) = default;

   ~item() { std::cout << "~dtor\n"; }
};

class LRUcache
{
   int mSize;

   std::map<int, std::list<item>::iterator> mMap;

   std::list<item> mDeque;

public:

   LRUcache(int sz) : mSize(sz) {}

   int get(int key)
   {
      auto iter = mMap.find(key);
      if (iter == mMap.end())
      {
         return -1;
      }

      auto itm = *(iter->second);
      mDeque.erase(iter->second);

      //////////////////////////////////////////////////////////////////////////
      mDeque.push_front(itm);
      mMap[key] = mDeque.begin();
      return itm.value;
   }

   void put(int key, int value)
   {
      auto iter = mMap.find(key);

      // push new item
      if (iter == mMap.end())
      {
         if (mDeque.size() == mSize)
         {
            mMap.erase(mDeque.back().key);
            mDeque.pop_back();
         }
         
         mDeque.push_front(item{ key, value });
         mMap[key] = mDeque.begin();
      }
      else
      {
         // rewrite exist item with new value
         mDeque.erase(iter->second);
         mDeque.push_front(item{ key, value });
         iter->second = mDeque.begin();
      }
   }

   std::list <item>::const_iterator begin() const
   {
      return mDeque.begin();
   }

   std::list <item>::const_iterator end() const
   {
      return mDeque.end();
   }
};

int main()
{
   int value = 0;

   LRUcache lru(3);
   value = lru.get(0);

   lru.put(1, 111);
   lru.put(2, 222);
   lru.put(3, 333);

   value = lru.get(2);

   lru.put(4, 444);

   for (auto& i: lru)
   {
      printf("%d : %d\n", i.key, i.value);
   }

   //////////////////////////////////////////////////////////////////////////

   LRUcache cache(2);
   cache.put(1, 11);
   cache.put(2, 22);
   value = cache.get(1);       // returns 11
   cache.put(3, 33);           // evicts key 2
   value = cache.get(2);       // returns -1 (not found)
   cache.put(4, 44);           // evicts key 1
   value = cache.get(1);       // returns -1 (not found)
   value = cache.get(3);       // returns 33
   value = cache.get(4);       // returns 44


   return 0;
}


// https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU

/*
LRUCache cache = new LRUCache( 2 );
cache.put(1, 111);
cache.put(2, 222);
cache.get(1);       // returns 111
cache.put(3, 333);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 444);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 333
cache.get(4);       // returns 444
*/
