//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能

class Solution {
public:
    int StrToInt(string str) {
    	long sum = 0;
	    int flag = 1;
	    for (int i = 0; i < str.size(); ++i) {
		    if (str[i] == '+') {
		    }
		    else if (str[i] == '-') {
			    flag = -1;
	    	}
		    else if (str[i] >= '0' && str[i] <= '9') {
			    sum += str[i] - '0';
			    sum = sum * 10;
		    }
	    	else {
		    	return 0;
		    }
	    }
	    sum = sum / 10;
	    sum = flag * sum;
	    return (int)sum;
    }
};