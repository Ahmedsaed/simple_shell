import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helper_functions import run_test


# Define the input for the shell
shell_input = "\n".join([
        "ls",
        "ls;",
        "ls ;",
        "ls ; ls /var",
        "ls /tmp; echo \"hello there \"; ls /var"
    ])

run_test(shell_input)
