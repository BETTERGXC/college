// 将一句话中单词进行倒置，标点符号不倒置
#include<iostream>
#include<string>
using namespace std;

void inver(string s,int pos1,int pos2) {
	while (pos1 < pos2) {
		swap(s[pos1],s[pos2]);
		++pos1;
		--pos2;
	}
}

int main() {
	string s;
	getline(cin, s);
	int pos1 = 0;
	int pos2 = 0;
	for (int i = 0; i <= s.size(); ++i) {
		if (s[i] == ' ' || i == s.size()) {
			pos2 = i - 1;
			//inver(s,pos1,pos2);
			while (pos1 < pos2) {
				swap(s[pos1], s[pos2]);
				++pos1;
				--pos2;
			}
			pos1 = i + 1;
		}
		
	}
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend()) {
		cout << *rit;
		++rit;
	}
}