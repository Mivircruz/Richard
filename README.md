# RichardEngine

Richard Engine is a game engine designed to build 2D singleplayer games

## Table of contents
<ol>
    <li>
        <a href="#about-the-project">About the project</a>
        <ul>
            <li><a href="#built-with">Built With</a></li>
        </ul>
    </li>
    <li>
        <a href="#getting-started">Getting started</a>
        <ul>
            <li><a href="#prerequisites">Prerequisites</a></li>
            <li><a href="#installation">Installation</a></li>
        </ul>
    </li>
    <li>
        <a href="#usage">Usage</a>
        <ul>
            <li><a href="#command-list">Command list</a></li>
        </ul>
    </li>
    <li><a href="#license">License</a></li>
</ol>

## About the project

RichardEngine is the final project to get my Software Engineering degree in Universidad de Buenos Aires. 

This project is being supervised by the professor Diego P. Corsi and developed by Milagros V. Cruz.

### Built With

* C++
* Python
* Lua

## Getting started

### Prerequisites

- **Operating system**

This project was designed to run in **Windows** only

- **Visual Studio**

Visual Studio is an integrated development environment (IDE) that is uses to write, debug, and build code. It can be downloaded in its [official website](https://visualstudio.microsoft.com/es/vs/)

- **VS Code**

Visual Studio Code is a code editor redefined and optimized for building and debugging modern web and cloud applications It can be downloaded in its [official website](https://code.visualstudio.com/)

- **WSL**

WSL, which stands for Windows Subsystem for Linux, let developers run a GNU/Linux environment directly on Windows. To install it, just run:

```bash
wsl --install
```

For more information, please refer to the [official website](https://learn.microsoft.com/en-us/windows/wsl/)

- **Premake**

 Premake is a self-contained, single file command line executable that can be downloaded from its [official website](https://premake.github.io/download) 

- **Python**

Python is a high level programming language that can be downloaded in its [official website](https://www.python.org/downloads/windows/)

- **MinGW-w64**

MinGW-64 will provide the necessary tools to compile the code. It can be installed via MSYS2 following [this tutorial](https://code.visualstudio.com/docs/cpp/config-mingw)

- **Aliases**

Executing the .exe *cli/cli.bat* will open a LINUX terminal. The file bash_aliases needs be edited to set the following aliases:

```bash
cli="./cli.sh" #To use *cli* as a command.
```

- **Environment variables**

Executing the .exe *cli/cli.bat* will open a LINUX terminal. The file bash_env needs be edited to set the following environment variables:

```bash
export VS_PATH="\"/mnt/c/your_path_to_devenv.exe\"" #Here you need to set yout path to devenv.exe inside yout Visual Studio installation

# MS build is what the Visual Studio compiler uses internally. This is what we what will be used to build this project. This executable is inside the IDE folder
export VS_BUILD_PATH="\"/mnt/c/your_path_to_MSBuild.exe\"" #Here you need to set yout path to MSBuild.exe inside yout Visual Studio installation. This executable is inside the MSBuild folder


export CODE_PATH="\"/mnt/c/your_path_to_Code.exe\"" #Here you need to set yout path to Code.exe inside yout VS Code installation. This executable is inside the Microsoft VS Code folder
```

- **Bashrc file**

The .bashrc file is a script file that's executed when a user logs in and bash_env needs to be added:
```bash
if [ -f ~/.bash_env ]; then
    . ~/.bash_env 
fi
```


## Usage

To clone the project, open a terminal and run:

```bash
git clone git@github.com:Mivircruz/RichardEngine.git
```

### Command list

Executing the .exe *cli/cli.bat* will open a LINUX terminal where commands can be ran.

To generate Visual Studio solutions, just change the file *premake5.lua* and run:

```bash
cli gensln
```

To check the command list version, just run: 

```bash
cli version
```

To string commands, just run *cli* followed by all the commands you want. *cli* command will handle them separately. For example:

```bash
cli gensln buildsln
```

## License

[Apache license 2.0](https://www.apache.org/licenses/LICENSE-2.0)

