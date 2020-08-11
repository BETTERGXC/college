//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个
//函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。时间复杂度 O(row+col)

bool FineTarget(int** arr,int target,int arrsize,int arrsizesize) {
	// 从数组的左下角或者右上角开始比较，从左下角比较为例子，如果
	// 小列++，如果大于行--
	int row = arrsize-1;
	int col = 0;

	while (row >= 0 && col <= arrsizesize) {
		if (target > arr[row][col]) {
			col++;
		}
		if (target < arr[row][col]) {
			row--;
		}
		if (target == arr[row][col]) {
			return true;
		}
	}
	return false;
}