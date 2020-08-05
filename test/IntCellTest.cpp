/******************************************************************
** 文件名: IntCellTest.cpp
** 创建人: BanMing 
** 日  期: 8/5/2020, 10:15:29 PM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
class IntCell1
{
private:
    int *storedValue;

public:
    explicit IntCell1(int initalValue = 0)
    {
        storedValue = new int{initalValue};
    };

    int read() const
    {
        return *storedValue;
    }

    void write(int x)
    {
        *storedValue = x;
    }
};

void Test1()
{
    // 这里都是浅拷贝，如果a销毁了，其他都没有了。
    IntCell1 a{2};
    IntCell1 b = a;
    IntCell1 c;

    c = b;
    a.write(4);
    std::cout << a.read() << b.read() << c.read() << std::endl;
}

class IntCell2
{
private:
    int *storedValue;

public:
    explicit IntCell2(int initalValue = 0)
    {
        storedValue = new int{initalValue};
    };

    ~IntCell2() { delete storedValue; }

    // 拷贝构造函数
    IntCell2(const IntCell2 &rhs)
    {
        storedValue = new int{*rhs.storedValue};
    }

    // 移动构造函数
    IntCell2(IntCell2 &&rhs) : storedValue{rhs.storedValue}
    {
        rhs.storedValue = nullptr;
    }

    // 拷贝赋值
    IntCell2 &operator=(const IntCell2 &rhs)
    {
        if (this != &rhs)
        {
            *storedValue = *rhs.storedValue;
        }
        return *this;
    }

    // 移动赋值
    IntCell2 &operator=(IntCell2 &&rhs)
    {
        std::swap(storedValue, rhs.storedValue);
        return *this;
    }

    int read() const
    {
        return *storedValue;
    }

    void write(int x)
    {
        *storedValue = x;
    }
};