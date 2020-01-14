//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，
//之后返回新的字符串。
//
// 
char * toLowerCase(char * str){
    if(str == NULL) {
        return NULL;
    }
    int i = strlen(str);
    for(int j = 0;j<i;j++) {
        if(str[j]>='A' && str[j]<='Z') {
            str[j] += 32;
        }
    }
    return str;
}
