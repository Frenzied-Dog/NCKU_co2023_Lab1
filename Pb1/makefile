pb1.bin: pb1.elf
	riscv64-unknown-elf-objcopy -S pb1.elf -O binary pb1.bin

pb1.elf: pb1.c user.o start.S
	riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib -static pb1.c user.o start.S call_to_aisemu.o -Tlink.ld -o pb1.elf