
int foo(int)
{
    return 0;
}

int (*fp)(int) = foo;

auto result = fp(256);

//////////////////////

