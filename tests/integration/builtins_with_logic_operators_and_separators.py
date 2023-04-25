import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helper_functions import run_test


# Define the input for the shell
shell_input = "\n".join([
        "ls /var && ls /var",
        "cd asdasdasd && echo \"you shouldn't read this\"",
        "",
        "cd asdasdasd || echo \"can you see me ;)\"",
        "cd /build; cd - ; cd - ; cd -;"
        ])

run_test(shell_input)
