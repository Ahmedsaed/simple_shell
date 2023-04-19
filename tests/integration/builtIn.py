import subprocess
import os
import difflib

# Define the input for the shell
shell_input = "\n".join([
        "ls",
        "exit",
    ])

# Run your compiled shell executable and capture its output
shell_output = subprocess.run("./build/shell.out", input=shell_input, capture_output=True, text=True).stdout
shell_output = shell_output.replace("$ ", "").replace("\nexit", "").strip();

# Run bash and capture its output
bash_output = subprocess.run("/bin/sh", input=shell_input, capture_output=True, text=True).stdout.strip();

# Compare the output of your shell and bash
sm = difflib.SequenceMatcher(None, shell_output, bash_output)
if sm.ratio() > 0.2:
    print(f"Integration test {os.path.basename(__file__)} passed!")
else:
    print(f"Integration test {os.path.basename(__file__)} failed.")
    print("Shell output: ", shell_output)
    print("Bash output: ", bash_output)
    dif = difflib.Differ()
    shell_diff = dif.compare(shell_output.splitlines(), bash_output.splitlines())
    print("\n".join(shell_diff))
