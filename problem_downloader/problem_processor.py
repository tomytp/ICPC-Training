import time
from pathlib import Path
from typing import Dict, List

from platform_manager import PlatformManager
from problem_info import ProblemInfo

class ProblemProcessor:
    def __init__(self):
        self.last_problem_time = None
        self.first_problem_received = False
        self.base_dir = Path(__file__).parent.parent.absolute()
        self.lib_dir = Path(__file__).parent.parent.parent.absolute() / 'icpc-lib' / 'typst' / 'src'
        self.template_path = self.lib_dir / 'template.cpp'
        self.makefile_path = self.lib_dir / 'makefile'
        self.makefile_increment = (self.base_dir/'problem_downloader'/'makefile.template').read_text()

    def save_test_cases(self, info: ProblemInfo, tests: List[Dict]):
        for i, test in enumerate(tests, 1):
            in_path, out_path = info.get_test_paths(i)
            in_path.write_text(test['input'].strip() + '\n')
            out_path.write_text(test['output'].strip() + '\n')

    def create_solution_template(self, info: ProblemInfo):
        solution_path = info.get_solution_path()
        if not solution_path.exists():
            template = self.template_path.read_text()
            solution_path.write_text(template)

    def process_problem(self, data: Dict) -> str:
        current_time = time.time()
        
        if not self.first_problem_received:
            self.first_problem_received = True
            self.last_problem_time = current_time

        manager = PlatformManager(self.base_dir)
        info = manager.get_problem_info(data['url'])
        
        print(f"\nProcessing problem: {info.problem_id}")
        
        info.folder_path.mkdir(parents=True, exist_ok=True)
        (info.folder_path / 'makefile').write_text(self.makefile_path.read_text() + "\n\n" + self.makefile_increment)
        print(f"Using directory: {info.folder_path}")
        
        if tests := data.get('tests', []):
            self.save_test_cases(info, tests)
            print(f"Saved {len(tests)} sample test cases")
        
        self.create_solution_template(info)
        print(f"Created solution template")
        print(f"Successfully processed problem {info.problem_id}")
        
        self.last_problem_time = current_time
        return str(info.folder_path)