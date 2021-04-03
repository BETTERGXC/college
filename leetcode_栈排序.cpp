/*
    定义两个栈，一个主栈，一个辅助栈
    当主栈为空，插入元素时，直接插入到主栈
    
    如果主栈不为空，插入元素大于主栈栈顶元素的话，
    将主栈的元素移动至辅助栈直至插入元素小于主栈栈顶元素或主栈为空
    然后插入val到主栈

    如果主栈栈顶元素小于插入元素 val，则直接插入val

    至此，主栈的元素都是有序的
    
*/
class SortedStack {
public:
    SortedStack() {
        
    }
    
    void push(int val) {
        if(_mainSt.empty()) {
            _mainSt.push(val);
        }
        else {
            while(!_mainSt.empty() && val > _mainSt.top()) {
                _helpSt.push(_mainSt.top());
                _mainSt.pop();
            }
            _mainSt.push(val);
            while(!_helpSt.empty()) {
                _mainSt.push(_helpSt.top());
                _helpSt.pop();
            }
        }
    }
    
    void pop() {
        if(!_mainSt.empty()) {
            _mainSt.pop();
        }
        
    }
    
    int peek() {
        if(!_mainSt.empty())
            return _mainSt.top();
        else 
            return -1;
    }
    
    bool isEmpty() {
        return _mainSt.empty();
    }
private:
    stack<int> _mainSt;
    stack<int> _helpSt;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
