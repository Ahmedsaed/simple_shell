import os
import subprocess
import difflib
import re
import inspect


def run_test(shell_input):
    filename = os.path.basename(inspect.stack()[1].filename)

    # run your compiled shell executable and capture its output
    shell_process = subprocess.run("./build/shell.out", input=shell_input, capture_output=True, text=True)
    shell_output = shell_process.stdout.strip()
    shell_stderr = shell_process.stderr.strip().replace("./build/shell.out", "shell")

    # run bash and capture its output
    bash_process = subprocess.run("/bin/sh", input=shell_input, capture_output=True, text=True)
    bash_output = bash_process.stdout.strip()
    bash_stderr = bash_process.stderr.strip().replace("/bin/sh", "shell")

    # compare the output of your shell and bash
    out, err = difflib.SequenceMatcher(None, shell_output, bash_output), difflib.SequenceMatcher(None, shell_stderr, bash_stderr)
    if out.ratio() == 1 and len(shell_stderr.split('\n')) == len(bash_stderr.split('\n')): # err.ratio() == 1
        print(f"integration test {filename} passed!")
    else:
        print(f"integration test {filename} failed.")
        if len(shell_stderr.split('\n')) != len(bash_stderr.split('\n')): #err.ratio() != 1
            print(f"stderr is different")
            print("shell error: ", shell_stderr)
            print("bash error: ", bash_stderr)
            dif = difflib.Differ()
            shell_diff = dif.compare(shell_stderr.splitlines(), bash_stderr.splitlines())
            print("\n".join(shell_diff))
        if out.ratio() != 1:
            print(f"stdout is different")
            print("shell output: ", shell_output)
            print("bash output: ", bash_output)
            dif = difflib.Differ()
            shell_diff = dif.compare(shell_output.splitlines(), bash_output.splitlines())
            print("\n".join(shell_diff))
