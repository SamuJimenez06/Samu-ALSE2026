#include <iostream>
#include "AuctionSystem.cpp"

int main() {
    AuctionSystem auctionSystem;
    
    auctionSystem.addBid(1, 7, 5);
    auctionSystem.addBid(2, 7, 6);
    std::cout << "getHighestBidder(7): " << auctionSystem.getHighestBidder(7) << " (Esperado: 2)" << std::endl;

    auctionSystem.updateBid(1, 7, 8);
    std::cout << "getHighestBidder(7): " << auctionSystem.getHighestBidder(7) << " (Esperado: 1)" << std::endl;

    auctionSystem.removeBid(2, 7);
    std::cout << "getHighestBidder(7): " << auctionSystem.getHighestBidder(7) << " (Esperado: 1)" << std::endl;
    std::cout << "getHighestBidder(3): " << auctionSystem.getHighestBidder(3) << " (Esperado: -1)" << std::endl;

    return 0;
}
