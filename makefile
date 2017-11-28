all:
	gcc main.c run.c
run: all
	./a.out
