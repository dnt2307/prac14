#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"

int main(int argc, char** argv){
    int option = 0;
    personPtr head = NULL;
    while(1){
        printf("---Enrollment Management System---\n");
        printf("[1] Enroll\t [2] List\t [3] Search\t [4] Delete\t [5] Quit\n");
        printf("Selection: ");
        scanf("%d", &option);
        switch(option){
			break;
            case 5:
                break;
            default:
                // selection(&option, &head);
                break;
        }
        if(option == 5){
            printf("Quitting...\n");
            break;
        }
        printf("----------------------------------\n\n");
    }
    return 0;
}
