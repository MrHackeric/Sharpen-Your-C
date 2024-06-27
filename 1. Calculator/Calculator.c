#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to perform the calculation
double calculate(double operand1, char operator, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Error: Unknown operator\n");
            exit(EXIT_FAILURE);
    }
}

// Function to parse the input expression
void parseExpression(char* expression, double* operand1, char* operator, double* operand2) {
    // Remove any spaces from the expression
    char* p = expression;
    char* q = expression;
    while (*q != '\0') {
        if (!isspace(*q)) {
            *p++ = *q;
        }
        q++;
    }
    *p = '\0';

    // Parse the expression
    if (sscanf(expression, "%lf%c%lf", operand1, operator, operand2) != 3) {
        printf("Error: Invalid expression format\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char expression[100];
    double operand1, operand2, result;
    char operator;

    // Prompt the user for input
    printf("Enter a mathematical expression (e.g., 3 + 4, 10 / 2): ");
    fgets(expression, sizeof(expression), stdin);

    // Parse the expression
    parseExpression(expression, &operand1, &operator, &operand2);

    // Perform the calculation
    result = calculate(operand1, operator, operand2);

    // Display the result
    printf("Result: %.2lf\n", result);

    return 0;
}

/*Explanation of the Code:

1. calculate Function:
This function takes two operands and an operator as input and performs the corresponding arithmetic operation.
If the operator is not recognized, or if there is an attempt to divide by zero, an error message is displayed, and the program exits.

2. parseExpression Function:
This function removes spaces from the input expression to simplify parsing.
It then uses `sscanf` to parse the input expression and extract the operands and operator.
If the input format is incorrect, an error message is displayed, and the program exits.

3. main Function:
The main function prompts the user to enter a mathematical expression.
It then calls `parseExpression` to parse the input and `calculate` to perform the calculation.
Finally, it prints the result.
*/
