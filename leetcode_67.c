// 二进制求和 


//给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//输入为非空字符串且只包含数字 1 和 0。


char* addBinary(char* a, char* b) {
    int i = strlen(a);
    int j = strlen(b);
    
    int len = i > j? i: j;
    char* res = (char*)malloc(sizeof(char) * (len + 2));
    res[++len] = 0;
    
    char carry = '0';
    char pa, pb;
    while(len > 1 || carry == '1') {
        pa = i > 0? a[--i]: '0';
        pb = j > 0? b[--j]: '0';
        res[--len] = pa ^ pb ^ carry; // 当前位
        carry = (pa & carry) | (pb & carry) | (pa & pb); //进位
    }
    return res + len;   // res是指针，len表示从第零位开始还是第一位 
}
