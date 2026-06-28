#include <stdio.h>
#include <string.h>

struct book_details
{
    int Book_id;
    char author[64];
    char title[64];
    char category[21];
    int total_quantity;
    int available_quantity;
};
struct book_details d;
void addbook() //addbook()
{
    printf("Enter Author: ");
    gets(d.author);
    printf("Enter Title: ");
    gets(d.title);
    printf("Enter Category: ");
    gets(d.category);
    printf("Enter Book_id: ");
    scanf("%d", &d.Book_id);
    printf("Enter total_quantity: ");
    scanf("%d", &d.total_quantity);
    d.available_quantity=d.total_quantity;

    FILE *ptr = fopen("data.bin", "ab");
    if (ptr == NULL)
    {
        printf("File not found");
    }
    fwrite(&d, sizeof(struct book_details), 1, ptr);
    fclose(ptr);
}    
    void searchbook() //searchbook()
    {
        int book_id;
        printf("Enter the book id:\n");
        scanf("%d", &book_id);
        struct book_details s1;
        FILE *ptr = fopen("data.bin", "rb");
        if (ptr == NULL)
        {
            printf("File not found");
            return;
        }

        while (fread(&s1, sizeof(struct book_details), 1, ptr))
        {

            if (s1.Book_id == book_id)

            {
                break;
            }
        }

        if (s1.Book_id == book_id)
        {
            printf("book id: %d\nAuthor: %s\nTitle: %s\nCategory: %s\ntotal quantity: %d\nAvailable quantity: %d", s1.Book_id, s1.author, s1.title, s1.category, s1.total_quantity,s1.available_quantity);
        }
        else
        {
            printf("Book not found");
        }

        fclose(ptr);
    }
    void displaybook() // display book()
    {
        struct book_details s1;
        FILE *ptr = fopen("data.bin", "rb");
        if (ptr == NULL)
        {
            printf("File not found");
            return;
        }
        int count = 0;
        while (fread(&s1, sizeof(struct book_details), 1, ptr))
        {
            printf("book id: %d\nAuthor: %s\nTitle: %s\nCategory: %s\ntotal quantity: %d\nAvailable quantity: %d\n", s1.Book_id, s1.author, s1.title, s1.category, s1.total_quantity,s1.available_quantity);
            count++;
            printf("---------------------------\n");
        }
        if (count == 0)
        {
            printf("The library was empty");
        }
        fclose(ptr);
    }
    void issuebook()
    {
        int a,b;
        printf("Enter the book id");
        scanf("%d",&a);
        printf("Enter the student id");
        scanf("%d",&b);
        struct book_details s2;
        FILE*ptr = fopen("data.bin", "rb+");
        if (ptr==NULL)
        {
            printf("File not found");
            return;
        }
        while (fread(&s2, sizeof(struct book_details), 1, ptr))
        {

            if (s2.Book_id == a)

            {
                if (s2.available_quantity>0)
                {
                    s2.available_quantity--;
                    fseek(ptr,-sizeof(struct book_details),SEEK_CUR);
                    fwrite(&s2,sizeof(struct book_details),1,ptr);
                    printf("Book issued successfully");
                    break;
                }
                else{
                    printf("Book is not available");
                    break;
                }
            }
        if (s2.Book_id==a)
        {
            
        }
        else{
            printf("Book not found");
        }
            
            
        }
        
    }
    

    

