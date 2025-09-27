# Command-line Instructions
For users that prefer building directly on command-line, or for the purposes of
automation...
## Create Python Virtual Environment
```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```
## Generate Build Files
Config options: `windows`, `linux`, `macos`, `emscripten`
```bash
builderer --config=CONFIG_OF_CHOICE_HERE generate
```
## Building (Linux)
```bash
builderer --config=linux generate
make -C Out/build/linux -j build
```
## Building (macOS)
```bash
builderer --config=macos generate
make -C Out/build/macos -j build
```
## Building (Emscripten)
```bash
builderer --config=emscripten generate
make -C Out/build/emscripten -j build
# Test with local server...
python3 -m http.server 8080 --directory=Out/emscripten
```
## Building (Windows)
```bash
builderer --config=windows generate
msbuild Out/build/windows/Solution.sln /p:Platform=x64 /p:Configuration=debug
```
