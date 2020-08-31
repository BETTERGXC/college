// 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
// 例如，输入 ”They are students.” 和 ”aeiou” ，
// 则删除之后的第一个字符串变成 ”Thy r stdnts.”
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1 = "They are student";
	string s2 = "aeiou";
	string ret;
	int arr[57] = {0};
	for (auto e : s2) {
		arr[e - 'A']++;
	}
	for (int i = 0; i < s1.length(); ++i) {
		if (arr[s1[i] - 'A'] == 0 || s1[i] == ' ') {
			ret += s1[i];
		}
	}
	cout << ret << endl;
}