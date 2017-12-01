#include "headers.h"

char ** colonoscopy(char * args) {
  /***
      Make commands separated by ';' into different strings and then run them
  ***/
  int i = 0;
  char ** commands = calloc(10, sizeof(char *));
  while((commands[i] = strsep(&args, ";"))) {
    //printf("commands[%d]: %s\n", i, commands[i]);
    i ++;
  }
  return commands;
}

char ** space_sep(char * line) {
  /***
      Separate a string into different args for execvp
  ***/
  int i = 0;
  char ** ret = (char **)calloc(10, sizeof(char *));
  while((ret[i] = strsep(&line, " "))) {
    i ++;
  }
  return ret;
}

int runner(char ** args) {
  /***
      Run specified command using execvp
  ***/
  int f = fork();
  if (!f) {
    execvp(args[0], args);
    if (strcmp(args[0], "exit") && strcmp(args[0], "cd") && strcmp(args[0], "\n")) {
      printf("%s: command not found\n", args[0]);
    }
    exit(0);
  }
  else {
    if (!strcmp(args[0], "cd")) {
      if (chdir(args[1])) {
        printf("cd: %s: No such file or directory\n", args[1]);
      }
    }
    if (!strcmp(args[0], "exit")) {
      exit(0);
    }
    int w;
    wait(&w);
  }
}
