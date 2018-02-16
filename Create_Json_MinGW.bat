@echo off
@break off
@title Create Json files for MinGW
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

for /f "usebackq "" delims=" %%a in ('*.cpp') do (set name=%%~na)
	
(
  echo {
  echo    "version": "0.2.0",
  echo    "configurations": [
  echo        {
  echo            "name": "(gdb) Launch",
  echo            "type": "cppdbg",
  echo            "request": "launch",
  echo            "program": "${workspaceFolder}/a.exe",
  echo            "args": [],
  echo            "stopAtEntry": false,
  echo            "cwd": "${workspaceFolder}",
  echo            "environment": [],
  echo            "externalConsole": true,
  echo            "MIMode": "gdb",
  echo            "miDebuggerPath": "C:\\mingw\\bin\\gdb.exe",
  echo            "setupCommands": [
  echo                {
  echo                    "description": "Enable pretty-printing for gdb",
  echo                    "text": "-enable-pretty-printing",
  echo                    "ignoreFailures": true
  echo                }
  echo            ],
  echo            //uncomment the line below to compile before debugging
  echo            //"preLaunchTask": "build"
  echo        }
  echo    ]
  echo }
  
) > "%cd%\.vscode\launch.json"

(
  echo {
  echo     "version": "2.0.0",
  echo     "tasks": [
  echo         {
  echo             "label": "build",
  echo             "type": "shell",
  echo             "command": "g++",
  echo             "args": [
  echo                 "-g", "'${workspaceRoot}\\!name!.cpp'"
  echo             ],
  echo             "group": {
  echo                 "kind": "build",
  echo                 "isDefault": true
  echo             }
  echo         }
  echo     ]
  echo }
) > "%cd%\.vscode\tasks.json"

exit