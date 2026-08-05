class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = 0;
        for (int i = 0; i < arr1.size(); i++) {
            int flag = 1;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr2[j] - arr1[i]) <= d) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                n++;
            }
        }
        return n;
    }
};