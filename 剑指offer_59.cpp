class MaxQueue {
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(_dq.empty()) {
            return -1;
        }
        return _dq.front();
    }
    
    void push_back(int value) {
        _q.push(value);
        while(!_dq.empty() && _dq.back() < value) {
            _dq.pop_back();
        }
        _dq.push_back(value);
    }
    
    int pop_front() {
        if(_q.empty()) {
            return -1;
        }
        int ret = _q.front();
        if(ret == _dq.front()) {
            _dq.pop_front();
        }
        _q.pop();
        return ret;
    }

private:
    queue<int> _q;
    deque<int> _dq;

};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */