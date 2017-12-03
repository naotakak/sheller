#include "headers.h"

void redirect(char* command){
  char** commands = space_sep(command)
  int in, out;
  in = open("stdin.txt", O_RDONLY);
  out = open("stdout.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
  dup2(in, 0);
  dup2(out, 1);
  close(in);
  close(out);
  execvp(commands[0],commands);
}

void pipe(char* command){
  char ** commands = calloc(10, sizeof(char *));
  while((commands[i] = strsep(&args, "|"))) {
    i ++;
  }
  char *first[] = space_sep(commands[0]);
  char *second[] = space_sep(commands[1]);

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
