//最后一个单词长度 


//给定一个仅包含大小写字母和空格?' '?的字符串 s，返回其最后一个单词的长度。
//
//如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
//
//如果不存在最后一个单词，请返回 0?。
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
