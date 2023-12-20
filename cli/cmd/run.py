import project_settings
import os, subprocess, sys

CMD_DIR = "cli/cmd"

# This process runs the VS Solution
err = subprocess.call(["cmd.exe", "/c", "{}\\run.bat".format(CMD_DIR.replace("/", "\\\\")), project_settings.CONFIG, project_settings.PROJECT_NAME], cwd=os.getcwd())
sys.exit(err)