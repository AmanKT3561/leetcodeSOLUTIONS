class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(),
             [](const vector<int>& i, const vector<int>& j) {
                 if (i[0] == j[0])
                     return i[1] > j[1];
                 return i[0] < j[0];
             });
        int last = arr[0][1];
        int fs = arr[0][0];
        int cnt = 0;

        for (auto i : arr)
            cout << i[0] << i[1] << " ";

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] >= fs && arr[i][1] <= last) {
                cnt++;
            } else {
                last = arr[i][1];
                fs = arr[i][0];
            }
        }
        return arr.size() - cnt;
    }
};