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
  int fin = dup(0);
  dup2(f, 0);
  runner(space_sep(commands[0]));
  dup2(fin, 0);
  free(commands);
}

// char *left = malloc(32);
// char *right = malloc (32);
// strcpy(left, strtok(line, "|"));
// strcpy(right, strtok(line, "|"));
//
// int piper[2];
// pipe(piper);
// 
// if (fork() == 0) {
//   close(piper[0]);
//   dup2(piper[0], 1);
//   runner(space_sep(command));
// } else {
//   close(piper[1]);
//   dup2(piper[1], 0);
//   runner(space_sep(command));
//   }


void piper(char* command){
  char **args = space_sep(command);
  int i, l;
  for (i = 0; args[i]; i++) {
    if (args[i][0] == '|') {

      char first[256] = "";
      for(l = 0; l < i; l++){
        strcat(first, args[l]);
        strcat(first, " ");
        printf("%s", first);
      }

      FILE *fp = popen(first, "r");
      int f = fileno(fp);
      dup2(f, 0);
      close(f);
      args += i + 1;
      execvp(args[0], args);
    }
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
