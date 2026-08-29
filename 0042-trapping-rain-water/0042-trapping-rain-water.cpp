class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int l = 0;
        int r = n - 1;
        int lmax = 0, rmax = 0;
        while (l < r) {
            lmax = max(height[l], lmax);
            rmax = max(height[r], rmax);
            if (lmax < rmax) {
                total += (lmax - height[l]);
                l++;
            } else {
                total += (rmax - height[r]);
                r--;
            }
        }
        return total;
    }
};