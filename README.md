# Quiz Application with Score Tracking

A simple console quiz program written in C++.

## Features
- Menu-driven interface: start quiz, view saved scores, exit
- Asks the player for their name (empty names are rejected)
- Shows 5 multiple-choice questions, one at a time
- Validates every input and shows a clear message for invalid choices
- Calculates the final score and percentage
- Saves the player's name and score to `scores.txt`
- Reads and displays the saved scores from the file

## Class design

### Class `Question`
- **Data members (private):** `text`, `options`, `correct`
- **Member functions (public):** constructor, `getText()`, `getOptionCount()`, `getOption()`, `getCorrect()`, `isCorrect()`

### Class `Quiz`
- **Data members (private):** `questions` (a vector of `Question` objects)
- **Member functions:**
  - constructor: stores the questions
  - `start()`: runs the quiz and shows the result
  - `showScores()`: reads and displays saved scores
  - `saveScore()` (private): writes the score to the file

### Relationship
`Quiz` has a list of `Question` objects (has-a relationship). Inheritance is not used because this project does not need it.

## Concepts used
- Classes and objects, constructors, encapsulation (private data, public getters)
- Vectors
- Strings
- File handling (`ofstream`, `ifstream`)
- Functions (`readChoice()` for input validation)
- Exception handling (`try`, `catch`, `throw`)

## How to run
Compile:

    g++ quiz.cpp -o quiz

Run:

    ./quiz

## Testing
| Type | Input | Expected result |
|------|-------|-----------------|
| Normal | Valid answers to all 5 questions | Score, percentage shown and saved |
| Boundary | 1 and 4 as answers | Accepted |
| Boundary | 0 and 5 as answers | Rejected with a message |
| Invalid | `abc`, negative number | Rejected with a message |
| Invalid | Empty name | "Name cannot be empty." |
| No records | View scores with no `scores.txt` | "No saved scores found yet." |

Screenshots of these tests are included in the submission.

## Author
Divisha Arora and Mohit Kataria
