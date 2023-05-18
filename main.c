#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WELCOME_MSG "\nWelcome to the BLK File Management System!\n"
#define CHOOSE_MSG "Choose if you want to create, delete or rename a file!\n"
#define CREATE_MSG ""

void choose(int* int_operation);

int main(){
    int int_operation = 0;
    printf("%s", WELCOME_MSG);
    choose(&int_operation);
    return 0;
}
void choose(int* int_operation){
    int len = 50;
    char operation[200];
    char* buffer = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", CHOOSE_MSG);
    while (scanf("%s", operation) != 0 && (strcmp(operation, "create") != 0 && strcmp(operation, "delete") != 0)) {
        buffer = (char*)realloc(buffer, (strlen(operation) + 1) * sizeof(char));
        printf("%s is not a valid option. Please enter 'create' or 'delete':\n", operation);
    }
    if(strcmp(operation, "create") == 0){
        *int_operation = 1;
    }
    else if(strcmp(operation, "delete") == 0){
        *int_operation = 2;
    }
    free(buffer);
}
void create(int* int_operation){
    
    FILE* file = fopen("")
}