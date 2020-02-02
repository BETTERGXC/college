//验证回文字符串 



bool isPalindrome(char * s){
    int len = strlen(s);
    int start = 0;
    int end = len - 1;
    int count = 0;
    for(int i = 0;i<len;++i) {
        if(((s[i]>='a' && s[i] <= 'z')||(s[i]>='A' && s[i] <= 'Z')
        ||(s[i]>='0' && s[i]<='9')))
        count++;
    }
    if(count == 0||len == 0)
     return true;
    while(start<end) {
        while(!((s[start]>='a' && s[start] <= 'z')||(s[start]>='A' && s[start] <= 'Z')
        ||(s[start]>='0' && s[start]<='9')))
            ++start;
        while(!((s[end]>='a' && s[end] <= 'z')||(s[end]>='A' && s[end] <= 'Z')
        ||(s[end]>='0' && s[end]<='9')))
            --end;
        if(((s[start]>='a' && s[start] <= 'z')||(s[start]>='A' && s[start] <= 'Z'))&&
        ((s[end]>='a' && s[end] <= 'z')||(s[end]>='A' && s[end] <= 'Z'))){
            if(s[start] == s[end] || s[start] == s[end]-32||s[start] == s[end]+32){
            ++start;
            --end;
            }
            else
                return false;
        }
        //有的数字和字符之间会相差32，所以将数字和字符分开处理 
        else if((s[start]>='0'&&s[start]<='9')&&(s[end]>='0'&&s[end]<='9')){        
            if(s[start] == s[end]){
                ++start;
                --end;
            }
            else
                return false;
        }
        else{
            return false;
        }
    }
    return true;
}
