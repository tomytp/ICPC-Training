import time
from pathlib import Path
from typing import Dict
from platforms import get_handler_for_url

class ProblemProcessor:
    def __init__(self):
        self.last_problem_time = None
        self.first_problem_received = False
        self.base_dir = Path(__file__).parent.parent.absolute()
        self.lib_dir = Path(__file__).parent.parent.parent.absolute() / 'icpc-lib' / 'typst' / 'src' 
        self.template_path = self.lib_dir / 'template.cpp'
        self.makefile_path = self.lib_dir / 'makefile' 

    def save_test_cases(self, platform, directory: Path, problem_id: str, tests: list):
        for i, test in enumerate(tests, 1):
            test_paths = platform.get_test_paths(directory, problem_id, i)
            test_paths[0].write_text(test['input'].strip() + '\n')
            test_paths[1].write_text(test['output'].strip() + '\n')

    def create_solution_template(self, platform, directory: Path, problem_id: str):
        solution_path = platform.get_solution_path(directory, problem_id)
        if not solution_path.exists():
            template = self.template_path.read_text()
            solution_path.write_text(template)

    def process_problem(self, data: Dict):
        current_time = time.time()
        
        if not self.first_problem_received:
            self.first_problem_received = True
            self.last_problem_time = current_time

        platform = get_handler_for_url(data['url'], self.base_dir)
        if not platform:
            raise ValueErro0r(f"No handler found for URL: {data['url']}")

        problem_id, group_id = platform.get_info_from_url(data['url'])
        print(f"\nProcessing problem: {problem_id}")
        
        directory = platform.get_directory(problem_id, group_id)

        directory.mkdir(parents=True, exist_ok=True)
        (directory / 'makefile').write_text(self.makefile_path.read_text())
        print(f"Using directory: {directory}")
        
        if tests := data.get('tests', []):
            self.save_test_cases(platform, directory, problem_id, tests)
            print(f"Saved {len(tests)} sample test cases")
            
        self.create_solution_template(platform, directory, problem_id)
        print(f"Created solution template")
        print(f"Successfully processed problem {problem_id}")
        
        self.last_problem_time = current_time
        return str(directory)