#include <iostream>
#include <string>
//#include "src/seqlist.cpp"
#include "hello.h"
#include "src/seqlist.cpp"
using namespace std;


void seqListTest(int n, int s, int d) {
    seqlist<char> jose = seqlist<char>(n);
    for (int i = 0; i < n; ++i) {
        jose.Insert(i);
    }
    cout << jose.ToString() << endl;
    while (jose.Length() > 2) {
        int removeIndex = (s + d - 1) % n;
        char oldVal = 0;
        jose.Remove(removeIndex, oldVal);
        printf("remove index: %d\n", oldVal);
        s = (removeIndex + 1) % n;
    }
    printf("left index: %c\n", jose.Get(0));
}

int main() {
    seqListTest(5, 1, 2);
    hello hello;
    hello.Say();
}
