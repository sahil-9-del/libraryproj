#include <stdio.h>
#include <string.h>

struct book_details
{
    int Book_id;
    char author[64];
    char title[64];
    char category[21];
    int total_quantity;
};

int main()
{
    struct book_details d;

    
    
    printf("Enter Author: ");
    gets(d.author);
    printf("Enter Title: ");
    gets(d.title);
    printf("Enter Category: ");
    gets(d.category);
    printf("Enter Book_id: ");
    scanf("%d",&d.Book_id);
    printf("Enter total_quantity: ");
    scanf("%d",&d.total_quantity);

    FILE* ptr = NULL;
    ptr = fopen("book.txt","a");
    
    fprintf(ptr,"%s %s %s %d %d",d.author,d.title,d.category,d.Book_id,d.total_quantity);
    printf("\n");

    fclose(ptr);
   
        
    
    
    
    
    return 0;
}
