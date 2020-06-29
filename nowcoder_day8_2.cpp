// 求最小公倍数

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using  namespace std;


int main() {
	int A, B;
	cin >> A >> B;
	int max = A * B;
	int more = A > B ? A : B;
	int ret;
	for (int i = more; i <= max; ++i) {
		if (i % A == 0 && i % B == 0) {
			ret = i;
            break;
		}
	}
	cout << ret;
}