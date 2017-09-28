#include <string>
#include <iostream>
#include <iomanip>
#include "Payroll.h"

using namespace std;

const double STANDARD_WEEK_HOURS = 40;
const double SALARY_FREQUENCY = 26;
const double OVER_TIME_MULTIPLIER = 1.5;
const double FICA_SSN_RATE = .062;
const double FICA_MED_RATE = .0145;
const double FIT_RATE = .15;


/**
 * Returns over time hours
 *
 * @param totalHours the total hours worked for one week
 * @return over time hours worked in one week
 */
double getOvertimeHours(double totalHours)
{
    double hours = 0;

    if(totalHours > STANDARD_WEEK_HOURS)
    {
        hours =  totalHours - STANDARD_WEEK_HOURS;
    }

    return hours;
}

/**
 * Returns regular payroll hours
 *
 * @param totalHours total hours worked for one week
 * @return regular payroll hours excluding over time hours
 */
double getRegularHours(double totalHours)
{
    double hours = totalHours;

    if(totalHours > STANDARD_WEEK_HOURS)
        hours = STANDARD_WEEK_HOURS;
    else if(totalHours < 0)
        hours = 0;

    return hours;
}

/**
  Returns gross pay for an hourly employee

  @param totalHours expects hours greater than 0
  @param hourlyRate expects a rate greater than 0
 * */
double getGrossPay(double regularHours, double overtimeHours, double hourlyRate)
{
    double grossPay = regularHours * hourlyRate + overtimeHours * hourlyRate * OVER_TIME_MULTIPLIER;

    return grossPay;
}

/**
 * Returns gross salary for a salaried employee for a salary frequency(biweekly)
 *
 * @param salary the yearly salary
 * @return the salary frequence(biweekly) salary
 */
double getGrossPay(double salary)
{
    return salary / SALARY_FREQUENCY;
}

/**
 * Returns Federal income tax
 *
 * @param grossPay for the given period
 * @return federal income tax
 */
double getFIT(double grossPay)
{
    if (grossPay < 0)
        return 0;
    else
        return grossPay * FIT_RATE;
}

/**
 * Calculates and returns FICA SSN
 *
 * @param grossPay for the given period
 * @return returns FICA SSN
 */
double getFICASSN(double grossPay)
{
    if (grossPay < 0)
        return 0;
    else
        return grossPay * FICA_SSN_RATE;
}

/**
 * Calculates and returns FICA MED
 *
 * @param grossPay for a given week
 * @return returns FICA MED given a salary
 */
double getFICAMED(double grossPay)
{
    if (grossPay < 0)
        return 0;
    else
        return grossPay * FICA_MED_RATE;
}

/**
 * Return the net pay for an employee
 *
 * @param grossPay pay for a given week
 * @param fitTax federal income tax
 * @param ficaSSN FICA SSN
 * @param ficaMED FICA MED
 * @return net pay for an employee
 */
double getNetPay(double grossPay, double fitTax, double  ficaSSN, double ficaMED)
{
    if (grossPay < 0)
        return 0;

    double netPay = grossPay - fitTax - ficaSSN - ficaMED;

    return netPay;
}

/**
 * Calculates over time rate given hourly rate
 *
 * @param hourlyRate regular rate for employee
 * @return over time rate
 */
double getOvertimeRate(double hourlyRate)
{
    return hourlyRate * OVER_TIME_MULTIPLIER;
}

void printCheck(double grossPay, double regularHours, double overtimeHours, double hourlyRate,
                double overtimeRate, double fitTax, double ficaSSNTax, double ficaMEDTax, double netPay)
{
    cout << "\n\n" << showpoint << fixed << setprecision(2);
    cout << right << setw(16) << "Regular hours: " << setw(8) << regularHours << endl;
    cout << right << setw(16) << "Overtime hours: " << setw(8) << overtimeHours << endl;
    cout << right << setw(16) << "Regular rate: " << setw(8) << hourlyRate << endl;
    cout << right << setw(16) << "Overtime rate: " << setw(8) << overtimeRate << endl;
    cout << right << setw(16) << "Gross pay: " << setw(8) << grossPay << endl;
    cout << right << setw(16) << "Federal Tax: " << setw(8) << fitTax << endl;
    cout << right << setw(16) << "FICA SSN Tax: " << setw(8) << ficaSSNTax << endl;
    cout << right << setw(16) << "FICA MED Tax: " << setw(8) << ficaMEDTax << endl;
    cout << right << setw(16) << "Net Pay: " << setw(8) << netPay << endl;
}

void displayPayrollHeader()
{
    cout << left << setw(15) << "Name" << " Hours " << " OT Hours " << "  Rate  " << " OT Rate " << " Regular Pay " << " OT Pay " << " Gross Pay "
           << "Fed Tax " << " FICA SSN " << " FICA Med " << " Net Pay " << endl;
    cout << fixed << showpoint << setprecision(2);
}

void displayPayroll(const string name[], const double grossPay[], const double regularHours[],
                    const double overtimeHours[], const double regularRate[], const double overtimeRate[],
                    const double regularPay[], const double overtimePay[], const double fitTax[],
                    const double ficaSSNTax[], const double ficaMEDTax[], const double netPay[],
                    int listSize) {

    for (int i = 0; i < listSize; i++)
    {
        cout << left << setw(15) << name[i];
        regularHours[i] > 0 ? cout << right << setw(6) << regularHours[i] : cout << setw(6) << " ";
        overtimeHours[i] > 0 ? cout << right << setw(10) << overtimeHours[i] : cout << setw(10) << " ";
        regularRate[i] > 0 ? cout << right << setw(8) << regularRate[i] : cout << setw(8) << " ";
        overtimeRate[i] > 0 ? cout << right << setw(9) << overtimeRate[i] : cout << setw(9) << " ";

        regularPay[i] > 0 ? cout << right << setw(13) << regularPay[i] : cout << setw(13) << " ";

        overtimePay[i] > 0 ? cout << right << setw(8) << overtimePay[i] : cout << setw(8) << " ";

        cout << right << setw(10) << grossPay[i]
             << right << setw(9) << fitTax[i]
             << right << setw(11) << ficaSSNTax[i]
             << right << setw(10) << ficaMEDTax[i]
             << right << setw(9) << netPay[i] << endl;
    }
}

bool isValidCategory(char chosenCategory)
{
    return (int(hourly) == chosenCategory || int(salary) == chosenCategory);
}

bool isValidHours(double totalHours)
{
    return (!(totalHours <= 0 || totalHours >= 60));
}

bool isValidRegularRate(double regularRate)
{
    return (!(regularRate <= 0 || regularRate >= 50));
}

bool isValidSalary(double yearlySalary)
{
    return yearlySalary >= 20000 && yearlySalary <= 100000;
}
