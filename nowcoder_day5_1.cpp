
// 题目：“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。花花非常喜欢这种拥
// 有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。现在她非常好奇有没有办法将字
// 符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，帮助她寻找有多少种插入办法可以使
// 新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。



#include<iostream>
#include<string>
using  namespace std;

int main() {
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int count = 0;
	for (int i = 0; i <= s1.size(); ++i) {
		string tmp(s1);
		tmp.insert(i, s2);
		int left = 0;
		int right = tmp.size() - 1;
		int flag = 1;
		while (left < right) {
			if (tmp[left] != tmp[right]) {
				flag = 0;
			}
			++left;
			--right;
		}
		if (flag == 1) {
			count++;
		}
	}
	cout << count;
}