#ifndef DEFS_H
#define DEFS_H

#include "include/types.h"

//entry.c
void init(void);
void bss_init(void);
void copy_bootparams(void);

// video.c
struct color {
    unsigned b : 8;
    unsigned g : 8;
    unsigned r : 8;
};
#define bgr(b, g, r) \
    (struct color) { \
        b, g, r      \
    }

#define rgb(r, g, b) \
    (struct color) { \
        b, g, r      \
    }

void video_init(void);
void write_pixel(uint32_t x, uint32_t y, struct color c);
void vga_draw_ascii(uint32_t x, uint32_t y, uint32_t c, char ch);
void vga_puts(int x, int y, char c, char *s);
void vga_boxfill(int x, int y, int width, int height, struct color c);

// trap.c
void idt_init(void);
void pic_init(void);

// kbd.c
void kbd_init(void);
void wait_kbc(void);
int kbdgetc(void);
void kbdintr(void);

// console.c
void vga_console_init(void);
void vga_console_putc(char c);
int vga_console_printf(char *fmt, ...);

// memory.c
void memory_init(void);

//timer.c
void timer_init(void);
void timerintr(void);

// scheduler.c
void run_scheduler(void);

#endif