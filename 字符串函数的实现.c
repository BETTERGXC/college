

//ʵ��  strlen

int my_strlen(char* dst) {
	assert(dst);
	char* ret = dst;
	int count = 0;
	while (*ret!='\0') {
		ret++;
		++count;
	}
	return count;
}  


//ʵ��  strcat

  
char* my_strcat(char* dst, const char* src) {
	assert(dst && src);
	char* ret = dst;           // ��Ϊ��� dst�Ѿ���Ҫ++��������ret����ԭ����λ��
	while (*dst != '\0') {    //���ҵ� dst ��'\0' ��λ��
		++dst;
	}
	while (*dst++ = *src++); //��dst ʱ'\0'ʱ �� src ��dst

	return ret;
}



//ʵ�� strcmp

int my_strcmp(const char* str1,const char* str2) {
	assert(str1 && str2);
	unsigned char* s1 = (unsigned char*)str1;
	unsigned char* s2 = (unsigned char*)str2;
	while (*s1 && *s2) {
		if (*s1 > *s2) {
			return 1;
		}
		else if (*s1 < *s2) {
			return -1;
		}
		else {
			++s1;
			++s2;
		}
	}
	if (*s1 == '\0'&&*s2 == '\0') {
		return 0;
	}
	else if (*s1 == '\0') {
		return -1;
	}
	else {
		return 1;
	}
}



int mian() {
	char* p1 = "hello";
	char p2[] = "world";
	//char* p2 = "world";
	//strcpy(p2,p1);  �ᱨ����Ϊ��world�� ���ڳ������ϣ��������޸�
	strcat(p2, p1);// ׷�� ƴ�ӣ�ע��p2�Ŀռ�Ҫ��׷���� p1������Խ��


	//strcpy��һ��׷�ӿ�����strcat��׷�ӿ���
}  



//strstr() ��ʵ��


char* my_strstr(const char* src, const char* sub) {
	assert(src && sub);
	const char* srci = src;
	const char* subi = sub;
	while (*srci != '\0') {
		while (*srci == *subi && *subi != '\0') {
			++srci;
			++subi;

		}
		if (*subi == '\0') {
			return src;
		}
		else {
			subi = sub;
			++src;
			srci = src;
		}
	}
}
 

//  ʵ��memcpy����
// memcpy �� strcpy ������memcpy���ڴ濽����������ʲô���ͣ�strcpyֻ�ܿ��ַ���


void* my_memcpy(void* dst, const void* src, size_t num) {
	assert(dst && src);       
	char* str_dst = (char*)dst;
	char* str_src = (char*)src;
	for (size_t i = 0; i < num; ++i) {
		str_dst[i] = str_src[i];   // �ȼ��� *(str_src + i)
	}
	return dst;
}



//  ʵ��memmove()

void* my_memmove(void* dst, const void* src, size_t num) {
	assert(src && dst);
	char* str_dst = (char*)dst;
	char* str_src = (char*)src;
	if (str_dst < str_src) { //ǰ�ص����߲��ص�����ǰ���󿽱�
		for (size_t i = 0; i < num; ++i) {
			str_dst[i] = str_src[i];
		}
	}
	else {//���ص������ǲ��ص����Ӻ���ǰ����
		for (int i = num-1 ; i >= 0; --i) {
			str_dst[i] = str_src[i];
		}
	}
	return dst;
 }

void* my_memmove(void* dst, const void* src, size_t num) {
	assert(src && dst);
	char* str_dst = (char*)dst;
	char* str_src = (char*)src;
	if (str_src < str_dst && str_dst<str_src +num) {   //���ص� �Ӻ���ǰ����
		for (int i = num - 1; i >= 0; --i) {
			str_dst[i] = str_src[i];
		}
	}
	else {   //ǰ�ص����߲��ص�����ǰ���󿽱�
		for (size_t i = 0; i < num; ++i) {
			str_dst[i] = str_src[i];
		}
	}
	return dst;
}



