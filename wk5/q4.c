#include <stdint.h>
#include <stdio.h>

uint8_t control = 0;    // 0b 0000 0000

#define READING   0x01  // 0b 0000 0001
#define WRITING   0x02  // 0b 0000 0010
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

}

uint8_t mark_reading(uint8_t control) {

}

uint8_t mark_no_writing(uint8_t control) {

}

uint8_t mark_writing(uint8_t control) {

}

uint8_t mark_locked(uint8_t control) {

}

uint8_t mark_unlocked(uint8_t control) {

}

uint8_t switch_read_to_write(uint8_t control) {

}

uint8_t switch_write_to_read(uint8_t control) {

}

int main(void) {
    uint8_t ctrl = 0b00000000;
    print_bits(ctrl);
}
