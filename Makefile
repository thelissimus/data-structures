SRC = $(wildcard *.c)

fmt:
	clang-format -i $(SRC)

.PHONY: fmt
