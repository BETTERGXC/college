//��������

//�����������ʹ�ü���������������?name��ż�����ڼ����ַ�?c?ʱ���������ܻᱻ���������ַ����ܱ����� 1 �λ��Ρ�
//
//�㽫�������������ַ�?typed���������Ӧ�Ŀ�����������ѵ����֣�����һЩ�ַ����ܱ�����������ô�ͷ���?True��



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
