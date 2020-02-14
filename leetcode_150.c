/*
** 逆波兰式表达式求值
*/ 





int evalRPN(char ** tokens, int tokensSize){
    int* stack = (int*)malloc(sizeof(int) * tokensSize * 2);
    int top = 0;
    int res = 0;
    int a = 0, b = 0;

    if (tokensSize == 1) {
        return atoi(tokens[0]);
    }

    for (int i = 0; i < tokensSize; i++) {
        if ((tokens[i][0] != '+' && tokens[i][0] != '-' && tokens[i][0] != '*' && tokens[i][0] != '/') || (tokens[i][0] == '-' && strlen(tokens[i]) != 1)) {
            stack[top++] = atoi(tokens[i]);
        } else {
            if (tokens[i][0] == '+') {
                a = stack[top-1]; top--;
                b = stack[top-1]; top--;
                res = a + b;
                stack[top++] = res;
            } else if (tokens[i][0] == '-') {
                a = stack[top-1]; top--;
                b = stack[top-1]; top--;
                res = b - a;
                stack[top++] = res;
            } else if (tokens[i][0] == '*') {
                a = stack[top-1]; top--;
                b = stack[top-1]; top--;
                res = a * b;
                stack[top++] = res;            
            } else {
                a = stack[top-1]; top--;
                b = stack[top-1]; top--;
                res = (int)(b / a);
                stack[top++] = res;               
            }
        }
    }
    free(stack);
    return res;
}
