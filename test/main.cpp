#include <ysLog.hpp>
#include <iostream>

class A
{
public:
    A() { YS::Log::log("Create Class A"); }
    ~A() { YS::Log::log("Destroy Class A"); }
};

void FuncA()
{
    YS::Log::log("This is FuncA!");
}

void FuncB()
{
    FuncA();
    YS::Log::log("This is FuncB!");
}

int main()
{
    A a;
    FuncA();
    FuncB();
}