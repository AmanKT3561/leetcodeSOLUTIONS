class SummaryRanges {
public:
    map<int, int> mp; 

    SummaryRanges() {}

    void addNum(int value) {

        auto it = mp.upper_bound(value);

        int left = value, right = value;

        if (it != mp.begin()) {
            auto prev = it;
            --prev;

            if (prev->second >= value)
                return; 

            if (prev->second + 1 == value) {
                left = prev->first;
                mp.erase(prev);
            }
        }

        if (it != mp.end() && it->first - 1 == value) {
            right = it->second;
            mp.erase(it);
        }

        mp[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (auto &[l, r] : mp)
            ans.push_back({l, r});

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */