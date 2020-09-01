/******************************************************************
** 文件名: some_test.cpp
** 创建人: BanMing 
** 日  期: 8/5/2020, 8:03:41 AM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void VectorTest()
{
    vector<int> squares(100);

    for (int i = 0; i < squares.size(); i++)
    {
        squares[i] = i * i;
    }

    for (int i = 0; i < squares.size(); i++)
    {
        cout << i << " " << squares[i] << endl;
    }
    int sum = 0;
    for (int x : squares)
    {
        sum += x;
    }
    cout << sum << endl;
    vector<int> test{11, 23, 4, 5};
}

template <typename Compareable>
const Compareable &findMax(const vector<Compareable> &a)
{
    int maxIndex = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[maxIndex] < a[i])
        {
            maxIndex = i;
        }
    }
    return a[maxIndex];
}

template <typename Object>
class MemoryCell
{
private:
    Object storedValue;

public:
    explicit MemoryCell(const Object &initialValue = Object{}) : storedValue{initialValue} {}
    const Object &read() const { return storedValue; }
    void write(const Object &x) { storedValue = x; }
};

int getbanaryNum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return getbanaryNum(n / 2) + 1;
}

void permute(const string &str)
{
    // permute(str, 0, str.size());
}

void permute(const string &str, int low, int high)
{
    if (low == high)
    {
        return;
    }
    cout << str << endl;
    permute(str, low + 1, high - 1);
}