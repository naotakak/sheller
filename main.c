#include "headers.h"

int main() {
  int f = fork();

  if (f == 0) {
    //child
    char * argv;
    scanf("%s", argv);
    //argv needs to read from stdin
    run_cmd(argv);
    //exit(0);
  }
  else {
    //parent
    int w = 10;
    //wait(&w);
    if (WEXITSTATUS(w)) {
      printf("WEXITSTATUS: %d\n", WEXITSTATUS(w));
      //exit(0);
      wait(&w);
    }
  }
  return 0;
}
