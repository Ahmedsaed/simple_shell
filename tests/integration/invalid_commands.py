import subprocess
import difflib
import os

# Define the input for the shell
shell_input = "\n".join([
        "lasasds",
        "asdddecho \"hallo world\"",
    ])

# Run your compiled shell executable and capture its output
shell_process = subprocess.run("./build/shell.out", input=shell_input, capture_output=True, text=True)
shell_output = shell_process.stdout.replace("$ ", "").replace("\nexit", "").strip();
shell_stderr = shell_process.stderr

# Run bash and capture its output
bash_process = subprocess.run("/bin/sh", input=shell_input, capture_output=True, text=True)
bash_output = bash_process.stdout.strip()
bash_stderr = bash_process.stderr

# Compare the output of your shell and bash
sm = difflib.SequenceMatcher(None, shell_output, bash_output)
if sm.ratio() == 1 and len(shell_stderr.split('\n')) == len(bash_stderr.split('\n')):
    print(f"Integration test {os.path.basename(__file__)} passed!")
else:
    print(f"Integration test {os.path.basename(__file__)} failed.")
    print("Shell output: ", shell_output)
    print("Bash output: ", bash_output)
    dif = difflib.Differ()
    shell_diff = dif.compare(shell_output.splitlines(), bash_output.splitlines())
    print("\n".join(shell_diff))
