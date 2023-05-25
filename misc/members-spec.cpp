
class BaseClass
{
    virtual void func();

    virtual void func2() const;
};

class DerivedClass: public BaseClass
{
    virtual void func() override; // ok

    virtual void func2() override; // compiler error: DerivedClass::funcB() does not
                                   // override BaseClass::funcB() const;

};
