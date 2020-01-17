#include <iostream>
#include <string>
#include <vector>
#include "src\seqlist.cpp"

using namespace std;

void hello() {
    vector<string> msg{"Hello", "33333333333C++", "World", "222222222from", "111111VS Code", " and the C++ extension!"};
    for (const string &word : msg) {
        cout << word << " ";
    }
    cout << endl;
}

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
    printf("left index: %c\n",jose.Get(0));
}

int main() {
    seqListTest(5, 1, 2);
}
