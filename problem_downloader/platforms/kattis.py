import re
from pathlib import Path
from typing import Optional, Tuple
from .base import Platform

class KattisHandler(Platform):
    URL_PATTERNS = [
        r'.*open\.kattis\.com/problems/([\w-]+)',
        r'.*open\.kattis\.com/contests/\w+/problems/([\w-]+)'
    ]

    def matches_url(self, url: str) -> bool:
        return any(re.match(pattern, url) for pattern in self.URL_PATTERNS)

    def get_info_from_url(self, url: str) -> Tuple[str, None]:
        for pattern in self.URL_PATTERNS:
            if match := re.match(pattern, url):
                return match.group(1), None
        raise ValueError(f"Invalid Kattis URL: {url}")

    def get_directory(self, problem_id: str, group_id: Optional[str]) -> Path:
        return self.base_directory / 'kattis' / problem_id

    def get_solution_path(self, directory: Path, problem_id: str) -> Path:
        return directory / 'main.cpp'

    def get_test_paths(self, directory: Path, problem_id: str, test_num: int) -> tuple[Path, Path]:
        return (directory / f'in{test_num}', directory / f'out{test_num}')