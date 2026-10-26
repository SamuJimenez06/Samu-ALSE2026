#include <vector>

class ATM {
private:
    long long banknotes[5]; // Usamos long long para evitar desbordamientos de cantidad
    const int denominations[5] = {20, 50, 100, 200, 500};

public:
    ATM() {
        for (int i = 0; i < 5; ++i) {
            banknotes[i] = 0;
        }
    }
    
    void deposit(std::vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            banknotes[i] += banknotesCount[i];
        }
    }
    
    std::vector<int> withdraw(int amount) {
        std::vector<int> count(5, 0);
        long long temp_banknotes[5];
        
        // Copiamos el estado actual para simular el retiro
        for (int i = 0; i < 5; ++i) {
            temp_banknotes[i] = banknotes[i];
        }
        
        // Intentamos retirar priorizando billetes de mayor valor (de 500 hacia abajo)
        for (int i = 4; i >= 0; --i) {
            if (amount <= 0) break;
            
            long long needed = amount / denominations[i];
            long long take = std::min(needed, temp_banknotes[i]);
            
            count[i] = take;
            amount -= take * denominations[i];
            temp_banknotes[i] -= take;
        }
        
        // Si no logramos completar el monto exacto, rechazamos la operación
        if (amount > 0) {
            return {-1};
        }
        
        // Si fue exitoso, actualizamos los billetes reales del cajero
        for (int i = 0; i < 5; ++i) {
            banknotes[i] = temp_banknotes[i];
        }
        
        return count;
    }
};
