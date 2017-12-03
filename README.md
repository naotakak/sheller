Cynthia Cheng and Naotaka Kinoshita<br>
Systems Pd10<br>
P01: Shell-ing out commands

<h3>Features implemented</h3>
    <ul>
        <li>Running multiple commands on one line by separating commands with ";". NOTE: commands must be formatted in the following way: `ls;echo hello` NOT `ls ; echo hello`</li>
        <li>Running commands with arguments (ex: `ls -a -l`)</li>
        <li>Using both `cd` and `exit`</li>
        <li>Printing current working directory</li>
    </ul>

<h3>Features we tried to implement but couldn't</h3>
    <ul>
        <li>Separating commands with ` ; ` instead of just `;`</li>
    </ul>

<h3>Bugs</h3>

<h3>Function Headers</h3>
```C
int main();

//run.c
char ** colonoscopy(char *);
char ** space_sep(char *);
int runner(char **);

//piping and redirection
void piper(char *);
void redirect(char *);
```
