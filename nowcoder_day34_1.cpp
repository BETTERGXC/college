// 收件人列表

#include <bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    // 接受数字
    while (cin >> n) {
        cin.get();
        string name;
        // 名字分别处理
        for (int i = 0; i < n; ++i) {
            bool flag = false;
            getline(cin, name);
            if (name.find(',') != string::npos ||
                name.find(' ') != string::npos)  // 找到逗号或者空格，就要加双引号
                flag = true;
            if (flag)
                putchar('\"');  // cout << '\"'; 使用putchar效率更高
            cout << name;
            if (flag)
                putchar('\"');  
            if (i == n - 1)  // 如果已经是最后一个字符串，那就补回车，否则加逗号和空格
                putchar('\n');
            else {
                putchar(',');
                putchar(' ');
            }
        }
    }
    return 0;
}
