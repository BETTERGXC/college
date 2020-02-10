/*
** 在字符串 s1 中查找字符串 s2 最右出现的位置，并返回一个指向该位置的指针
*/


#include<string.h>

char* my_strrstr(char const *s1,char const *s2) {
	register char* last;
	register char* current;
	/*
	** 把指针初始化为我们已经找到的前一次的匹配位置
	*/
	last = NULL;
	/*
	** 只在第 2 个字符串不为空时才进行查找，如果 s2 为空，返回 NULL。
	*/
	
	if(*s2 != '\0') {
		/*
		** 查找 s2 在 s1 中第一次出现的位置
		*/
		current = strstr(s1,s2);
		
	/*
	** 每次找到字符串时，让指针指向它的起始位置。然后查找该字符串下一个匹配位置。
	*/
		while(current != NULL) {
			last = current;
			current = strstr(last+1,s2);
		} 
	} 
	// 返回指向找到的最后一次匹配的起始位置。
	return last; 
} 
