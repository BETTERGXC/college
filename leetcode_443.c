/*
** 压缩字符串
*/ 




int compress(char* chars, int charsSize){
    int start = 0;
    int end = 0;
    int ReturnSize = 0;
    int times;
    int i;
    for(;start<charsSize;++start) {
        if(start == charsSize - 1 || chars[start] != chars[start + 1]) {
            chars[ReturnSize++] = chars[end];
            if(start > end) {           // 连续次数大于一时保存次数
                times = start - end + 1;
                i = ReturnSize;         // 保存数字反转的起点

                while(times) {
                    chars[ReturnSize++] = times % 10 + '0';
                    times = times/10;
                }
                for(int j = 0;j<(ReturnSize - i)/2;++j) {  // 反转数字
                    char tmp = chars[i + j];
                    chars[i + j] = chars[ReturnSize - j - 1];
                    chars[ReturnSize - j - 1] = tmp;
                }
            }
        end = start + 1;
        }
    }
    return ReturnSize;
}
