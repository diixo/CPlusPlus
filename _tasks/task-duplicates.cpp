
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template <class ForwardIterator>
ForwardIterator unique(ForwardIterator first, ForwardIterator last)
{
   if (first == last) return last;

   ForwardIterator result = first;
   while (++first != last)
   {
      if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
         *(++result) = *first;
   }
   return ++result;
}

int main(int, char**)
{
   int src[]{ 1, 2, 2, 2, 6, 5, 5, 4, 1 };

   // 1-st solution:
   {
      std::vector<int> dest(std::begin(src), std::end(src));

      dest.erase(std::unique(dest.begin(), dest.end()), end(dest));

      for (int i : dest)
      {
         std::cout << i << " ";
      }
   }

   // 2-nd solution:
   {
      std::vector<int> dest(
         std::begin(src), 
         std::unique(std::begin(src), std::end(src))
         );

      for (int i : dest)
      {
         std::cout << i << " ";
      }
   }
   return 0;
}
