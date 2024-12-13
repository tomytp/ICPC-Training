import http.server
import json
import os
import re
import time
import subprocess
from pathlib import Path
import argparse
from datetime import datetime
from typing import Dict, Optional

PORT = 10043
REPOSITORY_DIR = Path(__file__).parent.absolute()
PROBLEMS_DIR = REPOSITORY_DIR / 'cf'
TEMPLATE_DIR = REPOSITORY_DIR / 'templates'
SINGLE_TEMPLATE = TEMPLATE_DIR / 'template_single.cpp'
MULTIPLE_TEMPLATE = TEMPLATE_DIR / 'template_multiple.cpp'

class ContestProblemHandler(http.server.BaseHTTPRequestHandler):
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        body = self.rfile.read(content_length)
        problem_data = json.loads(body)
        directory = self.server.problem_processor.process_problem(problem_data)
        self.server.last_contest_dir = directory
        self.send_response(200)
        self.end_headers()
        
    def log_message(self, format, *args):
        print(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] {format%args}")

class ProblemProcessor:
    def __init__(self):
        self.last_problem_time = None
        self.first_problem_received = False
        
    def get_problem_id(self, url: str):
        patterns = [
            r'.*codeforces\.com/contest/(\d+)/problem/([A-Z]\d*)',
            r'.*codeforces\.com/problemset/problem/(\d+)/([A-Z]\d*)',
            r'.*codeforces\.com/gym/(\d+)/problem/([A-Z]\d*)'
        ]
        for pattern in patterns:
            if match := re.search(pattern, url, re.IGNORECASE):
                contest_num, problem_letter = match.groups()
                return str(contest_num), problem_letter.lower()
        raise ValueError(f"Invalid Codeforces URL format: {url}")

    def get_or_create_contest_directory(self, contest: str) -> Path:
        directory = PROBLEMS_DIR / contest
        directory.mkdir(parents=True, exist_ok=True)
        return directory

    def save_test_cases(self, directory: Path, letter: str, tests: list):
        for i, test in enumerate(tests, 1):
            (directory / f'{letter}{i}.in').write_text(test['input'].strip() + '\n')

    def create_solution_template(self, directory: Path, problem: str, is_single_testcase: bool):
        path = directory / f'{problem}.cpp'
        if not path.exists():
            template = SINGLE_TEMPLATE.read_text() if is_single_testcase else MULTIPLE_TEMPLATE.read_text()
            path.write_text(template)

    def process_problem(self, data: Dict):
        current_time = time.time()
        
        if not self.first_problem_received:
            self.first_problem_received = True
            self.last_problem_time = current_time
        
        contest, letter = self.get_problem_id(data['url'])
        print(f"\nProcessing problem: {letter}")
        
        directory = self.get_or_create_contest_directory(contest)
        print(f"Created directory: {directory}")
        
        if tests := data.get('tests', []):
            self.save_test_cases(directory, letter, tests)
            print(f"Saved {len(tests)} sample test cases")
            
        self.create_solution_template(directory, letter, data['testType'] == 'single')
        print(f"Created solution template, type: {data['testType']}")
        print(f"Successfully processed problem {letter}")
        
        self.last_problem_time = current_time
        return str(directory)

class TimedHTTPServer(http.server.HTTPServer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.last_contest_dir = None

    def serve_with_timeout(self):
        self.timeout = 1
        start_time = time.time()
        first_problem_wait = 180
        no_problem_wait = 1
        
        while True:
            try:
                if not self.problem_processor.first_problem_received:
                    if time.time() - start_time > first_problem_wait:
                        print("\nNo problems received within 3 minutes. Shutting down...")
                        break
                    self.handle_request()
                    continue
                
                if time.time() - self.problem_processor.last_problem_time > no_problem_wait:
                    print("\nNo new problems received for 1 seconds. Processing complete.")
                    break
                    
                self.handle_request()
            except TimeoutError:
                continue
        
        return self.last_contest_dir

def main():
    parser = argparse.ArgumentParser(description="Contest Problem Parser for Competitive Companion")
    args = parser.parse_args()
    
    processor = ProblemProcessor()
    server = TimedHTTPServer(('localhost', PORT), ContestProblemHandler)
    server.problem_processor = processor
    
    print(f"Starting Competitive Companion parser on port {PORT}")
    print(f"Base directory: {os.path.abspath(PROBLEMS_DIR)}")
    print("Waiting for problems...\n")
    
    try:
        contest_dir = server.serve_with_timeout()
        if contest_dir:
            print(f"\nOpening VS Code in directory: {contest_dir}")
            subprocess.Popen([
                'code',
                str(contest_dir),
                '--profile',
                'CP'
                ])
        else:
            print("\nNo contest directory created.")
    except KeyboardInterrupt:
        print("\nShutting down...")
    finally:
        server.server_close()

if __name__ == '__main__':
    main()