#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
      string input1;
      string input2;
      cin >> input1 >> input2;
      vector<int> result;
      result.resize(input1.size() + input2.size(), 0);
      if (input1.size() > input2.size()) {
            swap(input1, input2);
      }
      for (int i = input1.size() - 1; i >= 0; i--) {
            for (int j = input2.size() - 1; j >= 0; j--) {
                  result[i + j + 1] += (input1[i]-'0') * (input2[j]-'0');
            }
      }
      string ans;
      int pos = result.size() - 1;
      while (result[pos] == 0) {
            pos--;
      }
      int carry = 0;
      while (result[pos] != 0) {
            ans = to_string((result[pos] + carry)% 10) + ans;
            carry = (result[pos]+carry) / 10;
            pos--;
      }
      if (carry > 0) {
            ans = to_string(carry) + ans;
      }
      cout << ans << endl;
}
