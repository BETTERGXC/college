/*
** ���ַ��� s1 �в����ַ��� s2 ���ҳ��ֵ�λ�ã�������һ��ָ���λ�õ�ָ��
*/


#include<string.h>

char* my_strrstr(char const *s1,char const *s2) {
	register char* last;
	register char* current;
	/*
	** ��ָ���ʼ��Ϊ�����Ѿ��ҵ���ǰһ�ε�ƥ��λ��
	*/
	last = NULL;
	/*
	** ֻ�ڵ� 2 ���ַ�����Ϊ��ʱ�Ž��в��ң���� s2 Ϊ�գ����� NULL��
	*/
	
	if(*s2 != '\0') {
		/*
		** ���� s2 �� s1 �е�һ�γ��ֵ�λ��
		*/
		current = strstr(s1,s2);
		
	/*
	** ÿ���ҵ��ַ���ʱ����ָ��ָ��������ʼλ�á�Ȼ����Ҹ��ַ�����һ��ƥ��λ�á�
	*/
		while(current != NULL) {
			last = current;
			current = strstr(last+1,s2);
		} 
	} 
	// ����ָ���ҵ������һ��ƥ�����ʼλ�á�
	return last; 
} 
