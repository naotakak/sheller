all:
  gcc main.c parse.c fork.c

run: all
     ./a.out
