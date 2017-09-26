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

void streamPayrollHeader(stringstream  &sscout );
void streamPayroll(stringstream &sscout, string name, double grossPay, double regularHours, double overtimeHours, double regularRate,
                   double overtimeRate, double regularPay, double overtimePay, double fitTax, double ficaSSNTax, double ficaMEDTax, double netPay);

bool isValidCategory(char chosenCategory);
bool isValidHours(double totalHours);
bool isValidRegularRate(double regularRate);
bool isValidSalary(double yearlySalary);




#endif