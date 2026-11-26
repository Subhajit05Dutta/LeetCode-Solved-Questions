class SmallestInfiniteSet {
    set<int> st;
    int curr;

public:
    SmallestInfiniteSet() { curr = 1; }

    int popSmallest() {
        if (!st.empty()) {
            int ans = *st.begin();
            st.erase(st.begin());
            return ans;
        }
        return curr++;
    }

    void addBack(int num) {
        if (num < curr)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */