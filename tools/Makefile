.DEFAULT_GOAL := kernel

.PHONY: kernel clean

ROOT_DIR := ..

ASMS := $(wildcard ${ROOT_DIR}/src/*/*.s)
SOURCES := $(wildcard ${ROOT_DIR}/src/*/*.c)
SOURCE_OBJECTS := $(SOURCES:%.c=%.o)
ASM_OBJECTS := $(ASMS:%.s=%.o)
INCLUDE_DIR := ${ROOT_DIR}/include

GCC_BOTH_ARGS := -m32 \
		-march=i686 \
		-Wall \
		-Werror \
		-Wextra \
		--std=gnu99 \
		-nostartfiles \
		-nostdlib \
		-nodefaultlibs \
		-ffreestanding \
		-I ${INCLUDE_DIR}

GCC_SRC_ARGS := ${GCC_BOTH_ARGS}
GCC_ASM_ARGS := ${GCC_BOTH_ARGS}
GCC_LNK_ARGS := ${GCC_BOTH_ARGS}

%.o: %.c
	@echo "Compiling Source File: $< to $@"
	gcc ${GCC_SRC_ARGS} -c $< -o $@

%.o: %.s
	@echo "Compiling Assembly File: $< to $@"
	gcc ${GCC_ASM_ARGS} -c $< -o $@

link: ${ASM_OBJECTS} ${SOURCE_OBJECTS}
	@echo "Linking"
	gcc ${GCC_LNK_ARGS} -T ${ROOT_DIR}/src/init/linker.ld \
		-o ${ROOT_DIR}/funix.bin ${SOURCE_OBJECTS} ${ASM_OBJECTS}

kernel: link

grub: kernel
	@echo "Creating grub entry"
	grub-file --is-x86-multiboot ${ROOT_DIR}/funix.bin
	@echo "Multiboot confirmed"
	mkdir -p ${ROOT_DIR}/isodir/boot/grub
	cp ${ROOT_DIR}/funix.bin ${ROOT_DIR}/isodir/boot/funix.bin
	cp ${ROOT_DIR}/src/init/grub.cfg ${ROOT_DIR}/isodir/boot/grub/grub.cfg
	grub-mkrescue -o ${ROOT_DIR}/funix.iso ${ROOT_DIR}/isodir

run: grub
	qemu-system-i386 -cdrom ${ROOT_DIR}/funix.iso

clean:
	@echo "Cleaning"
	rm -rvf *.o ${ASM_OBJECTS} ${SOURCE_OBJECTS}
