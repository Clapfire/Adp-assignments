# Adp-assignments
A collection of solutions to assignments in Advanced Programming at SDU

# How to use Create_Json_MS_Build bat for VS Code msbuild tool compiling/debugging:
Install "msbuild Tools" by sterin from the Extension manager in vs code. You can also clone the git repository and install it yourself.

Create a project using Visual Studio Community 2017

Copy the batch file into the project folder containing the .sln file.

Run the batch file

msbuild Tools will now be available to use to compile and debug this project from vs code.

# How to use Create_Json_MinGW for VS Code g++/gdb compiling/debugging
Install "C/C++" (ms-vscode.cpptools) by Microsoft from the Extension manager in vs code.

Download MinGW and install the mingw32-base and the mingw32-gcc-g++ packages in the default location (C:/MinGW)

(This is probably specific to Windows 10, how to edit path variables may vary if you have a different version)
Add the "C:\MinGW\bin" path to your PATH variable. This is found in Environment Variables under System Properties. Select the Path variable and click edit. Click new and paste the path into the slot.

Copy the batch file into the folder containing your C++ file. It is best to have a clean folder with only the cpp file.

Run the batch file

This should create the files necessary for VS Code to use the "Tasks: Run build task" (Ctrl+Shift+B) and Debug(F5) commands.

Note: In the launch.json file, there is a line commented out "preLaunchTask" : "build"
      Uncomment this line to compile when using the Debug command.
