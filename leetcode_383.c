//��Ŀ��������һ������� (ransom) �ַ�����һ����־(magazine)�ַ�����
//�жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�
//������Թ��ɣ����� true �����򷵻� false��
//

 
 
 
//�������ַ���a��b��Ҫ��ʹ��b�а������ַ����a��b�е�ÿ���ַ�ֻ����һ�Ρ�
//
//����aa��aba�᷵��true��bb��aba�᷵��false��

//�ȶ������� 26 ��Ԫ�ص����飬Ȼ��������Ǹ���ĸ����Ӧλ�ü�һ��Ȼ��Ա��������ߵ���ĸ��û����־�����Ӧ����ĸ�������� 
bool canConstruct(char * ransomNote, char * magazine){
    int ran[26] = {0};
    int maga[26] = {0};
    int ret = 1;
    int len_ran = strlen(ransomNote);
    int len_maga = strlen(magazine);
    for(int i = 0;i<len_ran;i++) {
        ran[ransomNote[i] - 97]++;
    }
    for(int i = 0;i<len_maga;i++) {
        maga[magazine[i] - 97]++;
    }
    for(int i = 0;i<26;i++) {
        if(ran[i]>maga[i])
        ret = 0;
    }
    if(ret == 1)
        return true;
    else
        return false;
}
