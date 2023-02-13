#include <iostream>
#include <cassert>

template <class T>
class stack
{
private:
    int cap;   // 栈的容量
    int rsize; // 栈的实际大小
    int pt;    // 栈顶元素下标
    T *elems;

public:
    stack();
    stack(int n);
    ~stack();
    bool empty();   // 判断是否栈空
    void push(T e); // 入栈
    void pop();     // 栈顶元素出栈
    T top();        // 获取栈顶元素
    int size();     // 获取堆栈的实际元素数
};

template <class T>
stack<T>::stack()
{
    rsize = cap = 0;
    elems = nullptr;
    pt = -1;
}

template <class T>
stack<T>::stack(int n)
{
    rsize = 0;
    cap = n;
    pt = -1;
    this->elems = new T[n];
    assert(this->elems != nullptr);
}

template <class T>
stack<T>::~stack()
{
    delete[] this->elems;
    this->elems = nullptr;
}

template <class T>
bool stack<T>::empty()
{
    return pt == -1;
}

template <class T>
void stack<T>::push(T e)
{
    if (pt >= cap - 1)
    {
        std::cout << "stack is full" << std::endl;
        return;
    }
    else
    {
        rsize++;
        elems[++pt] = e;
    }
}

template <class T>
void stack<T>::pop()
{
    if (pt == -1)
    {
        std::cout << "stack is empty" << std::endl;
    }
    else
    {
        rsize--;
        pt--;
    }
}

template <class T>
T stack<T>::top()
{
    return elems[pt];
}

template<class T>
int stack<T>::size()
{
    return rsize;
}