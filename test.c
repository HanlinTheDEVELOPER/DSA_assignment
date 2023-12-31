/* Week 3 Assigement OF DDSA FROM N1C*/


#include<stdio.h>
#include<stdlib.h>

//declare function
void menu();
void singup();

//structure declare
struct D_B_S{

    char name[30];
    int phone;
    char email[30];
    char password[30];

};

struct D_B_S data[5];


//Main Funcion
int main(){

    menu();

}


//I.Menu Function
void menu(){


    while (1)
    {
        int num = 0;
        printf("\n\n=========== Menu Page ===========\n\n");
        printf("1.Sing Up\n2.Sing In\n3.Exit");
        printf("\n\nInput To Start Program:");
        scanf("%d", &num);

        if (num == 1)
        {
            singup();

        }else if (num == 2)
        {

        }else
        {
            exit(1);
        }



    }


}/*End Of Menu Function*/


//II.Sing Up Function
void singup(){
    char user_name[30];
    int user_phone = 0;
    char user_email[30];
    char user_pass[30];

    printf("\n\n=========== Sing Up Page ==============\n\n");
    printf("Enter Your Name :");
    scanf(" %[^\n]", &user_name);
    printf("Enter Your Phone Number:");
    scanf("%d", &user_phone);
    printf("Enter Your Email: ");
    scanf(" %[\n]", &data[0].email);
    printf("Enter Your Password: ");
    scanf(" %[\n]", &data[0].password);

    printf("\nWellcome %s, have a nice day", user_name);
    printf("%d is your phone number", user_phone);


}//End Of II.Sing Up Function

//II.1.Input Sing Up Data To Database
void sud_2_dbs(){


}