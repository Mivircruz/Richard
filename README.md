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
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
</ol>

## About the project

RichardEngine is the final project to get my Software Engineering degree in Universidad de Buenos Aires. 

This project is being supervised by the professor Diego P. Corsi and developed by Milagros V. Cruz.

### Built With

* C++
* Python
* Lua

## Prerequisites

- Operating system

This project was designed to run in **Windows** only

- WSL

WSL, which stands for Windows Subsystem for Linux, let developers run a GNU/Linux environment directly on Windows. To install it, just run:

```bash
wsl --install
```

For more information, please refer to the [official website](https://learn.microsoft.com/en-us/windows/wsl/)

- Premake

 Premake is a self-contained, single file command line executable that can be downloaded from its [official website](https://premake.github.io/download) 

- Python

Python is a high level programming language that can be downloaded in its [official website](https://www.python.org/downloads/windows/)

- MinGW-w64

MinGW-64 will provide the necessary tools to compile the code. It can be installed via MSYS2 following [this tutorial](https://code.visualstudio.com/docs/cpp/config-mingw)

## Usage

To clone the project, open a terminal and run:

```bash
git clone git@github.com:Mivircruz/RichardEngine.git
```
Executing the .exe *cli/exe.bat* will open a LINUX terminal. The file bash_aliases can be edited to set "cli="./cli.sh" so you can use *cli* as a command.

To generate Visual Studio solutions, just change the file *premake5.lua* and run:

```bash
cli gensln
```

## License

[Apache license 2.0](https://www.apache.org/licenses/LICENSE-2.0)