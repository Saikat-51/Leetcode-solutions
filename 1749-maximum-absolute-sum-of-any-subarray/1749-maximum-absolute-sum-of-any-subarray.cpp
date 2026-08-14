class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnd=0;
        int minEnd=0;

        int maxSum=0;
        int minSum=0;

        for(int X:nums){
            maxEnd=max(X,maxEnd+X);
            minEnd=min(X,minEnd+X);
            maxSum=max(maxSum,maxEnd);
            minSum=min(minSum,minEnd);
        }
        return max(maxSum,-minSum);
    }
};