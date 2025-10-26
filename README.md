# Builderer Examples

This repository demonstrates how to use [Builderer](https://github.com/builderer/builderer) for cross-platform C/C++ development.

## What is Builderer?

Builderer is a fast, dependency-free build file generator for C/C++/Objective-C projects. It generates native build files (Makefiles, Visual Studio solutions) from Python-based build descriptions, supporting multiple platforms without the complexity of traditional meta-build systems.

## Quick Start

### With VSCode (Recommended)
1. Create a Python virtual environment (see [VSCode Setup Guide](docs/build_vscode.md))
2. Press F5 to build and debug!

### With Command Line
```bash
# Create Python environment
python -m venv .venv
source .venv/bin/activate  # On Windows: .venv\Scripts\activate
pip install -r requirements.txt

# Build and run
builderer --config=macos build
builderer --config=macos run apps:triangle
```

## What's Included

This example project includes:
- **Triangle demo** - A simple OpenGL application that works on Windows, macOS, Linux, and WebAssembly
- **Cross-platform builds** - Configured for Windows (MSBuild), macOS/Linux (Make), and Emscripten (WebAssembly)
- **VSCode integration** - Pre-configured tasks and launch configurations
- **External dependencies** - Demonstrates using git repositories (GLFW, glad, linmath)

## Documentation

- **[Getting Started](docs/build.md)** - Prerequisites and setup instructions
- **[VSCode Instructions](docs/build_vscode.md)** - Build and debug in VSCode
- **[Command-Line Instructions](docs/build_cmdline.md)** - Build from the terminal

## What's New

This example has been updated to use Builderer's new `build` and `run` commands for a simpler workflow:

```bash
# Old way (still works)
builderer --config=macos generate
make -C Out/build/macos -j build

# New way (recommended)
builderer --config=macos build        # Generate + build in one step
builderer --config=macos run apps:triangle  # Build + run
```

## Learn More

For more information about Builderer, visit:
- [Builderer Documentation](https://github.com/builderer/builderer/tree/main/docs)
- [Builderer Repository](https://github.com/builderer/builderer)
