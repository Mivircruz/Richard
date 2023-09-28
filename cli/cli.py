import os
import sys
import subprocess

CMD_DIR = "cli/cmd"

def RunCommand(cmd):
    os.chdir("..")
    subprocess.call(["python3", "{}/{}/{}.py".format(os.getcwd(), CMD_DIR, cmd)])

for i in range(1, len(sys.argv)):
    cmd = sys.argv[1]
    print( "-----------------------------------------")
    print("Executing command ", cmd)

    RunCommand(cmd)