class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> row;
        vector<int> ans;
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1)
                    count++;
            }
            row.push_back({i, count});
        }
        sort(row.begin(), row.end(), [](auto& a, auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        });
        for (int i = 0; i < k; i++) {
            ans.push_back(row[i].first);
        }
        return ans;
    }
};