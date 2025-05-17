#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Template class

template <class T>
class MemoryCalculate 
{
public:
    T id;
    string name;


    // Constructor

    MemoryCalculate(T i, string n) 
    {
        id = i;
        name = n;
    }

    // Method to display student details

    void display()
    { 
        cout << "ID: " << id << ", Name: " << name << endl;    
    }
};

vector<MemoryCalculate<int>> students; 

// Function to add a student
void addStudent(int id, string name)    
{
    students.push_back(MemoryCalculate<int>(id, name));
    cout << "Student added successfully.\n";
}


// Function to display all students
void displayAllStudents()                 
{
    cout << "\nList of Students:\n";
    for (auto &student : students) 
    {
        student.display();
    }
    cout << endl;
}


// Function to remove student by ID      

void removeStudentByID(int id)            
{
    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student with ID " << id << " removed.\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student with ID " << id << " not found.\n";
}

// Function to search student by ID
void searchStudentByID(int id) 
{
    bool found = false;
    for (auto &student : students) 
    {
        if (student.id == id) {
            cout << "Student Found:\n";
            student.display();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student with ID " << id << " not found.\n";
}

// Main function
int main() 
{
    int choice, id;
    string name;

    do {
        cout << "\nStudent Management Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            addStudent(id, name);
            break;

        case 2:
            displayAllStudents();
            break;

        case 3:
            cout << "Enter Student ID to Remove: ";
            cin >> id;
            removeStudentByID(id);
            break;

        case 4:
            cout << "Enter Student ID to Search: ";
            cin >> id;
            searchStudentByID(id);
            break;

        case 5:
            cout << "Exiting Program.\n";
            break;

        default:
            cout << "Invalid Choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
