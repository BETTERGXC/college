#include <iostream>
#include <vector>
using namespace std;

void test() {
	vector<int> weight = { 1,3,4 };
	vector<int> value = { 15,20,30 };
	int bagWeight = 4;

	//二维数组
	vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));

	// 初始化  这里一定要倒序遍历，如果正序遍历。
	//例如dp[0][1] = 15，到了dp[0][2] = dp[0][2-1] + 15，也就是dp[0][2] = 30了，物品0重复放入
	/*for (int i = bagWeight; i >= weight[0]; i--) {
		dp[0][i] = dp[0][i - weight[0]] + value[0];
	}*/
	for (int i = 0; i < bagWeight; i++) {
		if (i >= weight[0]) {
			dp[0][i] = value[0];
		}
	}

	//weight数组的大小 就是物品个数
	for (int i = 1; i < weight.size(); i++) {
		for (int j = 0; j <= bagWeight; j++) {
			if (j < weight[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			
		}
	}

	cout << dp[weight.size() - 1][bagWeight] << endl;
}

int main() {
	test();
	return 0;
}