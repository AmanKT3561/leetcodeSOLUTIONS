#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

class MedianFinder {
public:
    ordered_set st;
    int id = 0;

    MedianFinder() {}

    void addNum(int num) {
        st.insert({num, id++});
    }

    double findMedian() {
        int n = st.size();

        if (n & 1) {
            return st.find_by_order(n / 2)->first;
        }

        auto it1 = st.find_by_order(n / 2 - 1);
        auto it2 = st.find_by_order(n / 2);

        return (it1->first + it2->first) / 2.0;
    }
};