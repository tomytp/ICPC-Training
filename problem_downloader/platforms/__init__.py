from pathlib import Path
from typing import List, Optional, Tuple
from .base import Platform
from .codeforces import CodeforcesHandler
from .kattis import KattisHandler
from .cses import CsesHandler
from .vjudge import VJudgeHandler

def get_platform_handlers(base_dir: Path) -> List[Platform]:
    return [
        CodeforcesHandler(base_dir),
        KattisHandler(base_dir),
        CsesHandler(base_dir),
        VJudgeHandler(base_dir),
    ]

def get_handler_for_url(url: str, base_dir: Path) -> Optional[Platform]:
    for handler in get_platform_handlers(base_dir):
        if handler.matches_url(url):
            return handler
    return None