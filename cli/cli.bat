REM Avoids printing out everything that is currently running
@echo off

REM Opens up a wsl prompt at this directoy so we can run Richard's commands
powershell -c start -verb runas cmd '/c start /D "%CD%" wsl.exe'