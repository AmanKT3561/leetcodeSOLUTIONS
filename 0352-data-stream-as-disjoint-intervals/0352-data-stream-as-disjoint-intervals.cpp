class SummaryRanges {
public:
    map<int, int> mp;
    SummaryRanges() {}

    void addNum(int value) { mp[value]++; }

    vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    int val = -1;
    int firstval = -1;

    for (auto i : mp) {

        if (val == -1) {
            val = i.first;
            firstval = i.first;
            continue;
        }

        if (i.first == val + 1) {
            val = i.first;
        } else {
            ans.push_back({firstval, val});
            firstval = i.first;
            val = i.first;
        }
    }

    if (val != -1)
        ans.push_back({firstval, val});

    return ans;
}
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */