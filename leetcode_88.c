// 合并两个有序数组

//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。 





void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	if(m == 0) {
        for(int i = 0;i<nums1Size;i++) {
            nums1[i] = nums2[i];
        }
    }
    else{
        while (m > 0 && n > 0) {
		    if (nums1[m - 1] < nums2[n - 1]) {
			    nums1[nums1Size - 1] = nums2[n - 1];
			    nums1Size--;
			    n--;
		    }
		    else {
			    nums1[nums1Size - 1] = nums1[m - 1];
			    nums1Size--;
			    m--;
		    }
	    }
	    if (m <= 0) {
		    for (int i = 0; i <= n - 1; i++) {
			    nums1[i] = nums2[i];
		    }
	    }
    }
}
