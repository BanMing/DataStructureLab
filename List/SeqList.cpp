#include <iostream>
// using namespace std;
//顺序表类，T指定元素类型
template <class T>
class SeqList
{
private:
    // 动态数组存储顺序表的数据元素
    T *element;
    int size;
    int len;
    void addLen();

public:
    SeqList(int size = 64);
    SeqList(T value[], int n);
    ~SeqList();
    bool IsEmpty();
    int Length();
    T Get(int i);
    bool Set(int i, T x);
    friend std::ostream &operator<<(std::ostream &out, SeqList<T> &list);
    bool Insert(int i, T x);
    bool Insert(T x);
    bool Remove(int i, T &old);
    void Clear();
};

// 增加长度
template <class T>
void SeqList<T>::addLen()
{
    this->size *= 2;
    T *newElement = new T[this->size];
    for (int i = 0; i < this->len; i++)
    {
        newElement[i] = this->element[i];
    }
    this->element = newElement;
}

// 按长度初始化顺序表
template <class T>
SeqList<T>::SeqList(int size)
{
    this->size = size < 64 ? 64 : size;
    this->element = new T[this->size];
    this->len = 0;
}

// 复制一个数组到顺序表
template <class T>
SeqList<T>::SeqList(T value[], int size)
{
    if (size > 0)
    {
        this = new SeqList(size);
        for (int i = 0; i < size; i++)
        {
            this->element[i] = value[i];
        }
    }
}

//  析构函数
template <class T>
SeqList<T>::~SeqList()
{
    delete[] this->element();
    this->size = 0;
    this->len = 0;
}

// 判断顺序表是否为空
template <class T>
bool SeqList<T>::IsEmpty()
{
    return this->len == 0;
}

// 顺序表长度
template <class T>
int SeqList<T>::Length()
{
    return this->len;
}

// 获得一个元素根据index
template <class T>
T SeqList<T>::Get(int index)
{
    if (index >= len)
    {
        return NULL;
    }
    return this->element[index];
}

// 设置一个元素到顺序表
template <class T>
bool SeqList<T>::Set(int index, T x)
{
    if (index >= len)
    {
        return false;
    }
    this->element[index] = NULL;
    this->element[index] = x;
    return true;
}

// 输出每个元素
template <class T>
std::ostream &operator<<(std::ostream &out, SeqList<T> &list)
{
    out << "(";
    for (int i = 0; i < list->len; i++)
    {
        out << "," << list->element[i];
    }
    out << ")\n";
    return out;
}

// 插入一个特定元素到特定位置
template <class T>
bool SeqList<T>::Insert(int index, T x)
{
    if (index >= len)
    {
        return false;
    }
    if (this->len == this->size)
    {
        this->addLen();
    }
    // 防错处理
    index = index < 0 ? 0 : index;
    index = index > this->len ? this->len : index;

    for (int i = this->len - 1; i > index; i--)
    {
        this->element[i] = this->element[i - 1];
    }
    this->element[index] = x;

    this->len += 1;
}

// 插入最后一个位置
template <class T>
bool SeqList<T>::Insert(T x)
{
    if (this->len == this->size)
    {
        this->addLen();
    }

    this->element[this->len] = x;
    this->len += 1;
}

// 清空
template <class T>
void SeqList<T>::Clear()
{
    delete[] this->element;
    this->size = 0;
    this->len = 0;
}