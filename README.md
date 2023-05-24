****simple_shell****
A simple UNIX command interpreter that provides a user interface to access and give orders to the operating system.

**It’s time for the famous Simple Shell project**

 This is one of the most anticipated project and also one that will challenge you a lot about everything you have learn so far:

>>Basics of programming

>>Basics of C

>>Basics of thinking like an engineer

>>Group work

>>and Learning how to learn


## Description
This is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. This was made as a project for Holberton School. In this project we apply the knowledge that we have learned in C programming language.
Standard functions and system calls employed in simple_shell include:
   ```sh
   access, execve, exit, fork, free, malloc, read, signal, wait, write.
   ```
### Features
- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [x] handles comments (#)
- [x] handles **;**
- [x] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement

### Built-ins

- [x] exit
- [x] env
- [ ] setenv
- [ ] unsetenv
- [x] cd
- [ ] help
- [ ] history

### Examples
<div id="examples"><div/>

1. Absolute path commands
- non interactive
```bash
$ echo "/bin/pwd" | ./hsh
$ /home/timex/simple_shell
```
- interactive mode
``` bash
$ ./hsh
./hsh$ /bin/echo hello world
helo world
./hsh$ exit
$
```
2. short command
- non interactive
```bash
$ echo "pwd" | ./hsh
$ /home/timex/simple_shell
```
- interactive mode
``` bash
$ ./hsh
./hsh$ echo hello world
helo world
./hsh$ exit
$
```
3. built-ins
- non interactive
```bash
$ echo "exit" | ./hsh
$ echo $?
0
```
- interactive mode
``` bash
$ ./hsh
./hsh$ exit 98
$ echo $?
98
```

**Some error output**
``` bash
$ ./hsh
./hsh$ ls /non_existing_folder
ls: cannot access '/non_existing_folder': No such file or directory
./hsh$ exit
$ echo $?
2
```
``` bash
$ echo "non_valid_command" | ./hsh
./hsh: 1: non_valid_command: not found
$ echo $?
127
```