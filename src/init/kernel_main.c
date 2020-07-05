#include "funix/util/vga.h"
#include "funix/util/compiler_check.h"

int kernel_main() {

    vga_reset();

    vga_write("Hello, World!\n");

    while (1);

    return 0;
}
