#ifndef _PAYROLL_H
#define _PAYROLL_H

#include<sstream>

using namespace std;

enum employeeCategory { hourly = 104, salary = 115 };

double getOvertimeHours(double totalHours);
double getRegularHours(double totalHours);
double getGrossPay(double regularHours, double overtimeHours, double hourlyRate);
double getGrossPay(double salary);
double getFIT(double grossPay);
double getFICASSN(double grossPay);
double getFICAMED(double grossPay);
double getNetPay(double grossPay, double fitTax, double  ficaSSN, double ficaMED);
double getOvertimeRate(double hourlyRate);
void displayPayrollHeader();
void displayPayroll(int index, int grossPayIndex);

void displayRecords();

void addRecord(const string name, const double grossPay, const double regularHours,
               const double overtimeHours, const double regularRate, const double overTimeRate,
               const double regularPay, const double overTimePay, const double fitTax,
               const double ficaSSNTax, const double ficaMEDTax, double const netPay);

int linearSearch(string name);
void displaySearchResult(string name);
void sortRecords();

bool isValidCategory(char chosenCategory);
bool isValidHours(double totalHours);
bool isValidRegularRate(double regularRate);
bool isValidSalary(double yearlySalary);




#endif