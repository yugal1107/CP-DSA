class AuctionSystem {
public:
    using ll = long long;
    unordered_map<ll, unordered_map<ll, ll>> u;
    unordered_map<ll, set<vector<int>>> a;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (u.find(userId)!=u.end()){
            if (u[userId].find(itemId)!=u[userId].end()){
                int amt = u[userId][itemId];
                a[itemId].erase({amt, userId});
            }
        }
        u[userId][itemId] = bidAmount;
        a[itemId].insert({ bidAmount, userId });
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int amt = u[userId][itemId];
        a[itemId].erase({ amt, userId});
        
        u[userId][itemId] = newAmount;
        a[itemId].insert({ newAmount, userId });
    }
    
    void removeBid(int userId, int itemId) {
        int amt = u[userId][itemId];
        u[userId].erase(itemId);
        a[itemId].erase({ amt, userId});
    }
    
    int getHighestBidder(int itemId) {
        if (a[itemId].empty()) return -1;
        auto it = a[itemId].end(); 
        vector<int> v = *prev(it);
        return v[1];
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */