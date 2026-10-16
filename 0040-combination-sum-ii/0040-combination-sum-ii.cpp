class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector < vector<int>>& ans, vector<int> current) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target)
                break;
            current.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], ans, current);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector < vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, ans, current);
        return ans;
    }
};