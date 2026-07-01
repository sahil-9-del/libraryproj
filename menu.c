#include <stdio.h>
#include "book.h"
#include "student.h"

int main()
{
    int choice;

    do
    {
        printf("\n1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display Books\n");
        printf("4. Add Student\n");
        printf("5. Search Student\n");
        printf("6. Display Students\n");
        printf("7. Issue Book\n");
        printf("8. Return Book\n");
        printf("9. Exit\n");

        printf("Enter your choice: \n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addbook();
                break;

            case 2:
                searchbook();
                break;

            case 3:
                displaybook();
                break;
            case 4:
                addstudent();
                break;
            case 5:
                searchstudent();
                break;
            case 6:
                displaystudent();
                break;
            case 7:
                issuebook();
                break;
            case 8:  
                returnbook();
                break; 
            case 9:
                break;

        }

    } while(choice != 9);

    return 0;
}