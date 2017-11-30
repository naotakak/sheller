#include "headers.h"

int main() {
  char args[100];
  char wd[100];
  printf("%s$ ", getcwd(wd, sizeof(wd)));
  while (1) {

    fgets(args, 100, stdin);
    args[strlen(args) - 1] = '\0';

    char ** semi;
    semi = colonoscopy(args);
    int i = 0;
    while (semi[i]) {
      runner(space_sep(semi[i]));
      i ++;
    }
    printf("%s$ ", getcwd(wd, sizeof(wd)));
  }
  return 0;
}
