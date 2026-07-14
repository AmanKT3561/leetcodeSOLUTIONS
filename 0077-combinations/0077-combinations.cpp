class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        function<void(int , vector<int>&)> func = [&](int idx,
                                                    vector<int>& temp) {
            if (temp.size() == k ) {
                ans.push_back(temp);
                return;
            }

            for (int i = idx; i <= n; i++) {
                temp.push_back(i);
                func(i + 1, temp);
                temp.pop_back();
            }
        };
        vector<int> temp;
        func(1, temp);
        return ans;
    }
};