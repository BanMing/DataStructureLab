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