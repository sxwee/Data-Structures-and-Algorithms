#include <iostream>
#include <vector>

using namespace std;

/*
 * 暴力法：时间复杂度为O(mn)，m和n分别为模式串和查找串的长度
 */
int pattern_search(string s, string t)
{
    int n = s.length(), m = t.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        for (; j < m; j++)
        {
            if (s[i + j] != t[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

vector<int> get_next(string t)
{
    int m = t.length();
    vector<int> next(m, 0);
    next[0] = -1;
    for (int j = 1; t[j]; j++)
    {
        int k = next[j - 1];
        while (k != -1 && t[j - 1] != t[k])
            k = next[k];
        next[j] = k + 1;
    }
    return next;
}

int kmp_search(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<int> next = get_next(t);
    int i, j;
    i = j = 0;
    while(s[i] && (j == -1 || t[j]))
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j == m)
        return i - j;
    return -1;
}

int main()
{
    string s = "ABADBCDEADB", t = "ADB";
    cout << pattern_search(s, t) << endl; // 2
    cout << kmp_search(s, t) << endl; // 2
    return 0;
}