// least recently used algorithm
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class LRUCache
{
private:
    int capacity;                                           // 缓存的最大容量
    list<pair<int, int>> cache;                             // 缓存
    unordered_map<int, list<pair<int, int>>::iterator> map; // 哈希表, 记录每个页面的存储位置
public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    int get(int key);

    void put(int key, int value);
};

int LRUCache::get(int key)
{
    if (map.count(key) > 0) // 数据页在缓存中存在
    {
        auto node = *map[key];
        cache.erase(map[key]);    // 将数据页从链表中删除
        cache.push_front(node);   // 将数据页移动到链表头部
        map[key] = cache.begin(); // 更新哈希表中该数据页的地址
        return node.second;
    }
    return -1; // 不存在直接返回-1
}

void LRUCache::put(int key, int value)
{
    if (map.count(key) > 0)
    {
        cache.erase(map[key]);
    }
    else if (capacity == cache.size()) // 缓存满, 删除链表尾部的结点
    {
        auto node = cache.back();
        map.erase(node.first);
        cache.pop_back();
    }
    cache.push_front({key, value}); // 将新结点放置的链表头部
    map[key] = cache.begin();
}

int main()
{
    LRUCache lru(3); // 创建缓存大小为3的LRU对象
    lru.put(0, 3);   // [(0, 3)]
    lru.put(1, 12);  // [(1, 12), (0, 3)]
    lru.put(2, 5);   // [(2,5), (1, 12), (0, 3)]
    lru.put(3, 9);   // [(3, 9), (2,5), (1, 12)]
    lru.put(1, 0);   // [(1, 0), (3, 9), (2, 5)]
    cout << lru.get(2) << endl; // 5
    return 0;
}