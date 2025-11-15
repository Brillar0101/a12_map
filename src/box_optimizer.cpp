#include "box_optimizer.hpp"
#include <unordered_map>
#include <algorithm>

std::pair<int, int> findItemsForBox(const std::vector<int>& item_weights, int box_capacity) {
    std::unordered_map<int, int> weight_to_index;
    
    // goes through all the items 
    for (int i = 0; i < item_weights.size(); i++) {
        int current_weight = item_weights[i];
        int needed = box_capacity - current_weight;
        
        // checks if complementary weight exists
        if (weight_to_index.find(needed) != weight_to_index.end()) {
            int j = weight_to_index[needed];
            if (i < j) {
                return std::make_pair(i, j);
            } else {
                return std::make_pair(j, i);
            }
        }
        
        // stores the weight and it's index
        weight_to_index[current_weight] = i;
    }

    return std::make_pair(-1, -1);
}