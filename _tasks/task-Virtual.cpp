
#include <iostream>
#include <memory>

// memset(this, 0, sizeof(*this))

using namespace std;

class A
{
public:

   virtual void f(int i = 1) = 0;
};

class B : public A
{
public:

   virtual void f(int i = 2)
   {
      cout << "B::f " << i << endl;
   }
};

class C : public B
{
public:

   virtual void f(int i = 4)
   {
      cout << "C::f " << i << endl;
   }
};

class D : public C
{
public:

   virtual void f(int i = 8)
   {
      cout << "D::f " << i << endl;
   }
};


int main()
{
   unique_ptr<A> pB(new B());
   unique_ptr<A> pC(new C());
   unique_ptr<A> pD(new D());

   pB->f();
   pC->f();
   pD->f();

   return 0;
}
