import sys
import os
import re

def validate_directory(directory):
    """
    Validate if the given directory is valid.
    """
    if not os.path.isdir(directory):
        print(f"{directory} is not a valid directory")
        sys.exit(1)

def get_function_calls_from_file(filepath, excluded_functions):
    """
    Get all function calls from the given file.
    """
    unique_function_calls = set()

    with open(filepath, "r") as f:
        file_contents = f.read()

    function_calls = [file.replace("(", "") for file in re.findall(r"[a-zA-Z_]\w*\(", file_contents)]

    for func_call in function_calls:
        # print(func_call, func_call not in excluded_functions)
        if func_call not in excluded_functions:
            unique_function_calls.add(func_call)

    return unique_function_calls

def print_function_calls(filename, unique_function_calls):
    """
    Print all unique function calls from the given file.
    """
    print(f"Function calls in {filename}:")
    for function_call in sorted(unique_function_calls):
        print(function_call)

def find_function_prototypes(directory):
    """
    Find all function prototypes in both header and source files in the given directory.
    Return a set of unique function names.
    """
    function_prototypes = set()

    for filename in os.listdir(directory):
        if not (filename.endswith(".c") or filename.endswith(".h")):
            continue

        filepath = os.path.join(directory, filename)

        with open(filepath, "r") as f:
            file_contents = f.read()

        function_prototype_matches = re.findall(r"\w+\s+\**\s*\w+\s*\([^)]*\);\s*", file_contents)
        function_names = set([re.findall(r"\w+\s+\**\s*(\w+)\s*\([^)]*\);\s*", function_prototype)[0] for function_prototype in function_prototype_matches])

        function_prototypes.update(function_names)

    return function_prototypes

def main(directory):
    """
    Main function that loops through all .c files in the given directory and prints their unique function calls.
    """
    rv = 0

    validate_directory(directory)
    function_prototypes = find_function_prototypes(directory)
    
    excluded_functions = []

    if sys.argv[2] == "check":
        excluded_functions.extend(function_prototypes)
        excluded_functions.extend(["access", "chdir", "close", "closedir", "execve", "exit", "_exit", "fflush", "fork", "free", "getcwd", "getline", "getpid", "isatty", "kill", "malloc", "open", "opendir", "perror", "read", "readdir", "signal", "stat", "lstat", "fstat", "strtok", "wait", "waitpid", "wait3", "wait4", "write", "sizeof", "main"])

        for filename in os.listdir(directory):
            if not filename.endswith(".c"):
                continue

            filepath = os.path.join(directory, filename)
            unique_function_calls = get_function_calls_from_file(filepath, excluded_functions)
            if len(unique_function_calls) != 0:
                rv = 1
                print_function_calls(filename, unique_function_calls)

    elif sys.argv[2] == "all":
        excluded_functions.extend(["access", "chdir", "close", "closedir", "execve", "exit", "_exit", "fflush", "fork", "free", "getcwd", "getline", "getpid", "isatty", "kill", "malloc", "open", "opendir", "perror", "read", "readdir", "signal", "stat", "lstat", "fstat", "strtok", "wait", "waitpid", "wait3", "wait4", "write", "sizeof", "main"])

        for filename in os.listdir(directory):
            if not filename.endswith(".c"):
                continue

            filepath = os.path.join(directory, filename)
            unique_function_calls = get_function_calls_from_file(filepath, excluded_functions)
            if len(unique_function_calls) != 0:
                rv = 0
                print_function_calls(filename, unique_function_calls)

    elif sys.argv[2] == "prototypes":
        print(*list(function_prototypes), sep='\n')
        rv = 0

    exit(rv)

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python function_calls.py <directory>")
        sys.exit(1)

    directory = sys.argv[1]
    main(directory)
