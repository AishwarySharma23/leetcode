class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        
        for (int size = l; size <= r; ++size) {
            int sum = 0;
            for (int i = 0; i < size; ++i) {
                sum += nums[i];
            }
            if (sum > 0) {
                ans = min(ans, sum);
            }
            for (int i = size; i < n; ++i) {
                sum += nums[i] - nums[i - size];
                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
