#include <stdio.h>
#include <string.h>

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

int main()
{
    struct student_details d;
    int a;
    printf("Enter 1 to add student details\nEnter 2 to search a student\nEnter 3 to display all students\n");
    scanf("%d", &a);
    getchar();
    if (a == 1)
    {

        printf("Enter student_name: ");
        gets(d.student_name);
        printf("Enter course: ");
        gets(d.course);
        printf("Enter institution: ");
        gets(d.institution);
        printf("Enter contact no: ");
        gets(d.contact);
        printf("Enter student_id: ");
        scanf("%d", &d.student_id);
        printf("Enter book_issued: ");
        scanf("%d", &d.book_issued);
        if (d.book_issued>=0 && d.book_issued<=5)
        {
           for (int i = 0; i < d.book_issued; i++)
           {
            printf("Enter book id: %d\n",i+1);
            scanf("%d",&d.issuedbookids[i]);
           }
           
        }
        else 
        {
            printf("Invalid input\nMaximum books allowed per student is 5.\nStudent record not saved\n");
            return 0;
        }
        
        

        FILE *ptr = fopen("student.bin", "ab");
        if (ptr == NULL)
        {
            printf("Unable to open student file");
        }
        fwrite(&d, sizeof(struct student_details), 1, ptr);
        fclose(ptr);
    }
    else if (a == 2)
    {
        int student_id;
        printf("Enter the Student id:\n");
        scanf("%d", &student_id);
        struct student_details s1;
        FILE *ptr = fopen("student.bin", "rb");
        if (ptr == NULL)
        {
            printf("Unable to open student file");
            return 0;
        }

        while (fread(&s1, sizeof(struct student_details), 1, ptr))
        {

            if (s1.student_id == student_id)

            {
                break;
            }
        }

        if (s1.student_id == student_id)
        {
            printf("student id: %d\nstudent_name: %s\ncontact no: %s\ncourse: %s\ninstitution: %s\nbook issued: %d", s1.student_id, s1.student_name,s1.contact, s1.course, s1.institution, s1.book_issued);
        }
        else
        {
            printf("Student not found");
        }

        fclose(ptr);
    }
    else if (a == 3)
    {
        struct student_details s1;
        FILE *ptr = fopen("student.bin", "rb");
        if (ptr == NULL)
        {
            printf("Student not found");
            return 0;
        }
        int count = 0;
        while (fread(&s1, sizeof(struct student_details), 1, ptr))
        {
            printf("student id: %d\nstudent_name: %s\ncontact no: %s\ncourse: %s\ninstitution: %s\nbook issued: %d\n", s1.student_id, s1.student_name,s1.contact, s1.course, s1.institution, s1.book_issued);
            count++;
            printf("---------------------------\n");
        }
        if (count == 0)
        {
            printf("No student registered");
        }
    }

    return 0;
}
