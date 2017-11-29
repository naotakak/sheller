#include "headers.h"

int main() {
  int f = fork();

  if (f == 0) {
    //child
    char argv[100];
    scanf("%s", argv);
    printf("argv: %s\n", argv);
    run_cmd(argv);
  }
  else {
    //parent
    int w;
    wait(&w);
    /***
    if (WEXITSTATUS(w)) {
      printf("WEXITSTATUS: %d\n", WEXITSTATUS(w));
      //exit(0);
      wait(&w);
    }
    ***/
  }
  return 0;
}
