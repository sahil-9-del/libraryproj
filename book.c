#include <stdio.h>
#include <string.h>
#include "book.h"

struct book_details
{
    int Book_id;
    char author[64];
    char title[64];
    char category[21];
    int total_quantity;
    int available_quantity;
};
struct student_details
{
    int student_id;
    char student_name[64];
    char course[64];
    char institution[21];
    char contact[11];
    int book_issued;
    int issuedbookids[5];
};
struct book_details d;
void addbook() // addbook()
{
    
    printf("Enter Author: ");
    getchar();
    gets(d.author);
    printf("Enter Title: ");
    gets(d.title);
    printf("Enter Category: ");
    gets(d.category);
    printf("Enter Book_id: ");
    scanf("%d", &d.Book_id);
    printf("Enter total_quantity: ");
    scanf("%d", &d.total_quantity);
    d.available_quantity = d.total_quantity;

    FILE *ptr = fopen("data.bin", "ab");
    if (ptr == NULL)
    {
        printf("File not found");
    }
    fwrite(&d, sizeof(struct book_details), 1, ptr);
    fclose(ptr);
}
void searchbook() // searchbook()
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
        printf("book id: %d\nAuthor: %s\nTitle: %s\nCategory: %s\ntotal quantity: %d\nAvailable quantity: %d", s1.Book_id, s1.author, s1.title, s1.category, s1.total_quantity, s1.available_quantity);
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
        printf("book id: %d\nAuthor: %s\nTitle: %s\nCategory: %s\ntotal quantity: %d\nAvailable quantity: %d\n", s1.Book_id, s1.author, s1.title, s1.category, s1.total_quantity, s1.available_quantity);
        count++;
        printf("---------------------------\n");
    }
    if (count == 0)
    {
        printf("The library was empty");
    }
    fclose(ptr);
}
void issuebook() // issue book()
{
    int a, b;
    printf("Enter the Book ID:\n");
    scanf("%d", &a);
    printf("Enter the Student ID\n");
    scanf("%d", &b);
    struct book_details s2;
    struct student_details s3;
    FILE *ptr = fopen("data.bin", "rb+");
    if (ptr == NULL)
    {
        printf("Book file not found");
        return;
    }
    FILE *fp = fopen("student.bin", "rb+");
    if (fp == NULL)
    {
        printf("Student file not found");
        return;
    }
    while (fread(&s3, sizeof(struct student_details), 1, fp))
    {
        if (s3.student_id == b)
        {
            if (s3.book_issued == 5)
            {
                printf("Already issued 5 books");
                fclose(ptr);
                fclose(fp);
                return;
            }
            break;
        }
    }

    if (s3.student_id != b)
    {
        printf("Student not found");
        fclose(ptr);
        fclose(fp);
        return;
    }

    while (fread(&s2, sizeof(struct book_details), 1, ptr))
    {

        if (s2.Book_id == a)

        {

            if (s2.available_quantity <= 0)
            {
                printf("Book is not available");
                fclose(ptr);
                fclose(fp);
                return;
            }
            break;
        }
    }

    if (s2.Book_id == a)
    {
        if (s2.available_quantity > 0)
        {
            s2.available_quantity--;
            fseek(ptr, -sizeof(struct book_details), SEEK_CUR);
            fwrite(&s2, sizeof(struct book_details), 1, ptr);
        }
    }
    else
    {
        printf("Book not found");
        fclose(ptr);
        fclose(fp);
        return;
    }
    if (s3.student_id == b)
    {

        s3.issuedbookids[s3.book_issued] = a;
        s3.book_issued++;
        fseek(fp, -sizeof(struct student_details), SEEK_CUR);
        fwrite(&s3, sizeof(struct student_details), 1, fp);
        printf("Book issued successfully");
    }

    fclose(ptr);
    fclose(fp);
}
void returnbook()
{
    int a, b,q=0;
    printf("Enter the Student ID\n");
    scanf("%d", &b);
    struct book_details s2;
    struct student_details s3;
     FILE *ptr = fopen("data.bin", "rb+");
    if (ptr == NULL)
    {
        printf("Book file not found");
        return;
    }
    FILE *fp = fopen("student.bin", "rb+");
    if (fp == NULL)
    {
        printf("Student file not found");
        return;
    }
     while (fread(&s3, sizeof(struct student_details), 1, fp))
    {
        if (s3.student_id == b)
        {
            break;
        }  
    }
    if (s3.student_id!=b)
    {
        printf("Student ID doesnot exist");
        fclose(fp);
        fclose(ptr);
        return;
    }
    
   for (int i = 0; i < s3.book_issued; i++)
            {
                printf("%d\n",s3.issuedbookids[i]);
            }
    printf("Enter the Book ID to return: \n");    
    scanf("%d",&a);
    for (int i = 0; i < s3.book_issued; i++)
    {
        if (s3.issuedbookids[i]==a)
        {
            printf("Book ID exists");
            s3.issuedbookids[i]=0; // issue with the array display
            s3.book_issued--;
            fseek(fp, -sizeof(struct student_details), SEEK_CUR);
            fwrite(&s3, sizeof(struct student_details), 1, fp);
            q=4;
            break;
        } 
    }
    if (q==0)
    {
        printf("Book ID doesnot exist");
        fclose(ptr);
        fclose(fp);
        return;
    }
    
    
    
    
    while (fread(&s2, sizeof(struct book_details), 1, ptr))
    {

        if (s2.Book_id == a)
        {
            break;
        }
    } 
    if (s2.Book_id==a)
    {
        s2.available_quantity++;
        fseek(ptr, -sizeof(struct book_details), SEEK_CUR);
        fwrite(&s2, sizeof(struct book_details), 1, ptr);
        printf("Book returned successfully");     
    }
    fclose(ptr);
    fclose(fp);   
    
    

    
}

