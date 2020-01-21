//仅仅反转字母

//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。 






char * reverseOnlyLetters(char * S) {
	int len = strlen(S);
    if(len==0||len==1)              //  字符串为空的情况
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
            if(left>=len)   // 如果 S字符串没有字母会陷入死循环然后访问未知内存。
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
