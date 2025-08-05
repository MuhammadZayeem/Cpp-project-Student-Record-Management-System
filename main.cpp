#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string gender;
    int age;
    float cgpa;
    char grade;
    string city;
    string mobile;
    float marks1, marks2, marks3;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Maximum student limit reached!\n";
        return;
    }

    Student s;

    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore();

    cout << "Name: ";
    getline(cin, s.name);

    cout << "Gender: ";
    getline(cin, s.gender);

    cout << "Age: ";
    cin >> s.age;
    if (s.age < 0) {
        cout << "Error: Negative values are not allowed.\n";
        return;
    }

    cout << "CGPA: ";
    cin >> s.cgpa;
    cin.ignore();

    cout << "City: ";
    getline(cin, s.city);

    cout << "Mobile: ";
    getline(cin, s.mobile);

    cout << "Marks in Subject 1: ";
    cin >> s.marks1;
    if (s.marks1 < 0) {
        cout << "Error: Negative values are not allowed.\n";
        return;
    }

    cout << "Marks in Subject 2: ";
    cin >> s.marks2;
    if (s.marks2 < 0) {
        cout << "Error: Negative values are not allowed.\n";
        return;
    }

    cout << "Marks in Subject 3: ";
    cin >> s.marks3;
    if (s.marks3 < 0) {
        cout << "Error: Negative values are not allowed.\n";
        return;
    }

    float total = s.marks1 + s.marks2 + s.marks3;
    if (total >= 270) s.grade = 'A';
    else if (total >= 240) s.grade = 'B';
    else if (total >= 210) s.grade = 'C';
    else if (total >= 180) s.grade = 'D';
    else s.grade = 'F';

    students[studentCount++] = s;
    cout << "Student added successfully.\n";
}

void displayAll() {
    if (studentCount == 0) {
        cout << "No records found.\n";
        return;
    }

    cout << "--- Student Records ---\n";
    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        float total = s.marks1 + s.marks2 + s.marks3;
        cout << "Roll No: " << s.rollNo << "\n";
        cout << "Name: " << s.name << "\n";
        cout << "Gender: " << s.gender << "\n";
        cout << "Age: " << s.age << "\n";
        cout << "CGPA: " << s.cgpa << "\n";
        cout << "Total Marks: " << total << "\n";
        cout << "Grade: " << s.grade << "\n";
        cout << "City: " << s.city << "\n";
        cout << "Mobile: " << s.mobile << "\n\n";
    }
}

void saveToFile() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        outFile << s.rollNo << "," << s.name << "," << s.gender << ","
                << s.age << "," << s.cgpa << "," << s.grade << ","
                << s.city << "," << s.mobile << ","
                << s.marks1 << "," << s.marks2 << "," << s.marks3 << "\n";
    }

    outFile.close();
    cout << "Records saved to file successfully.\n";
}

void loadFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No existing records found.\n";
        return;
    }

    studentCount = 0;
    string line;
    while (getline(inFile, line) && studentCount < MAX_STUDENTS) {
        stringstream ss(line);
        Student s;
        string ageStr, cgpaStr, marks1Str, marks2Str, marks3Str;

        getline(ss, line, ','); s.rollNo = stoi(line);
        getline(ss, s.name, ',');
        getline(ss, s.gender, ',');
        getline(ss, line, ','); s.age = stoi(line);
        getline(ss, line, ','); s.cgpa = stof(line);
        getline(ss, line, ','); s.grade = line[0];
        getline(ss, s.city, ',');
        getline(ss, s.mobile, ',');
        getline(ss, line, ','); s.marks1 = stof(line);
        getline(ss, line, ','); s.marks2 = stof(line);
        getline(ss, line);      s.marks3 = stof(line);

        students[studentCount++] = s;
    }

    inFile.close();
    cout << "Records loaded from file successfully.\n";
}

void searchByName() {
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].name == name) {
            found = true;
            Student s = students[i];
            float total = s.marks1 + s.marks2 + s.marks3;
            cout << "\nRecord Found:\n";
            cout << "Roll No: " << s.rollNo << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Gender: " << s.gender << "\n";
            cout << "Age: " << s.age << "\n";
            cout << "CGPA: " << s.cgpa << "\n";
            cout << "Total Marks: " << total << "\n";
            cout << "Grade: " << s.grade << "\n";
            cout << "City: " << s.city << "\n";
            cout << "Mobile: " << s.mobile << "\n\n";
        }
    }

    if (!found) {
        cout << "No student found with that name.\n";
    }
}

void updateByMobile() {
    string mobile;
    cout << "Enter mobile number to update: ";
    cin.ignore();
    getline(cin, mobile);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].mobile == mobile) {
            found = true;
            cout << "Enter new city: ";
            getline(cin, students[i].city);
            cout << "Record updated successfully.\n";
        }
    }

    if (!found) {
        cout << "No student found with that mobile number.\n";
    }
}

void deleteByRollNo() {
    int rollNo;
    cout << "Enter Roll No to delete: ";
    cin >> rollNo;

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            found = true;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Record deleted successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "No student found with that roll number.\n";
    }
}

void sortByRollNo() {
    for (int i = 0; i < studentCount - 1; i++) {      // Bubble sorting
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << "Student records sorted by Roll No.\n";
}

void showMenu() {
    cout << "======================================\n";
   // cout << "\nC++ SEMESTER PROJECT - ASSIGNMENT 4\n";
    cout << " " "Student Record Management System\n";
    cout << "======================================\n";
    cout << "1. Add New Student Record\n";
    cout << "2. Display All Student Records\n";
    cout << "3. Save Records to File\n";
    cout << "4. Load Records from File\n";
    cout << "5. Search Student by Name\n";
    cout << "6. Delete Record by Roll No\n";
    cout << "7. Update Record by Mobile No\n";
    cout << "8. Sort Records by Roll No\n";
    cout << "0. Exit\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
             break;

            case 2:
                displayAll();
             break;

            case 3:
                 saveToFile();
             break;

            case 4:
                loadFromFile();
             break;

            case 5:
                searchByName();
            break;

            case 6:
                deleteByRollNo();
            break;

            case 7:
                updateByMobile();
            break;

            case 8:
                sortByRollNo();
             break;

            case 0:
                cout << "Exiting... Thank you!\n";
            break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

