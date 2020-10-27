class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.size() == 0) 
            return -1;
        
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s2.top();
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }

private:
    stack<int> s1;
    stack<int> s2;

};

// 优化方法

//维护两个栈，第一个栈支持插入操作，第二个栈支持删除操作。

/*根据栈先进后出的特性，我们每次往第一个栈里插入元素后，第一个栈的底部元素是最后插入的元素，第一个栈的顶部元素是下一个待删除的元素。为了维护队列先进先出的特性，我们引入第二个栈，用第二个栈维护待删除的元素，在执行删除操作的时候我们首先看下第二个栈是否为空。如果为空，我们将第一个栈里的元素一个个弹出插入到第二个栈里，这样第二个栈里元素的顺序就是待删除的元素的顺序，要执行删除操作的时候我们直接弹出第二个栈的元素返回即可。*/

