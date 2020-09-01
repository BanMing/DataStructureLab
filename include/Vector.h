/******************************************************************
** 文件名: Vector.h
** 创建人: BanMing
** 日  期: 9/1/2020, 8:26:33 PM
** 描  述:

**************************** 修改记录 ******************************
** 修改人:
** 日  期:
** 描  述:
*******************************************************************/
#include <iostream>
#ifndef Vector_H
#define Vector_H

namespace my_stl
{
    template<class T>
    class Vector
    {
    private:
        size_t theSize;
        size_t theCapacity;
        T* datas;
    public:
        static const int SPARE_CAPACITY = 16;

        explicit Vector(size_t initSize);

        Vector(const T& rhs);

        Vector(T&& rhs);

        T& operator=(const T& rhs);
        T& operator=(T&& rhs);

        ~Vector();

        // common methods
        size_t size() const;

        void clear();

        bool empty() const;

        void push_back(const T& x);

        void pop_back();

        const T& back()const;

        const T& front() const;

        // specail methods
        T& operator [](int idx);

        const T& operator[](int index) const;

        T& at(int idx);

        int capacity() const;

        void reserve(int newCapacitty);

        void resize(int newSize);

        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin() { return &datas[0]; };

        iterator end() { return &datas[size()]; };;

        const_iterator begin() const { return &datas[0]; };;

        const_iterator end() const { return &datas[size()]; };;
    };

} // namespace my_stl

#endif
