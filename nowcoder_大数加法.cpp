string solve(string s, string t) {
      // write code here
      if (s.empty())
            return t;
      if (t.empty())
            return s;
      if (s.size() < t.size()) {
            swap(s, t);
      }
      int len = s.size() - t.size();
      while (len--) {
            t = '0' + t;
      }
      // 表示进位
      int carry = 0;
      int tmp = 0;
      for (int i = s.size() - 1; i >= 0; i--) {
            tmp = s[i] - '0' + t[i] - '0' + carry;
            if (tmp > 9) {
                  carry = 1;
                  tmp -= 10;
            }
            else {
                  carry = 0;
            }
            s[i] = tmp + '0';
      }
      if (carry == 1)
            s = '1' + s;
      return s;
}
