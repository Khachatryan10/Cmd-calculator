#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char calculation_types[4][16] = {"Addition", "Divison", "Multiplication", "Subtraction"};

int calculate_num(char calc_type[], int num1, int num2)
{    
    int result;

    if (strcmp(calc_type, "A") == 0)
    {
        result = num1 + num2;
        printf("%s %d \n", "Result:", result);
        printf("\n");
        return 0;
    }

    else if (strcmp(calc_type, "B") == 0)
    {
        result = num1 / num2;
        printf("%s %d \n", "Result:", result);
        printf("\n");
        return 0;
    }

    else if (strcmp(calc_type, "C") == 0)
    {
        result = num1 * num2;
        printf("%s %d \n", "Result:", result);
        printf("\n");
        return 0;
    }

    else if (strcmp(calc_type, "D") == 0)
    {
        result = num1 - num2;
        printf("%s %d \n", "Result:", result);
        printf("\n");
        return 0;
    }

}

int first_num;
int second_num;

int ask_num1(){
    printf("%s", "First Number: ");
    scanf("%d", &first_num);  
}

int ask_num2(){
    printf("%s", "Second Number: ");
    scanf("%d", &second_num) ;
}

int ask(){
    char choice[256];
    printf("Type your choice: ");
    fgets(choice, 256, stdin);
    printf("\n");

    choice[strcspn(choice, "\n")] = '\0';
    
    if (choice[0] == 'a'){
        choice[0] = 'A';
    }

    else if (choice[0] == 'b'){
        choice[0] = 'B';
    }

    else if (choice[0] == 'c'){
        choice[0] = 'C';
    }

    else if (choice[0] == 'd'){
        choice[0] = 'D';
    }

    if (strcmp(choice, "A") == 0 || strcmp(choice, "B") == 0 || strcmp(choice, "C") == 0 || strcmp(choice, "D") == 0){
        
        while (ask_num1() != 1){
            printf("Invalid character \n");
            return 1;
        }

        while (ask_num2() != 1){
            printf("Invalid character \n");
            return 1;
        }

        calculate_num(choice, first_num, second_num);
    }

    else
    {
        printf("Please provide a valid answer e.g. A, B \n");
        ask();
        return 1;
    }    
}

int main(){
    printf("\n");
    printf("%s %s \n", "A:", calculation_types[0]);
    printf("%s %s \n", "B:", calculation_types[1]);
    printf("%s %s \n", "C:", calculation_types[2]);
    printf("%s %s \n", "D:", calculation_types[3]);
    printf("\n");
    ask();
    return 0;
}
