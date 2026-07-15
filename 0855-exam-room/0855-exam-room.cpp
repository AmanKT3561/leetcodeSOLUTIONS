class ExamRoom {
public:
    int n;
    set<int> seats;

    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int dist = *seats.begin();
        int ans = 0;

        auto prev = seats.begin();
        auto it = next(seats.begin());

        while (it != seats.end()) {
            int d = (*it - *prev) / 2;
            if (d > dist) {
                dist = d;
                ans = *prev + d;
            }
            prev = it;
            ++it;
        }

        if (n - 1 - *seats.rbegin() > dist) {
            ans = n - 1;
        }

        seats.insert(ans);
        return ans;
    }

    void leave(int p) {
        seats.erase(p);
    }
};