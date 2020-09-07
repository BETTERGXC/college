// 抄送列表
// write your code here cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        vector<string> names;  // 存放所有数据
        int pos = 0;
        while (pos < str.length()) {  // 位置如果大于等于了长度，那么证明找完了，双引号的情况从该位置跳出
            if (str[pos] == '\"') {  // 找到双引号要处理双引号内部
                int end = str.find('\"', pos + 1);
                names.push_back(str.substr(pos + 1, end - pos - 1));  // 截取出来放到names中
                pos = end + 2;  // 跳过后面的双引号和逗号
            }
            else {
                int end = str.find(",", pos + 1);
                if (end == -1)  {  // 找不到逗号证明这是最后一个字符串了，直接存该字符串后跳出
                    names.push_back(str.substr(pos, str.size() - pos));
                    break;
                }
                names.push_back(str.substr(pos, end - pos));
                pos = end + 1;  // 跳过后面的逗号
            }
        } 
        getline(cin, str);
        if (names.end() == find(names.begin(), names.end(), str)) 
            // find函数在两个迭代器中间查找，最后一个参数为要找的值
            // 找到了返回对应迭代器，找不到返回区间末尾位置，本例子为end()
            cout << "Important!" << endl;
        else
            cout << "Ignore" << endl;
    }
    return 0;
}
