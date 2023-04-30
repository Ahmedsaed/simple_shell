[![Automated Tests](https://github.com/Ahmedsaed/simple_shell/actions/workflows/QA-testing.yml/badge.svg?branch=main)](https://github.com/Ahmedsaed/simple_shell/actions/workflows/QA-testing.yml)

# Simple Shell Project - ALX SE Program

This is a project developed as part of the ALX SE Program. It is a simple UNIX command interpreter (shell) program that simulates the functionalities of a Unix shell. Additional functions are also included. This program was written entirely in C.

## Description

The Simple Shell program is a command-line interface that accepts user input and executes corresponding commands. It provides a basic set of functionalities such as executing commands, changing directories, displaying environment variables, handling aliases, and exiting the shell.

## Usage

To use the Simple Shell program, follow these steps:

1. Clone the repository from GitHub to your local machine:  
`git clone https://github.com/Ahmedsaed/simple_shell.git`

2. Compile the program by running the following command:  
`gcc -Wall -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

3. Run the program by typing the following command:
`./hsh`

4. Once the program is running, you can type commands into the command prompt and the program will execute them.

5. You can go an extra step and set the shell to be the default on your terminal app **[Not Recommended]**   
    - In Gnome Terminal: Preferences > Profile > Command  
    - Enable `Run a custom command instead of my shell`
    - Set `Custom Command` to the path to the compiled shell

## Makefile Usage

We have wrote a Makefile that can be used to automate various tasks such as checking the code style, compiling the shell, running tests, and more.

To use the Makefile, open a terminal and navigate to the project directory. Then, type `make` followed by the recipe you want to run. Here's a list of the available recipes:

- `check_style`: This recipe checks the code style of all C files in the project using the Betty style checker. This requires the `betty-style` and `betty-doc` programs to be installed.

- `build`: This recipe compiles the shell. It generates an executable file called `shell.out`. 

- `run_tests`: This recipe runs unit and integration tests on the shell. The integration tests requires `python 3` to be installed

- `check_memory`: This recipe checks for memory leaks and errors using Valgrind. It requires the `Valgrind` program to be installed.

- `all`: This is a special recipe that gets called when no arguments are being passed to `make`. This recipe will run `clear_screen check_style build run_tests check_memory check_forbidden_functions`. This means typing `make` in terminal will run these recipes in order.

- `check_forbidden_functions`: This recipe checks if any forbidden function is used in any C file in the project.

- `print_used_functions`: This recipe prints all user-defined and predefined functions.

- `run`: This recipe runs the compiled shell (`./build/shell.out`).

- `ssh_alx`: This recipe allows you to SSH into the ALX provided sandbox using the variables defined in the environment variables. This requires the `sshpass` program to be installed.  
    - You need to set these variables to their respective values
        - `ALX_HOST`: sandbox host name
        - `ALX_PASSWORD`: sandbox password
        - `ALX_USER`: the username used to ssh into the sandbox

Note that some of the recipes require specific programs to be installed, such as `valgrind`, `betty-style`, `betty-doc`, and `sshpass`. If you encounter any errors when running the Makefile, make sure that these programs are installed on your system.

To run a recipe, type `make` followed by the recipe name. For example, to compile the shell, type:

```bash
make build
```

This will generate an executable file called `shell.out` in `build` directory. To run the shell, type:
```bash
make run
```

## Features

The Simple Shell program supports the following features:

- Displays a shell prompt that shows the `current working directory`
- Execution of commands
- Changing directories
- Displaying environment variables
- Handling aliases
- Exiting the shell
- Uses a custom implementation of `getline` and `strtok`
- Supports command separator `;`
- Supports shell logical operators `||` and `&&`
- Supports Variable replacement
- Supports Alias replacement
- Supports shell commands `#`
- Execute instructions and commands from a file

## Included Built-Ins

Our shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.                                                                    |
| setenv [var] [value]| Set an environment variable and value. If the variable exists, the value will be updated. |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the directory.                                                                     |

## Examples

Here are some examples of how to use the Simple Shell program:

- Execute a command:
```bash
~/Documents/Projects/ALX/simple_shell$ ls
AUTHORS  built_in2.c  env_utils1.c  error.c  getline2.c  main.h    mem_utils.c  parser.c       README.md  shell_handlers.c  str_utils2.c  tests     build    built_in.c   env_utils2.c  file.c   getline.c   Makefile  output       print_utils.c  shell.c    str_utils1.c      str_utils3.c
```

- Change directory:
```bash
~/Documents/Projects/ALX/simple_shell$ cd /home/ahmed/Documents
~/Documents$ 
```

- Display environment variable:
```bash
~/Documents/Projects/ALX/simple_shell$ echo $PATH
/home/ahmed/.local/bin:/usr/local/bin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/sbin:/var/lib/flatpak/exports/bin:/usr/lib/jvm/default/bin:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl:/home/ahmed/.local/share/gem/ruby/3.0.0/bin
~/Documents/Projects/ALX/simple_shell$ 
```

- Exit the shell:
```bash
~/Documents/Projects/ALX/simple_shell$ exit
```

## Authors

This program was developed by [Ahmed Saed](https://www.github.com/Ahmedsaed) and [Adham Essam](https://www.github.com/Adhamet) as part of the ALX SE Program.