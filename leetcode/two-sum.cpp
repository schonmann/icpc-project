class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indexByNumber;
        for (int i = 0; i < nums.size(); i++) {
            indexByNumber[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator sumComplementEntry = indexByNumber.find(target - nums[i]);
            bool hasValidSumComplement = sumComplementEntry != indexByNumber.end() && sumComplementEntry->second != i;
            if (hasValidSumComplement) {
                return vector<int>{ i, sumComplementEntry->second };
            }
        }
        return vector<int>();
    }
};