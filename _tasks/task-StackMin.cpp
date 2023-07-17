
#include <stack>
#include <algorithm>

// Stack, that always return min-value by constant time.

struct CMinStack 
{
   std::stack<int> mStack;
   std::stack<int> mMin;

   void push(int x)
   {
      if (mMin.empty())
      {
         mMin.push(x);
      }
      else
         mMin.push(std::min(x, mMin.top()));

      mStack.push(x);
   }

   void pop() 
   {
      mStack.pop();
      mMin.pop();
   }

   int top() {
      return mStack.top();
   }

   int getMin() 
   {
      return mMin.top();
   }
};
