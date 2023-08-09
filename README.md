### Host Cache Manager

This repository contains a simple implementation of a Host Cache Manager using C++.

## Introduction

Welcome to the Host Cache Manager repository! This project provides a simple and efficient way to manage and store host information, including host names and their corresponding IP addresses. The Host Cache Manager is designed to optimize the retrieval, updating, and removal of host data, making it a useful tool for various applications that involve host management.

In this repository, you'll find the necessary source code and examples to get started with the Host Cache Manager. Whether you're a developer looking for an easy way to manage host information or a learner exploring cache management concepts, this project can serve as a helpful resource.

Feel free to explore the code, run the examples, and contribute to the project. We hope you find the Host Cache Manager useful and informative!



## Contents

The repository is structured as follows:

- `Host.h`: Header file containing the `HostManager` and `Cache` class definitions.
- `Host.cpp`: Implementation file for the `HostManager` methods.
- `main.cpp`: A sample program demonstrating how to use the `HostManager` to update the host cache.
- `Host.txt`: A sample text file to store host information.

## Usage

To use the Host Cache Manager in your project:

1. Include the `Host.h` header file in your source files.
2. Create an instance of the `HostManager` class to manage the host cache.
3. Use the provided methods to interact with the cache: `update`, `remove_host`, `add`, `remove`, `getCache`, `check`, and `clearCache`.

## Example

Here's a simple example of how to use the Host Cache Manager:

```cpp
#include "Host.h"

int main() {
    // Create a host cache manager instance
    HostManager hostManager;

    // Update host information
    std::string hostName = "example_host";
    std::vector<std::string> ipAddresses = { "192.168.1.1", "192.168.1.2" };
    hostManager.update(hostName, ipAddresses);

    // Remove a host from the cache
    std::string hostToRemove = "obsolete_host";
    hostManager.remove_host(hostToRemove);

    // Retrieve and print the updated cache
    std::cout << "Current Host Cache:" << std::endl;
    for (const std::string& hostInfo : hostManager.getCache().getCache()) {
        std::cout << hostInfo << std::endl;
    }

    return 0;
}
