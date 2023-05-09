SRC = $(wildcard src/*.c)

all: options

options:
	@echo "SRC = $(SRC)"

fmt:
	clang-format -i $(SRC)

.PHONY: all options fmt
