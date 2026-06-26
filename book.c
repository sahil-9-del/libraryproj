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
{   struct book_details d;
    int a;
    printf("Enter 1 to add book details\nEnter 2 to search a book\n");
    scanf("%d",&a);
    getchar();
    if (a==1)
    {
        
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

        FILE* ptr = fopen("data.bin", "ab");
        if (ptr==NULL)
        {
            printf("File not found");
        }
        fwrite(&d,sizeof(struct book_details),1,ptr);
        fclose(ptr);    
    }
    else if (a==2)
    {
        int book_id;
        printf("Enter the book id");
        scanf("%d",&book_id);
        struct book_details s1;
         FILE* ptr = fopen("data.bin", "rb");
        if (ptr==NULL)
        {
            printf("File not found");
        }
        fread(&s1,sizeof(struct book_details),1,ptr);
        while (book_id!=s1.Book_id)
        {
            
            if (s1.Book_id == book_id)
            
            {
                printf("book id: %d\nAuthor: %s\nTitle: %s\nCategory: %stotal quantity: %d",s1.Book_id,s1.author,s1.title,s1.category,s1.total_quantity);
            }
            
        }
        fclose(ptr);
        

    }
    
    
    
    
    
    
    
    
    

    
    
    
    
    

   
   
    
    
    
    
    
    return 0;
}
