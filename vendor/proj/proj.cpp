#include "proj.h"
#include <iostream>

void Configuration::set_inherited() {
    std::cout << "trying set inherited" << std::endl;
    (*this)["foo"] = "bar";
    std::cout << "done" << std::endl;
}

void Configuration::print_inherited() {
    std::cout << "trying print inherited" << std::endl;
    auto found = find ("foo");
    if (found != end()) {
      std::cout << found -> second << std::endl;
    }
    std::cout << "done" << std::endl;
}

void Configuration::set_composed() {
    std::cout << "trying set composed" << std::endl;
    (*this).submap["baz"] = "qux";
    std::cout << "done" << std::endl;
}

void Configuration::print_composed() {
    std::cout << "trying print composed" << std::endl;
    auto found = submap.find("baz");
    if (found != end()) {
      std::cout << found -> second << std::endl;
    }
    std::cout << "done" << std::endl;
}
