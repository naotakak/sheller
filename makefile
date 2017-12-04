all:
	gcc main.c run.c parse.c
run: all
	./a.out
