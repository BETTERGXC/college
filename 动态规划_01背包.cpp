// 从n个商品中做选择，当包大小为m时的最大价值
// 状态F(i,j)：从i个商品中做选择，当包大小为j时的最大价值
// A[i-1] <= j  F(i,j) = max{F(i-1,j),F(i-1,j-A[i-1]) + V[i-1]}
// A[i-1] > j     F(i,j) = F(i-1,j)

int backPack(int m, vector<int>& A, vector<int>& V) {
	int n = A.size();
	if (n == 0 || m == 0)
		return 0;

	vector<vector<int>> maxV(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (A[i - 1] <= j) {
				maxV[i][j] = max(maxV[i - 1][j], maxV[i - 1][j - A[i - 1]] + V[i - 1]);
			}
			else
				maxV[i][j] = maxV[i - 1][j];
		}
	}
	return maxV[n][m];
}