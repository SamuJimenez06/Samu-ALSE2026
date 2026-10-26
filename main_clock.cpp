#include <iostream>
#include "Clock.cpp"

int main() {
    std::cout << "=== PRUEBAS CLOCK ===" << std::endl;

    Clock c1 = Clock::at(10, 30);
    std::cout << "Hora inicial (10:30): " << c1.toString() << std::endl;

    Clock c2 = c1.plus(90);
    std::cout << "Sumar 90 minutos (12:00): " << c2.toString() << std::endl;

    Clock c3 = c1.minus(40);
    std::cout << "Restar 40 minutos (09:50): " << c3.toString() << std::endl;

    Clock c4 = Clock::at(12, 0);
    if (c2 == c4) {
        std::cout << "Comparacion de igualdad (12:00 == 12:00): Exitoso!" << std::endl;
    }

    return 0;
}
