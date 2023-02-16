#include <iostream>

template <class T>
class queue
{
public:
    int f;     // 对头指针，指向对头之前的位置
    int r;     // 队尾指针，指向队尾元素
    int count; // 统计队列中元素的个数
    T *data;   // 队列元素数组
    int cap;   // 队列容量
public:
    queue(int n);
    ~queue();
    void push(T e);
    T front();
    void pop();
    bool empty();
    int size();
};

template <class T>
queue<T>::queue(int n)
{
    cap = n;
    f = r = -1;
    count = 0;
    data = new T[n];
}

template <class T>
queue<T>::~queue()
{
    delete[] data;
    data = nullptr;
}

template <class T>
T queue<T>::front()
{
    if (count == 0)
    {
        throw "No emements in queue";
    }
    return data[(f + 1) % cap];
}

template <class T>
void queue<T>::push(T e)
{
    if (count == cap)
    {
        throw "queue is full";
    }
    r = (r + 1) % cap;
    data[r] = e;
    count++;
}

template <class T>
void queue<T>::pop()
{
    if (count == 0)
    {
        std::cout << "queue is already empty" << std::endl;
        return;
    }
    f = (f + 1) % cap;
    count--;
}

template <class T>
bool queue<T>::empty()
{
    return count == 0;
}

template <class T>
int queue<T>::size()
{
    return count;
}
