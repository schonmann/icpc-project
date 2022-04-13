class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int lastNonZeroIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                lastNonZeroIndex++;
                if (i != lastNonZeroIndex) {
                    nums[lastNonZeroIndex] = nums[i];
                    nums[i] = 0;
                }
            }
        }
        return nums;
    }
};