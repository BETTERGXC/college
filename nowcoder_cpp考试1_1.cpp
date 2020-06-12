// 输入一个字符串，求出该字符串包含的字符集合

#include<iostream>
#include<string>

using namespace std;
int main() {
    string s;
	while(cin >> s) {
        char arr[100] = { 0 };
	    int count = 0;
	    for (int i = 0; i < s.size(); ++i) {
	    	int flag = 0;
    		for (int j = 0; j < 100; ++j) {
	    		if (s[i] == arr[j])
			    	flag = 1;
	    	}
	    	if (flag != 1) {
	    		arr[count++] = s[i];
	    	}
        }
	    for (int i = 0; i < count; ++i) {
	    	cout << arr[i];
	    }
        cout << endl;
    }
}