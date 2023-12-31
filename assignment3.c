//
// Created by hanlin on 12/31/23.
//

#include <stdio.h>

void menu();
int login();
int signup();
void copy_two_char_arr(char first[50], char second[50]);
int compare_size_of_two_arr(char first[30], char second[30]);

struct User {
    int user_id;
    char user_name[30];
    char user_email[30];
    char password[20];
    int phone_number;
    char address[50];
};

struct User data[5];
int g_user_count = 0;

int main() {
    menu();
    return 1;
}

void menu() {
    while (1) {
        int option = 0;

        printf("\n<<<<<<<<<< Welcome to our system >>>>>>>>>>\n");
        printf("Press 1 to Sign in:\nPress 2 to Sign Up:\nPress 3 to Exit\n");

        printf("Please Enter Your Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                login();
                break;
            case 2:
                signup();
                break;
            case 3:
                printf("exit");
                break;
            default:
                menu();
        }
    }
}

int login() {
    char in_email[30];
    char in_password[20];

    printf("\n<<<<<<<< Registration >>>>>>>>:\n");
    printf("Enter your email to Login:");
    scanf(" %[^\n]", &in_email[0]);

    printf("Enter your pasword to Login:");
    scanf(" %[^\n]", &in_password[0]);

    int s ;
    printf("db mail;   %s\n",data[0].user_email);
    printf("in main; %s",in_email);
    s= compare_size_of_two_arr(in_email,data[0].user_email);
    printf("%d",s);


    return 1;
}

int signup() {
    char in_username[30];
    char in_email[30];
    char in_password[20];
    int in_phone = 0;
    char in_address[50];

    printf("\n<<<<<<<< Registration >>>>>>>>:\n");
    printf("Enter your user name to Register:");
    scanf(" %[^\n]", &in_username[0]);

    printf("Enter your user email to Register:");
    scanf(" %[^\n]", &in_email[0]);

    printf("Enter your user password to Register:");
    scanf(" %[^\n]", &in_password[0]);

    printf("Enter your PhoneNumber to Register:");
    scanf("%d", &in_phone);// NOLINT(*-err34-c)

    printf("Enter your Address to Register:");
    scanf(" %[^\n]", &in_address[0]);

    copy_two_char_arr(in_username, data[g_user_count].user_name);
    copy_two_char_arr(in_email, data[g_user_count].user_email);
    copy_two_char_arr(in_password, data[g_user_count].password);
    copy_two_char_arr(in_address, data[g_user_count].address);
    data[g_user_count].phone_number = in_phone;
    data[g_user_count].user_id = g_user_count;
    g_user_count++;
    return 1;
}

void copy_two_char_arr(char first[50], char second[50]) {
    int i = 0;
    while (first[i] != "\0" && i < 50) {
        second[i] = first[i];
        i++;
    }
}

int compare_size_of_two_arr(char first[30], char second[30]) {
    int i = 0;
    int result = 0;
    for (i = 0; i < 30; i++) {
        if(first[i] != "\0" && second[i] != "\0") {
            result = 1;
        } else {
            result = 0;
          break;
        }
    }

    return result;
}

int size_of_arr(char arr[50]) {
    int size = 0;
    int i =0;
    for (i=0;i<30;i++) {
        if(arr[i] == "\0") {
            break;
        }
        size++;
    }
    return size;
}