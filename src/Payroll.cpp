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

const int SIZE = 10;
string name[SIZE];

double  regularRate[SIZE], overtimeRate[SIZE], grossPay[SIZE],
        regularHours[SIZE], regularPay[SIZE], overtimeHours[SIZE], overtimePay[SIZE],
        fitTax[SIZE], ficaSSNTax[SIZE], ficaMEDTax[SIZE], netPay[SIZE];

int currentSize = 0, grossPaySortedIndexes[SIZE];

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

/**
 * Prints payroll header names
 */
void displayPayrollHeader()
{
    cout << left << setw(15) << "Name" << " Hours " << " OT Hours " << "  Rate  " << " OT Rate " << " Regular Pay " << " OT Pay " << " Gross Pay "
           << "Fed Tax " << " FICA SSN " << " FICA Med " << " Net Pay " << endl;
    cout << fixed << showpoint << setprecision(2);
}

/**
 * Displays a payroll record
 *
 * @param i index of record to display
 * @param grossPayIndex if grossPayIndex present use this index instead of i
 */
void displayPayroll(int i, int grossPayIndex = -1) {

    cout << left << setw(15) << name[i];
    regularHours[i] > 0 ? cout << right << setw(6) << regularHours[i] : cout << setw(6) << " ";
    overtimeHours[i] > 0 ? cout << right << setw(10) << overtimeHours[i] : cout << setw(10) << " ";
    regularRate[i] > 0 ? cout << right << setw(8) << regularRate[i] : cout << setw(8) << " ";
    overtimeRate[i] > 0 ? cout << right << setw(9) << overtimeRate[i] : cout << setw(9) << " ";

    regularPay[i] > 0 ? cout << right << setw(13) << regularPay[i] : cout << setw(13) << " ";

    overtimePay[i] > 0 ? cout << right << setw(8) << overtimePay[i] : cout << setw(8) << " ";

    grossPayIndex == -1 ? cout<< right << setw(10) << grossPay[i] :
                          cout<< right << setw(10) << grossPay[grossPayIndex];

    cout << right << setw(9) << fitTax[i]
         << right << setw(11) << ficaSSNTax[i]
         << right << setw(10) << ficaMEDTax[i]
         << right << setw(9) << netPay[i] << endl;
}

/**
 * Adds one record to the array
 *
 * @param employeeName
 * @param totalPay
 * @param regHours
 * @param overTimeHours
 * @param regRate
 * @param overTimeRate
 * @param regPay
 * @param overTimePay
 * @param FITTax
 * @param FICASSNTax
 * @param FICAMEDTax
 * @param netpay
 */
void addRecord(const string employeeName, const double totalPay, const double regHours,
               const double overTimeHours, const double regRate, const double overTimeRate,
               const double regPay, const double overTimePay, const double FITTax,
               const double FICASSNTax, const double FICAMEDTax, double const netpay)
{
    name[currentSize] = employeeName;
    grossPay[currentSize] = totalPay;
    regularHours[currentSize] = regHours;
    overtimeHours[currentSize] = overTimeHours;
    regularRate[currentSize] = regRate;
    overtimeRate[currentSize] = overTimeRate;
    regularPay[currentSize] = regPay;
    overtimePay[currentSize] = overTimePay;
    fitTax[currentSize] = FITTax;
    ficaSSNTax[currentSize] = FICASSNTax;
    ficaMEDTax[currentSize] = FICAMEDTax;
    netPay[currentSize] = netpay;

    if(currentSize < SIZE)
    {
        grossPaySortedIndexes[currentSize] = currentSize;
        currentSize++;
    }
}

/**
 * Performs linear search
 *
 * @param employeeName
 * @return position of record found, -1 if no record found
 */
int linearSearch(string employeeName)
{
    int first = 0, index = 0, position = -1;
    bool found = false;

    while(index < currentSize && !found)
    {
        if(name[index] == employeeName)
        {
            found = true;
            position = index;
        }
        index++;
    }

    return position;
}

/**
 * Helper function to display payroll records
 */
void displayRecords()
{
    displayPayrollHeader();

    for (int i = 0; i < currentSize; i++) {

        displayPayroll(i);
    }
}

/**
 * Call linear search function and display record if any
 *
 * @param name
 */
void displaySearchResult(string name)
{
    int index = linearSearch(name);

    if(index > -1)
        displayPayroll(index);
    else
        cout<<name<<" not found...";
}

/**
 * Sort using a linear search and display sorted records
 *
 */
void sortRecords()
{
    int startScan, minIndex, minValue, tempIndex;

    for(startScan = 0; startScan < (currentSize-1);startScan++)
    {
        minIndex = startScan;
        minValue = grossPay[startScan];

        for(int index = startScan + 1; index < currentSize; index++)
        {
            if(grossPay[index] < minValue)
            {
                minValue = grossPay[index];
                minIndex = index;
            }
        }

        tempIndex = grossPaySortedIndexes[minIndex];
        cout<<startScan<<" "<<tempIndex<<" "<<minIndex<<endl;
        grossPaySortedIndexes[minIndex] = startScan;
        grossPaySortedIndexes[startScan] = tempIndex;


        grossPay[minIndex] = grossPay[startScan];
        grossPay[startScan] = minValue;
    }

    displayPayrollHeader();

    for (int i = 0; i < currentSize; i++) {

        displayPayroll(grossPaySortedIndexes[i], i);
    }

}

/**
 * check category for valid value
 *
 * @param chosenCategory
 * @return boolean variable
 */
bool isValidCategory(char chosenCategory)
{
    return (int(hourly) == chosenCategory || int(salary) == chosenCategory);
}

/**
 * Check for valid hours
 *
 * @param totalHours
 * @return boolean variable
 */
bool isValidHours(double totalHours)
{
    return (!(totalHours <= 0 || totalHours >= 60));
}

/**
 * Validate regular rate
 *
 * @param regularRate
 * @return
 */
bool isValidRegularRate(double regularRate)
{
    return (!(regularRate <= 0 || regularRate >= 50));
}

/**
 * Validate salary
 *
 * @param yearlySalary
 * @return
 */
bool isValidSalary(double yearlySalary)
{
    return yearlySalary >= 20000 && yearlySalary <= 100000;
}
