#include "proj.h"

int main() {
    Configuration config;
    config.set_inherited();
    config.set_composed();

    config.print_inherited();
    config.print_composed();
    return 0;
}
