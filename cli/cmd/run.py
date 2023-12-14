import globals
import os, subprocess

CMD_DIR = "cli/cmd"

# This process runs the VS Solution
subprocess.call(["cmd.exe", "/c", "{}\\run.bat".format(CMD_DIR.replace("/", "\\\\")), globals.CONFIG, globals.PROJECT_NAME], cwd=os.getcwd())