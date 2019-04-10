ZeusOS 
------------------------------------------

## How to run ##
* make
* qemu-system-i386 -fda os-image.bin

## Notes ##
* Make sure to have qemu and nasm installed so you can compile and run
* Make sure to have i386 installed

### Compiling other files ###
* nasm -f bin file.asm -o file.bin
* qemu-system-i386 file.bin

