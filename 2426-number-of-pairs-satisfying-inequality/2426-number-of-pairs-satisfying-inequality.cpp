class Solution {
    #define ll long long 
    int N=1e5;
    vector<ll>BIT;

    void update(int ind){
        while(ind<N){
            BIT[ind]+=1;
            ind+=(ind&(-ind));
        }
    }

    ll query(int ind){
        ll sum=0;
        while(ind>0){
            sum+=BIT[ind];
            ind-=(ind&(-ind));
        }
        return sum;
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        BIT.resize(N,0);

        ll ans=0, shift=1e4;

        for(int i=0; i<n; i++){
            int ind=nums1[i]-nums2[i]+diff+2*shift;
            ans+=query(ind+1);

            int val=nums1[i]-nums2[i]+2*shift;
            update(val+1);
        }

        return ans;
    }
};