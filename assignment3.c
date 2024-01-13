//
// Created by hanlin on 12/31/23.
//

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

void menu();
int login();
int signup();
int logout();
int size_of_arr(char arr[50]);
void copy_two_char_arr(char given[50], char desired[50]);
int compare_each_index_of_two_arr(char first[30], char second[30]);
int show_login_user_info(int user_id);
int check_is_password_stron(char password[20]);
int after_login_option();

struct User {
    int user_id;
    char user_name[30];
    char user_email[30];
    char password[20];
    int phone_number;
    char address[50];
    int coins;
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
        printf("Press 1 to Sign up:\nPress 2 to Sign in:\n\n");

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
            default:
                exit(-1);
        }
    }
}

int login() {
    char in_email[30];
    char in_password[20];
    int is_success = 0;

    if (g_login_user_id != -1) {
        printf("You have already logged in.\nLog out first to sign in with another account\n");
        return 0;
    }

    if (g_user_count == 0) {
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
                    printf("Successfully logged in to our system!\n");
                    g_login_user_id = i;
                    after_login_option();
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
    if (g_user_count < 5) {
        char in_username[30];
        char in_email[30];
        char in_password[20];
        int in_phone = 0;
        char in_address[50];
        int is_email_unique = 0;
        int is_password_strong = 0;

        printf("\n<<<<<<<< Registration >>>>>>>>:\n");
        printf("Enter your user name to Register:");
        scanf(" %[^\n]", &in_username[0]);

        do {
            printf("Enter your user email to Register:");
            scanf(" %[^\n]", &in_email[0]);
            int i = 0;
            for (i = 0; i <= g_user_count; i++) {
                int emailCheck = compare_each_index_of_two_arr(in_email, data[i].user_email);
                if (emailCheck) {
                    printf("Email already used!!!\n");
                    break;
                } else {
                    is_email_unique = 1;
                }
            }
        } while (is_email_unique == 0);

        do {
            printf("\nPassword must be at least EIGHT LETTERS )\n(Password must include at least ONE CAPTIAL LETTER,ONE SPECIAL CHARACTER and ONE NUMBER,\n");
            printf("Enter your user password to Register:");
            scanf(" %[^\n]", &in_password[0]);
            int is_strong = check_is_password_stron(in_password);
            if (is_strong == 1) {
                is_password_strong = 1;
            }


        } while (is_password_strong == 0);

        printf("Enter your PhoneNumber to Register:");
        scanf("%d", &in_phone);// NOLINT(*-err34-c)

        printf("Enter your Address to Register:");
        scanf(" %[^\n]", &in_address[0]);

        copy_two_char_arr(in_username, data[g_user_count].user_name);
        copy_two_char_arr(in_email, data[g_user_count].user_email);
        copy_two_char_arr(in_password, data[g_user_count].password);
        copy_two_char_arr(in_address, data[g_user_count].address);
        data[g_user_count].phone_number = in_phone;
        data[g_user_count].coins = 500;
        data[g_user_count].user_id = g_user_count;
        g_user_count++;
        return 1;
    } else {
        printf("No more room for another user");
        return 1;
    }
}

int logout() {
    //    if (g_login_user_id == -1) {
    //        printf("You can't log out if you are not logged in!!!\n");
    //        return 1;
    //    }
    g_login_user_id = -1;
    printf("You have successfully log out");
    return 1;
}

void copy_two_char_arr(char given[50], char desired[50]) {
    int i = 0;
    while (given[i] != '\000' && i < 50) {
        desired[i] = given[i];
        i++;
    }
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

int show_login_user_info(int user_id) {
    if (user_id != -1) {
        printf("UserName: %s\n", data[user_id].user_name);
        printf("Email: %s\n", data[g_login_user_id].user_email);
        printf("Phone Number: %d\n", data[g_login_user_id].phone_number);
        printf("Address: %s\n", data[g_login_user_id].address);
        printf("Total coins: %d\n", data[g_login_user_id].coins);
    } else {
        printf("No logged in user found!!\n");
    }
    return 1;
}

int check_is_password_stron(char password[20]) {
    int is_valid = 0;
    char special_char[9] = {'!', '@', '#', '$', '%', '^', '&', '*', '?'};
    int is_capital_include = 0;
    int is_num_include = 0;
    int is_special_include = 0;

    if (size_of_arr(password) < 8) {
        is_valid = 0;
    } else {
        int i = 0;
        // add 1 to size of password so that if number or capital letter is in the last index it won't failed!
        for (i = 0; i < size_of_arr(password) + 1; i++) {
            //check if all of validation pass and break from the outer loop;
            if (is_special_include == 1 && is_num_include == 1 && is_capital_include == 1) {
                is_valid = 1;
                printf("isvalid %d\n", is_valid);
                break;
            } else {
                //checking if the given password include at least one capital letter
                // in ASCII Table , A is 65 and Z is 90
                if (is_capital_include == 0) {
                    if (password[i] > 64 && password[i] < 91) {
                        is_capital_include = 1;
                        continue;
                    }
                }
                //checking if the given password include as least one number
                //in ASCII Table , 0 is 48 && 9 is 57
                if (is_num_include == 0) {
                    if (password[i] > 47 && password[i] < 58) {
                        is_num_include = 1;
                        continue;
                    }
                }
                //checking if the given password include as least one special char
                if (is_special_include == 0) {
                    int j = 0;
                    for (j = 0; j < size_of_arr(special_char); j++) {
                        if (password[i] == special_char[j]) {
                            is_special_include = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("is valid %d", is_valid);
    printf("is capital %d", is_capital_include);
    printf("is special %d", is_special_include);
    printf("is num %d\n", is_num_include);
    return is_valid;
}

int after_login_option() {

    while (1) {
        int opt = 0;
        printf("Press 1 to view account info!\nPress 2 to transfer ASM Coins!\nPress 3 to logout!\n");
        printf("Please enter your option : ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                show_login_user_info(g_login_user_id);
                break;
            case 2:
                break;
            case 3:
                logout();
                return 1;
                break;
            default:
                exit(-1);
        }
    }
}

int transfer_conis() {
    return 1;
}