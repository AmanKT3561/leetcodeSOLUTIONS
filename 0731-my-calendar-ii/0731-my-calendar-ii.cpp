class MyCalendarTwo {
public:
    map<int, int> mp;
    MyCalendarTwo() { mp.clear(); }

    bool book(int s, int e) {
        mp[s] += 1;
        mp[e] -= 1;
        int count = 0;
        for (auto& i : mp) {
            count += i.second;
            if (count > 2) {
                mp[s] -= 1;
                mp[e] += 1;
                return 0;
            }
           
        }
         return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */