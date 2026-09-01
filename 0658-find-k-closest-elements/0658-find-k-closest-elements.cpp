class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> closer;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            closer.push_back({arr[i], diff});
        }
        sort(closer.begin(), closer.end(), [](auto& a, auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a < b;
            }
        });
        for (int i = 0; i < k; i++) {
            ans.push_back(closer[i].first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};