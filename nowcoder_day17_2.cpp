// 超长正整数相加

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s1;
	string s2;
	while (cin >> s1 >> s2) {
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		string sum;

		int len1 = s1.size();
		int len2 = s2.size();
		int maxlen = len1 > len2 ? len1 : len2;

		int carry = 0;
		int si1;
		int si2;
		int ret = 0;
		for (int i = 0; i < maxlen; ++i) {
			if (i < len1)
				si1 = s1[i] - '0';
			else
				si1 = 0;
			if (i < len2)
				si2 = s2[i] - '0';
			else
				si2 = 0;

			ret = si1 + si2 + carry;
			carry = ret > 9 ? 1 : 0;
			sum += ret % 10 + '0';
		}
		if (carry == 1)
			sum += 1+'0';
		reverse(sum.begin(),sum.end());
		cout << sum << endl;
	 }
}



