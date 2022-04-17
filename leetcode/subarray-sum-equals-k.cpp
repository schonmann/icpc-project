class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> ocurrencesBySum;
        int sum = 0;
        int count = 0;
        ocurrencesBySum[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            auto it = ocurrencesBySum.find(sum - k);
            if (it != end(ocurrencesBySum)) {
                count += it->second;
            }
            ocurrencesBySum[sum]++;
        }
        return count;
    }
};