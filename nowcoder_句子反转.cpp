#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    while(getline(cin, str)) {
        vector<string> v;
        string temp;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ')
                continue;
            temp.resize(0);
            while(str[i] != ' ' && i < str.size()) {
                temp += str[i];
                i++;
            }
            v.push_back(temp);
        }
        int j = v.size() - 1;
        while(j >= 1) {
            cout << v[j] << " ";
            j--;
        }
        cout << v[0] << endl;
    }
}