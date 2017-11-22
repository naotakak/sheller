#include "headers.h"

int run_cmd(char * args) {
  /***
      Make commands separated by ';' into different strings and then run them
  ***/
  int i = 0;
  char * commands = calloc(5, sizeof(char *));
  commands = strsep(&args, ";");
  while (commands[i]) {
    space_sep(commands[i]);
    i ++;
  }
}

char ** space_sep(char * line) {
  /***
      Separate a string into different args for execvp
  ***/
  char ** ret = (char **)calloc(6, sizeof(char*));
  if (!ret) {
    printf("%s\n", strerror(errno));
  }
  int i = 0;
  while (line) {
    ret[i] = strsep(&line, " ");
    i ++;
  }
  return ret;
}

int runner(char ** args) {
  /***
      Run specified command using execvp
  ***/
  if (execvp(args[0], args) < 0) {
    printf("%s\n", sterror(errno));
  }
}