# Command-line Instructions
For users that prefer building directly on command-line, or for the purposes of
automation...

## Create Python Virtual Environment
```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

## Quick Start - Build and Run

Config options: `windows`, `linux`, `macos`, `emscripten`

### Build Everything
```bash
builderer --config=linux build
```

### Build and Run a Specific Target
```bash
# Linux
builderer --config=linux run apps:triangle

# macOS
builderer --config=macos run apps:triangle

# Windows
builderer --config=windows run apps:triangle
```

## Advanced Usage

### Generate Build Files Only
If you prefer to use native build tools directly (make, msbuild, etc.):
```bash
builderer --config=linux generate
make -C Out/build/linux -j$(nproc) build CONFIG=debug
```