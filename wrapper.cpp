#include "wrapper.h"
#include "vendor/proj/proj.h"

Configuration * newConfig() {
    return new Configuration;
}

void setInherited(Configuration *c) {
    c->set_inherited();
}

void printInherited(Configuration *c) {
    c->print_inherited();
}

void setComposed(Configuration *c) {
    c->set_composed();
}

void printComposed(Configuration *c) {
    c->print_composed();
}

void delConfig(Configuration *c) {
    delete c;
}
