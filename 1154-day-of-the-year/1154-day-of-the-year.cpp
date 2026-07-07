class Solution {
public:
    int dayOfYear(string date) {
        string year = "";
        string month = "";
        string day = "";
        for (int i = 0; i < 10; i++) {
            if (i < 4)
                year += date[i];
            else if (i < 7 && i > 4)
                month += date[i];
            else if (i < 10 && i > 7)
                day += date[i];
        }
        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        int extra = 0;
        // Check leap year
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
            extra = 1;
        }
        int sum_days = 0;
        for (int i = 1; i < m; i++) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 ||
                i == 12) {
                sum_days += 31;
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                sum_days += 30;
            } else if (i == 2) {
                if (extra == 1)
                    sum_days += 29;
                else
                    sum_days += 28;
            }
        }
        sum_days += d;
        return sum_days;
    }
};