#include "Host.h"

std::string HostManager::update(const std::string &host,
                                const std::vector<std::string> &ip) {
  std::string line;
  std::string PATCH{"Host.txt"};
  if (getCache().empty()) {
    std::fstream my_file{PATCH, std::ios::in};
    if (!my_file.is_open()) {
      std::cout << "Can not open file for in, error" << std::endl;
      return "Can not open file, error";
    }
    while (std::getline(my_file, line)) {
      add(line);
    }
    my_file.close();
  }
  auto cacheContents = cache_.getCache();
  auto it = std::find_if(cacheContents.begin(), cacheContents.end(),
                         [&host](const std::string &str) {
                           auto ret_pos = str.find_first_of(' ');
                           if (ret_pos != std::string::npos) {
                             auto temp_str = str.substr(0, ret_pos);
                             if (temp_str == host) {
                               std::cout << "Find host! " << std::endl;
                               return true;
                             }
                           }
                           return false;
                         });

  if (it != cacheContents.end()) {
    it = cacheContents.erase(it);
  } else {
    std::cout
        << " Not Find host, the host will be placed at the end of the file! "
        << std::endl;
  }

  cacheContents.push_back(((concat(host, ip))));

  std::cout << " Host update!" << std::endl;

  std::fstream my_file{PATCH, std::ios::out | std::ios::trunc};
  if (!my_file.is_open()) {
    std::cout << "Can not open file, error (2)" << std::endl;
    return "Can not open file, error";
  }

  for (const std::string &str : cacheContents) {
    my_file << str << std::endl;
  }

  while (std::getline(my_file, line)) {
    add(line);
  }
  return "";
}

std::string HostManager::remove_host(const std::string &host) {
  std::string line;
  if (getCache().empty()) {
    std::fstream my_file{"Host.txt", std::ios::in};
    if (!my_file.is_open()) {
      return "Can not open file, error(1)";
    }
    while (std::getline(my_file, line)) {
      add(line);
    }
    my_file.close();
  }
  auto cacheContents = cache_.getCache();
  auto it = std::find_if(cacheContents.begin(), cacheContents.end(),
                         [&host](const std::string &str) {
                           auto ret_pos = str.find_first_of(' ');
                           if (ret_pos != std::string::npos) {
                             auto temp_str = str.substr(0, ret_pos);
                             if (temp_str == host) {
                               std::cout << "Find host! " << std::endl;
                               return true;
                             }
                           }
                           return false;
                         });
  if (it == cacheContents.end()) {
    std::cout << " Not Find host! " << std::endl;
    return " Not find! ";
  }
  cacheContents.erase(it);

  std::fstream my_file{"Host.txt", std::ios::out | std::ios::trunc};
  if (!my_file.is_open()) {
    std::cout << "Can not open file, error (2)" << std::endl;
    return "Can not open file, error";
  }

  for (const std::string &str : cacheContents) {
    my_file << str << std::endl;
  }
  while (std::getline(my_file, line)) {
    add(line);
  }
  return "";
}

std::string HostManager::concat(const std::string &host,
                                const std::vector<std::string> &ip) {
  std::string temp_ip{};
  for (const auto &elem : ip) {
    temp_ip += elem;
  }
  return host + " " + temp_ip;
}
