#include <stdio.h>
#include <stdlib.h>

struct Hospital
{
    int bed_no;
    char name[30];
    int age;
    char ward[20];
};

void admit()
{
    struct Hospital h;
    FILE *fp = fopen("hospital.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Bed Number: ");
    scanf("%d", &h.bed_no);
    printf("Enter Patient Name: ");
    scanf("%s", h.name);
    printf("Enter Age: ");
    scanf("%d", &h.age);
    printf("Enter Ward (General/ICU): ");
    scanf("%s", h.ward);

    fprintf(fp, "%d %s %d %s\n", h.bed_no, h.name, h.age, h.ward);
    fclose(fp);
    printf("Patient admitted successfully!\n");
}

void viewAll()
{
    struct Hospital h;
    FILE *fp = fopen("hospital.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo record file found!\n");
        return;
    }

    printf("\nBed No\tName\t\tAge\tWard\n");
    printf("\n-----------------------------------\n");

    while (fscanf(fp, "%d %s %d %s", &h.bed_no, h.name, &h.age, h.ward) != EOF)
    {
        printf("%d\t%s\t\t%d\t%s\n", h.bed_no, h.name, h.age, h.ward);
    }

    fclose(fp);
}

void search()
{
    struct Hospital h;
    FILE *fp = fopen("hospital.txt", "r");
    int search_bed, found = 0;

    if (fp == NULL)
    {
        printf("\nNo record file found!\n");
        return;
    }

    printf("\nEnter Bed Number to search: ");
    scanf("%d", &search_bed);

    while (fscanf(fp, "%d %s %d %s", &h.bed_no, h.name, &h.age, h.ward) != EOF)
    {
        if (h.bed_no == search_bed)
        {
            printf("\n--- Patient Found ---\n");
            printf("Bed No   : %d\n", h.bed_no);
            printf("Name     : %s\n", h.name);
            printf("Age      : %d\n", h.age);
            printf("Ward     : %s\n", h.ward);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("No patient found on Bed No %d!\n", search_bed);
    }

    fclose(fp);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n*** HOSPITAL MANAGEMENT ***\n");
        printf("1. Admit Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            admit();
            break;
        case 2:
            viewAll();
            break;
        case 3:
            search();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
