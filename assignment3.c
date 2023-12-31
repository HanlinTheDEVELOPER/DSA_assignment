//
// Created by hanlin on 12/31/23.
//

#include <stdio.h>

void menu();
int login();
int signup();

struct User {
    int user_id;
    char user_name[30];
    char user_email[30];
    char password[20];
    int phone_number;
    char address[50];
};

struct User data[5];

int main() {
    menu();
    return 1;
}

void menu() {
    while (1) {
        int option = 0;
        printf("_________________Welcome to our system_________________\n");
        printf("Press 1 to Sign in:\nPress 2 to Sign Up:\nPress 3 to Exit\n");
        printf("Please Enter Your Option: ");
        scanf("%d",&option);

        switch (option) {
            case 1:
                printf("Login");
                break;
            case 2:
                printf("Sign Up");
                break;
            case 3:
                printf("exit");
                break;
            default:
              menu();
        }
    }
}

int login () {
    return 1;
}

int signup() {
    char in_username[30];
    char in_email[30];
    char in_password[20];
    int in_phone=0;
    char in_address[50];

    printf("This is Registration Option:\n");
    printf("Enter your user name to Register:");
    scanf(" %[^\n]",&in_username[0]);

    printf("Enter your user email to Register:");
    scanf(" %[^\n]",&in_email[0]);

    printf("Enter your user password to Register:");
    scanf(" %[^\n]",&in_password[0]);

    printf("Enter your PhoneNumber to Register:");
    scanf("%d",&in_phone); // NOLINT(*-err34-c)

    printf("Enter your Address to Register:");
    scanf(" %[^\n]",&in_address[0]);

}