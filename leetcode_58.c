//���һ�����ʳ��� 


//����һ����������Сд��ĸ�Ϳո�?' '?���ַ��� s�����������һ�����ʵĳ��ȡ�
//
//����ַ����������ҹ�����ʾ����ô���һ�����ʾ��������ֵĵ��ʡ�
//
//������������һ�����ʣ��뷵�� 0?��
//



int lengthOfLastWord(char * s){
    int length = strlen(s);
    if(length == 0) 
        return 0;
    int i = length - 1;
    while(s[i] == ' ') {
        i--;
        if(i<0)
        break;
    }
    if(i<0) {
        return 0;
    }
    int num = i;
    while(s[num] != ' ') {
        num--;
        if(num < 0)
        break;
    }
    return i-num;
}
