#include<iostream>
#include<string>
using namespace std;

bool IsPalindrome(int num) {
	string str;
	while (num) {
		str += num % 10 + '0';
		num /= 10;
	}

	int left = 0;
	int right = str.size() - 1;

	while (left < right) {
		if (str[left] != str[right]) {
			return false;
		}
		left++;
		right--;
	}
	return true;
}

int main() {
	int num;
	cin >> num;
	cout <<IsPalindrome(num) << endl;
}