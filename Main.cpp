#include "Host.h"

int main() {
  std::vector<std::string> vec{"890.999.99.99"};
  std::string host_Name{"myhost2"};
  HostManager host{};
  host.update(host_Name, vec);

  return 0;
}
