//������ת��ĸ

//����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת�� 






char * reverseOnlyLetters(char * S) {
	int len = strlen(S);
    if(len==0||len==1)              //  �ַ���Ϊ�յ����
        return S;
	//char *str = (char*)malloc(sizeof(char)*len);
    char str[len];
    for(int i = 0;i<len;++i) {
        str[i] = S[i];
    }
	int left = 0;
	int right = len - 1;
	while (left < right) {
		while (!((S[left] >= 'a' && S[left] <= 'z') || (S[left] >= 'A' && S[left] <= 'Z'))) {
			left++;
            if(left>=len)   // ��� S�ַ���û����ĸ��������ѭ��Ȼ�����δ֪�ڴ档
                return S;

		}
		while (!((S[right] >= 'a' && S[right] <= 'z') || (S[right] >= 'A' && S[right] <= 'Z'))) {
			right--;
		}
		str[left] = S[right];
		str[right] = S[left];
		++left;
		--right;
	}
	for(int i = 0;i<len;++i) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            S[i] = str[i];
        }
    }
	return S;
}
