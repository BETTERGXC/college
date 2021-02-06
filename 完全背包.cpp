#include <iostream>
#include <vector>
using namespace std;

void test() {
	vector<int> weight = {1,3,4};
	vector<int> value = {15,20,30};
	int bagWeight = 4;
	
	//初始化
	vector<int> dp(bagWeight+1, 0);
	for(int i = 0; i < weight.size(); i++) {
		for(int j = weight[i]; j <= bagWeight; j++) {
			dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
		}
	}
	cout << dp[bagWeight] << endl;
}

int main() {
	test();
	return 0;
}