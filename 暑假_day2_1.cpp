//要求写一个函数，将字符串中的空格替换为%20。样例： “abc defgx yz” 转换成 “abc%20defgx%20yz”

#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	string tmp;
	getline(cin, str);
	int len = str.length();
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			len += 2;
		}
	}

	tmp.resize(len);
	int pos = tmp.length() - 1;
	for (int i = str.length() - 1; i >= 0; --i) {
		if (str[i] == ' ') {
			tmp[pos--] = '0';
			tmp[pos--] = '2';
			tmp[pos--] = '%';
		}
		else {
			tmp[pos--] = str[i];
		}
	}
	str.swap(tmp);
	cout << str << endl;
}