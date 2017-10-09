#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main() {
  printf("Taxation Automator v9000 For C\n");

  // Declarations
  char loop_ctrl;
  char relationship_status;
  int gross_income;
  int num_exemptions;

  do {
    puts("Are you [S]ingle, [M]arried, or [C]ohabiting?");
    scanf(" %c", &relationship_status);
    relationship_status = tolower(relationship_status);

    if (!check(relationship_status)) {
      printf("`%c` is not valid, please try again.", relationship_status);
      continue;
    }
    puts("Enter gross income: ");
    scanf(" %d", &gross_income);

    puts("Enter amount of exemptions: ");
    scanf(" %d", &num_exemptions);

    calculate(relationship_status, gross_income, num_exemptions);
    putchar('\n');

    // Loop again?
    puts("Would you like to process another? ");
    scanf(" %c", &loop_ctrl);
    loop_ctrl = tolower(loop_ctrl);
  } while (loop_ctrl == 'y');
  printf("Have a nice day!");
  return 0;
}