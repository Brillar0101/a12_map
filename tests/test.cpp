#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "api_monitor.hpp"
#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"

#include <map>
#include <vector>
#include <string>

TEST_CASE("Box Fitting Optimizer used to find correct indices", "[box_optimizer]") {
    std::vector<int> weights;
    weights.push_back(10);
    weights.push_back(20);
    weights.push_back(30);
    weights.push_back(40);
    weights.push_back(50);
    
    int box_capacity = 70;
    std::pair<int, int> result = findItemsForBox(weights, box_capacity);
    
    REQUIRE(result.first == 2);
    REQUIRE(result.second == 3);
    REQUIRE(weights[result.first] + weights[result.second] == box_capacity);
}

TEST_CASE("Cart analysis to find common products", "[cart_analysis]") {
    std::vector<std::vector<std::string>> carts;
    
    std::vector<std::string> cart1;
    cart1.push_back("laptop");
    cart1.push_back("mouse");
    cart1.push_back("keyboard");
    carts.push_back(cart1);
    
    std::vector<std::string> cart2;
    cart2.push_back("laptop");
    cart2.push_back("mouse");
    cart2.push_back("monitor");
    carts.push_back(cart2);
    
    std::vector<std::string> cart3;
    cart3.push_back("mouse");
    cart3.push_back("laptop");
    cart3.push_back("webcam");
    carts.push_back(cart3);
    
    std::vector<std::string> common = commonProductsAcrossCarts(carts);
    
    REQUIRE(common.size() == 2);
    REQUIRE(common[0] == "laptop");
    REQUIRE(common[1] == "mouse");
}

TEST_CASE("Customer loyalty assigns correct tiers", "[customer_loyalty]") {
    std::map<int, std::string> tiers = createLoyaltyTiers();
    
    REQUIRE(getLoyaltyTier(tiers, 0) == "Bronze");
    REQUIRE(getLoyaltyTier(tiers, 499) == "Bronze");
    REQUIRE(getLoyaltyTier(tiers, 500) == "Silver");
    REQUIRE(getLoyaltyTier(tiers, 1200) == "Gold");
    REQUIRE(getLoyaltyTier(tiers, 5000) == "Platinum");

}

TEST_CASE("API monitor to find most frequent endpoints", "[api_monitor]") {
    std::vector<std::string> api_logs;
    api_logs.push_back("/api/login");
    api_logs.push_back("/api/cart");
    api_logs.push_back("/api/checkout");
    api_logs.push_back("/api/cart");
    api_logs.push_back("/api/login");
    api_logs.push_back("/api/cart");
    api_logs.push_back("/api/login");
    
    std::pair<std::vector<std::string>, int> result = find_most_frequent_endpoints(api_logs);
    std::vector<std::string> endpoints = result.first;
    int count = result.second;
    
    REQUIRE(count == 3);
    REQUIRE(endpoints.size() == 2);
    REQUIRE(endpoints[0] == "/api/cart");
    REQUIRE(endpoints[1] == "/api/login");
}