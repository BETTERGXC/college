// 出现一次的字符

#include<iostream>
using namespace std;

int main() {
    string str;
    while(cin >> str) {
        int pos1 = 0;
        int pos2 = 0;
        // 判断是否有输出
        int FLAG = 0;
        for(;pos1 < str.size();++pos1) {
            // 判断是否有相同字符
            int flag = 0;
            for(pos2 = 0;pos2 < str.size();++pos2) {
                // 如果是和当前字符想比较，那就跳过不做比较
                if(pos1 == pos2)
                    continue;
                if(str[pos1] == str[pos2])
                    flag = 1;
            }
            if(flag == 0) {
                cout << str[pos1] << endl;
                FLAG = 1;
                break;
            }
        }
        if(FLAG == 0)
            cout << -1 << endl;
    }
}