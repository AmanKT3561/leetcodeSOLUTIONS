class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
          priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
          if(arr.empty()) return {};
          int N = arr.size();
        int x = *min_element(arr.begin() , arr.end());
        for(int i = 0;i<N ;i++)
        {
            pq.push({arr[i] , i});
            
        }
        vector<int> ans(N);
        int rank = 0;
        int prev = INT_MAX;
        while(!pq.empty()){
           int j = pq.top().second;
           int i = pq.top().first;
           pq.pop();
            if( i != prev)
           {
               rank++;
           }
           prev = i;
           ans[j] = rank;
            
        }
        return ans;
    }
};