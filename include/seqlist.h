
#include <iostream>
//using namespace std;
//顺序表类，T指定元素类型
template<class T>
class seqlist {
private:
    // 动态数组存储顺序表的数据元素
    T *element;
    int size;
    int len;

    void addLen();

public:
    seqlist(int size = 64);

    seqlist(T value[], int n);

    ~seqlist();

    bool IsEmpty();

    int Length();

    T Get(int i);

    bool Set(int i, T x);

    std::string ToString();

    bool Insert(int i, T x);

    bool Insert(T x);

    bool Remove(int i, T &old);

    void Clear();
};
