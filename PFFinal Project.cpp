#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Prototypes 
void addPatient();
void addNormal();

void viewPatients();
void viewNormals();

void searchPatient();
void searchNormal();

void editPatient();
void editNormal();

void deletePatient();
void deleteNormal();

void compareExpression();

// ADD Patient 
void addPatient() {
    ofstream file("patient.txt", ios::app);  
    int id, age;
    string name, gene;
    float expression;

    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Patient Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gene Name: ";
    cin >> gene;
    cout << "Enter Gene Expression Level: ";
    cin >> expression;

    // Store record in file
    file << id << " " << name << " " << age << " " << gene << " " << expression << endl;
    cout << "Patient record added successfully!\n";
    file.close();
}



// Add Normal 
void addNormal() {
    ofstream file("normal.txt", ios::app);
    int id, age;
    string name, gene;
    float expression;

    cout << "Enter Normal Sample ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gene Name: ";
    cin >> gene;
    cout << "Enter Gene Expression Level: ";
    cin >> expression;

    file << id << " " << name << " " << age << " " << gene << " " << expression << endl;
    cout << "Normal sample added successfully!\n";
    file.close();
}

// View Diseased 
void viewPatients() {
    ifstream file("patient.txt");

    if (!file) {
        cout << "No patient records found.\n";
        return;
    }

    int id, age;
    string name, gene;
    float expression;

    cout << "\n--- Diseased Patient Samples ---\n";
    while (file >> id >> name >> age >> gene >> expression) {
        cout << "ID: " << id
            << "  Name: " << name
            << "  Age: " << age
            << "  Gene: " << gene
            << "  Expression: " << expression << endl;
    }
    file.close();
}


// View Normal 
void viewNormals() {
    ifstream file("normal.txt");

    if (!file) {
        cout << "No normal records found.\n";
        return;
    }

    int id, age;
    string name, gene;
    float expression;

    cout << "\n--- Normal Samples ---\n";
    while (file >> id >> name >> age >> gene >> expression) {
        cout << "ID: " << id
            << "  Name: " << name
            << "  Age: " << age
            << "  Gene: " << gene
            << "  Expression: " << expression << endl;
    }
    file.close();
}



// Search Patient
void searchPatient() {
    ifstream file("patient.txt");
    int searchID;
    cout << "Enter Patient ID to search: ";
    cin >> searchID;

    int id, age;
    string name, gene;
    float expression;
    bool found = false;

    while (file >> id >> name >> age >> gene >> expression) {
        if (id == searchID) {
            cout << "\nRecord Found!\n";
            cout << "ID: " << id
                << "  Name: " << name
                << "  Age: " << age
                << "  Gene: " << gene
                << "  Expression: " << expression << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

// Search Normal 
void searchNormal() {
    ifstream file("normal.txt");
    int searchID;
    cout << "Enter Normal Sample ID to search: ";
    cin >> searchID;

    int id, age;
    string name, gene;
    float expression;
    bool found = false;

    while (file >> id >> name >> age >> gene >> expression) {
        if (id == searchID) {
            cout << "\nRecord Found!\n";
            cout << "ID: " << id
                << "  Name: " << name
                << "  Age: " << age
                << "  Gene: " << gene
                << "  Expression: " << expression << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}
// Edit Patient
void editPatient() {
    ifstream file("patient.txt");
    ofstream temp("temp.txt");

    int editID;
    cout << "Enter Patient ID to edit: ";
    cin >> editID;

    int id, age;
    string name, gene;
    float expression;
    bool found = false;

    while (file >> id >> name >> age >> gene >> expression) {
        if (id == editID) {
            cout << "Enter New Name: ";
            cin >> name;
            cout << "Enter New Age: ";
            cin >> age;
            cout << "Enter New Gene: ";
            cin >> gene;
            cout << "Enter New Expression: ";
            cin >> expression;
            found = true;
        }
        temp << id << " " << name << " " << age << " " << gene << " " << expression << endl;
    }

    file.close();
    temp.close();

    remove("patient.txt");
    rename("temp.txt", "patient.txt");

    if (found)
        cout << "Record updated successfully!\n";
    else
        cout << "Record not found.\n";
}

// Edit Normal 
void editNormal() {
    ifstream file("normal.txt");
    ofstream temp("temp.txt");

    int editID;
    cout << "Enter Normal Sample ID to edit: ";
    cin >> editID;

    int id, age;
    string name, gene;
    float expression;
    bool found = false;

    while (file >> id >> name >> age >> gene >> expression) {
        if (id == editID) {
            cout << "Enter New Name: ";
            cin >> name;
            cout << "Enter New Age: ";
            cin >> age;
            cout << "Enter New Gene: ";
            cin >> gene;
            cout << "Enter New Expression: ";
            cin >> expression;
            found = true;
        }
        temp << id << " " << name << " " << age << " " << gene << " " << expression << endl;
    }

    file.close();
    temp.close();

    remove("normal.txt");
    rename("temp.txt", "normal.txt");

    if (found)
        cout << "Record updated successfully!\n";
    else
        cout << "Record not found.\n";
}

// Delete Diseased 
void deletePatient() {
    ifstream file("patient.txt");
    ofstream temp("temp.txt");

    int delID;
    cout << "Enter Patient ID to delete: ";
    cin >> delID;

    int id, age;
    string name, gene;
    float expression;
    bool found = false;

    while (file >> id >> name >> age >> gene >> expression) {
        if (id != delID)
            temp << id << " " << name << " " << age << " " << gene << " " << expression << endl;
        else
            found = true;
    }

    file.close();
    temp.close();

    remove("patient.txt");
    rename("temp.txt", "patient.txt");

    if (found)
        cout << "Record deleted successfully!\n";
    else
        cout << "Record not found.\n";
}

// Delete Normal 
void deleteNormal() {
    ifstream file("normal.txt");
    ofstream temp("temp.txt");

    int delID;
    cout << "Enter Normal Sample ID to delete: ";
    cin >> delID;

    int id, age;
    string name, gene;
    float expression;
    bool found = false;

    while (file >> id >> name >> age >> gene >> expression) {
        if (id != delID)
            temp << id << " " << name << " " << age << " " << gene << " " << expression << endl;
        else
            found = true;
    }

    file.close();
    temp.close();

    remove("normal.txt");
    rename("temp.txt", "normal.txt");

    if (found)
        cout << "Record deleted successfully!\n";
    else
        cout << "Record not found.\n";
}

// Comparison of Expression 
void compareExpression() {
    string targetGene;
    int id, age;
    string name, gene;
    float expression;

    float pSum = 0, nSum = 0;
    int pCount = 0, nCount = 0;

    ifstream pFile("patient.txt");
    ifstream nFile("normal.txt");

    if (!pFile || !nFile) {
        cout << "Error opening files!" << endl;
        return;
    }
    cout << "Comparison of the Gene Expression:"<< endl;
    cout << "Enter Gene Name: ";
    cin >> targetGene;

    while (pFile >> id >> name >> age >> gene >> expression) {
        if (gene == targetGene) {
            pSum = pSum + expression;
            pCount = pCount + 1;
        }
    }

    while (nFile >> id >> name >> age >> gene >> expression) {
        if (gene == targetGene) {
            nSum = nSum + expression;
            nCount = nCount + 1;
        }
    }

    cout << "--- Results ---" << endl;

    if (pCount > 0 && nCount > 0) {
        float pAvg = pSum / pCount;
        float nAvg = nSum / nCount;

        cout << "Patient Average: " << pAvg << endl;
        cout << "Normal Average: " << nAvg << endl;

        if (pAvg > nAvg) {
            cout << "Result:Expression is Over-expressed in the diseased patient." << endl;
        } else if (pAvg < nAvg) {
            cout << "Result: Expression is Under-expressed in the diseased patient." << endl;
        } else {
            cout << "Result: Same expression." << endl;
        }
    } else {
        cout << "Gene not found in one or both files." << endl;
    }

    pFile.close();
    nFile.close();
}
    
// MAIN PROGRAM 
int main() 
{
    int choice;
    do {
        cout << "\n===== Gene Expression File Analyzer =====\n";
        cout << "1. Add Diseased Patient Sample\n";
        cout << "2. Add Normal Sample\n";
        cout << "3. View Diseased Patient Samples\n";
        cout << "4. View Normal Samples\n";
        cout << "5. Search Diseased Patient Sample\n";
        cout << "6. Search Normal Sample\n";
        cout << "7. Edit Diseased Patient Sample\n";
        cout << "8. Edit Normal Sample\n";
        cout << "9. Compare Gene Expression (Normal Vs Diseased)\n";
        cout << "10. Delete Diseased Patient\n";
        cout << "11. Delete Normal Sample\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addPatient(); break;
        case 2: addNormal(); break;
        case 3: viewPatients(); break;
        case 4: viewNormals(); break;
        case 5: searchPatient(); break;
        case 6: searchNormal(); break;
        case 7: editPatient(); break;
        case 8: editNormal(); break;
        case 9: compareExpression(); break;
        case 10: deletePatient(); break;
        case 11: deleteNormal(); break;
        case 12: cout << "Program exited successfully.\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 12);

    return 0;
}

