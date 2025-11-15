#include "cart_analysis.hpp"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string>

std::vector<std::string> commonProductsAcrossCarts(const std::vector<std::vector<std::string>>& carts) {
    if (carts.size() == 0) {
        return std::vector<std::string>();
    }
    
    std::unordered_map<std::string, int> product_count;
    int total_carts = carts.size();
    
    // goes through each cart
    for (int i = 0; i < carts.size(); i++) {
        std::unordered_set<std::string> seen_in_this_cart;
        
        for (int j = 0; j < carts[i].size(); j++) {
            std::string product = carts[i][j];
            seen_in_this_cart.insert(product);
        }
        
        // counts unique product in the cart
        std::unordered_set<std::string>::iterator it;
        for (it = seen_in_this_cart.begin(); it != seen_in_this_cart.end(); it++) {
            product_count[*it]++;
        }
    }
    
    // collects products that appear in every cart
    std::vector<std::string> result;
    std::unordered_map<std::string, int>::iterator map_it;
    for (map_it = product_count.begin(); map_it != product_count.end(); map_it++) {
        if (map_it->second == total_carts) {
            result.push_back(map_it->first);
        }
    }
    
    // sorts alphabetically
    std::sort(result.begin(), result.end());
    return result;
}