// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float split_bill(float bill, float tax, float tip);

int main(void)
{
    float bill_amount = get_float("Total bill ");
    float tax_percent = get_float("Tax percentage ");
    int tip_percent = get_int("Tip percentage ");

    split_bill(bill_amount, tax_percent, tip_percent);

    printf("Each should pay %2f $\n", split_bill(bill_amount, tax_percent, tip_percent));
}

float split_bill(float bill, float tax, float tip)
{
    float pay = (bill + (bill * (tax / 100)) + (bill * (tip / 100))) / 2;

    return pay;
}
