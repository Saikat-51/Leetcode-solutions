class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct = nums[0];
        int minproduct = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int newmax = max({x, maxproduct * x, minproduct * x});
            int newmin = min({x, maxproduct * x, minproduct * x});

            maxproduct = newmax;
            minproduct = newmin;

            ans = max(ans, maxproduct);
        }
        return ans;
    }
};