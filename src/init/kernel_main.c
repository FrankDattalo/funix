#include "funix/util/vga.h"
#include "funix/util/compiler_check.h"

int kernel_main() {

    vga_reset();

    vga_write("Hello, World!\nThis should be on the second line\nAnd this the third\n:D\n");

    vga_reset();

    vga_write("I should be overwriting some text!");

    while (1);

    return 0;
}
