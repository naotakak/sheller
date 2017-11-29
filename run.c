#include "headers.h"

void run_cmd(char * args) {
  /***
      Make commands separated by ';' into different strings and then run them
  ***/
  //int i = 0;
  char * commands = calloc(10, sizeof(char *));
  commands = strsep(&args, ";");
  printf("comm2: %s\n", commands);
  while (commands) {
    runner(space_sep(commands));
    commands = strsep(&args, ";");
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
  char * thing;
  int i = 0;
  thing = strsep(&line, " ");
  while (thing) {
    printf("THING: %s\n", thing);
    ret[i] = thing;
    i ++;
    thing = strsep(&line, " ");
  }
  printf("RET: %p\n", ret);
  return ret;
}

int runner(char ** args) {
  /***
      Run specified command using execvp
  ***/
  if (execvp(args[0], args) < 0) {
    printf("%s\n", strerror(errno));
  }
}
