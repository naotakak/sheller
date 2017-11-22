#include "headers.h"

int main() {
  int f = fork();

  if (f == 0) {
    //child

    //argv needs to read form stdin
    run_cmd(argv);
  }
  else {
    //parent
    int w;
    wait(&w);
  }
  return 0;
}
