class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for (auto& str : tokens) {
            // 1.操作符取栈数据进行运算
            // 2.操作数入栈
            if (str == "+" || str == "-" || str == "/" || str == "*") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (str[0]) {
                case '+':
                    st.push(left + right);
                    break;
                case  '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};