class Solution {
public:
    bool isleap(int y) {
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
            return true;
        return false;
    }
    string dayOfTheWeek(int day, int month, int year) {

        // As January 1, 1971 was a Friday.
        vector<string> week_days = {"Friday", "Saturday", "Sunday",
    "Monday", "Tuesday", "Wednesday", "Thursday"};
        vector<int> days_in_month = {31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};

        int odd_days = 0;

        // Days in previous years
        for (int i = 1971; i < year; i++) {
            odd_days += isleap(i) ? 366 : 365;
        }
        
        // Days in previous months
        for (int m = 1; m < month; m++) {
            if (m == 2 && isleap(year)) {
                odd_days += 29;
            } else {
                odd_days += days_in_month[m - 1];
            }
        }
        // Current month's days
        odd_days += (day - 1);

        return week_days[odd_days%7];
    }
};