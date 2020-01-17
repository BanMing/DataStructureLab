//#include <SeqList.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void hello()
{
   vector<string> msg{"Hello", "33333333333C++", "World", "222222222from", "111111VS Code", " and the C++ extension!"};
   for (const string &word : msg)
   {
      cout << word << " ";
   }
   cout << endl;
}

//void seqListTest(int n, int s, int d)
//{
//   SeqList<int> jose(n);
//   int removeIndex = (n + s) % d;
//   while (jose.Length() > 1)
//   {
//   }
//}

int main()
{
   hello();
}