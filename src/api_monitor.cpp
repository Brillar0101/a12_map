#include "api_monitor.hpp"
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data) {
    if (log_data.empty()) {
        std::vector<std::string> empty_vec;
        return std::make_pair(empty_vec, 0);
    }
    
    // counts the number of times endpoints appear
    std::unordered_map<std::string, int> counts;
    for (int i = 0; i < log_data.size(); i++) {
        counts[log_data[i]]++;
    }
    
    // finds the maximum count
    int max_frequency = 0;
    std::unordered_map<std::string, int>::iterator it;
    for (it = counts.begin(); it != counts.end(); it++) {
        if (it->second > max_frequency) {
            max_frequency = it->second;
        }
    }
    
    // gets all endpoints that have the max count
    std::vector<std::string> top_endpoints;
    for (it = counts.begin(); it != counts.end(); it++) {
        if (it->second == max_frequency) {
            top_endpoints.push_back(it->first);
        }
    }
    
    // sorts of endpoints
    std::sort(top_endpoints.begin(), top_endpoints.end());
    
    return std::make_pair(top_endpoints, max_frequency);
}