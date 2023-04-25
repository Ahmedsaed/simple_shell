import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helper_functions import run_test


# Define the input for the shell
shell_input = "\n".join([
        "alias",
        "alias l=lol",
        "alias e=eoe name=ahmed"
    ])

run_test(shell_input)
