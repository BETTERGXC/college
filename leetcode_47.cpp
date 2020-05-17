class Solution {
public:
    string multiply(string num1, string num2) {
        string str;
        // 判断有 0 相乘的结果
        if (num1[0] == '0' || num2[0] == '0') {
            str += '0';
            return str;
        }

        // 开int 型数组，防止数字大于127而造成溢出
        int* value = (int*)malloc(sizeof(int)*(num1.size() + num2.size()));
        int len = num1.size() + num2.size();
        for (int i = 0; i < len; ++i) {
            value[i] = 0;
        }

        // 两数相乘
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        // 处理进位
        int carry = 0;
        for (int i = len - 1; i >= 0; --i) {
            value[i] += carry;
            carry = value[i] / 10;
            value[i] = value[i] % 10;
        }

        // 转换为字符
        for (int i = 0; i < len; ++i) {
            value[i] += '0';
        }

        // 处理字符串前边的 0
        int index = 0;
        for (int i = 0; i < len; ++i) {
            if (value[i] != '0') {
                break;
            }
            index++;
        }
        for (int i = index; i < len; ++i) {
            str += value[i];
        }
        return str;
    }
};