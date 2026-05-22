# Exercise Randomizer & Scaffolder

A powerful Python command-line utility to manage, filter, and practice math exercises in your Obsidian repository.

## Features

- **Smart Topic Matching:** No need to type the full numbered prefixes (e.g. `02_Vectors`). Enter `vectors`, `Vectors`, or even `vec` and the utility will automatically resolve the correct directory.
- **Advanced Filtering:** Filter questions dynamically using YAML frontmatter tags (`-t` / `--tag`) and difficulty ratings (`-d` / `--difficulty`).
- **Obsidian Daily Practice Note:** Generate a `Daily_Practice.md` note in the root directory that embeds selected exercises using Obsidian's transclusion syntax (`![[Note]]`), enabling a consolidated workspace.
- **Frictionless Scaffolding:** Create new question-solution note pairs from your templates in seconds using `--new`. It automatically sets up frontmatter, tags, headings, and relative cross-links.

---

## Command Line Usage

Run the utility from the root of the repository:

```bash
python3 randomizer.py [topic] [flags]
```

### Searching & Filtering Flags

| Flag | Name | Type | Description |
| :--- | :--- | :--- | :--- |
| `topic` | Topic | Positional | Optional folder substring to match (e.g., `vectors`, `matrices`, `systems`). |
| `-n`, `--number` | Count | Integer | Number of questions to random-sample (default: `5`). |
| `-d`, `--difficulty`| Difficulty | String | Filter by YAML frontmatter difficulty level (`Easy`, `Medium`, `Hard`). |
| `-t`, `--tag` | Tag | String | Filter by YAML frontmatter tag (e.g., `dot-product`, `orthogonality`). |
| `-p`, `--practice` | Practice Note| Flag | Generates `Daily_Practice.md` in the root with Obsidian transclusions. |

### Scaffolding Flags

| Flag | Name | Type | Description |
| :--- | :--- | :--- | :--- |
| `--new` | Create | String | Scaffolds a new Question and Solution file. Must be used with a topic. |

---

## Examples

### 1. Daily Study and Randomization

| Goal | Command |
| :--- | :--- |
| **Get 5 random questions (Default)** | `python3 randomizer.py` |
| **Get 3 random questions** | `python3 randomizer.py -n 3` |
| **Get 3 Easy questions from Vectors** | `python3 randomizer.py vectors -d Easy -n 3` |
| **Get questions matching tag "dot-product"**| `python3 randomizer.py -t dot-product` |
| **Generate a Daily Practice Workspace note**| `python3 randomizer.py matrices -n 3 --practice` |

### 2. Scaffold a New Exercise Note-Pair

To create a new question and solution pair for vectors named `Q_Angle_Between_Vectors.md` and `S_Angle_Between_Vectors.md`:

```bash
python3 randomizer.py vectors --new Angle_Between_Vectors --difficulty Easy
```

This command will:
1. Smart-resolve `vectors` to `02_Exercises/02_Vectors/`.
2. Retrieve templates `Template_Question.md` and `Template_Solution.md` from `99_Templates/`.
3. Create `Questions/Q_Angle_Between_Vectors.md` with:
   - Topic metadata filled.
   - Difficulty metadata filled.
   - Interactive Check Answer link `[[S_Angle_Between_Vectors]]`.
4. Create `Solutions/S_Angle_Between_Vectors.md` with:
   - Topic metadata filled.
   - Interactive Back to Question link `[[Q_Angle_Between_Vectors]]`.

