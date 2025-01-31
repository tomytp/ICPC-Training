import re
from pathlib import Path
from typing import Optional, Tuple
from .base import Platform

class CodeforcesHandler(Platform):
    URL_PATTERNS = [
        r'.*codeforces\.com/contest/(\d+)/problem/([A-Z]\d*)',
        r'.*codeforces\.com/problemset/problem/(\d+)/([A-Z]\d*)',
        r'.*codeforces\.com/gym/(\d+)/problem/([A-Z]\d*)'
    ]

    def matches_url(self, url: str) -> bool:
        return any(re.match(pattern, url) for pattern in self.URL_PATTERNS)

    def get_info_from_url(self, url: str) -> Tuple[str, str]:
        for pattern in self.URL_PATTERNS:
            if match := re.match(pattern, url):
                contest_id, problem_id = match.groups()
                return problem_id.lower(), contest_id
        raise ValueError(f"Invalid Codeforces URL: {url}")

    def get_directory(self, problem_id: str, group_id: Optional[str]) -> Path:
        if not group_id:
            raise ValueError("Contest/Gym ID is required for Codeforces")
        return self.base_directory / 'cf' / group_id

    def get_solution_path(self, directory: Path, problem_id: str) -> Path:
        return directory / f'{problem_id}.cpp'

    def get_test_paths(self, directory: Path, problem_id: str, test_num: int) -> tuple[Path, Path]:
        return (directory / f'in{problem_id}{test_num}', directory / f'out{problem_id}{test_num}')
