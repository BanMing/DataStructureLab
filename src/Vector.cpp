/******************************************************************
** 文件名: Vector.cpp
** 创建人: BanMing
** 日  期: 9/1/2020, 8:27:59 PM
** 描  述:

**************************** 修改记录 ******************************
** 修改人:
** 日  期:
** 描  述:
*******************************************************************/

#include "Vector.h"

namespace my_stl
{

    // constructor
    template<class T>
    Vector<T>::Vector(size_t initSize)
        :theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
    {
        this->datas = new T[theCapacity];
    }

    // copy constructor 
    template<class T>
    Vector<T>::Vector(const T& rhs)
        :theSize{ rhs.theSize }, datas{ nullptr }
    {
        datas = new T[theCapacity];
        for (size_t i = 0; i < theSize; i++)
        {
            datas[i] = rhs.datas[i];
        }
    }

    template<class T>
    Vector<T>::Vector(T&& rhs) :theCapacity{ rhs.theSize },
        theSize{ rhs.theCapacity }, datas{ rhs.datas } {
        rhs.datas = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    template<class T>
    T& Vector<T>::operator=(const T& rhs) {
        T copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    template<class T>
    T& Vector<T>::operator=(T&& rhs) {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(datas, rhs.datas);

        return *this;
    }

    template<class T>
    Vector<T>::~Vector() {
        delete[] datas;
    }

    template<class T>
    size_t Vector<T>::size()const {
        return this->theSize;
    }

    template<class T>
    void Vector<T>::clear() {
        for (size_t i = 0; i < this->theCapacity;i++)
        {
            this->datas[i] = nullptr;
        }

        this->theCapacity = 0;
    }

    template<class T>
    bool Vector<T>::empty() const {
        return this->size() == 0;
    }

    template<class T>
    void Vector<T>::push_back(const T& x) {
        if (this->theCapacity == this->theSize)
        {
            this->reserve(2 * this->theCapacity + 1);
        }

        this->datas[this->theSize] = x;
        this->theSize++;
    }

    template<class T>
    void Vector<T>::pop_back() {
        this->theSize--;
    }

    template<class T>
    const T& Vector<T>::back() const {
        return this->datas[this->theSize - 1];
    }

    template<class T>
    const T& Vector<T>::front() const {
        return this->datas[0];
    }


    template<class T>
    T& Vector<T>::operator[](int index) {
        return this->datas[index];
    }

    template<class T>
    const T& Vector<T>::operator[](int index) const {
        return this->datas[index];
    }

    template<class T>
    T& Vector<T>::at(int idx) {
        if (idx < 0 || idx >= this->theCapacity)
        {
            return nullptr;
        }
        return this->datas[idx];
    }

    template<class T>
    int Vector<T>::capacity() const {
        return this->theCapacity;
    }

    template<class T>
    void Vector<T>::reserve(int newCapacity) {
        if (newCapacity < theSize)
        {
            return;
        }

        T* newArray = new T[newCapacity];
        for (size_t i = 0; i < theSize; i++)
        {
            newArray[i] = std::move(datas[i]);
        }

        theCapacity = newCapacity;
        std::swap(datas, newArray);
        delete[] newArray;

    }

    template<class T>
    void Vector<T>::resize(int newSize) {
        if (newSize > theCapacity) {
            reserve(newSize * 2);
        }
        theSize = newSize;
    }
} // namespace my_stl
