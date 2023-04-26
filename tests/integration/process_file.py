import os
import subprocess
import difflib
import re
import inspect


def run_test(input_file):
    filename = os.path.basename(inspect.stack()[1].filename)

    # run your compiled shell executable and capture its output
    shell_process = subprocess.run(["./build/shell.out", input_file], capture_output=True, text=True)
    shell_output = shell_process.stdout
    shell_stderr = shell_process.stderr.replace("./build/shell.out", "shell")

    # run bash and capture its output
    bash_process = subprocess.run(["/bin/sh", input_file], capture_output=True, text=True)
    bash_output = bash_process.stdout
    bash_stderr = bash_process.stderr.replace("/bin/sh", "shell")

    # compare the output of your shell and bash
    out, err = difflib.SequenceMatcher(None, shell_output, bash_output), difflib.SequenceMatcher(None, shell_stderr, bash_stderr)
    if out.ratio() == 1 and len(shell_stderr.split('\n')) == len(bash_stderr.split('\n')) and shell_process.returncode == bash_process.returncode:
        print(f"integration test {filename} passed!")
    else:
        print(f"integration test {filename} failed.")
        if len(shell_stderr.split('\n')) != len(bash_stderr.split('\n')): #err.ratio() != 1
            print(f"stderr is different")
            print("shell error: \n", shell_stderr)
            print("bash error: \n", bash_stderr)
            dif = difflib.Differ()
            shell_diff = dif.compare(shell_stderr.splitlines(), bash_stderr.splitlines())
            print("\n".join(shell_diff))
        if out.ratio() != 1:
            print(f"stdout is different")
            print("shell output: \n", shell_output)
            print("bash output: \n", bash_output)
            dif = difflib.Differ()
            shell_diff = dif.compare(shell_output.splitlines(), bash_output.splitlines())
            print("\n".join(shell_diff))
        if shell_process.returncode != bash_process.returncode:
            print(f"exit status is different")
            print(f"Shell exit code: {shell_process}")
            print(f"Bash exit code: {bash_process}")


run_test("./tests/sample_input2.txt")