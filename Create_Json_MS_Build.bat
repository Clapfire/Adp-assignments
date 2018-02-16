@echo off
@break off
@title Create folder with batch but only if it doesn't already exist - D3F4ULT
@color 0a
@cls

setlocal EnableDelayedExpansion

if not exist "%cd%\.vscode\" (
  mkdir "%cd%\.vscode\"
  if "!errorlevel!" EQU "0" (
    echo Folder created successfully
  ) else (
    echo Error while creating folder
  )
) else (
  echo Folder already exists
)

for /f "usebackq "" delims=" %%a in ('*.sln') do (set name=%%~na)
	
(
  echo {
  echo     "solution": "${workspaceRoot}/!name!.sln",
  echo     "variables": {
  echo         "MSBUILD": "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/MSBuild/15.0/Bin/MSBuild.exe",
  echo         "DEVENV": "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/Common7/IDE/devenv.com"
  echo     },
  echo     "preBuildTasks": [
  echo         {
  echo             "name": "Building",
  echo             "program": "cmd",
  echo             "args": [ "/c", "echo [pre-build task]: Preparing to build" ],
  echo             "cwd": "${workspaceRoot}"
  echo         }
  echo     ],
  echo     "postBuildTasks": [
  echo         {
  echo             "name": "Post Build",
  echo             "program": "cmd",
  echo             "args": [ "/c", "echo [post-build task]: Build Complete" ],
  echo             "cwd": "${workspaceRoot}"
  echo         }
  echo     ],
  echo     "debugConfigurations": [
  echo         {
  echo             "name": "Debug",
  echo             "cwd": "${workspaceRoot}",
  echo             "program": "${workspaceRoot}/x64/${buildConfig}/!name!.exe",
  echo             "args": []
  echo         }
  echo     ] 
  echo }
) > "%cd%\.vscode\msbuild-tools.json"

exit