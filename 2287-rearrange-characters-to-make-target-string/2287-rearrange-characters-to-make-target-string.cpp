class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<vector<int>> map(2, vector<int>(26, 0));
        for (int i = 0; i < s.length(); i++) {
            map[0][s[i] - 'a']++;
        }
        for (int i = 0; i < target.length(); i++) {
            map[1][target[i] - 'a']++;
        }
        int count = -1;
        for (int i = 0; i < 26; i++) {
            if (map[1][i] > 0) {
                if (count == -1) {
                    count = map[0][i] / map[1][i];
                } else {
                    count = min(count, map[0][i] / map[1][i]);
                }
            }
        }
        return count;
    }
};