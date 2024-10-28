#include <stdint.h>
#include <stdio.h>

uint8_t control = 0;    // 0b 0000 0000
                        // 0b    l bbwr

#define READING   0x01  // 0b 0000 0001 ~READING = 0b 1111 1110
#define WRITING   0x02  // 0b 0000 0010 ~WRITING = 0b 1111 1101
#define AS_BYTES  0x04  // 0b 0000 0100
#define AS_BLOCKS 0x08  // 0b 0000 1000
#define LOCKED    0x10  // 0b 0001 0000

void print_bits(uint8_t control) {
    for (int i = 0; i < 8; i++) {
        if (control & (1 << 7)) {
            putchar('1');
        } else {
            putchar('0');
        }
        control <<= 1;
    }
    putchar('\n');
}

uint8_t mark_no_reading(uint8_t control) {
    return control & 0b11111110; // Remove the READING bit
}

uint8_t mark_reading(uint8_t control) {
    return control | 0b00000001; // Set the READING bit
}

uint8_t mark_no_writing(uint8_t control) {
    uint8_t mask = ~WRITING;
    return control & mask;
}

uint8_t mark_writing(uint8_t control) {
    uint8_t mask = WRITING;
    return control | mask;
}

uint8_t mark_unlocked(uint8_t control) {

}

uint8_t mark_locked(uint8_t control) {

}

uint8_t switch_read_to_write(uint8_t control) {

}

uint8_t switch_write_to_read(uint8_t control) {

}

int main(void) {
    uint8_t ctrl = 0;
    print_bits(ctrl); // 00000000
    ctrl = mark_reading(ctrl);
    print_bits(ctrl); // 00000001
    ctrl = mark_locked(ctrl);
    print_bits(ctrl); // 00010001
    ctrl = switch_read_to_write(ctrl);
    print_bits(ctrl); // 00010010
}