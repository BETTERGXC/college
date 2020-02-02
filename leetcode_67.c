// ��������� 


//���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
//
//����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��


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
        res[--len] = pa ^ pb ^ carry; // ��ǰλ
        carry = (pa & carry) | (pb & carry) | (pa & pb); //��λ
    }
    return res + len;   // res��ָ�룬len��ʾ�ӵ���λ��ʼ���ǵ�һλ 
}
