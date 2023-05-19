#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


#define WELCOME_MSG "\nWelcome to the BLK File Management System!\n"
#define CHOOSE_MSG "Choose if you want to create, delete or rename a file! You can also now create directories using the directory input!\n"
#define CREATE_MSG "You have selected creation mode! Type in the file name (.txt) and adress starting at the root folder that you want to create!\n"
#define DIR_CREATE_MSG "You have selected directory creation mode! Type in the dir's adress with it's name starting at the root folder.\n"
#define DELETE_MSG "You have selected deleting mode! Type in the files current adress starting at the root folder and it will be deleted!\n1"
#define RENAME_MSG "You have selected renaming mode! Type in the files current adress starting at the root folder and name and a new name for it!\n"
#define ERR_LEN "UNKNOWN ERROR(0x1) Please contact our support team ar github.com/boouke and provide the memory adress\n"
#define ERR_FILE_CREATE "FILE CREATE ERROR(0x2) Please restart the program, and try again. If you encounter the same problem contact our support team at github.com/boouke\n"

void choose(int* int_operation);
void create(void);
void rename(void);
void dir_create(void);
void file_delete(void);

int main(){
    int int_operation = 0;
    printf("%s", WELCOME_MSG);
    choose(&int_operation);
    if(int_operation == 1){
        create();
        return 0;
    }
    else if(int_operation == 2){
        file_delete();
        return 0;
    }
    else if(int_operation == 3){
        dir_create();
        return 0;
    }
    else if(int_operation == 4){
        rename();
        return 0;
    }
    return 0;
}
void choose(int* int_operation){
    int len = 50;
    char operation[200];
    char* buffer = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", CHOOSE_MSG);
    while (scanf("%s", operation) != 0 && (strcmp(operation, "create") != 0 && strcmp(operation, "delete") != 0 && strcmp(operation, "directory") != 0) && strcmp(operation, "rename") != 0){
        buffer = (char*)realloc(buffer, (strlen(operation) + 1) * sizeof(char));
        printf("%s is not a valid option. Please enter 'create', 'delete' or 'directory':\n", operation);
    }
    if(strcmp(operation, "create") == 0){
        *int_operation = 1;
        free(buffer);
        return;
    }
    else if(strcmp(operation, "delete") == 0){
        *int_operation = 2;
        free(buffer);
        return;
    }
    else if(strcmp(operation, "directory") == 0){
        *int_operation = 3;
        free(buffer);
        return;
    }
    free(buffer);
}
void create(void) {
    int len = 50;
    char* file_name = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", CREATE_MSG);
    while (scanf("%s", file_name) != 1) {
        printf("%s at %p", ERR_LEN, file_name);
    }
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("%s", ERR_FILE_CREATE);
    } else {
        fclose(file);
    }
    free(file_name);
}

void file_delete(void){
    printf("%s", DELETE_MSG);
}
void dir_create(void) {
    int len = 50;
    char* dir_name = (char*)malloc((len + 1) * sizeof(char));
    printf("%s", DIR_CREATE_MSG);
    while (scanf("%s", dir_name) != 1) {
        printf("%s at %p", ERR_LEN, dir_name);
    }
    int creating = mkdir(dir_name, S_IRWXU);
    if(creating == 0){
        printf("Directory created succesfully!\n");
        return;
    }
    else{
        printf("%s", ERR_LEN);
        return;
    }
}

void rename(void){
    printf("%s", RENAME_MSG);
}
