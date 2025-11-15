#ifndef API_MONITOR_HPP
#define API_MONITOR_HPP

#include <vector>
#include <string>
#include <utility>

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data);

#endif 