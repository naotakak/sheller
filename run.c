#include "headers.h"

void run_cmd(char * args) {
  /***
      Make commands separated by ';' into different strings and then run them
  ***/
  //int i = 0;
  char * commands = calloc(5, sizeof(char *));
  //commands = strsep(&args, ";");
  //printf("COMMANDS: %s\n", commands);
  while ((commands = strsep(&args, ";")) != 0) {
    //printf("SPACE SEP %s\n", *space_sep(commands));
    printf("COMMAND: %s\n", commands);
    space_sep(commands);
    //i ++;
  }

}

void space_sep(char * line) {
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
  runner(ret, i);
  //return ret;
}

int runner(char ** args, int cmds) {
  /***
      Run specified command using execvp
  ***/
  if (execvp(args[0], args) < 0) {
    printf("%s\n", strerror(errno));
  }

  // if more than 1 command, exit with 1 and tell main there's more commands to run
  if (cmds) {
    exit(1);
  }
  else {
    exit(0);
  }
  //exit(0);
}
