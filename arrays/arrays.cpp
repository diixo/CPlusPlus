
void do_something(size_t size)
{
    // init first element
    double* numbers = new double[size]{ 0 };

    delete [] numbers;
}

int myArr1[]{ 1, 2, 3, 4 };
int myArr2[3] = { 5, 6, 7 };
int myArr3[5] = { 8, 9, 10 };
///////////////////////////////////////////////

struct MyStruct {
    int myInt;
    char myChar;
};
int main() {
    int intArr1[2][2]{{ 1, 2 }, { 3, 4 }};
    int intArr3[2][2] = {1, 2, 3, 4};
    MyStruct structArr[]{ { 1, 'a' }, { 2, 'b' }, {3, 'c'} };
}
/////////////////////////////////////////////////