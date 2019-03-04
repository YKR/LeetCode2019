class LRUCache {
public:
    int myCapacity;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> lruMap;

    LRUCache(int capacity) {
        myCapacity = capacity;
    }
    
    int get(int key) {
        auto found = lruMap.find(key);
        if (found == lruMap.end()) return -1;
        lru.splice(lru.begin(), lru, found->second);
        return found->second->second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1)
        {
            lru.front().second = value;
            return;
        }
        if (lru.size() == myCapacity)
        {
            lruMap.erase(lru.back().first);
            lru.pop_back();
        }
        lru.push_front(make_pair(key, value));
        lruMap[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */