/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache
 *
 * Hard (16.50%)
 * Total Accepted:    113863
 * Total Submissions: 689686
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity / );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
public:
    struct Node {
        int k, v;
        Node(int _k = 0, int _v = 0) : k(_k), v(_v) {}
    };

    list<Node> nodes;
    unordered_map<int, list<Node>::iterator> m;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;

        nodes.splice(nodes.begin(), nodes, m[key]);
        m[key] = nodes.begin();
        return m[key]->v;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it == m.end()) {
            if (nodes.size() == capacity) {
                auto last = nodes.back();
                nodes.pop_back();
                m.erase(last.k);
            }
            nodes.push_front(Node(key, value));
            m[key] = nodes.begin();
        } else {
            get(key);
            m[key]->v = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
