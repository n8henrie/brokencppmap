#include "proj.h"
#include <iostream>

void Configuration::set_inherited() {
    (*this)["foo"] = "bar";
}

void Configuration::print_inherited() {
    auto found = find ("foo");
    std::cout << found -> second << std::endl;
}

void Configuration::set_composed() {
    submap["baz"] = "qux";
}

void Configuration::print_composed() {
    auto found = submap.find("baz");
    std::cout << found -> second << std::endl;
}
