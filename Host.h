#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

template <typename T> class Cache {
public:
  Cache() = default;
  std::string add(const T &data) {
    cache_.push_back(data);
    return "Data added to cache.";
  }
  std::string remove(const T &data) {
    auto it = std::find(cache_.begin(), cache_.end(), data);
    if (it != cache_.end()) {
      cache_.erase(it);
      return "Data removed from cache.";
    }
    return "Data not found in cache.";
  }
  std::vector<T> getCache() { return cache_; }
  bool check(const T &data) {
    return std::find(cache_.begin(), cache_.end(), data) != cache_.end();
  }
  void clearCache() { cache_.clear(); }

private:
  std::vector<T> cache_;
};

class HostManager {
public:
  HostManager() = default;
  std::string update(const std::string &host,
                     const std::vector<std::string> &ip);
  std::string remove_host(const std::string &host);
  std::string add(const std::string &data) { return cache_.add(data); }
  std::vector<std::string> getCache() { return cache_.getCache(); }

private:
  std::string concat(const std::string &host,
                     const std::vector<std::string> &ip);
  Cache<std::string> cache_;
};
