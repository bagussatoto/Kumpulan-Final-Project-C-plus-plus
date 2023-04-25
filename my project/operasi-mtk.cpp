#include <iostream>
#include <cmath>

using namespace std;

// Function prototypes
int factorial(int n);
double power(double base, int exponent);
double absoluteValue(double x);
int gcd(int x, int y);
int lcm(int x, int y);

int main()
{
    // Test the factorial function
    cout << "5! = " << factorial(5) << endl;
    cout << "6! = " << factorial(6) << endl;

    // Test the power function
    cout << "2^3 = " << power(2, 3) << endl;
    cout << "5^4 = " << power(5, 4) << endl;

    // Test the absolute value function
    cout << "|-3.14| = " << absoluteValue(-3.14) << endl;
    cout << "|4.20| = " << absoluteValue(4.20) << endl;

    // Test the GCD function
    cout << "gcd(18, 24) = " << gcd(18, 24) << endl;
    cout << "gcd(36, 60) = " << gcd(36, 60) << endl;

    // Test the LCM function
    cout << "lcm(18, 24) = " << lcm(18, 24) << endl;
    cout << "lcm(36, 60) = " << lcm(36, 60) << endl;

    return 0;
}

// Function to calculate the factorial of a number
int factorial(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// Function to calculate the power of a base
double power(double base, int exponent)
{
    double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

// Function to calculate the absolute value of a number
double absoluteValue(double x)
{
    if (x < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}

// Function to calculate the GCD of two numbers
int gcd(int x, int y)
{
    if (x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    while (y != 0)
    {
        int remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

// Function to calculate the LCM of two numbers
int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}