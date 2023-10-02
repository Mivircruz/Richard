import subprocess
import os

PREMAKE_PATH = "bin\\premake\\premake5"
VS_VERSION = "vs2022"

# This proccess generates a Visual Studio solution
# The specifications of this solution are defined in the Premake file
subprocess.call(["cmd.exe", "/c", PREMAKE_PATH, VS_VERSION])