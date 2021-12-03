#include "wrapper.h"
#include "vendor/proj/proj.h"

struct config {
    void *obj;
};

config_t * newConfig() {
    config_t *c;
    Configuration *obj;
    c = (decltype(c))malloc(sizeof(*c));
    obj = new Configuration();
    c->obj = obj;
    return c;
}

void setInherited(config_t *c) {
    Configuration *obj;
    if (c == NULL) {
        return;
    }
    obj = static_cast<Configuration *>(c->obj);
    obj->set_inherited();
}

void printInherited(config_t *c) {
    Configuration *obj;
    if (c == NULL) {
        return;
    }
    obj = static_cast<Configuration *>(c->obj);
    obj->print_inherited();
}

void delConfig(config_t *c) {
    if (c == NULL) {
        return;
    }
    delete static_cast<Configuration *>(c->obj);
    free(c);
}

// void Configuration::print_inherited() {
//     std::cout << "trying print inherited" << std::endl;
//     auto found = find ("foo");
//     std::cout << found -> second << std::endl;
//     std::cout << "done" << std::endl;
// }
//
// void Configuration::set_composed() {
//     std::cout << "trying set composed" << std::endl;
//     (*this).submap["baz"] = "qux";
//     std::cout << "done" << std::endl;
// }
//
// void Configuration::print_composed() {
//     std::cout << "trying print composed" << std::endl;
//     auto found = submap.find("baz");
//     std::cout << found -> second << std::endl;
//     std::cout << "done" << std::endl;
// }
