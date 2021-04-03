/*
    ��������ջ��һ����ջ��һ������ջ
    ����ջΪ�գ�����Ԫ��ʱ��ֱ�Ӳ��뵽��ջ
    
    �����ջ��Ϊ�գ�����Ԫ�ش�����ջջ��Ԫ�صĻ���
    ����ջ��Ԫ���ƶ�������ջֱ������Ԫ��С����ջջ��Ԫ�ػ���ջΪ��
    Ȼ�����val����ջ

    �����ջջ��Ԫ��С�ڲ���Ԫ�� val����ֱ�Ӳ���val

    ���ˣ���ջ��Ԫ�ض��������
    
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
