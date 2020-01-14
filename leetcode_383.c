//题目描述给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
//判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
//如果可以构成，返回 true ；否则返回 false。
//

 
 
 
//有两个字符串a和b，要求使用b中包含的字符组成a，b中的每个字符只能用一次。
//
//例如aa和aba会返回true，bb和aba会返回false。

//先定义两个 26 个元素的数组，然后如果有那个字母就相应位置加一，然后对比赎金信里边的字母有没有杂志里边相应的字母的数量多 
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
