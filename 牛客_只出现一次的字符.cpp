
/*
    可以先创建一个大小为26的整型数组来记录每个字母出现的次数
    用字符串中的字符减去字符 a 就是字符应该在数组中的位置

*/

#include<iostream>
#include<string>
//using namespace std;
//
//int main() {
//    string str;
//    while (cin >> str) {
//        // 这里的flag放在while循环里边，每次都先初始化为 1，防止多个测试用例初始值不是 1
//        int flag = 1;    
//        int _str[26] = { 0 };
//        for (int i = 0; i < str.size(); ++i)
//            _str[str[i] - 'a']++;
//        for (int i = 0; i < str.size(); ++i) {
//            if (_str[str[i] - 'a'] == 1) {
//                // 这里打印字符后边要加换行  否则会报错
//                cout << str[i] << endl;
//                flag = 0;
//                break;
//            }
//        }
//        if (flag)
//            // 这里也要加换行 ，否则报错
//            cout << -1 << endl;
//    }
//    return 0;
//}

