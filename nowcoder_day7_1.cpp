// 把一个数变成一个斐波那契数要几步
#include<iostream>
#include<vector>
#include<string>
using  namespace std;

int main() {
	int N;
	cin >> N;
	int minx;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	int i = 1;
	while (v[i] < N) {
		i++;
		v.push_back(v[i - 1] + v[i - 2]);
	}

	if (v[i] - N < N - v[i - 1]) {
		minx = v[i] - N;
	}
	else {
		minx = N - v[i - 1];
	}
	cout << minx << endl;
}