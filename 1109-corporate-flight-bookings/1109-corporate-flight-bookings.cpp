class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& arr, int n) {
        vector<int> diff(n+1);

        for(auto i:arr){
        diff[i[0] - 1] += i[2];
        if(i[1] <= n ) diff[i[1]] -= i[2];
        }

         vector<int> freq(n);

        freq[0] = diff[0];
        for (int i = 1; i < n; i++)
            freq[i] = freq[i - 1] + diff[i];

        return freq;
    }
};