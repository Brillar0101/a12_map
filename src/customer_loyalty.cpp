#include "customer_loyalty.hpp"
#include <map>
#include <string>

std::map<int, std::string> createLoyaltyTiers() {
    std::map<int, std::string> tiers;
    
    // tier thresholds
    tiers[0] = "Bronze";
    tiers[500] = "Silver";
    tiers[1000] = "Gold";
    tiers[2000] = "Platinum";
    
    return tiers;
}

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score) {
    // looks for the tier boundary
    std::map<int, std::string>::const_iterator it = tiers.lower_bound(score);
    
    if (it == tiers.end()) {
        it--;
        return it->second;
    }
    
    if (it->first == score) {
        return it->second;
    }
    
    if (it == tiers.begin()) {
        return it->second;
    }
    
    it--;
    return it->second;
}