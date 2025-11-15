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