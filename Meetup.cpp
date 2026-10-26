#include <string>
#include <stdexcept>

class Meetup {
private:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) {
        switch (month) {
            case 2: return isLeapYear(year) ? 29 : 28;
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }

    
    int getDayOfWeek(int day, int month, int year) {
        if (month < 3) {
            month += 12;
            year -= 1;
        }
        int q = day;
        int m = month;
        int k = year % 100;
        int j = year / 100;
        int h = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

        return (h + 5) % 7 + 1 == 7 ? 0 : (h + 5) % 7 + 1; 
    }


};
