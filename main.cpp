#include <iostream>
#include <vector>
#include "ATM.cpp"

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i + 1 < vec.size() ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main() {
    ATM atm;
    
    // atm.deposit([0,0,1,2,1]) -> Depósitos: 1 de $100, 2 de $200, 1 de $500
    atm.deposit({0, 0, 1, 2, 1});
    
    // atm.withdraw(600) -> Esperado: [0, 0, 1, 0, 1]
    std::vector<int> res1 = atm.withdraw(600);
    std::cout << "withdraw(600): ";
    printVector(res1);

    // atm.deposit([0,1,0,1,1]) -> Depósitos: 1 de $50, 1 de $200, 1 de $500
    atm.deposit({0, 1, 0, 1, 1});
    
    // atm.withdraw(600) -> Esperado: [-1] (Rechazado)
    std::vector<int> res2 = atm.withdraw(600);
    std::cout << "withdraw(600): ";
    printVector(res2);

    // atm.withdraw(550) -> Esperado: [0, 1, 0, 0, 1]
    std::vector<int> res3 = atm.withdraw(550);
    std::cout << "withdraw(550): ";
    printVector(res3);

    return 0;
}
