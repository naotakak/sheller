# Cynthia Cheng and Naotaka Kinoshita<br>Systems Pd10<br>P01: Shell-ing out commands

<h3>Features implemented</h3>
    <ul>
        <li>Running multiple commands on one line by separating commands with <code>;</code>.
        <li>Running commands with arguments (ex: <code>ls -a -l</code>)</li>
    <li>Using both <code>cd</code> and <code>exit</code> - <code>cd</code> and <code>cd $HOME</code> both cd into the home directory</li>
        <li>Printing current working directory</li>
        <li>Redirecting using <code><</code> and <code>></code> (see bugs)</li>
        <li>Pipes (see bugs)</li>
    </ul>
<h3>Features we tried to implement but couldn't</h3>
    <ul>
        <li>Printing out username and machine name (ex: dw@marge): too complicated and varies from system to system</li>
        <li>Getting ~/ to work, time constraints</li>
        <li>Would have liked to get ^C or ^D to quit child processes, but ran out of time</li>
    </ul>

<h3>Bugs</h3>
    <ul>
        <li><b>IMPORTANT!!!! All commands with ;, <, >, | CANNOT have spaces separating them</b> - format like <code>ls;echo hi</code> NOT <br><code>ls ; echo hi</code> or <code>ls; echo hi</code> or <code>ls ;echo hi</code></li>
        <li>When redirecting using >, the input will be redirected, but will also print to stdout (ex: <code>ls>test</code> will put the output of <code>ls</code> into <code>test</code>, but will also run ls and have the output print to the terminal.</li>
        <li>When redirecting using <, the command will be run using the input from the argument after <, but won't exit the process.</li>
        <li>Pipes</li>
    </ul>
<h3>Function Headers</h3>

```C
//main.c
int main();
    /***
        Prints working directory when starting shell, and after commands are executed.
        Forever while loop to read from stdin, and pass user input on to tell_run, where commands are run.
    ***/
    
//run.c - Functions controlling parsing and executing commands.
void tell_run(char *);
    /***
        Input: The command as read from stdin, passed in through main.
        
        Output: Void
        
        Determines if we need to redirect (in either direction), pipe, or split on semicolons, 
        and then runs those functions the appropriate number of times.
    ***/
    
int runner(char **);
    /***
        Input: A command separated into the format [command, args, arg2, ...]
        
        Output: Returns 1 when successful (not really needed)
        
        Runs functions using execvp, or cd or exit.
        If trying to cd into a directory that doesn't exist, or trying to run a command that does
        not exit, an error message is printed.
        For cd, handles cd with no arguments to navigate to home directory (same result as typing cd $HOME), and cd with arguments.
    ***/

//parse.c - Handles all line parsing functions.
char ** colonoscopy(char *);
    /***
        Input: A string of commands that may or may not have a semicolon in it.
        
        Output: A char ** with each element being a separate command, i.e ["ls -a", "cd .."]
        
        Splits input into commands that should be separated by semicolons, and puts individual commands into a char **.
    ***/
    
char ** space_sep(char *);
    /***
        Input: A single command string that may or may not have mutiple arguments.
        
        Output: A char ** with the command and arguments separated i.e. ["ls", "-a", "-l"]
        
        Splits a single command into individual arguments, to be passed on to runner, which will then execute the command.
    ***/
    
void piper(char *);
    /***
        Input: A command with a pipe (|) in it.
        
        Output: Void
        
        Takes a command with a pipe in it, and executes the command preceding the pipe into the file after the pipe.
     ***/
     
void redirectG(char *);
    /***
        Input: A command with > in it.
        
        Output: Void
        
        Takes a command with > in it, and redirects the command before the > into the command after it.
    ***/
    
void redirectL(char *);
    /***
        Input: A command with < in it.
        
        Output: Void
        
        Takes a command with < in it, and redirects the command after the < into the command before it.
    ***/
```
