class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low + k;
    }
};

/*
    //Alternative Approach with O(n) time complexity

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 1;
        int i = 0;
        int ans = 0;
        while (i < n) {
            if (arr[i] == st) {
                st++;
                i++;
            } else {
                k--;
                if (k == 0) {
                    ans = st;
                    break;
                }
                st++;
            }
        }
        if (ans == 0 && i == n) {
            ans = arr[n - 1] + k;
        }
        return ans;
    }
*/