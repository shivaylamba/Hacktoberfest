import os
from collections import defaultdict

# Map file extensions to language names
LANGUAGE_MAP = {
    '.py': 'Python',
    '.js': 'JavaScript',
    '.cpp': 'C++',
    '.c': 'C',
    '.java': 'Java',
    '.rb': 'Ruby',
    '.go': 'Go',
    '.ts': 'TypeScript',
    '.html': 'HTML',
    '.css': 'CSS',
    '.php': 'PHP',
    '.rs': 'Rust',
    '.swift': 'Swift'
}

def get_language(file_name):
    _, ext = os.path.splitext(file_name)
    return LANGUAGE_MAP.get(ext, None)

def generate_stats(base_path='.'):
    stats = defaultdict(int)
    total_files = 0

    for root, _, files in os.walk(base_path):
        for file in files:
            lang = get_language(file)
            if lang:
                stats[lang] += 1
                total_files += 1

    return stats, total_files

def write_markdown(stats, total):
    with open("STATS.md", "w") as f:
      with open("STATS.md", "w", encoding="utf-8") as f:
        f.write(f"**Total code files analyzed:** {total}\n\n")
        f.write("| Language | File Count |\n")
        f.write("|-----------|-------------|\n")
        for lang, count in sorted(stats.items(), key=lambda x: x[1], reverse=True):
            f.write(f"| {lang} | {count} |\n")
        f.write("\n✨ Generated automatically by `stats_generator.py`\n")

if __name__ == "__main__":
    stats, total = generate_stats()
    write_markdown(stats, total)
    print(f"Stats generated successfully! {total} files counted.")
