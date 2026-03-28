# 🚀 QueryLiteDB

A lightweight SQL-like database engine built in C++ using Object-Oriented Programming, STL, and file handling.

---

## 📌 Features

* Supports SQL-like commands:

  * INSERT
  * SELECT
  * UPDATE
  * DELETE
  * CREATE TABLE
* Dynamic table creation
* File-based persistence (data stored in `/data`)
* Custom query parser
* Case-insensitive query support
* Command-line interface

---

## 🧠 Tech Stack

* C++
* STL (vector, map)
* File handling (fstream)
* OOP design principles

---

## 📁 Project Structure

```
QueryLiteDB/
│
├── src/        # Source files
├── include/    # Header files
├── data/       # Stored table data
├── build/      # Compiled output
│
├── main.cpp
├── README.md
└── .gitignore
```

---

## ▶️ How to Run

```bash
g++ -std=c++17 main.cpp src/*.cpp -o build/app.exe
build\app.exe
```

---

## 💡 Example Queries

```sql
CREATE TABLE students (id, name, age)

INSERT INTO students VALUES (1, Sumu, 22)
INSERT INTO students VALUES (2, Ravi, 23)

SELECT * FROM students

UPDATE students SET age = 25 WHERE id = 1

DELETE FROM students WHERE id = 2
```

---

## ⚠️ Limitations

* Supports only basic SQL-like syntax
* WHERE supports only single condition (=)
* No JOIN or indexing support

---

## 🔮 Future Improvements

* Support multiple conditions (AND/OR)
* Add indexing for faster queries
* Support SELECT specific columns
* Improve query validation
# 💾 Mini Database System (C++)

## 👨‍💻 Author

**Sumanth G**

---
