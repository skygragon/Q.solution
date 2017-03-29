/*
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed
 *
 * Hard (28.39%)
 * Total Accepted:    12145
 * Total Submissions: 42780
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n[[],[1],[1],[2],[],[1],[]]'
 *
 * Design a data structure that supports all following operations in average
 * O(1) time.
 * Note: Duplicate elements are allowed.
 * 
 * 
 * insert(val): Inserts an item val to the collection.
 * remove(val): Removes an item val from the collection if present.
 * getRandom: Returns a random element from current collection of elements. The
 * probability of each element being returned is linearly related to the number
 * of same value the collection contains.
 * 
 * 
 * 
 * Example:
 * 
 * // Init an empty collection.
 * RandomizedCollection collection = new RandomizedCollection();
 * 
 * // Inserts 1 to the collection. Returns true as the collection did not
 * contain 1.
 * collection.insert(1);
 * 
 * // Inserts another 1 to the collection. Returns false as the collection
 * contained 1. Collection now contains [1,1].
 * collection.insert(1);
 * 
 * // Inserts 2 to the collection, returns true. Collection now contains
 * [1,1,2].
 * collection.insert(2);
 * 
 * // getRandom should return 1 with the probability 2/3, and returns 2 with
 * the probability 1/3.
 * collection.getRandom();
 * 
 * // Removes 1 from the collection, returns true. Collection now contains
 * [1,2].
 * collection.remove(1);
 * 
 * // getRandom should return 1 and 2 both equally likely.
 * collection.getRandom();
 * 
 * 
 */
class RandomizedCollection {
public:
    vector<int> v, prev, next;
    unordered_map<int, int> index;

    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto it = index.find(val);
        int last = (it != index.end()) ? it->second : -1;

        int i = v.size();

        v.push_back(val);
        prev.push_back(last);
        next.push_back(-1);

        if (last != -1) next[last] = i;

        index[val] = i;
        return last == -1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = index.find(val);
        if (it == index.end()) return false;

        int i = it->second;
        int j = v.size()-1;

        swap(v[i], v[j]);
        swap(prev[i], prev[j]);
        swap(next[i], next[j]);

        if (i != j) {
            if (prev[i] != -1) next[prev[i]] = i;
            if (next[i] != -1) prev[next[i]] = i;
            else index[v[i]] = i;
        } else {
            index[v[i]] = prev[i];
        }

        if (prev[j] != -1) {
            index[val] = prev[j];
        } else {
            index.erase(val);
        }

        v.pop_back();
        prev.pop_back();
        next.pop_back();

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int i = rand() % v.size();
        return v[i];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
