
// https://learn.microsoft.com/ru-ru/cpp/cpp/function-call-cpp?view=msvc-140

typedef void(*ptf)();
void func()
{
}
struct S
{
   operator ptf()
   {
      return func;
   }
};

int main()
{
   S s;
   s();//operates as s.operator ptf()()
}
