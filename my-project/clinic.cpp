#include <iostream>
#include <string>

using namespace std;

// Structure to store the name and medical condition of a patient
struct Patient
{
    string name;
    string condition;
};

// Function prototype for the search function
int search(Patient patients[], int numPatients, string name);

int main()
{
    // Array to store the patient records
    Patient patients[100];

    // Variable to store the number of patients
    int numPatients = 0;

    // Prompt the user to enter the patient information
    cout << "Enter the patient information (enter 'quit' to stop):" << endl;
    while (true)
    {
        // Prompt the user to enter the name and medical condition
        cout << "Name: ";
        string name;
        cin >> name;
        if (name == "quit")
            break;
        cout << "Medical condition: ";
        string condition;
        cin >> condition;

        // Add the patient to the array
        patients[numPatients].name = name;
        patients[numPatients].condition = condition;
        numPatients++;
    }

    // Prompt the user to enter a name to search for
    cout << "Enter a name to search for: ";
    string name;
    cin >> name;

    // Search for the patient
    int index = search(patients, numPatients, name);
    if (index == -1)
    {
        // Patient not found
        cout << "Patient not found." << endl;
    }
    else
    {
        // Patient found
        cout << "Patient found: " << patients[index].name << " (" << patients[index].condition << ")" << endl;
    }

    return 0;
}

// Function to search for a patient by name
int search(Patient patients[], int numPatients, string name)
{
    for (int i = 0; i < numPatients; i++)
    {
        if (patients[i].name == name)
        {
            // Patient found
            return i;
        }
    }
    // Patient not found
    return -1;
}