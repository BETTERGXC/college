class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto ret = _hashmap.find(key);
        if(ret != _hashmap.end()) {
            // 保证LRU机制，把刚刚get的值放到链表头上
            list<pair<int,int>>::iterator pos = ret->second;
            pair<int,int> kv = *pos;
            _lrulist.erase(pos);
            _lrulist.push_front(kv);
            _hashmap[key] = _lrulist.begin();
            return kv.second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // 判断是插入还是更新
        auto ret = _hashmap.find(key);

        // 找到了就是更新
        if(ret != _hashmap.end()) {
            list<pair<int,int>>::iterator pos = ret->second;
            _lrulist.erase(pos);
            _lrulist.push_front(make_pair(key,value));
            _hashmap[key] = _lrulist.begin();
        }
        // 没找到，插入
        else {
            // 满了，删除尾上数据
            if(_lrulist.size() == _capacity) {
                pair<int,int> back = _lrulist.back();
                _hashmap.erase(back.first);
                _lrulist.pop_back();
            }

            _lrulist.push_front(make_pair(key,value));
            _hashmap.insert(make_pair(key,_lrulist.begin()));
        }
        
    }
private:
    // map的value上存放list的迭代器，就可以满足list查找value在O(1)完成
    // 使用list 就可以保证插入和删除是在O(1)完成
    unordered_map<int,list<pair<int,int>>::iterator> _hashmap;
    list<pair<int,int>> _lrulist;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */