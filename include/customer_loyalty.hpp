#ifndef CUSTOMER_LOYALTY_HPP
#define CUSTOMER_LOYALTY_HPP

#include <map>
#include <string>

std::map<int, std::string> createLoyaltyTiers();

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score);

#endif 