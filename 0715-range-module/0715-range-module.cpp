class RangeModule {
private:
    set<pair<int, int>> st;

public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = st.lower_bound({left, 0});
        if (it != st.begin()) {
            auto prevIt = prev(it);
            if (prevIt->second >= left)
                it = prevIt;
        }
        int mini = left, maxi = right;
        while (it != st.end() && it->first <= right) {
            maxi = max(maxi, it->second);
            mini = min(mini, it->first);
            it = st.erase(it);
        }
        st.insert({mini, maxi});
    }

    bool queryRange(int left, int right) {
        auto it = st.upper_bound({left, INT_MAX});
        if (it == st.begin())
            return false;
        auto prevIt = prev(it);
        return prevIt->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = st.lower_bound({left, 0});
        if (it != st.begin()) {
            auto prevIt = prev(it);
            if (prevIt->second > left)
                it = prevIt;
        }
        vector<pair<int, int>> temp;
        while (it != st.end() && it->first < right) {
            if (it->first < left)
                temp.push_back({it->first, left});
            if (it->second > right)
                temp.push_back({right, it->second});
            it = st.erase(it);
        }
        for (auto& pair : temp)
            st.insert(pair);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */