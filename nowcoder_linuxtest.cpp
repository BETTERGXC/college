// 找第 k 个小的数
#include<iostream>
#include<vector>
#include<set>


using namespace std;

int main() {
	
	int n;
	while (cin >> n) {
		vector<int> v1;
		v1.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> v1[i];
		}

		vector<int>v2;
		set<int>s(v1.begin(), v1.end());
		for (auto& e : s) {
			v2.push_back(e);
		}

		int k = 0;
		cin >> k;
		cout << v2[k - 1] << endl;

	}
}