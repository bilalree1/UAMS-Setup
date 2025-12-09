#include <iostream>
#include <conio.h>   
  using namespace std;
const int MAX = 100;
 string  names[MAX];
 unsigned long long CNICs[MAX];
   double  registrationNos[MAX];
  int     interMarks[MAX];
 int     matricMarks[MAX];
int studentCount = 0;
string email;
string password;
void UAMS();
  void menu();
void addStudent();
void deleteStudent();
  void updateStudent();
  void viewSpecificStudent();
void viewAllStudents();
void viewStudentPercentage();   
int  findStudentIndexByRegNo(double regNo);
int main() {
    cout << "enter your Email : ";
    cin >> email;
    cout << "Enter password : ";
    cin >> password;

    if (!(email == "bilalcs@gmail.com" && password == "cs123")) 
	{
        cout << "INVALID";
        return 0;   
     }

    getch(); 

    int option;
    bool running = true;
while (running) {
        cout << string(5, '\n');
        UAMS();
        menu();
        cout << "enter any option given above: ";
        cin >> option;

        cout << string(2, '\n');

        switch (option) {
         case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            updateStudent();
            break;
           case 4:
            viewSpecificStudent();
            break;
        case 5:
            viewAllStudents();
            break;
        case 6:
             viewStudentPercentage();
            break;
         case 7:                         
            cout << "Thanks for using UAMS" << endl;
            getch();
            running = false;
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            getch();
        }
    }

    return 0;
   }

void UAMS() {
    cout << "*************----------*********************************" << endl;

    cout << "*     *   " << "   *    " << " *     * " << " ***** " << endl;
    cout << "*     *   " << "  * *   " << "**   ** " << "*      " << endl;
    cout << "*     *   " << " *****  " << "* * * * " << " ***** " << endl;
    cout << "*     *   " << "*     * " << "*  *  * " << "      *" << endl;
    cout << " *****    " << "*     * " << "*     * " << " ***** " << endl;
    cout << " ***********-------------******************************" << endl;
   }
void menu() {
     cout << "                   *************MENU***************    " << endl;
      cout << "                       1. Add Student                          " << endl;
    cout << "                         2. Delete Student                       " << endl;
    cout << "                         3. Update Record                        " << endl;
    cout << "                         4. View Specific Student                " << endl;
    cout << "                         5. View All Students                    " << endl;
    cout << "                         6. View Student Percentage                                " << endl;
    cout << "                         7.    Exit             " << endl; 
}
int findStudentIndexByRegNo(double regNo) {
    for (int i = 0; i < studentCount; i++) {
        if (registrationNos[i] == regNo) {
            return i;
        }
    }
    return -1; 
}
void addStudent() {
    if (studentCount >= MAX) {
        cout << "Cannot add more students. Maximum limit reached (" << MAX << ").\n";
        getch();
        return;
    }

     cout << "Adding Student #" << (studentCount + 1) << endl;
    cout << "Enter student name: ";
    cin >> names[studentCount];

          cout << "Enter student's CNIC: ";
     cin >> CNICs[studentCount];

        cout << "Enter student's registration number: ";
    cin >> registrationNos[studentCount];

    cout << "Enter student's inter marks out of 1200: ";
    cin >> interMarks[studentCount];

    cout << "Enter student's matric marks out of 1200: ";
    cin >> matricMarks[studentCount];

      cout << "\n................DATA REVIEW........................\n";
     cout << "Name of student: " << names[studentCount] << endl;
    cout << "Student's CNIC: " << CNICs[studentCount] << endl;
    cout << "Student's registration no: " << registrationNos[studentCount] << endl;
      cout << "Student's inter marks: " << interMarks[studentCount] << endl;
    cout << "Student's matric marks: " << matricMarks[studentCount] << endl;

       studentCount++;

    getch();
}
void deleteStudent() {
    if (studentCount == 0) {
        cout << "No students to delete.\n";
        getch();
        return;
    }
double regNo;
    cout << "Enter registration number of student to delete: ";
    cin >> regNo;

    int index = findStudentIndexByRegNo(regNo);
    if (index == -1) {
        cout << "Student not found.\n";
        getch();
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        names[i]          = names[i + 1];
        CNICs[i]          = CNICs[i + 1];
        registrationNos[i]= registrationNos[i + 1];
        interMarks[i]     = interMarks[i + 1];
        matricMarks[i]    = matricMarks[i + 1];
    }

    studentCount--;
 cout << "Student with registration no " << regNo << " deleted successfully.\n";
    getch();
}
void updateStudent() {
    if (studentCount == 0) {
        cout << "No students to update.\n";
        getch();
        return;
    }

    double regNo;
    cout << "Enter registration number of student to update: ";
    cin >> regNo;

    int index = findStudentIndexByRegNo(regNo);
    if (index == -1) {
        cout << "Student not found.\n";
        getch();
        return;
    }

         cout << "Updating data for student: " << names[index]
         << " (Reg No: " << registrationNos[index] << ")\n\n";

          cout << "Enter new student name (current: " << names[index] << "): ";
    cin >> names[index];

        cout << "Enter new student's CNIC (current: " << CNICs[index] << "): ";
    cin >> CNICs[index];
   
     cout << "Enter new student's registration number (current: "
         << registrationNos[index] << "): ";
        cin >> registrationNos[index];

       cout << "Enter new student's inter marks (current: "
         << interMarks[index] << "): ";
         cin >> interMarks[index];

       cout << "Enter new student's matric marks (current: "
         << matricMarks[index] << "): ";
       cin >> matricMarks[index];

    cout << "\nRecord updated successfully.\n";
    getch();
}


      void viewSpecificStudent() 
	  {
    if (studentCount == 0) {
        cout << "No students to view.\n";
        getch();
        return;
    }

    double regNo;
    cout << "Enter registration number of student to view: ";
    cin >> regNo;

    int index = findStudentIndexByRegNo(regNo);
    if (index == -1) {
        cout << "Student not found.\n";
        getch();
        return;
    }

    cout << "................STUDENT DATA........................\n";
     cout << "Name of student: " << names[index] << endl;
     cout << "Student's CNIC: " << CNICs[index] << endl;
      cout << "Student's registration no: " << registrationNos[index] << endl;
    cout << "Student's inter marks: " << interMarks[index] << endl;
       cout << "Student's matric marks: " << matricMarks[index] << endl;

    getch();
}


void viewAllStudents() {
    if (studentCount == 0) {
        cout << "No students to show.\n";
        getch();
        return;
    }

    cout << "Total students: " << studentCount << "\n\n";

    for (int i = 0; i < studentCount; i++) {
           cout << " Student #" << (i + 1) << " \n";
        cout << "Name: " << names[i] << endl;
          cout << "CNIC: " << CNICs[i] << endl;
        cout << "Registration no: " << registrationNos[i] << endl;
          cout << "Inter marks: " << interMarks[i] << endl;
        cout << "Matric marks: " << matricMarks[i] << endl;
        cout << "------------------------------------\n";
    }

    getch();
}
void viewStudentPercentage()
 {
    if (studentCount == 0) {
        cout << "No students to calculate percentage.\n";
        getch();
        return;
    }

    double regNo;
    cout << "Enter registration number of student to calculate percentage: ";
    cin >> regNo;

    int index = findStudentIndexByRegNo(regNo);
    if (index == -1) {
        cout << "Student not found.\n";
        getch();
        return;
    }
	int inter   = interMarks[index];
    int matric  = matricMarks[index];
    int obtainedTotal = inter + matric;
    double totalMarks = 2400.0;

    double percentage = (obtainedTotal / totalMarks) * 100.0;
      cout << "................PERCENTAGE REPORT................\n";
    cout << "Name: " << names[index] << endl;
       cout << "Registration no: " << registrationNos[index] << endl;
    cout << "Inter marks : " << inter << " / 1200" << endl;
     cout << "Matric marks: " << matric << " / 1200" << endl;
    cout << "Total obtained: " << obtainedTotal << " / 2400" << endl;
        cout << "Percentage   : " << percentage << " %" << endl;
  
    getch();
}
	
