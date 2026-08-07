using ll = long long;
class MergeSortTree {
private:
    vector<vector<ll>> seg;

public:
    MergeSortTree(int n) { seg.resize(4 * n); }

    vector<ll> merge(vector<ll>& A, vector<ll>& B) {
        int n1 = A.size(), n2 = B.size();
        int i = 0, j = 0;
        vector<ll> ans;
        while (i < n1 && j < n2) {
            if (A[i] < B[j])
                ans.push_back(A[i++]);
            else
                ans.push_back(B[j++]);
        }
        while (i < n1)
            ans.push_back(A[i++]);
        while (j < n2)
            ans.push_back(B[j++]);
        return ans;
    }

    void buildMergeSortTree(int idx, int l, int r, vector<ll>& pref) {
        if (l == r) {
            seg[idx] = {pref[l]};
            return;
        }
        int mid = (l + r) / 2;
        buildMergeSortTree(2 * idx + 1, l, mid, pref);
        buildMergeSortTree(2 * idx + 2, mid + 1, r, pref);
        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
        return;
    }
    int query(int idx, int l, int r, int start, int end, ll mini, ll maxi) {
        if (l > end || r < start)
            return 0;
        if (l >= start && r <= end) {
            return upper_bound(seg[idx].begin(), seg[idx].end(), maxi) - lower_bound(seg[idx].begin(), seg[idx].end(), mini);
        }
        int mid = (l + r) / 2;
        int left = query(2 * idx + 1, l, mid, start, end, mini, maxi);
        int right = query(2 * idx + 2, mid + 1, r, start, end, mini, maxi);
        return left + right;
    }
};
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];
        int ans = 0;
        MergeSortTree* tree = new MergeSortTree(n + 1);
        tree->buildMergeSortTree(0, 0, n, pref);
        for (int i = 1; i <= n; i++) {
            int var = tree->query(0, 0, n, 0, i - 1, pref[i] - upper,
                                  pref[i] - lower);
            ans += var;
        }
        delete tree;
        return ans;
    }
};