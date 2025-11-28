# Getting Started with Builderer Examples

This repository demonstrates how to use [Builderer](https://github.com/builderer/builderer) for cross-platform C/C++ development.

## Quick Start

For the fastest way to get started, we recommend using VSCode which provides a consistent experience across all platforms: **[VSCode Setup Guide](build_vscode.md)** - Just create a Python environment and press F5!

Alternatively, if you prefer command-line tools: **[Command-Line Instructions](build_cmdline.md)** - Build and run from your terminal

## Prerequisites

### Required for All Platforms
* **Git** - Required to fetch dependencies
* **Python 3.9+** - Required for Builderer to generate build files

### Platform-Specific Requirements

* Windows
  * Visual Studio 2022 with "Desktop development with C++"

* macOS
  * XCode Command-line Tools: `xcode-select --install`

* Linux
  * C/C++ toolchain: `build-essential`, `g++-multilib`
  * GLFW dependencies: `libx11-dev`, `libxcursor-dev`, `libxinerama-dev`, `libxi-dev`, `libxrandr-dev`

#### WebAssembly / Emscripten
* [Emscripten SDK](https://emscripten.org/)