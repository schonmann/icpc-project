class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroIndex = -1, i = 0; i < nums.size(); i++) {
            if (nums[i] != 0 && i != ++lastNonZeroIndex) {
                swap(nums[lastNonZeroIndex], nums[i]);
            }
        }
    }
};
