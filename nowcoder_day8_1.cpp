//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.
//根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" <
//"doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" <
//"doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证


#include<iostream>
#include<vector>
#include<string>
#include<stack>
using  namespace std;


int main() {
	vector<string> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int flag1 = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (v[i] > v[i + 1]) {
			flag1 = 0;
		}
		
	}

	int flag2 = 1;
	for (int i = 0; i < n-1; ++i) {
		if (v[i].size() > v[i + 1].size())
			flag2 = 0;
	}

	if (flag1 == 1 && flag2 == 0) {
		cout << "lexicographically";
	}
	if (flag1 == 0 && flag2 == 1) {
		cout << "lengths";
	}
	if (flag1 == 1 && flag2 == 1) {
		cout << "both";
	}
	if (flag1 == 0 && flag2 == 0) {
		cout << "none";
	}
}