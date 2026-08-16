class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = part.size();
        while (true) {

            int st = s.find(part);
            /*if (st == string::npos) means:
            "If part was NOT found inside s*/
            if (st == string::npos) {
                break;
            } else {
                s.erase(st, len);
            }
        }
        return s;
    }
};