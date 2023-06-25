# ByteShell: A Custom Shell

ByteShell is a custom shell implementation that provides a command-line interface to interact with the operating system. It allows users to execute various commands, navigate directories, and perform basic shell operations.

## Features

1. **Command Execution**: ByteShell can execute system commands and display the output to the user.
2. **Built-in Commands**: It supports several built-in commands such as `cd` (change directory), `history` (view command history), `exit` (exit the shell), `help` (display help information), `alias` (create command aliases), `kill` (terminate processes), `mkdir` (create directories), and `rmdir` (remove directories).
3. **Command History**: ByteShell maintains a history of executed commands, allowing users to view and reuse previous commands using the `history` command.
4. **Alias Support**: Users can create command aliases using the `alias` command, allowing them to define shortcuts for frequently used commands.
5. **Process Termination**: The `kill` command enables users to terminate processes by specifying their process IDs (PIDs).
6. **Directory Navigation**: ByteShell supports the `cd` command to change directories, allowing users to navigate through the file system.
7. **Error Handling**: The shell provides basic error handling and displays appropriate error messages when encountering issues.

## Compilation & Execution

To compile and execute ByteShell:

1. Clone the repository to your local machine.
2. Open a terminal or command prompt in the project directory.
3. Compile the shell using the following command:   
    `gcc -o shell shell.c command.c tokenizer.c builtins.c utils.c`

4. Execute the shell by running the following command: `./shell`


## Usage

Once you have launched ByteShell, you can start interacting with it by entering commands at the prompt. Here are some examples of command usage:

- **System Commands**: You can execute system commands like `ls`, `cat`, `pwd`, etc., by typing the command name followed by any required arguments.   
    * `ByteShell> ls`
    * `ByteShell> cat file.txt`   
    * `ByteShell> pwd`



- **Built-in Commands**: ByteShell provides several built-in commands:
    1. `cd`: Change the current directory.
        * `ByteShell> cd /path/to/directory`

    2. `history`: View the command history.
        * `ByteShell> history`


    3. `exit`: Exit the shell.
        * `ByteShell> exit`


    4. `help`: Display help information.
        * `ByteShell> help`


    5.  `alias`: Create command aliases.
        * `ByteShell> alias myls ls`


    6. `kill`: Terminate processes by specifying their PIDs.
        * `ByteShell> kill 1234`

    
    7. `mkdir`: Create directories.
        * `ByteShell> mkdir new_directory`

    
    8. `rmdir`: Remove directories.
        * `ByteShell> rmdir old_directory`


- **Command History**: You can access previous commands by using the `history` command.

## Contributions

Contributions to ByteShell are welcome! If you have any bug fixes, enhancements, or new features to propose, please submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for more details.

## Credits
ByteShell was developed by [Ashutosh Kumar](https://github.com/ashutoshkr129).


