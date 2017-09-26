#include <iostream>
#include <string>
#include <sstream>
#include "Payroll.h"

using namespace std;

int main()
{
    stringstream ss;
    string name;

    double totalHours = 0, regularRate = 0, overTimeRate = 0, grossPay, regularHours = 0, overtimeHours = 0,
            fitTax, ficaSSNTax, ficaMEDTax, netPay;
    char category, choice;

    streamPayrollHeader(ss);
    do
    {
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
            overtimeHours = getOvertimeHours(totalHours);
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

        streamPayroll(ss, name, grossPay, regularHours, overtimeHours, regularRate, overTimeRate, regularRate * regularHours,
                      getOvertimeRate(regularRate) * overtimeHours, fitTax, ficaSSNTax, ficaMEDTax, netPay);

        cout << "Enter y for another record: ";
        cin >> choice;
        cin.ignore();

        totalHours = 0, regularRate = 0, overTimeRate = 0, grossPay, regularHours = 0, overtimeHours = 0;

    } while (choice == 'y');

    cout << ss.str();

    return 0;
}
