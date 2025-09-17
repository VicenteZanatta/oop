# Object-Oriented Programming – Assignment 1

## Problem Description

Professor John Doe is a very busy man with several appointments scheduled in his agenda.  
To manage these efficiently, he decided to hire programmers to develop a **commitment filtering system**.  
Your task is to implement this system.

### 1. Commitments

The professor’s agenda includes different types of commitments:

- **Classes (Undergraduate, Specialization, Master’s):** includes date, time, duration (minutes), subject name, and level.
- **Student Advising (Undergraduate, Specialization, Master’s):** includes date, time, duration (minutes), advisee’s name, and level.
- **Department Meetings:** includes date, time, and duration (minutes).
- **Events:** includes date, time, duration (days), event name, and location.
- **Personal Commitments:** includes date, time, duration (minutes), and reason.

Each commitment has:
- A **numeric identifier** (read from input).
- A **description** depending on type.
- A **priority degree**.
- A **priority multiplier factor**, based on commitment type.

Commitments can also be **postponable (adiável)** or **non-postponable**.  
Classes and events are never postponable.  
If a commitment is non-postponable (other than classes and events), its multiplier increases by +1.

---

### 2. Filtering

The system must identify **conflicting commitments** and produce four reports:

1. **Confirmed commitments (`relatconfirmados.txt`):**  
   Commitments that do not conflict or have the highest priority.  
   Ordered by date and time.

2. **Postponed commitments (`relatadiados.txt`):**  
   Postponable commitments that lose a conflict.  
   Ordered by decreasing priority.

3. **Cancelled commitments (`relatcancelados.txt`):**  
   Non-postponable commitments that lose a conflict.  
   Ordered by increasing duration.

4. **Complete commitments report (`relatcompromissos.txt`):**  
   All commitments with full data.  
   Ordered by identifier.

Additionally, generate **`resultado.txt`**, which contains the sum of durations (minutes) of the i-th, j-th, k-th, and m-th elements of the above reports.  
The indices (i, j, k, m) come from the input file `posicoes.txt`.

**Tie-breaking rules:**
1. Earliest start time wins.  
2. If equal, priority order is: Meeting > Event > Class > Personal > Advising.  
3. If still equal, alphabetical order of description decides.

---

### 3. Input Format

- Main input file: **`agenda.txt`**.  
  - Contains all commitments with specific formatting per type.  
  - Commitments separated by a blank line.  
  - Two blank lines after the last commitment.

- Secondary input file: **`posicoes.txt`**.  
  - Contains 4 integers (i, j, k, m), one per line.

Examples are provided in the **`exemplo/`** folder.

---

### 4. Output Format

Reports must follow strict formatting rules (see assignment specification).  
Commitments must be separated by exactly one blank line.  
No extra spaces or blank lines at the end of files.

---

### 5. Implementation Requirements

- Proper modularization (no global variables, constants allowed).  
- Clean and consistent coding style with extensive comments.  
- Program must read input from `agenda.txt` and `posicoes.txt`.  
- One **generic sorting subprogram** must be implemented and reused.  
- Use a **generic linked list**:
  - In C: `void*`-based implementation.
  - In C++: template-based implementation.  
  - **Do not use built-in list libraries.**
- Implement a class/struct hierarchy to represent different types of commitments.

---

### 6. Delivery Conditions

- Submit via GitHub Classroom (TBD).  
- Include:
  - **Makefile**  
  - **README.md** with student name and enrollment number  
  - Source code files

---

### 7. Evaluation

- Use **Valgrind** to check for memory leaks.  
- Code correctness, modularity, and clarity will be evaluated.  
- Reports must strictly follow the specification.

---
