// 光标的位置

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int n;
    string str;
    while (cin >> n >> str) {
        // 歌曲数量小于等于4
        if (n <= 4) {
            vector<int> v;
            v.resize(n);
            for (int i = 0; i < n; ++i) {
                v[i] = i + 1;
            }
            int pos = 1;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == 'U') {
                    if (pos == 1) {
                        pos = n;
                    }
                    else {
                        pos--;
                    }
                }
                if (str[i] == 'D') {
                    if (pos == n) {
                        pos = 1;
                    }
                    else {
                        pos++;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << v[i] << ' ';
            }
            cout << endl;
            cout << pos << endl;
        }

        // 歌曲数量大于4的情况
        if (n > 4) {
            vector<int> v;
            v.resize(4);
            for (int i = 0; i < 4; ++i) {
                v[i] = i + 1;
            }
            int pos = 1;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == 'U') {
                    if (pos == 1) {
                        pos = n;
                        v[3] = n;
                        v[2] = n - 1;
                        v[1] = n - 2;
                        v[0] = n - 3;
                    }
                    else if (pos == v[0]) {
                        pos--;
                        for (int j = 0; j < 4; ++j) {
                            v[j]--;
                        }
                    }
                    else {
                        pos--;
                    }
                }

                if (str[i] == 'D') {
                    if (pos == n) {
                        pos = 1;
                        v[3] = 4;
                        v[2] = 3;
                        v[1] = 2;
                        v[0] = 1;
                    }
                    else if (pos == v[3]) {
                        pos++;
                        for (int j = 0; j < 4; ++j) {
                            v[j]++;
                        }
                    }
                    else {
                        pos++;
                    }
                }

            }

            for (int i = 0; i < 4; ++i) {
                cout << v[i] << ' ';
            }
            cout << endl;
            cout << pos << endl;
        }
    }

}