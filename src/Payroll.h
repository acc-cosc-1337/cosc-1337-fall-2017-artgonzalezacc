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

void printCheck(double grossPay, double regularHours, double overtimeHours, double hourlyRate,
                double overTimeRate, double ficaTax,	double ficaSSNTax, double ficaMEDTax, double netPay);

void displayPayrollHeader();
void displayPayroll(const string name[], const double grossPay[], const double regularHours[],
                    const double overtimeHours[], const double regularRate[], const double overtimeRate[],
                    const double regularPay[], const double overtimePay[], const double fitTax[],
                    const double ficaSSNTax[], const double ficaMEDTax[], const double netPay[], int listSize);

bool isValidCategory(char chosenCategory);
bool isValidHours(double totalHours);
bool isValidRegularRate(double regularRate);
bool isValidSalary(double yearlySalary);




#endif