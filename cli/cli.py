import os
import sys
import subprocess

PYTHON_VERSION = "python3"
CMD_DIR = "cli/cmd"

# RunCommand takes a command name, finds its path and executes it
# If no path is found, it prints a message error
def RunCommand(cmd):
    err = 0
    
    os.chdir("..")
    script_path =  "{}/{}/{}.py".format(os.getcwd(), CMD_DIR, cmd)

    if os.path.exists(script_path):
        print("Executing command", cmd)
        err = subprocess.call([PYTHON_VERSION, script_path])
    else:
        print("Invalid command", cmd)
        err = -1

    return err

# This loop iterates over the commands received and runs them 
for i in range(1, len(sys.argv)):
    cmd = sys.argv[1]
    print( "\n-----------------------------------------")

    if RunCommand(cmd) != 0:
        break