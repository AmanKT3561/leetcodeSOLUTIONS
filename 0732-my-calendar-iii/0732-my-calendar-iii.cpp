class MyCalendarThree {
public:map<int, int> mp;
int cnt = 0;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int s, int e) {
         mp[s] += 1;
         mp[e] -= 1;
         int count =0;
        for (auto& i : mp) {
            count += i.second;
            cnt = max(count , cnt);
        }
        return cnt;
         
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */