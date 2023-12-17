import globals
import os, subprocess, sys

CMD_DIR = "cli/cmd"

# This process runs the VS Solution
err = subprocess.call(["cmd.exe", "/c", "{}\\run.bat".format(CMD_DIR.replace("/", "\\\\")), globals.CONFIG, globals.PROJECT_NAME], cwd=os.getcwd())
sys.exit(err)