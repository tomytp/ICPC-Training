import yaml
from typing import Tuple, Optional
from pathlib import Path
from platform import Platform

class PlatformManager:
    def __init__(self):
        config_file = Path(__file__).parent.absolute() / 'platforms.yaml'
        with open(config_file) as f:
            config = yaml.safe_load(f)
        self.platforms = {
            name: Platform(name, platform_config)
            for name, platform_config in config['platforms'].items()
        }
    
    def get_platform_and_ids(self, url: str) -> Tuple[Platform, str, Optional[str]]:
        for platform in self.platforms.values():
            if info := platform.get_problem_info(url):
                problem_id, group_id = info
                return platform, problem_id, group_id
        raise ValueError(f"No matching platform found for URL: {url}")