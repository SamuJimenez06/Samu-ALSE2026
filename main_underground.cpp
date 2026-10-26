#include <iostream>
#include "UndergroundSystem.cpp"

int main() {
    UndergroundSystem undergroundSystem;
    
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);

    std::cout << "getAverageTime(\"Leyton\", \"Waterloo\"): " << undergroundSystem.getAverageTime("Leyton", "Waterloo") << std::endl;
    std::cout << "getAverageTime(\"Paradise\", \"Cambridge\"): " << undergroundSystem.getAverageTime("Paradise", "Cambridge") << std::endl;

    undergroundSystem.checkIn(10, "Leyton", 24);
    std::cout << "getAverageTime(\"Leyton\", \"Waterloo\"): " << undergroundSystem.getAverageTime("Leyton", "Waterloo") << std::endl;

    undergroundSystem.checkOut(10, "Waterloo", 38);
    std::cout << "getAverageTime(\"Leyton\", \"Waterloo\"): " << undergroundSystem.getAverageTime("Leyton", "Waterloo") << std::endl;

    return 0;
}
