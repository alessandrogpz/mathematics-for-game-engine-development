import os
import random
import argparse
import re
from datetime import datetime

def find_topic_folder(topic_query, base_path="02_Exercises"):
    """
    Finds a topic folder within base_path matching topic_query.
    Supports case-insensitive exact matching, numbered prefix ignoring, and substring matching.
    """
    if not topic_query:
        return None
    if not os.path.exists(base_path):
        return None
    
    # List all directories in base_path
    try:
        subdirs = [d for d in os.listdir(base_path) if os.path.isdir(os.path.join(base_path, d))]
    except Exception as e:
        print(f"Error accessing base path '{base_path}': {e}")
        return None
    
    query_clean = topic_query.lower().strip()
    
    # 1. Try exact or clean match (ignoring prepended numbers like "02_")
    for d in subdirs:
        d_clean = d.lower()
        d_no_prefix = re.sub(r'^\d+_', '', d_clean)
        if query_clean == d_clean or query_clean == d_no_prefix:
            return os.path.join(base_path, d)
            
    # 2. Try substring match
    for d in subdirs:
        d_clean = d.lower()
        d_no_prefix = re.sub(r'^\d+_', '', d_clean)
        if query_clean in d_clean or query_clean in d_no_prefix:
            return os.path.join(base_path, d)
            
    return None

def parse_frontmatter(file_path):
    """
    Parses YAML frontmatter (topic, difficulty, tags) from a markdown file.
    Does not require external libraries.
    """
    metadata = {"topic": None, "difficulty": None, "tags": []}
    if not os.path.exists(file_path):
        return metadata
    try:
        with open(file_path, "r", encoding="utf-8") as f:
            content = f.read()
        if not content.startswith("---"):
            return metadata
        parts = content.split("---", 2)
        if len(parts) < 3:
            return metadata
        frontmatter_text = parts[1]
        for line in frontmatter_text.splitlines():
            line = line.strip()
            if not line or ":" not in line:
                continue
            key, val = line.split(":", 1)
            key = key.strip().lower()
            val = val.strip()
            if key == "topic":
                metadata["topic"] = val
            elif key == "difficulty":
                metadata["difficulty"] = val
            elif key == "tags":
                # Handle tags as inline array e.g. [tag1, tag2] or simple values
                val_clean = val.strip("[]").strip()
                if val_clean:
                    metadata["tags"] = [t.strip().lower() for t in val_clean.split(",") if t.strip()]
    except Exception as e:
        print(f"Warning: Error parsing frontmatter for {file_path}: {e}")
    return metadata

def scaffold_new_question(name, topic_query, difficulty=None, base_path="02_Exercises", templates_path="99_Templates"):
    """
    Generates a new question and solution file based on templates, with prefilled linking and frontmatter.
    """
    # 1. Resolve topic folder
    topic_folder = find_topic_folder(topic_query, base_path)
    if not topic_folder:
        print(f"Error: Topic '{topic_query}' not found under '{base_path}'.")
        try:
            subdirs = [re.sub(r'^\d+_', '', d) for d in os.listdir(base_path) if os.path.isdir(os.path.join(base_path, d))]
            print(f"Available topics: {', '.join(subdirs)}")
        except Exception:
            pass
        return False
    
    # Extract clean topic name (e.g. "Vectors" from "02_Vectors")
    folder_name = os.path.basename(topic_folder)
    clean_topic_name = re.sub(r'^\d+_', '', folder_name).replace("_", " ").title()
    
    # Normalize name: strip Q_ or S_ if provided
    base_name = name
    if base_name.startswith("Q_"):
        base_name = base_name[2:]
    elif base_name.startswith("S_"):
        base_name = base_name[2:]
        
    q_file_name = f"Q_{base_name}.md"
    s_file_name = f"S_{base_name}.md"
    
    q_dir = os.path.join(topic_folder, "Questions")
    s_dir = os.path.join(topic_folder, "Solutions")
    
    os.makedirs(q_dir, exist_ok=True)
    os.makedirs(s_dir, exist_ok=True)
    
    q_path = os.path.join(q_dir, q_file_name)
    s_path = os.path.join(s_dir, s_file_name)
    
    if os.path.exists(q_path) or os.path.exists(s_path):
        print(f"Error: Question or Solution file already exists:")
        print(f"  Question: {q_path} (Exists: {os.path.exists(q_path)})")
        print(f"  Solution: {s_path} (Exists: {os.path.exists(s_path)})")
        return False
        
    # Templates
    q_template_path = os.path.join(templates_path, "Template_Question.md")
    s_template_path = os.path.join(templates_path, "Template_Solution.md")
    
    if not os.path.exists(q_template_path) or not os.path.exists(s_template_path):
        print(f"Error: Templates not found under '{templates_path}'.")
        print("Please check that 'Template_Question.md' and 'Template_Solution.md' exist.")
        return False
        
    try:
        # Read templates
        with open(q_template_path, "r", encoding="utf-8") as f:
            q_content = f.read()
        with open(s_template_path, "r", encoding="utf-8") as f:
            s_content = f.read()
            
        # Prefill Question template
        diff_val = difficulty.capitalize() if difficulty else ""
        q_content = q_content.replace("topic: ", f"topic: {clean_topic_name}")
        q_content = q_content.replace("difficulty: ", f"difficulty: {diff_val}")
        q_content = q_content.replace("[[Solution_Name]]", f"[[S_{base_name}]]")
        
        # Prefill Solution template
        s_content = s_content.replace("topic: ", f"topic: {clean_topic_name}")
        s_content = s_content.replace("[[Question_Name]]", f"[[Q_{base_name}]]")
        
        # Write outputs
        with open(q_path, "w", encoding="utf-8") as f:
            f.write(q_content)
        with open(s_path, "w", encoding="utf-8") as f:
            f.write(s_content)
            
        print(f"Successfully scaffolded new exercise under '{clean_topic_name}':")
        print(f"  Question file: {q_path} -> [[{q_file_name[:-3]}]]")
        print(f"  Solution file: {s_path} -> [[{s_file_name[:-3]}]]")
        return True
    except Exception as e:
        print(f"Error during scaffolding: {e}")
        return False

def generate_daily_practice(questions, output_path="Daily_Practice.md"):
    """
    Creates a Daily_Practice.md file in the root folder transcluding selected questions.
    """
    try:
        date_str = datetime.now().strftime("%Y-%m-%d")
        content = []
        content.append(f"# Daily Practice - {date_str}")
        content.append("")
        content.append("Use these Obsidian transclusions to practice today's exercises directly in this note. Click on the question links or solutions to check your answers.")
        content.append("")
        
        for i, q_path in enumerate(questions, 1):
            q_base = os.path.basename(q_path)
            q_name = q_base[:-3]  # Strip .md
            content.append(f"## {i}. [[{q_name}]]")
            content.append(f"![[{q_name}]]")
            content.append("")
            content.append("---")
            
        # Clean up trailing divider
        if content and content[-1] == "---":
            content.pop()
            
        with open(output_path, "w", encoding="utf-8") as f:
            f.write("\n".join(content))
            
        print(f"\nCreated Daily Practice Note: '{output_path}' with {len(questions)} transcluded questions!")
        return True
    except Exception as e:
        print(f"Error generating Daily Practice note: {e}")
        return False

def get_random_questions(count=5, topic_query=None, difficulty_filter=None, tag_filter=None, practice=False, base_path="02_Exercises"):
    """
    Walks through topic folders, parses metadata, filters by criteria, and prints random questions.
    Optionally calls Daily Practice generation.
    """
    # 1. Resolve search path
    search_path = base_path
    resolved_topic_name = None
    if topic_query:
        topic_folder = find_topic_folder(topic_query, base_path)
        if topic_folder:
            search_path = topic_folder
            folder_name = os.path.basename(topic_folder)
            resolved_topic_name = re.sub(r'^\d+_', '', folder_name).replace("_", " ").title()
        else:
            print(f"Warning: Topic folder for '{topic_query}' not found under '{base_path}'. Searching all topics instead.")
            
    # 2. Walk directory structure
    all_questions = []
    for root, dirs, files in os.walk(search_path):
        if os.path.basename(root) == "Questions":
            for file in files:
                if file.endswith(".md") and file.startswith("Q_"):
                    all_questions.append(os.path.join(root, file))
                    
    if not all_questions:
        print("No questions found.")
        return
        
    # 3. Apply YAML frontmatter filters
    filtered_questions = []
    for q_path in all_questions:
        metadata = parse_frontmatter(q_path)
        
        # Difficulty filtering
        if difficulty_filter:
            q_diff = metadata["difficulty"]
            if not q_diff or q_diff.lower() != difficulty_filter.lower():
                continue
                
        # Tag filtering
        if tag_filter:
            q_tags = metadata["tags"]
            if tag_filter.lower() not in [t.lower() for t in q_tags]:
                continue
                
        filtered_questions.append(q_path)
        
    if not filtered_questions:
        filters_str = []
        if difficulty_filter:
            filters_str.append(f"difficulty='{difficulty_filter}'")
        if tag_filter:
            filters_str.append(f"tag='{tag_filter}'")
        filter_msg = f" with filters ({', '.join(filters_str)})" if filters_str else ""
        topic_msg = f" for topic '{resolved_topic_name}'" if resolved_topic_name else " across all topics"
        print(f"No questions found{topic_msg}{filter_msg}.")
        return

    # 4. Sample and display
    sample_size = min(count, len(filtered_questions))
    selected = random.sample(filtered_questions, sample_size)
    
    topic_str = f"Topic: {resolved_topic_name}" if resolved_topic_name else "All Topics"
    filters_display = []
    if difficulty_filter:
        filters_display.append(f"Difficulty: {difficulty_filter.capitalize()}")
    if tag_filter:
        filters_display.append(f"Tag: {tag_filter}")
    filters_str = f" | {', '.join(filters_display)}" if filters_display else ""
    
    print(f"--- Random Selection ({sample_size} of {len(filtered_questions)} available | {topic_str}{filters_str}) ---")
    for i, path in enumerate(selected, 1):
        print(f"{i}. [[{os.path.basename(path)[:-3]}]] (Path: {path})")
        
    # 5. Generate daily practice transcluded file
    if practice:
        generate_daily_practice(selected)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Pick or scaffold math questions.")
    
    # Scaffolding group
    scaffold_group = parser.add_argument_group("Scaffolding new questions")
    scaffold_group.add_argument("--new", type=str, metavar="NAME", help="Create a new Question and Solution file from templates (e.g. Angle_Between_Vectors)")
    
    # Query/Filtering group
    query_group = parser.add_argument_group("Searching & Filtering")
    query_group.add_argument("topic", nargs="?", default=None, help="Optional topic folder substring to filter within (e.g., Vectors)")
    query_group.add_argument("-n", "--number", type=int, default=5, help="Number of questions to pick (default: 5)")
    query_group.add_argument("-d", "--difficulty", type=str, default=None, help="Filter by difficulty level (Easy, Medium, Hard)")
    query_group.add_argument("-t", "--tag", type=str, default=None, help="Filter by frontmatter tag")
    query_group.add_argument("-p", "--practice", action="store_true", help="Generate a Daily_Practice.md file with transcluded questions in the root directory")
    
    args = parser.parse_args()
    
    if args.new:
        if not args.topic:
            parser.error("The 'topic' argument is required when using --new to specify where the question should be created.")
        scaffold_new_question(args.new, args.topic, args.difficulty)
    else:
        get_random_questions(
            count=args.number,
            topic_query=args.topic,
            difficulty_filter=args.difficulty,
            tag_filter=args.tag,
            practice=args.practice
        )

