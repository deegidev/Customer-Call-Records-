Date: 6/30/2021

Situation - Attempting to convert school C++ project to native environement.  
Task and Problem - Taking proect files and copy/pasting them to Visual Studio Code to check for errors, so that I can commit them to github via Visual Studio code. 
Problem: Include errors -- Unable to resolve configuration with compilerPath: "gcc". 
Action - All of the text below shows my results form searching various parts of error messages.  
Resolution - Success!! Environment set up for C/C++ projects.     


Precondition: C/C++ for Visual Studio code downloaded and enabled globally. Code runner as well.
Downloaded for Visual Studio as well.
Took a while (Created "Newbie Programming Vocabulary" project while I waited.)
Tried to set up in Windows Powershell
Tried to set up in Powershell for Visual Studio
Same error.
Solution: Decided to slow down and watch a full Youtube: How to Download and Install C Cpp Toolset ( gcc g++ gdb ) in Windows 10 using mingw-w64 and msys2 https://www.youtube.com/watch?v=0HD0pqVtsmw

Msys2- A software distribution and building platform for Windows. A collection of tools and libraries needed for the environment for building and creating Native Windows applications.
It consists of a command line terminal called mintty, bash, version control systems like git and subversion, tools like tar and awk and even build systems like autotools, all based on a modified version of Cygwin.
Provides package management system called pacman that keeps the system up to date by synchronizing package lists with the master server. mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb
Set up path location variable.
Opened C++ file again Visual Studio Code > Run.
Problem: New error -- collect2.exe: error: ld returned 1 exit status https://stackoverflow.com/questions/27593029/c-compile-collect2-error-ld-returned-1-exit-status
Solution: Start > Environment Variable > Path > C C++ Workspace path copied > Save > Close Workspace > Reopen > Run
Success!!!
Problem: No console I/O + Code wont stop running.

Settings > Check: Run code in Terminal.
Problem: Unable to write into user settings. Please open the user settings to correct errors/warnings in it and try again. https://stackoverflow.com/questions/68185876/vs-code-unable-to-write-into-user-settings-please-open-the-user-settings-to-co
Solution: Delete all text in json file.
Success!!!
Postcodition: Environment set up for C/C++ projects./
