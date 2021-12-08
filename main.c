#include <stdio.h>
#include "wrapper.h"

int main(int argc, char **argv) {
    Configuration *c = newConfig();
    setInherited(c);
    printInherited(c);
    setComposed(c);
    printComposed(c);
}
