#include <iostream>
#include <string>

using namespace std;

// Constants for the cost per item and the tax rate
const double COST_PER_ITEM = 3.50;
const double TAX_RATE = 0.08;

// Structure to store the name and number of items of a user
struct User
{
    string name;
    int numItems;
};

// Function prototype for the calculateCost function
double calculateCost(int numItems, double costPerItem);

int main()
{
    // Array to store the user records
    User users[100];

    // Variable to store the number of users
    int numUsers = 0;

    // Prompt the user to enter the user information
    cout << "Enter the user information (enter 'quit' to stop):" << endl;
    while (true)
    {
        // Prompt the user to enter the name and number of items
        cout << "Name: ";
        string name;
        cin >> name;
        if (name == "quit")
            break;
        cout << "Number of items: ";
        int numItems;
        cin >> numItems;

        // Add the user to the array
        users[numUsers].name = name;
        users[numUsers].numItems = numItems;
        numUsers++;
    }

    // Calculate and display the total cost for each user
    double totalCost = 0;
    for (int i = 0; i < numUsers; i++)
    {
        double cost = calculateCost(users[i].numItems, COST_PER_ITEM);
        cout << users[i].name << ": $" << cost << endl;
        totalCost += cost;
    }

    // Display the total cost for all users
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}

// Function to calculate the total cost for a user based on the number of items and the cost per item
double calculateCost(int numItems, double costPerItem)
{
    double cost = numItems * costPerItem;
    double tax = cost * TAX_RATE;
    return cost + tax;
}