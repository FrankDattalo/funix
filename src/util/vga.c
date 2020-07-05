#include "funix/util/vga.h"
#include "funix/util/compiler_check.h"

// const static char TERMINAL_ROWS = 25;
static const char TERMINAL_COLS = 80;
static const short TERMINAL_BUFFER_LENGTH = 2000; /* 80 * 25 */
static const char DEFAULT_VGA_COLORS = 0x0f; /* white on black */

static volatile short* TERMINAL_BUFFER = (short*) 0xB8000; /* location in mem where vga char is */

static volatile char row;
static volatile char col;

/*
 * Converts a character to a vga character, adding color info
 */
static inline short to_vga(char character, char color) {
    short ret = ((short) color) << 8 | ((short) character);
    return ret;
}

/*
 * Converts a character to a vga character using the default color
 */
static inline short to_vga_default(char character) {
    return to_vga(character, DEFAULT_VGA_COLORS);
}

/*
 * Given an row and col return the proper vga index
 */
static inline short to_index(char row, char col) {
    short vga_index = row * TERMINAL_COLS + col;
    return vga_index;
}

/*
 * Resets the cursor to the first column of the first row
 */
void vga_reset() {
    row = 0;
    col = 0;
}

/*
 * Writes the string to the screen, or at least as much as is possible
 */
void vga_write(char* str) {
    for (short i = 0; str[i] != '\0'; i++) {
        short index = to_index(row, col);

        if (index >= TERMINAL_BUFFER_LENGTH) {
            break;
        }

        if (str[i] == '\n') {
            row += 1;
            col = 0;
            continue;
        }

        TERMINAL_BUFFER[index] = to_vga_default(str[i]);
        col += 1;
    }
}
