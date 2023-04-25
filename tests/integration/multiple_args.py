import subprocess
import difflib
import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helper_functions import run_test


# Define the input for the shell
shell_input = "\n".join([
        "ls -l /tmp",
        "echo \"hallo world\"",
    ])

run_test(shell_input)