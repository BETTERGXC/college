//长键按入

//你的朋友正在使用键盘输入他的名字?name。偶尔，在键入字符?c?时，按键可能会被长按，而字符可能被输入 1 次或多次。
//
//你将会检查键盘输入的字符?typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回?True。



bool isLongPressedName(char * name, char * typed){
    int name_index = 0;
    int typed_index = 0;
    int name_len = strlen(name);
    int typed_len = strlen(typed);
    while(name_index < name_len) {
        if(name[name_index] == typed[typed_index]) {
            name_index++;
            typed_index++;
        }
        else{
            typed_index++;
            if(typed_index >= typed_len)
                return false;
        }
    }
    return true;
}
