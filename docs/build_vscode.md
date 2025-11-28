# VSCode Instructions
VSCode provides a consistent development solution for Windows, Mac and Linux
that works well with Builderer workflow. The setup is identical across all
platforms, making it easy to get started.

## Create Python Virtual Environment
VSCode can help you create a Python environment in just a few steps:

### 1) Open the Command Palette (Ctrl-Shift-P or Cmd-Shift-P) and select "Python: Create Environment"
![](images/vscode/create_python_environment.png)

### 2) Select "Venv" as the environment type
![](images/vscode/select_python_venv.png)

### 3) Select a Python version >= 3.9 as your interpreter
![](images/vscode/select_python_version.png)

### 4) Select "requirements.txt" for what dependencies to install
![](images/vscode/select_python_requirements.png)

## Build, Run and Debug

The pre-configured launch targets automatically handle building and running your application. Simply:

### Press F5 or select a launch configuration in the "Run and Debug" panel

Available configurations:
- **apps:triangle debug** - Build and run in debug mode with debugger attached
- **apps:triangle release** - Build and run in release mode (optimized)

The build tasks use Builderer's `build` command which automatically:
- Generates build files if needed
- Invokes the appropriate native build tool (make, msbuild, etc.)
- Uses parallel compilation for fast builds
- Shows compiler errors and warnings in the Problems panel

![](images/vscode/debugging.png)

## Manual Build Tasks

You can also run build tasks manually from the Command Palette:
- **Terminal > Run Build Task** (Ctrl-Shift-B or Cmd-Shift-B)
  - Select "build_debug" to build debug configuration
  - Select "build_release" to build release configuration