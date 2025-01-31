import http.server
import json
import time
from datetime import datetime
from problem_processor import ProblemProcessor

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

class TimedHTTPServer(http.server.HTTPServer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.last_contest_dir = None
        self.problem_processor = None

    def serve_with_timeout(self):
        self.timeout = 1
        start_time = time.time()
        first_problem_wait = 180
        no_problem_wait = 5
        
        while True:
            try:
                if not self.problem_processor.first_problem_received:
                    if time.time() - start_time > first_problem_wait:
                        print("\nNo problems received within 3 minutes. Shutting down...")
                        break
                    self.handle_request()
                    continue
                
                if time.time() - self.problem_processor.last_problem_time > no_problem_wait:
                    print("\nNo new problems received for 1 second. Processing complete.")
                    break
                    
                self.handle_request()
            except TimeoutError:
                continue
        
        return self.last_contest_dir