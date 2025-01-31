from abc import ABC, abstractmethod
from pathlib import Path
from typing import Optional, Tuple

class Platform(ABC):
    def __init__(self, base_dir: Path):
        self.base_directory = base_dir

    @abstractmethod
    def matches_url(self, url: str) -> bool:
        """Check if URL belongs to this platform"""
        pass

    @abstractmethod
    def get_info_from_url(self, url: str) -> Tuple[str, Optional[str]]:
        """Extract problem ID and optional group ID from URL"""
        pass

    @abstractmethod
    def get_directory(self, problem_id: str, group_id: Optional[str] = None) -> Path:
        """Get directory where files should be saved"""
        pass

    @abstractmethod
    def get_solution_path(self, directory: Path, problem_id: str) -> Path:
        """Get path for solution file"""
        pass

    @abstractmethod
    def get_test_paths(self, directory: Path, problem_id: str, test_num: int) -> tuple[Path, Path]:
        """Get paths for test case files"""
        pass