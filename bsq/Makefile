src_dir = src

.PHONY: all
all: bsq

bsq: objects
	gcc -o bsq ft_helpers.o helpers.o main.o map_loader.o map_utils.o print.o
	rm -f *.o

objects: $(src_dir)/ft_helpers.c $(src_dir)/helpers.c $(src_dir)/main.c $(src_dir)/map_loader.c $(src_dir)/map_utils.c $(src_dir)/print.c
	gcc -c -Wall -Wextra -Werror $(src_dir)/ft_helpers.c $(src_dir)/helpers.c $(src_dir)/main.c $(src_dir)/map_loader.c $(src_dir)/map_utils.c $(src_dir)/print.c

.PHONY: clean
clean:
	rm -f *.o bsq
