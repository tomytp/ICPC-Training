import subprocess
import argparse

from pathlib import Path

from problem_processor import ProblemProcessor
from server import TimedHTTPServer , ContestProblemHandler


PORT = 10043

def main():
    parser = argparse.ArgumentParser(description="Contest Problem Parser for Competitive Companion")
    args = parser.parse_args()
    
    processor = ProblemProcessor()
    server = TimedHTTPServer(('localhost', PORT), ContestProblemHandler)
    server.problem_processor = processor
    
    print(f"Starting Competitive Companion parser on port {PORT}")
    print("Waiting for problems...\n")
    
    try:
        contest_dir = server.serve_with_timeout()
        if contest_dir:
            print(f"\nOpening VS Code in directory: {contest_dir}")
            subprocess.Popen([
                'code',
                str(contest_dir),
            ])
        else:
            print("\nNo contest directory created.")
    except KeyboardInterrupt:
        print("\nShutting down...")
    finally:
        server.server_close()

if __name__ == '__main__':
    main()