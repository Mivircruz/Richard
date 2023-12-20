import subprocess
import sys
import project_settings

# This proccess generates a Visual Studio solution
# The specifications of this solution are defined in the Premake file
err = subprocess.call(["cmd.exe", "/c", project_settings.PREMAKE_PATH, project_settings.VS_VERSION])
sys.exit(err)