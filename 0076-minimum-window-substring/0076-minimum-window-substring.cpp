class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need, window;

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            window[c]++;

            if (need.count(c) && window[c] <= need[c]) {
                count++;
            }

            while (count == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    count--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};