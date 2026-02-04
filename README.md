````markdown
# Student Grading System 

This is a **C++ Student Grading System** project designed for semester coursework. It allows users to manage student records, calculate GPA and grades, sort students, and export reports to files.

---

## Features

- Add new student records
- Display all students with ID, name, GPA, and grade
- Update existing student records
- Search student by ID
- Sort students by GPA
- Export report to a text file (`report.txt`) with:
  - Top 3 students
  - Subject averages
  - Pass/Fail ratio
- Save and load student data from `student.txt` file

---

## Technologies Used

- C++ (Standard Library)
  - `iostream`, `fstream`, `iomanip`, `string`
- File handling (`student.txt` & `report.txt`)
- Structs for student records
- Console-based menu system

---

## How to Run

1. **Clone or download the repository**:
```bash
git clone https://github.com/ihtasham37/student-grading-system.git
````

2. **Compile the program**:

```bash
g++ main.cpp -o grading_system
```

3. **Run the executable**:

```bash
./grading_system   # Linux / Mac
grading_system.exe # Windows
```

4. Follow the **menu options** in the console to use the program.

---

## File Structure

```
/student-grading-system
├─ main.cpp          # Main program code
├─ student.txt       # Data file to store student records
├─ report.txt        # Generated report file
└─ README.md         # Project documentation
```

---

## Notes

* `student.txt` will be automatically created when you add students and save.
* GPA and grades are calculated based on marks in 5 subjects.
* Top 3 students and subject averages can be exported via the menu.
* Ensure you enter **marks between 0 and 100** for correct calculations.

---

## License

This project is free to use and modify for educational purposes.

---

## Author

* **Created by:** Ihtasham
* **Semester Project:** Student Grading System

```
```
