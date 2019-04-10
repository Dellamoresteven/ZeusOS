#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include <stdint.h>

#include "../libc/zeus.h"

void kernel_main() {
    isr_install();
    irq_install();

    asm("int $2");
    asm("int $3");
    kprint("Welcome to ZeusOS type 'HELP' to see a list of commands\n");
    kprint("\n> ");
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    } else if (strcmp(input, "PAGE") == 0) {
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
        kprint("\n");
    }else if(strcmp(input, "HELP") == 0){
      kprint("\n\nPAGE\nEND\n\n");
    }else if(strcmp(input, "") == 0){
    }else if(strcmp(input, "LS") == 0){
      kprint("listing directorys\n");
    }else if(strcmp(input, "CLEAR") == 0){
      kprint("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }else{
      kprint("'");
      kprint(input);
      kprint("' is not a command\n");
    }
    kprint("> ");
}
