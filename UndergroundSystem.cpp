#include <string>
#include <unordered_map>
#include <utility>

class UndergroundSystem {
private:
    struct CheckInInfo {
        std::string stationName;
        int t;
    };

    struct RouteInfo {
        long long totalTime = 0;
        int count = 0;
    };

    std::unordered_map<int, CheckInInfo> checkIns;
    std::unordered_map<std::string, RouteInfo> routes;

public:
    UndergroundSystem() {}

    void checkIn(int id, std::string stationName, int t) {
        checkIns[id] = {stationName, t};
    }

    void checkOut(int id, std::string stationName, int t) {
        auto it = checkIns.find(id);
        if (it != checkIns.end()) {
            std::string startStation = it->second.stationName;
            int startTime = it->second.t;
            checkIns.erase(it);

            std::string routeKey = startStation + "->" + stationName;
            routes[routeKey].totalTime += (t - startTime);
            routes[routeKey].count += 1;
        }
    }

    double getAverageTime(std::string startStation, std::string endStation) {
        std::string routeKey = startStation + "->" + endStation;
        auto it = routes.find(routeKey);
        if (it != routes.end()) {
            return (double)it->second.totalTime / it->second.count;
        }
        return 0.0;
    }
};
