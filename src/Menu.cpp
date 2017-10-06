#include<iostream>
#include "Menu.h"
#include "Payroll.h"

using namespace std;

/**
 * Display Main Menu
 *
 */
void displayMainMenu()
{
    cout<<"Main Menu"<<endl<<endl;
    cout<<"1 Add Record"<<endl;
    cout<<"2 Display Records"<<endl;
    cout<<"3 Search Record"<<endl;
    cout<<"4 Sort Records"<<endl;
    cout<<"5 Exit"<<endl<<endl;
}

/**
 * Handle Menu choices selected
 *
 * @param choice
 */
void handleMainMenu(char choice)
{
    switch(choice)
    {
        case '1':
            handleAddRecord();
            break;
        case '2':
            handleDisplayRecords();
            break;
        case '3':
            handleSearchRecord();
            break;
        case '4':
            handleSortRecords();
            break;
        case '5':
            exit(1);
    }
}

/**
 * Run the main menu
 *
 */
void runMainMenu()
{
    char choice;
    do
    {
        displayMainMenu();
        cout<<"Enter Menu choice [1-5]";
        cin>>choice;

        handleMainMenu(choice);

    }while(choice != '5');
}

/**
 * Handle the add record menu selection
 *
 */
void handleAddRecord()
{
    string name;
    double totalHours = 0;
    double  regularRate, overTimeRate, grossPay,
            regularHours, regularPay, overtimeHours, overTimePay,
            fitTax, ficaSSNTax, ficaMEDTax, netPay;
    char category, choice;

    do
    {
        totalHours = 0, regularRate = 0, overTimeRate = 0,  regularHours = 0,
        overtimeHours = 0, overTimePay = 0, regularPay = 0;
        cin.ignore();
        cout << "Enter employee Name: ";
        getline(cin, name);

        do
        {
            cout << "Enter employee category h or s: ";
            cin >> category;
        } while(! (isValidCategory(category)));

        if (int(category) == hourly)
        {
            do
            {
                cout << "Enter total hours worked [0-60]: ";
                cin >> totalHours;
            } while (!(isValidHours(totalHours)));

            do
            {
                cout << "Enter hourly rate [0-50]: ";
                cin >> regularRate;
            } while (!(isValidRegularRate(regularRate)));

            regularHours = getRegularHours(totalHours);
            regularPay = regularHours * regularRate;
            overtimeHours = getOvertimeHours(totalHours);
            overTimePay = getOvertimeRate(regularRate) * overtimeHours;
            grossPay = getGrossPay(regularHours, overtimeHours, regularRate);
        }
        else if (int(category) == salary)
        {
            double salary = 0;

            while (!(isValidSalary(salary)))
            {
                cout << "Enter yearly salary[20000-100000]: ";
                cin >> salary;
            }

            grossPay = getGrossPay(salary);
        }

        fitTax = getFIT(grossPay);
        ficaSSNTax = getFICASSN(grossPay);
        ficaMEDTax = getFICAMED(grossPay);
        netPay = getNetPay(grossPay, fitTax, ficaSSNTax, ficaMEDTax);

        addRecord(name, grossPay, regularHours, overtimeHours, regularRate, overTimeRate, regularPay,
                  overTimePay, fitTax, ficaSSNTax, ficaMEDTax, netPay);

        cout << "Enter y for another record: ";
        cin >> choice;


    } while (choice == 'y');
}

/**
 *  Handle the search record menu selection
 */
void handleSearchRecord()
{
    string name;
    cout<<"Enter name to search for: ";
    cin.ignore();
    getline(cin, name);

    displaySearchResult(name);
}

/**
 * Handle sort records menu selection
 *
 */
void handleSortRecords()
{
    sortRecords();
}

/**
 * Handle display records menu selection
 */
void handleDisplayRecords()
{
    displayRecords();
}