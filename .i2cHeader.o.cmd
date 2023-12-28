cmd_/home/Guilherme/programerC++/kernel-module/i2cHeader.o := ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o /home/Guilherme/programerC++/kernel-module/i2cHeader.o @/home/Guilherme/programerC++/kernel-module/i2cHeader.mod  ; ./tools/objtool/objtool --hacks=jump_label --hacks=noinstr --ibt --orc --retpoline --rethunk --sls --static-call --uaccess  --link  --module /home/Guilherme/programerC++/kernel-module/i2cHeader.o

/home/Guilherme/programerC++/kernel-module/i2cHeader.o: $(wildcard ./tools/objtool/objtool)
