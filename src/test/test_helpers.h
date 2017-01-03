#pragma once

#include <iostream>
#include <iostream>
#include <assert.h>

void log(std::string message) {
  std::cout << message << std::endl;
}

void check(bool condition, std::string message) {
  if (condition) {
    std::cout << message << ": pass" << std::endl;
    return;
  }
  std::cout << message << ": fail" << std::endl;
}
