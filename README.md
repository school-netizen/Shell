# Shell ($)
---
>Shell is a command line interpreted language. This project aims to make one of such from scratch using C lang. Here I have followed the POSIX standards, as much I could have..Works on **REPL** -Read,Evaluate,Print,Loop.
---
###  Following are the commands of Shell which have been implemented :)
1. `$ echo Hello World`
2. `$ exit 0`
3. `$ type builtin_cmd`
4. `$ type executable_file`
5.  `$ pwd`
6.  `$ cd ~`
7.  `$ cd -`
8.  `$ cd /home/user/absolute_path`
9.  `$ cd ../../relative_path`
---
### ToDos :)
1. Run the executable program once called from the terminal $
    * Assuming the file is default set in _PATH_ environment variable
    * else scan the absolute path to the file
2. Quoting
    * single quotes
    * double quotes
    * backslash
    * ...and we'll look for it
3. Redirection
    * Redirect
    * Append
4. Autocompletion of commands

---
>Usage
```
gcc main.c -o main
main
```
