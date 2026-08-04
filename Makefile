CC ?= arm-none-eabi-gcc
CFLAGS ?= -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffreestanding -O2 -g
LDFLAGS ?= -Wl,-T,ld/linker.ld -Wl,-Map=build/app.map

all: build/app.elf

build:
	mkdir -p build

build/app.elf: build src/main.c src/startup.c | build
	$(CC) $(CFLAGS) -Iinclude src/main.c src/startup.c $(LDFLAGS) -o build/app.elf

clean:
	rm -rf build

.PHONY: all clean
