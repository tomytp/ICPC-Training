#!/usr/bin/env python3
#
# Testing tool for the King of the Hill problem
#
# Usage:
#
#   python3 testing_tool.py -f inputfile <program invocation>
#
#
# Use the -f parameter to specify the input file, e.g. 1.in.
# Format of the input file:
# - One line with an integer n, the size of one of the sides of the input square.
# - n lines with n integers, the values in the grid
# e.g.:
# 3
# 1 3 5
# 7 9 8
# 6 4 2
#
#
# You can compile and run your solution as follows:

# C++:
#   g++ solution.cpp
#   python3 tool.py -f in_ ./k

# Python3
#   python3 testing_tool.py -f 1.in python3 ./solution.py

# Java
#   javac solution.java
#   python3 testing_tool.py -f 1.in java solution

# Kotlin
#   kotlinc solution.kt
#   python3 testing_tool.py -f 1.in kotlin solutionKt


# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it.
#
# The tool attempts to detect and report common errors, but it is not an exhaustive test.
# It is not guaranteed that a program that passes this testing tool will be accepted.


import argparse
import subprocess
import traceback
import time

def write(p, line):
    assert p.poll() is None, "Program terminated early"
    print(f"Write: {line}", flush=True)
    p.stdin.write(f"{line}\n")
    p.stdin.flush()


def read(p):
    assert p.poll() is None, "Program terminated early"
    line = p.stdout.readline().strip()
    assert line != "", "Read empty line or closed output pipe"
    print(f"Read: {line}", flush=True)
    return line


parser = argparse.ArgumentParser(description="Testing tool for problem King of the Hill.")
parser.add_argument(
    "-f",
    dest="inputfile",
    metavar="inputfile",
    default=None,
    type=argparse.FileType("r"),
    required=True,
    help="The input file to use.",
)
parser.add_argument("program", nargs="+", help="Invocation of your solution")

args = parser.parse_args()

with args.inputfile as f:
    lines = f.readlines()
    assert len(lines) > 0

    n = int(lines[0].split()[0])
    max_queries = 10 * n + 100

    grid = [list(map(int, line.split())) for line in lines[1:]]
    answer = max(v for line in grid for v in line)

with subprocess.Popen(
    " ".join(args.program),
    shell=True,
    stdout=subprocess.PIPE,
    stdin=subprocess.PIPE,
    universal_newlines=True,
) as p:
    try:
        write(p, n)

        queries = 0
        while True:
            op, *rest = read(p).split()
            if op == "?":
                queries += 1
                x, y = map(int, rest)
                assert (
                    1 <= x <= n and 1 <= y <= n
                ), f"Your query ({x}, {y}) is out-of-bounds (x and y must be between 1 and {n})"
                write(p, grid[y - 1][x - 1])
            elif op == "!":
                v = int(rest[0])
                if (v != answer):
                    while True:
                        print(v, answer)
                        time.sleep(5)
                        pass
                assert v == answer, f"You printed {v}, but the answer is {answer}."
                
                break
            else:
                assert False, f"Operation '{op}' is not one of '?' or '!'."

        assert (
            p.stdout.readline() == ""
        ), "Your submission printed extra data after finding a solution."
        assert p.wait() == 0, "Your submission did not exit cleanly after finishing."

        assert (
            queries <= max_queries
        ), f"Used {queries} queries, which is more than the allowed 10n+100 ({max_queries})."

        print(f"\nSuccess.\nQueries used: {queries}\n")


    except AssertionError as e:
        print()
        print(f"Error: {e}")
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()

    except Exception as e:
        print()
        traceback.print_exc()
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()
        raise e

    finally:
        print(f"Exit code: {p.wait()}\n", flush=True)
