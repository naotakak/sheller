#include "headers.h"

void redirect(char* command){
  int i = 0;
  char ** commands = calloc(10, sizeof(char *));
  while((commands[i] = strsep(&command, ">"))) {
    printf("commands[%d]: %s\n", i, commands[i]);
    i ++;
  }
  int f = open(commands[1], O_CREAT | O_WRONLY, 0644);
  int fout = dup(1);
  dup2(f, 1);
  runner(space_sep(commands[0]));
  dup2(fout, 1);
  free(commands);
}

void pipe(char* command){
  char ** commands = calloc(10, sizeof(char *));
  while((commands[i] = strsep(&command, "|"))) {
    i ++;
  }
  
  char **first[] = space_sep(commands[0]);
  char **second[] = space_sep(commands[1]);

  int inputforpipe[2]
  int pid;

  pipe(inputforpipe);
  pid = fork();

  if (pid == 0){ //child does second command
    dup2(inputforpipe[0], 0);
    //closes the other half
    close(inputforpipe[1]);
    execvp(first[0],first);
  }
  else{
    dup2(inputforpipe[1], 1);
    close(inputforpipe[0]);
    execvp(second[0],second);
  }
}

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
