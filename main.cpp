#include <iostream>
#include <string>
#include "Payroll.h"

using namespace std;

int main()
{
    const int SIZE = 3;
    string name[SIZE];
    double totalHours = 0;
    double  regularRate[SIZE], overTimeRate[SIZE], grossPay[SIZE],
            regularHours[SIZE], regularPay[SIZE], overtimeHours[SIZE], overTimePay[SIZE],
            fitTax[SIZE], ficaSSNTax[SIZE], ficaMEDTax[SIZE], netPay[SIZE];
    char category[SIZE], choice;
    int indx = 0;

    do
    {
        totalHours = 0, regularRate[indx] = 0, overTimeRate[indx] = 0,  regularHours[indx] = 0,
        overtimeHours[indx] = 0, overTimePay[indx];

        cout << "Enter employee Name: ";
        getline(cin, name[indx]);

        do
        {
            cout << "Enter employee category h or s: ";
            cin >> category[indx];
        } while(! (isValidCategory(category[indx])));

        if (int(category[indx]) == hourly)
        {
            do
            {
                cout << "Enter total hours worked [0-60]: ";
                cin >> totalHours;
            } while (!(isValidHours(totalHours)));

            do
            {
                cout << "Enter hourly rate [0-50]: ";
                cin >> regularRate[indx];
            } while (!(isValidRegularRate(regularRate[indx])));

            regularHours[indx] = getRegularHours(totalHours);
            regularPay[indx] = regularHours[indx] * regularRate[indx];
            overtimeHours[indx] = getOvertimeHours(totalHours);
            overTimePay[indx] = getOvertimeRate(regularRate[indx]) * overtimeHours[indx];
            grossPay[indx] = getGrossPay(regularHours[indx], overtimeHours[indx], regularRate[indx]);
        }
        else if (int(category[indx]) == salary)
        {
            double salary = 0;

            while (!(isValidSalary(salary)))
            {
                cout << "Enter yearly salary[20000-100000]: ";
                cin >> salary;
            }

            grossPay[indx] = getGrossPay(salary);
        }

        fitTax[indx] = getFIT(grossPay[indx]);
        ficaSSNTax[indx] = getFICASSN(grossPay[indx]);
        ficaMEDTax[indx] = getFICAMED(grossPay[indx]);
        netPay[indx] = getNetPay(grossPay[indx], fitTax[indx], ficaSSNTax[indx], ficaMEDTax[indx]);

        cout << "Enter y for another record: ";
        cin >> choice;
        cin.ignore();
        indx++;
    } while (choice == 'y');

    displayPayrollHeader();
    displayPayroll(name, grossPay, regularHours, overtimeHours, regularRate, overTimeRate, regularPay,
                   overTimePay, fitTax, ficaSSNTax, ficaMEDTax, netPay, SIZE);

    return 0;
}
