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

## Getting started

### Prerequisites

- **Operating system**

This project was designed to run in **Windows** only

- **Visual Studio**

Visual Studio is an integrated development environment (IDE) that is uses to write, debug, and build code. It can be downloaded in its [official website](https://visualstudio.microsoft.com/es/vs/)

- **VS Code**

Visual Studio Code is a code editor redefined and optimized for building and debugging modern web and cloud applications It can be downloaded in its [official website](https://code.visualstudio.com/)

- **GLFW**

GLFW is is a library, written in C, specifically targeted at OpenGL. GLFW gives the bare necessities required for rendering images to the screen.

It can be obtained from the [official website](https://www.glfw.org/download.html)

- **GLAD**
Because OpenGL is only really a standard/specification it is up to the driver manufacturer to implement the specification to a driver that the specific graphics card supports. Since there are many different versions of OpenGL drivers, the location of most of its functions is not known at compile-time and needs to be queried at run-time. GLAD is an open source library that manages the retrieval of the location of the functions the app needs and store them in function pointers for later use. 

It can be obtained from the [official website](https://glad.dav1d.de//)


## Usage

To clone the project, open a terminal and run:

```bash
git clone git@github.com:Mivircruz/RichardEngine.git
```

### Linkig

We need to include the directories in the engine and on the client that is going to use the engine.

Let's start with the engine. In the include directories include:

```
src
..\dependencies\include
..\dependencies\include\glad\include
```

On the client, we will add the engine code in the include directories:

```
..\engine\src
```

### Start coding

The new VS solution that will use Richard Engine needs to implement the application.h interface. Once implemented, you can use it to create your game.

## License

[Apache license 2.0](https://www.apache.org/licenses/LICENSE-2.0)

