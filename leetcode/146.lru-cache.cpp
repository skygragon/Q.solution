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
    typedef struct ListNode {
        int k, v;
        ListNode *prev, *next;

        ListNode(int _k = 0, int _v = 0) : k(_k), v(_v) {}
    } ListNode;

    ListNode head;
    unordered_map<int, ListNode*> m;
    int cap, cur;

    LRUCache(int capacity) {
        cap = capacity; cur = 0;
        head.next = head.prev = &head;
    }
    
    int get(int key) {
        ListNode *p = m[key];
        if (!p) return -1;

        remove(p); insert(p);
        return p->v;
    }
    
    void put(int key, int value) {
        ListNode* p = m[key];
        if (!p) {
            p = new ListNode(key, value);
            insert(p);
            m[key] = p;
        } else {
            p->v = value;
            remove(p); insert(p);
        }
    }

    ListNode* remove(ListNode *p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = p->next = NULL;
        --cur;
        return p;
    }

    void insert(ListNode *p) {
        p->next = head.next;
        p->prev = &head;
        head.next->prev = p;
        head.next = p;
        ++cur;

        while (cur > cap) {
            ListNode *p = remove(head.prev);
            m.erase(p->k);
            delete p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
