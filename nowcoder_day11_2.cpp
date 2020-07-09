//求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

#include<iostream>
#include<string>

using namespace std;
int main() {
	int x;
    while(cin>>x) {
	    int count = 0;
	    int max = 0;
	    while (x) {
		    if (x & 0x1 == 1) {
			    count++;
			    x = x >> 1;
		    }
		    else {
			    if(count > max)
				    max = count;
			    count = 0;
			    x = x >> 1;
		    }
	    }
	    if (count > max)
		    cout << count << endl;
	    else
	    	cout << max << endl;
    }
}
