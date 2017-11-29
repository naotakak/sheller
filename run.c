#include "headers.h"

char ** run_cmd(char * args) {
  /***
      Make commands separated by ';' into different strings and then run them
  ***/
  int i = 0;
  int a = 0;
  char ** commands = calloc(5, sizeof(char *));
  char * thing = args;
  while((commands[i] = strsep(&thing, " ; "))) {
    i ++;
  }
  return commands;
}

char ** space_sep(char * line) {
  /***
      Separate a string into different args for execvp
  ***/
  int i = 0;
  char ** ret = (char **)calloc(6, sizeof(char*));
  if (!ret) {
    printf("%s\n", strerror(errno));
  }
  char * thing = line;
  while((ret[i] = strsep(&thing, " "))) {
    //printf("ret[%d]: %s\n", i, ret[i]);
    i ++;
  }

  /***
  printf("space");
  for (int a = 0; a < sizeof(ret); a ++) {
    printf("%s, ", ret[i]);
  }
  printf("\n");
  ***/

  return ret;
}

int runner(char ** args) {
  /***
      Run specified command using execvp
  ***/
  int f = fork();
  if (!strcmp(args[0], "cd")) {
    cd(args);
  }
  if (!strcmp(args[0], "exit")) {
    exit(0);
  }
  if (!f) {
    execvp(args[0], args);
    exit(0);
  }
  else {
    int w;
    wait(&w);
  }
}

int cd (char ** args) {
  if (!chdir(args[1])) {
    return 1;
  }
  return 0;
}
