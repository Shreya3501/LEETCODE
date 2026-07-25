class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node]++;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx);
        else
            update(2 * node + 1, mid + 1, r, idx);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }
};

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        SegmentTree st(vals.size());

        long long ans = 0;

        for (int x : prefix) {

            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin();

            if (idx > 0)
                ans += st.query(1, 0, vals.size() - 1, 0, idx - 1);

            st.update(1, 0, vals.size() - 1, idx);
        }

        return (int)ans;
    }
};