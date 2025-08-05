Student Record Management System

The Student Record Management System is a C++ console-based application developed to efficiently manage student information. This project is designed to demonstrate the use of structures, file handling, and modular programming in C++. It is suitable for beginners and students who want to understand how to create a menu-driven application for managing data.

Developed by: Muhammad Zayeem

Language: C++ (Console-Based)

File I/O | Menu-Driven | Password-Protected Admin Panel


---Overview

This system allows users to add, view, update, search, delete, sort, and store student records in a structured manner. The application uses file handling to ensure that data is saved and can be retrieved later, making the program more practical and useful.

---Features

1.Add Student Record
  
  Allows entry of essential student details such as roll number, name, gender, age, CGPA, marks for three subjects, grade, city, and mobile number.

2.Display All Records

  Shows all stored student information in a structured format.

3.Search by Name
  
  Quickly find and view details of a student by their name.

4.Update Record by Mobile Number
  
  Modify details (e.g., city) using the student's mobile number as an identifier.

5.Delete Record by Roll Number
  
  Remove a student's data completely using their roll number.

6.Sort Records by Roll Number
  
  Sort all student records in ascending order of roll number using Bubble Sort.

7.Save and Load Records

  Save to File: Writes all student details into students.txt in CSV format for persistence.

8.Load from File: 

  Reads previously saved records back into the program.

---Core Functionalities

1.Data Validation:
  
  Ensures no negative values for age or marks.

2.Grading System:
  
  Calculates grade based on total marks (A, B, C, D, F).

3.Error Handling:
  
  Handles invalid choices and prevents exceeding maximum student capacity.

---Key Concepts:

1.Structures for grouping student details

2.Arrays for managing multiple records

3.Functions for modular code organization

4.File Handling (ofstream, ifstream, stringstream)

5.Sorting algorithm (Bubble Sort)

6.Menu-driven console interface

---Learning Outcomes

1.Understanding of data structures (struct) in C++

2.Practical implementation of file handling for data storage and retrieval

3.Development of modular programs with reusable functions

4.Experience in creating interactive, menu-based applications

