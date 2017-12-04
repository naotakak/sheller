#include "headers.h"

void tell_run(char * args) {
  /***
      Runs functions based on presence of >, <, |, and ;
  ***/
  int i = 0;
  char ** semi;
  semi = colonoscopy(args);
  while (semi[i]) {
    if (strstr(semi[i], ">")) {
      redirectG(semi[i]);
    }
    else if (strstr(semi[i], "<")) {
      redirectL(semi[i]);
    }
    if (strstr(semi[i], "|")) {
      piper(semi[i]);
    }
    else {
      runner(space_sep(semi[i]));
    }
    i ++;
  }
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
      if (!args[1] || !strcmp(args[1], "$HOME")) {
        chdir(getenv("HOME"));
      } 
      else if (chdir(args[1])) {
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
