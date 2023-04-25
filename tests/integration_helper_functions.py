import os
import subprocess
import difflib
import re
import inspect


def run_test(shell_input):
    filename = os.path.basename(inspect.stack()[1].filename)

    # run your compiled shell executable and capture its output
    shell_process = subprocess.run("./build/shell.out", input=shell_input, capture_output=True, text=True)
    shell_output = re.sub(r".*\$ ", "", shell_process.stdout, flags=re.MULTILINE).strip()
    shell_stderr = shell_process.stderr

    # run bash and capture its output
    bash_process = subprocess.run("/bin/sh", input=shell_input, capture_output=True, text=True)
    bash_output = bash_process.stdout.strip()
    bash_stderr = bash_process.stderr

    # compare the output of your shell and bash
    sm = difflib.SequenceMatcher(None, shell_output, bash_output)
    if sm.ratio() == 1 and len(shell_stderr.split('\n')) == len(bash_stderr.split('\n')):
        print(f"integration test {filename} passed!")
    else:
        print(f"integration test {filename} failed.")
        if len(shell_stderr.split('\n')) != len(bash_stderr.split('\n')):
            print(f"stderr is not similar")
            print("shell error: ", shell_stderr)
            print("bash error: ", bash_stderr)
        else:
            print("shell output: ", shell_output)
            print("bash output: ", bash_output)
            dif = difflib.Differ()
            shell_diff = dif.compare(shell_output.splitlines(), bash_output.splitlines())
            print("\n".join(shell_diff))
