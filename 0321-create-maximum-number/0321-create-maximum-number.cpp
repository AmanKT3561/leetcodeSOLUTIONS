class Solution {
public:

    vector<int> maxnum(vector<int> nums, int k){
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i] && n - i + st.size() > k) st.pop();
            if(st.size() < k) st.push(i);
        }
        vector<int> ans;
        while(!st.empty()) ans.push_back(nums[st.top()]), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string merge(vector<int>& n1, vector<int>& n2, int k){
        vector<int> ans(k, 0);
         int i = 0, j = 0, x = 0;
            while(i < n1.size() && j < n2.size()){
                if(n2[j] > n1[i]) ans[x++] = n2[j], j++;
                else if(n2[j] == n1[i]){
                    int indi=i, indj=j;
                    while(indi < n1.size() && indj < n2.size() && n1[indi] == n2[indj]) indi++, indj++;
                    if(indj == n2.size()) ans[x++] = n1[i], i++;
                    else{
                        if(indi < n1.size() && n1[indi] > n2[indj]) ans[x++] = n1[i], i++;
                        else ans[x++] = n2[j], j++;
                    }
                }

                else ans[x++] = n1[i], i++; 
            }
            while(i < n1.size()) ans[x++] = n1[i], i++;
            while(j < n2.size()) ans[x++] = n2[j], j++;
            string s = "";
            for(auto it: ans) s += to_string(it);
            return s;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        string mx = "";
        for(int i = 0; i <= k && i <= n; i++){
            if((k-i) > m) continue; 
            vector<int> n1 = maxnum(nums1, i);
            vector<int> n2 = maxnum(nums2, k-i);
            string s = merge(n1, n2, k);
            mx = max(mx, s);
        }
        vector<int> res;
        for(int i = 0; i < mx.size(); i++) res.push_back(mx[i] - '0');
        return res;
    }
};