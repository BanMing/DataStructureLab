#include <iostream>
#include <string>
// #include "include/hello.h"
#include "src/hello.cpp"
#include "src/some_test.cpp"
using namespace std;

int main()
{
    hello hello;
    hello.Say();

    VectorTest();
}
