class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = INT_MIN / 2;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int newNoDelete = max(noDelete + arr[i], arr[i]);

            int newOneDelete = max(oneDelete + arr[i], noDelete);

            noDelete = newNoDelete;
            oneDelete = newOneDelete;

            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};