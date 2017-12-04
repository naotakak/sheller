#include "headers.h"

void redirectG(char* command){
  int i = 0;
  char ** commands = calloc(10, sizeof(char *));
  while((commands[i] = strsep(&command, ">"))) {
    //printf("commands[%d]: %s\n", i, commands[i]);
    i ++;
  }
  int f = open(commands[1], O_CREAT | O_WRONLY, 0644);
  int fout = dup(1);
  dup2(f, 1);
  runner(space_sep(commands[0]));
  dup2(fout, 1);
  free(commands);
}

void redirectL(char* command){
  int i = 0;
  char ** commands = calloc(10, sizeof(char *));
  while((commands[i] = strsep(&command, "<"))) {
    //printf("commands[%d]: %s\n", i, commands[i]);
    i ++;
  }
  int f = open(commands[1], O_RDONLY);
  int fout = dup(0);
  dup2(f, 10);
  runner(space_sep(commands[0]));
  dup2(fout, 0);
  free(commands);
}

void piper(char* command){
  char ** commands = calloc(10, sizeof(char *));
  int i =0;
  while((commands[i] = strsep(&command, "|"))) {
    printf("commands[%d]: %s\n", i, commands[i]);
    i ++;
  }

  char **first = space_sep(commands[0]);
  char **second = space_sep(commands[1]);

  int inputforpipe[2];
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
