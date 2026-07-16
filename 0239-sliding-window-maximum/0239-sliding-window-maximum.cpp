class SparseTable {
    vector<vector<int>> st;
    vector<int> lg;
    int n;

public:
    SparseTable(vector<int>& arr) {
        n = arr.size();

        // Precompute logs
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;
        st.assign(K, vector<int>(n));

        // Level 0
        for (int i = 0; i < n; i++)
            st[0][i] = arr[i];

        // Build Sparse Table
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = max(st[j - 1][i],
                               st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    // Maximum in [L, R]
    int query(int L, int R) {
        int len = R - L + 1;
        int j = lg[len];
        return max(st[j][L],
                   st[j][R - (1 << j) + 1]);
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;

        
        vector<int> result;

      
        int l= 0 ;
        int r = k-1;
        int n = arr.size();

        SparseTable st(arr);


        while(r<n){
          result.push_back(st.query(l , r));
          l++;
          r++;
        } 
            

        return result;
          

    }
};