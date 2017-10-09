#include <stdbool.h>
#include <stdlib.h>

bool check(char input) {
  if (input == 'm' || input == 's' || input == 'c') {
    return true;
  } else {
    return false;
  }
}

void print_tax_values(float taxRate, int income) {
  float taxesOwed = income * taxRate;
  printf("You owe: %f in taxes.\n", taxesOwed);
  printf("Your tax rate is: %.2f\n", taxRate);
  printf("Your taxable income is: %d\n", income);
}

void handle_single(int income) { print_tax_values(0.20, income); }

void handle_married(int income) { print_tax_values(0.25, income); }

void handle_co(int income) {
  float rate;
  if (income < 20000)
    rate = 0.10;
  else if (income >= 20000 && income <= 50000)
    rate = 0.15;
  else if (income > 50000)
    rate = 0.30;
  else
    return;
  print_tax_values(rate, income);
}

void calculate(char relationship_status, int income, int exemptions) {
  float taxRate;
  float taxesOwed = 0;
  income = income - (1000 * exemptions);
  switch (relationship_status) {
    case 's':
      handle_single(income);
      break;
    case 'm':
      handle_married(income);
      break;
    case 'c':
      handle_co(income);
      break;
  }
}