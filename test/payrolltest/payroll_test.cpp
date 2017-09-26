//
// Created by art on 9/14/2017.
//
#include "gtest/gtest.h"
#include <string>
#include "Payroll.h"

using namespace std;


TEST(PayrollTest, test_get_regular_hours_when_hours_equal_0) {
    EXPECT_EQ(0, getRegularHours(0));
}

TEST(PayrollTest, test_get_regular_hours_when_hours_less_than_40) {
    EXPECT_EQ(20, getRegularHours(20));
}

TEST(PayrollTest, test_get_regular_hours_when_hours_greater_than_40) {
    EXPECT_EQ(40, getRegularHours(50));
}

TEST(PayrollTest, test_get_regular_hours_when_hours_less_than_0) {
    EXPECT_EQ(0, getRegularHours(-5));
}

TEST(PayrollTest, test_get_overtime_hours_when_hours_less_than_0) {
    EXPECT_EQ(0, getOvertimeHours(-5));
}

TEST(PayrollTest, test_get_overtime_hours_when_hours_less_than_40) {
    EXPECT_EQ(0, getOvertimeHours(30));
}

TEST(PayrollTest, test_get_overtime_hours_when_hours_greater_than_40) {
    EXPECT_EQ(10, getOvertimeHours(50));
}

TEST(PayrollTest, test_get_gross_pay_when_hours_less_than_40) {
    EXPECT_EQ(800, getGrossPay(40, 0, 20));
}

TEST(PayrollTest, test_get_gross_pay_when_hours_greater_than_40) {
    EXPECT_EQ(1040, getGrossPay(40, 8, 20));
}

TEST(PayrollTest, test_get_gross_pay_when_hours_less_than_0) {
    EXPECT_EQ(0, getGrossPay(getRegularHours(-10), getOvertimeHours(-10), 20));
}

TEST(PayrollTest, test_get_fit_when_gross_salary_greater_than_0) {
    EXPECT_EQ(150, getFIT(1000));
}

TEST(PayrollTest, test_get_fit_when_gross_salary_less_than_0) {
    EXPECT_EQ(0, getFIT(-1000));
}

TEST(PayrollTest, test_get_fica_ssn_when_gross_salary_greater_than_0) {
    EXPECT_EQ(62, getFICASSN(1000));
}

TEST(PayrollTest, test_get_fica_ssn_when_gross_salary_less_than_0) {
    EXPECT_EQ(0, getFICASSN(-1000));
}

TEST(PayrollTest, test_get_fica_med_when_gross_salary_greater_than_0) {
    EXPECT_EQ(14.5, getFICAMED(1000));
}

TEST(PayrollTest, test_get_fica_med_when_gross_salary_less_than_0) {
    EXPECT_EQ(0, getFICAMED(-1000));
}

/*TEST(PayrollTest, test_get_net_pay_when_gross_salary_greater_than_0) {
	EXPECT_EQ(to_string(804.44), to_string(getNetPay(1040, 156)));
}

TEST(PayrollTest, test_get_net_pay_when_gross_salary_less_than_0) {
	EXPECT_EQ(0, getNetPay(-1000));
}
*/

TEST(PayrollDataValiation, test_is_valid_category_when_category_hourly) {
    EXPECT_EQ(true, isValidCategory('h'));
}

TEST(PayrollDataValiation, test_is_valid_category_when_category_salary) {
    EXPECT_EQ(true, isValidCategory('s'));
}

TEST(PayrollDataValiation, test_is_valid_category_when_category_invalid) {
    EXPECT_EQ(false, isValidCategory('a'));
}

TEST(PayrollDataValidation, test_is_valid_hours_when_hours_less_than_0) {
    EXPECT_EQ(false, isValidHours(-5));
}

TEST(PayrollDataValidation, test_is_valid_hours_when_hours_gt_0_and_lt_60) {
    EXPECT_EQ(true, isValidHours(5));
}

TEST(PayrollDataValidation, test_is_valid_hours_when_hours_greater_than_60) {
    EXPECT_EQ(false, isValidHours(65));
}

TEST(PayrollDataValidation, test_is_valid_regular_rate_when_rate_less_than_0) {
    EXPECT_EQ(false, isValidRegularRate(-5));
}

TEST(PayrollDataValidation, test_is_valid_regular_rate_when_rate_greater_than_0) {
    EXPECT_EQ(true, isValidRegularRate(10));
}

TEST(PayrollDataValidation, test_is_valid_regular_rate_when_rate_more_than_50) {
    EXPECT_EQ(false, isValidRegularRate(55));
}

TEST(payrollDataValidation, test_is_valid_salary_when_salary_less_than_20000) {
    EXPECT_EQ(false, isValidSalary(-20000));
}

TEST(payrollDataValidation, test_is_valid_salary_when_salary_greatereq_than_20000_and_less_than_eq_100k) {
    EXPECT_EQ(true, isValidSalary(50000));
}

TEST(payrollDataValidation, test_is_valid_salary_when_salary_greater_than_100000) {
    EXPECT_EQ(false, isValidSalary(101000));
}