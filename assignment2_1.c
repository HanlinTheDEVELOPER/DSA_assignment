//
// Created by hanlin on 12/12/23.
//

#include "stdio.h"
float operations(int opt);
void showResult();
int choosing();
int add();
int sub();
int multiply();
float division();

int main() {
    int next = 0;
    showResult();
    printf("\nWant to use again? if Yes press 1 , else press any key to exit:");
    scanf("%d", &next);
    if (next == 1) {
        main();
    }
    return 0;
}

void showResult() {
    int opt = choosing();

    float ans = operations(opt);
    if (opt == 4) {
        printf("The result is %.1f", ans);
    } else {
        printf("The result is %.0f", ans);
    }
}

int choosing() {
    int choice = 0;
    printf("Operations!\n");
    printf("1.Add 2.Sub 3.Multiply 4.Division\n");
    printf("Enter corresponding no of  from operations above : ");
    scanf("%d", &choice);
    return choice;
}

float operations(int opt) {

    float ans = 0.0;
    switch (opt) {
        case 1:
            ans = add();
            break;
        case 2:
            ans = sub();
            break;
        case 3:
            ans = multiply();
            break;
        case 4:
            ans = division();
            break;
        default:
            printf("Please enter only number between 1 to 4.\n");
            operations(opt);
            break;
    };
    return ans;
}

int add() {
    int num1, num2, result = 0;
    printf("Enter first number : ");
    scanf("%d", &num1);
    printf("Enter second number : ");
    scanf("%d", &num2);
    result = num1 + num2;
    return result;
}

int sub() {
    int num1, num2, result = 0;
    printf("Enter first number : ");
    scanf("%d", &num1);
    printf("Enter second number : ");
    scanf("%d", &num2);
    result = num1 - num2;
    return result;
}

int multiply() {
    int num1, num2, result = 0;
    printf("Enter first number : ");
    scanf("%d", &num1);
    printf("Enter second number : ");
    scanf("%d", &num2);
    result = num1 * num2;
    return result;
}

float division() {
    float num1, num2 = 0.0;
    float result = 0.0;
    printf("Enter first number : ");
    scanf("%f", &num1);
    do {
        printf("Enter second number : ");
        scanf("%f", &num2);
    } while (num2 == 0.0);
    result = num1 / num2;
    return result;
}