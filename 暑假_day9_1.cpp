// 最大连续子数组

int maxArr(int* arr, int n) {
	int max = arr[0];
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (ret < 0) {
			ret = 0;
		}
		else {
			ret += arr[i];
		}
		if (max < ret) {
			max = ret;
		}
	}
	return max;
}