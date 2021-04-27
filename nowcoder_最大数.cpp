class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */
    static bool cmp(string& str1, string&str2) {
        return str1 + str2 > str2 + str1;
    }
    string solve(vector<int>& nums) {
        // write code here
        vector<string> input;
        for(int i = 0; i < nums.size(); i++) {
            input.push_back(to_string(nums[i]));
        }
        sort(input.begin(), input.end(), cmp);
        if(input[0] == "0")
            return "0";
        string ret;
        for(int i = 0; i < input.size(); i++) {
            ret += input[i];
        }
        return ret;
    }
};
