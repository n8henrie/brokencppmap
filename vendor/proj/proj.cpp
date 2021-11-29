#include "proj.h"
#include <map>
#include <iostream>

struct Configuration::ConfigImpl {
    std::map<std::string, std::string> map;
};

Configuration::Configuration() : impl(new ConfigImpl) {}

Configuration::~Configuration() {
    delete impl;
}

void Configuration::set_composed() {;
    impl->map["baz"] = "qux";
}

void Configuration::print_composed() {
    auto found = impl->map.find("baz");
    std::cout << found -> second << std::endl;
}
