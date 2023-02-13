#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    int n = 5;
    stack<int> s(n);
    s.push(3);
    s.push(5);
    s.push(1);
    cout << "size of stack: " << s.size() << endl; // size of stack: 3
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl; // 1 5 3
    return 0;
}