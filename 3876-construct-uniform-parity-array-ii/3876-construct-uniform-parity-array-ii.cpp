class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int minOdd = INT_MAX;
        for (int& i : nums1)
            if (i & 1)
                minOdd = min(minOdd, i);

        auto helper = [&](int parity) {
            for (int& i : nums1) {
                if ((i & 1) != parity && i <= minOdd)
                    return false;
            }
            return true;
        };

        return helper(0) || helper(1);
    }
};