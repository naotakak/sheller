#include "headers.h"

void run_cmd(char * args) {
  /***
      Make commands separated by ';' into different strings and then run them
  ***/
  //int i = 0;
  char * commands = calloc(5, sizeof(char *));
  commands = strsep(&args, ";");
  printf("comm2: %s\n", commands);
  if (!commands) {
    commands = args;
    printf("comm: %s\n", commands);
    runner(space_sep(commands));
  }
  runner(space_sep(commands));
  /***
  while (!commands) {
    //printf("SPACE SEP %s\n", *space_sep(commands));
    commands = strsep(&args, " ; ");
    printf("COMMAND: %s\n", commands);
    runner(space_sep(commands));
  }
  ***/
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
  while ((thing = strsep(&line, " ")) != 0) {
    printf("THING: %s\n", thing);
    ret[i] = thing;
    i ++;
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
