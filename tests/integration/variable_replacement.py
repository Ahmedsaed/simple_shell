import subprocess
import os
import difflib
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helper_functions import run_test

# Define the input for the shell
shell_input = "\n".join([
        "setenv name ahmed",
        "setenv hallo hehe",
        "echo $name",
        "echo $hallo",
        "echo $PATH",
        "unsetenv name",
        "echo $name"
    ]) 

run_test(shell_input)
