class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }

        for(int i = ptr; i < nums.size(); i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }


    }
};