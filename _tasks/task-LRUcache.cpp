

#include <iostream>
#include <map>
#include <list>

struct item
{
   int key;
   int value;
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
      //
   }

};


int main() 
{
   int value = 0;

   LRUcache cache(2);
   cache.put(1, 111);
   cache.put(2, 222);
   value = cache.get(1);       // returns 111
   cache.put(3, 33);           // evicts key 2
   value = cache.get(2);       // returns -1 (not found)
   cache.put(4, 44);           // evicts key 1
   value = cache.get(1);       // returns -1 (not found)
   value = cache.get(3);       // returns 3
   value = cache.get(4);       // returns 4

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
