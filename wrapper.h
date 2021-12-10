#pragma once
#include "brokencppmap/vendor/proj/proj.h"
#include <memory>

inline std::unique_ptr<Configuration> new_configuration() {
  return std::unique_ptr<Configuration>(new Configuration);
}
