//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对

#include<iostream>
using namespace std;

bool is_prime(int x) {
	int flag = 1;
	for (int i = 2; i < x; ++i) {
		if (x % i == 0)
			flag = 0;
	}
	if (flag == 1)
		return true;
	return false;
}

int main() {
	int n;
	while(cin >> n) {
        int min = n;
	    int arr[2] = { 0 };
	    for (int i = 2; i <= n/2; ++i) {
		    if (is_prime(i) && is_prime(n - i)) {
		    	if (n - 2 * i < min) {
			    	min = n - 2 * i;
				    arr[0] = i;
			    	arr[1] = n - i;
		    	}
		    }
	    }
	    cout << arr[0] << endl;
	    cout << arr[1] << endl;
    }
}