@echo off

powershell -c start -verb runas cmd '/c start /D "%CD%" wsl.exe'