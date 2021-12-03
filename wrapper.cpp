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

void setComposed(config_t *c) {
    Configuration *obj;
    if (c == NULL) {
        return;
    }
    obj = static_cast<Configuration *>(c->obj);
    obj->set_composed();
}

void printComposed(config_t *c) {
    Configuration *obj;
    if (c == NULL) {
        return;
    }
    obj = static_cast<Configuration *>(c->obj);
    obj->print_composed();
}

void delConfig(config_t *c) {
    if (c == NULL) {
        return;
    }
    delete static_cast<Configuration *>(c->obj);
    free(c);
}
