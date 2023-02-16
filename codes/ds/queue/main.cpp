#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    int n = 10;
    queue<double> q(n);
    q.push(1.1);
    q.push(2.2);
    q.push(3.3);
    cout << q.size() << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}