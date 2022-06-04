# Object-Oriented Programming 2 - Practical Work

C++ project based on Simple-Cpp-Setup

## If you use the Dev Container

If you install [ms-vscode-remote.remote-containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) and [Docker](https://www.docker.com/products/docker-desktop), you will be able to run your code inside a Linux container (kind of like a virtual machine, but faster). Also, you will get static analyzers, code formatters and useful extensions installed out of the box! It is a great option to get started with C++ quickly.

(Unfortunately, if you want to do GUI applications they don't work well from within a container and you might have to do a proper setup on your own desktop instead. But for simple command-line applications this works amazingly well!)

NB: the container might take a while to build the first time.

## If you don't use the Dev Container

### Compiling

You need to install [CMake](https://cmake.org/download/).

To use CMake I recommend this VS Code extension : [ms-vscode.cmake-tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools). You will need to setup the extension with a compiler. Here is [the tutorial](https://code.visualstudio.com/docs/cpp/cmake-linux). It is based on Linux but at the bottom of the page you will find the explanations to adapt it for [Windows](https://code.visualstudio.com/docs/cpp/config-msvc) and [Mac](https://code.visualstudio.com/docs/cpp/config-clang-mac).

Alternatively you can just create a *build* folder at the root of this project, open a terminal and run `cmake ..`; chances are it will detect what compiler you have installed and generate the appropriate Makefile / Visual Studio solution / Xcode project.

### Auto-formatting

[Check this out](https://julesfouchy.github.io//Learn--Clean-Code-With-Cpp/lessons/formatting-tool) to learn why you would want to use a code formatter and how to do it.

### Static analysis

[Check this out](https://julesfouchy.github.io/Learn--Clean-Code-With-Cpp/lessons/static-analysis-and-sanitizers) to learn why you would want to use static analysis and how to do it.

## Lessons read

### ✅ Level 1

### 🔳 Level 2
+ [X] Make it work, then make it good
+ [X] Prefer free functions
+ [X] Design cohesive classes
+ [ ] Use structs to group data
+ [ ] Write small functions
+ [X] DRY: Don't repeat yourself
+ [X] Enums
+ [X] Split problems in small pieces
+ [ ] Composition over Inheritance

### 🔳 Level 3
+ [ ] std::vector
+ [ ] Minimize dependencies
+ [ ] Strong Types
+ [ ] Use libraries
+ [ ] Range-based for loop
+ [ ] Testing
+ [ ] Lambda functions
+ [ ] Master your IDE
+ [ ] std::optional
+ [ ] Single Source of Truth
+ [ ] Code reviews
+ [ ] const
+ [ ] Documentation
+ [ ] Don't overfocus on performance
+ [X] Git submodules
+ [ ] STL algorithms
+ [ ] assert
+ [ ] auto
+ [ ] Debug vs Release
+ [ ] Immediately Invoked Function
+ [ ] Markdown
+ [ ] Smart Pointers
+ [ ] std::function
+ [ ] Dependency Injection
+ [ ] Error Handling
+ [ ] Git Pull Requests
+ [ ] Advanced Git features
+ [X] CMake
+ [ ] Functional programming
+ [ ] Move semantics
+ [ ] The Rule of 5
+ [ ] State and Strategy
+ [ ] std::variant
+ [ ] Cache and Branches
+ [ ] Multithreading
+ [ ] Polymorphism
+ [ ] Space out your code

### 🔳 Level 4

### 🔳 Level 5