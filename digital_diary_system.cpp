// DIGITAL DIARY SYSTEM IN C++
// Concepts Used:
// Classes & Objects
// Constructor
// Encapsulation
// Functions
// File Handling
// Loops
// Conditions

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Diary
{
private:
    string date;
    string title;
    string note;

public:
    // Constructor
    Diary()
    {
        date = "";
        title = "";
        note = "";
    }

    // Add Diary Entry
    void addEntry()
    {
        cin.ignore();

        cout << "\nEnter Date (DD/MM/YYYY): ";
        getline(cin, date);

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Write Your Note: ";
        getline(cin, note);

        ofstream file("diary.txt", ios::app);

        file << "Date: " << date << endl;
        file << "Title: " << title << endl;
        file << "Note: " << note << endl;
        file << "-----------------------------" << endl;

        file.close();

        cout << "\nDiary Entry Saved Successfully!\n";
    }

    // View Diary Entries
    void viewEntries()
    {
        ifstream file("diary.txt");

        if (!file)
        {
            cout << "\nNo Diary Entries Found!\n";
            return;
        }

        string line;

        cout << "\n====== YOUR DIARY ENTRIES ======\n";

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    // Search Diary Entry
    void searchEntry()
    {
        cin.ignore();

        string searchDate;
        string line;
        bool found = false;

        cout << "\nEnter Date to Search Entry: ";
        getline(cin, searchDate);

        ifstream file("diary.txt");

        while (getline(file, line))
        {
            if (line == "Date: " + searchDate)
            {
                found = true;

                cout << "\nEntry Found!\n";
                cout << line << endl;

                getline(file, line);
                cout << line << endl;

                getline(file, line);
                cout << line << endl;

                getline(file, line);
                cout << line << endl;

                break;
            }
        }

        if (!found)
        {
            cout << "\nNo Entry Found On This Date!\n";
        }

        file.close();
    }
};

// Main Function
int main()
{
    Diary d;

    int choice;

    do
    {
        cout << "\n====== DIGITAL DIARY SYSTEM ======\n";
        cout << "1. Add Diary Entry\n";
        cout << "2. View All Entries\n";
        cout << "3. Search Entry By Date\n";
        cout << "4. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            d.addEntry();
            break;

        case 2:
            d.viewEntries();
            break;

        case 3:
            d.searchEntry();
            break;

        case 4:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}
