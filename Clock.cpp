#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Clock {
private:
    int totalMinutes;


    static int normalize(int minutes) {
        int dayMinutes = 24 * 60;
        minutes %= dayMinutes;
        if (minutes < 0) {
            minutes += dayMinutes;
        }
        return minutes;
    }

public:
    Clock(int hours, int minutes) {
        totalMinutes = normalize(hours * 60 + minutes);
    }

    static Clock at(int hours, int minutes) {
        return Clock(hours, minutes);
    }

    Clock plus(int minutes) const {
        return Clock(0, totalMinutes + minutes);
    }

    Clock minus(int minutes) const {
        return Clock(0, totalMinutes - minutes);
    }

    std::string toString() const {
        int h = (totalMinutes / 60) % 24;
        int m = totalMinutes % 60;
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << h << ":"
            << std::setfill('0') << std::setw(2) << m;
        return oss.str();
    }


    bool operator==(const Clock& other) const {
        return totalMinutes == other.totalMinutes;
    }

    bool operator!=(const Clock& other) const {
        return !(*this == other);
    }
};
