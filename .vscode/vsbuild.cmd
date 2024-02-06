@echo off
setlocal enabledelayedexpansion
for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -requires Microsoft.Component.MSBuild -find **\MSBuild.exe`) do (
  "%%i" %*
  EXIT /b !errorlevel!
)
ECHO Failed to locate MsBuild 1>&2
EXIT /b 1