from pathlib import Path
from typing import Tuple
from platforms import Platform, VJudgeHandler, KattisHandler, CodeforcesHandler, CsesHandler
from problem_info import ProblemInfo

class PlatformManager:
    def __init__(self, base_dir: Path):
        self.platforms = [
            VJudgeHandler(base_dir),
            KattisHandler(base_dir),
            CodeforcesHandler(base_dir),
            CsesHandler(base_dir),
        ]
    
    def get_problem_info(self, url: str) -> Tuple[Platform, ProblemInfo]:
        for platform in self.platforms:
            if platform.matches_url(url):
                return platform.get_info_from_url(url)
        raise ValueError(f"No matching platform found for URL: {url}")
