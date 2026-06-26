class MedianFinder {
public:
    priority_queue<int> pq;   // max heap
    priority_queue<int, vector<int>, greater<int>> mn; // min heap

    MedianFinder() {}

    void addNum(int num) {

        if (pq.empty() || num <= pq.top())
            pq.push(num);
        else
            mn.push(num);

        if (pq.size() > mn.size() + 1) {
            mn.push(pq.top());
            pq.pop();
        }
        else if (mn.size() > pq.size()) {
            pq.push(mn.top());
            mn.pop();
        }
    }

    double findMedian() {

        if (pq.size() == mn.size())
            return (pq.top() + mn.top()) / 2.0;

        return pq.top();
    }
};