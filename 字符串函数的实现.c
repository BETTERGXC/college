

//实现  strlen

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


//实现  strcat

  
char* my_strcat(char* dst, const char* src) {
	assert(dst && src);
	char* ret = dst;           // 因为后边 dst已经需要++，所以用ret保存原来的位置
	while (*dst != '\0') {    //先找到 dst 上'\0' 的位置
		++dst;
	}
	while (*dst++ = *src++); //当dst 时'\0'时 将 src 给dst

	return ret;
}



//实现 strcmp

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
	//strcpy(p2,p1);  会报错，因为“world” 存在常量区上，不允许修改
	strcat(p2, p1);// 追加 拼接，注意p2的空间要能追加上 p1，避免越界


	//strcpy是一种追加拷贝，strcat是追加拷贝
}  



//strstr() 的实现


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
 

//  实现memcpy（）
// memcpy 和 strcpy 的区别，memcpy是内存拷贝，不管是什么类型，strcpy只能拷字符串


void* my_memcpy(void* dst, const void* src, size_t num) {
	assert(dst && src);       
	char* str_dst = (char*)dst;
	char* str_src = (char*)src;
	for (size_t i = 0; i < num; ++i) {
		str_dst[i] = str_src[i];   // 等价于 *(str_src + i)
	}
	return dst;
}



//  实现memmove()

void* my_memmove(void* dst, const void* src, size_t num) {
	assert(src && dst);
	char* str_dst = (char*)dst;
	char* str_src = (char*)src;
	if (str_dst < str_src) { //前重叠或者不重叠，从前往后拷贝
		for (size_t i = 0; i < num; ++i) {
			str_dst[i] = str_src[i];
		}
	}
	else {//后重叠或者是不重叠，从后往前拷贝
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
	if (str_src < str_dst && str_dst<str_src +num) {   //后重叠 从后往前拷贝
		for (int i = num - 1; i >= 0; --i) {
			str_dst[i] = str_src[i];
		}
	}
	else {   //前重叠或者不重叠，从前往后拷贝
		for (size_t i = 0; i < num; ++i) {
			str_dst[i] = str_src[i];
		}
	}
	return dst;
}



