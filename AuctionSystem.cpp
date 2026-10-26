#include <unordered_map>
#include <set>
#include <utility>

class AuctionSystem {
private:
    // itemId -> (userId -> bidAmount) para búsquedas y actualizaciones rápidas
    std::unordered_map<int, std::unordered_map<int, int>> userBids;
    
    // itemId -> set de pares {bidAmount, userId} ordenados por monto y luego por userId
    std::unordered_map<int, std::set<std::pair<int, int>>> itemBids;

public:
    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
        // Si el usuario ya tenía una oferta para este ítem, la removemos primero
        if (userBids[itemId].find(userId) != userBids[itemId].end()) {
            int oldAmount = userBids[itemId][userId];
            itemBids[itemId].erase({oldAmount, userId});
        }
        
        // Registramos la nueva oferta
        userBids[itemId][userId] = bidAmount;
        itemBids[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = userBids[itemId][userId];
        itemBids[itemId].erase({oldAmount, userId});
        
        userBids[itemId][userId] = newAmount;
        itemBids[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        int oldAmount = userBids[itemId][userId];
        itemBids[itemId].erase({oldAmount, userId});
        userBids[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if (itemBids[itemId].empty()) {
            return -1;
        }
        // El último elemento del set tiene el mayor bidAmount y, en caso de empate, el mayor userId
        return itemBids[itemId].rbegin()->second;
    }
};
