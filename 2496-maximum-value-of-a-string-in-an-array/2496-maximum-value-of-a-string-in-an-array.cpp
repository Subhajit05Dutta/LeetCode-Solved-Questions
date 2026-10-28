class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int mxlen = 0;
        for (int i = 0; i < strs.size(); i++) {
            bool dig = true;
            int j = 0;
            while (j < strs[i].size()) {
                if (isdigit(strs[i][j])) {
                    j++;
                } else {
                    dig = false;
                    break;
                }
            }
            int len = strs[i].size();
            if (dig == true) {
                int num = stoi(strs[i]);
                mxlen = max(mxlen, num);
            } else {
                mxlen = max(mxlen, len);
            }
        }
        return mxlen;
    }
};