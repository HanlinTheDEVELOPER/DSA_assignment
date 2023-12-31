//
// Created by hanlin on 12/31/23.
//

#include <stdio.h>
#include <stdlib.h>

void menu();
int login();
int signup();
void logout() ;
        int size_of_arr(char arr[50]);
void copy_two_char_arr(char given[50], char desired[50]);
int compare_size_of_two_arr(char first[30], char second[30]);
int compare_each_index_of_two_arr(char first[30], char second[30]);
void show_login_user_info(int user_id);

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
int g_login_user_id = -1;

int main() {
    menu();
    return 1;
}

void menu() {
    while (1) {
        int option = 0;

        printf("\n<<<<<<<<<< Welcome to our system >>>>>>>>>>\n");
        printf("Press 1 to Sign up:\nPress 2 to Sign in:\nPress 3 to show logged in user info\nPress 4 to logout\n\n");

        printf("Please Enter Your Option: ");
        scanf("%d", &option);
        printf("\n\n");

        switch (option) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                show_login_user_info(g_login_user_id);
                break;
            case 4:
                logout();
                break;
            default:
                exit(-1);
        }
    }
}

int login() {
    char in_email[30];
    char in_password[20];
    int is_success = 0;

    if(g_login_user_id != -1) {
        printf("You have already logged in.\nLog out first to sign in with another account\n");
        return 0;
    }

    if(g_user_count == 0) {
        printf("No entries in the database!! Create a user by signing up first!!\n\n");
        return 0;
    }

    do {
        printf("\n<<<<<<<< Log In >>>>>>>>:\n");
        printf("Enter your email to Login:");
        scanf(" %[^\n]", &in_email[0]);

        printf("Enter your pasword to Login:");
        scanf(" %[^\n]", &in_password[0]);

        int i = 0;
        for (i = 0; i < g_user_count; i++) {
            int emailCheck = compare_each_index_of_two_arr(in_email, data[i].user_email);
            if (emailCheck) {
                int passCheck = compare_each_index_of_two_arr(in_password, data[i].password);
                if (passCheck) {
                    is_success = 1;
                    printf("Successfully logged in to our system!");
                    g_login_user_id = i;
                    show_login_user_info(g_login_user_id);
                    break;
                } else {
                    is_success = 0;
                    printf("Wrong Password!! Try Again!!\n");
                }
            } else {
                is_success = 0;
                printf("Wrong Email!! Try Again!!\n");
            }
        }
    } while (is_success == 0);

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

void logout() {
   if(g_login_user_id == -1) {
       printf("You can't log out if you are not logged in!!!\n");
       return;
   }
       g_login_user_id = -1;
       printf("You have successfully log out");
}

void copy_two_char_arr(char given[50], char desired[50]) {
    int i = 0;
    while (given[i] != '\000' && i < 50) {
        desired[i] = given[i];
        i++;
    }
}

int compare_size_of_two_arr(char first[30], char second[30]) {
    int i = 0;
    int result = 0;
    for (i = 0; i < 30; i++) {
        if (first[i] != '\000' && second[i] != '\000') {
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
    int i = 0;
    for (i = 0; i < 30; i++) {
        if (arr[i] == '\000') {
            break;
        } else {
            size++;
        }
    }
    return size;
}

int compare_each_index_of_two_arr(char first[30], char second[30]) {
    int identical = 0;
    int firstSize = size_of_arr(first);
    int secondSize = size_of_arr(second);
    if (firstSize != secondSize) {
        return 0;
    } else {
        int i = 0;
        for (i = 0; i < firstSize; i++) {
            if (first[i] != second[i]) {
                identical = 0;
                break;
            } else {
                identical = 1;
            }
        }
    }
    return identical;
}

void show_login_user_info(int user_id) {
   if(user_id != -1) {
       printf("UserName: %s\n",data[user_id].user_name);
       printf("Email: %s\n",data[g_login_user_id].user_email);
       printf("Phone Number: %d\n",data[g_login_user_id].phone_number);
       printf("Address: %s\n",data[g_login_user_id].address);
   } else {
       printf("No logged in user found!!\n");
   }
}