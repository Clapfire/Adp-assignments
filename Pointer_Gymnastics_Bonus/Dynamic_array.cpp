/*
Bonus round: Dynamic arrays

Make a program, which asks the user about how many numbers to input. Then use the built-in function
new to allocate the necessary number of members in a dynamic array ( int *dynarr = int[n];). Input the
numbers to the dynamic array and then output them in reverse order. Delete the array with the function
delete (delete dynarr[];) and let the program start all over again.
*/

#include <iostream>
using namespace std;

int main()
{

    while (true)
    {
        int n;
        cout << "Please insert the amount of numbers in the array" << endl;
        cin >> n;
        while(!cin.good()){
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please input an integer" << endl;
            cin >> n;
        }

        int *dynarr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Please enter digit number " << i+1 << endl;
            cin >> dynarr[i];
        }

        cout << "Your array: ";
        for (int i = 0; i < n; i++)
        {
            cout << dynarr[i] << " ";
        }

        cout << endl << "In reverse: ";
        for (int i = n-1; i >= 0; i--)
        {
            cout << dynarr[i] << " ";
        }

        cout << endl;

        delete dynarr;
    }

    return 0;
}