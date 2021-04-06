class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        unordered_map<int, int> hashmap;
        for(int i = 0; i < numbers.size(); i++) {
            if(hashmap.find(target-numbers[i]) != hashmap.end()) {
                return {hashmap[target-numbers[i]] + 1, i+1};
            } 
            else
                hashmap[numbers[i]] = i;
        }
        return {};
    }
};
