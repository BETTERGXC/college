// 字符串压缩.输入字符串只包含 a - z 字母以及结束标志，请编写函数实现对连续出现的相同字符进行压缩, 例
// 如： ”xxxyyyyz” 压缩后字符串为 ”3x4yz” ， ”yyyyyyy” 压缩后为 ”7y”

#include<iostream>
#include<string>
using namespace std;

string CompressString(string input) {
	string ret;
	int count = 1;
	for (int i = 0; i < input.size(); ++i) {
		
		if (input[i] == input[i + 1]) {
			count++;
		}
		else {
			if (count == 1) {
				ret += input[i];
			}
			else {
				ret += count + '0';
				ret += input[i];
			}
			count = 1;
		}
	}
	return ret;
}