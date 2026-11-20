class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int sc = 0, cnt = 0;
        for (int i = 0; i < events.size(); i++) {
            if (events[i] == "WD") {
                sc += 1;
            } else if (events[i] == "NB") {
                sc += 1;
            } else if (events[i] == "W") {
                cnt += 1;
            } else {
                sc += stoi(events[i]);
            }
            if (cnt == 10) {
                break;
            }
        }
        return {sc, cnt};
    }
};