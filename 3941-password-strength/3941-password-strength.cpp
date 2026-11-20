class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < password.size(); i++) {
            mpp[password[i]]++;
        }
        int total = 0;
        for (auto& it : mpp) {

            if (isdigit(it.first)) {
                total += 3;
            } else if (isupper(it.first)) {
                total += 2;
            } else if (islower(it.first)) {
                total += 1;
            } else {
                total += 5;
            }
        }
        return total;
    }
};