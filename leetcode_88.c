// �ϲ�������������

//�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣 





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
