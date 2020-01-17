#include "seqlist.h"

// 增加长度
template<class T>
void seqlist<T>::addLen() {
    this->size *= 2;
    T *newElement = new T[this->size];
    for (int i = 0; i < this->len; i++) {
        newElement[i] = this->element[i];
    }
    this->element = newElement;
}

// 按长度初始化顺序表
template<class T>
seqlist<T>::seqlist(int size) {
    this->size = size < 64 ? 64 : size;
    this->element = new T[this->size];
    this->len = 0;
}

// 复制一个数组到顺序表
template<class T>
seqlist<T>::seqlist(T value[], int size) {
    if (size > 0) {
        this = new seqlist(size);
        for (int i = 0; i < size; i++) {
            this->element[i] = value[i];
        }
    }
}

//  析构函数
template<class T>
seqlist<T>::~seqlist() {
    delete (this->element);
    this->size = 0;
    this->len = 0;
}

// 判断顺序表是否为空
template<class T>
bool seqlist<T>::IsEmpty() {
    return this->len == 0;
}

// 顺序表长度
template<class T>
int seqlist<T>::Length() {
    return this->len;
}

// 获得一个元素根据index
template<class T>
T seqlist<T>::Get(int index) {
    if (index >= len) {
        return NULL;
    }
    return this->element[index];
}

// 设置一个元素到顺序表
template<class T>
bool seqlist<T>::Set(int index, T x) {
    if (index >= len) {
        return false;
    }
    this->element[index] = NULL;
    this->element[index] = x;
    return true;
}

// 插入一个特定元素到特定位置
template<class T>
bool seqlist<T>::Insert(int index, T x) {
    if (index >= len) {
        return false;
    }
    if (this->len == this->size) {
        this->addLen();
    }
    // 防错处理
    index = index < 0 ? 0 : index;
    index = index > this->len ? this->len : index;

    for (int i = this->len - 1; i > index; i--) {
        this->element[i] = this->element[i - 1];
    }
    this->element[index] = x;

    this->len += 1;
    return true;
}

// 输出每个元素
template<class T>
string seqlist<T>::ToString() {
    string res = "";
    for (int i = 0; i < this->len; ++i) {
        res += to_string(this->element[i]) + "\t";
    }
    return res;
}

// 插入最后一个位置
template<class T>
bool seqlist<T>::Insert(T x) {
    if (this->len == this->size) {
        this->addLen();
    }

    this->element[this->len] = x;
    this->len += 1;
    return true;
}

//删除一个元素
template<class T>
bool seqlist<T>::Remove(int index, T &old) {
    if (index < 0 || index > this->len) {
        return false;
    }
    this->len--;
    old = this->element[index];
    for (int i = index; i < this->len; ++i) {
        this->element[i] = this->element[i + 1];
    }
    return true;
}

// 清空
template<class T>
void seqlist<T>::Clear() {
    delete (this->element);
    this->size = 0;
    this->len = 0;
}
