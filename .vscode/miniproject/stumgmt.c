

#include <stdio.h>            
#include <string.h>
#include "student.h"

int main() 
{
    Students listStudent[100];
    int lastStudentIndex = 0;
    int choice = 0;

    while (1) 
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 4) 
        {
            break;
        }
        else if (choice == 1) 
        {
            if (lastStudentIndex >= 100) {
                printf("\nDatabase is full! Cannot add more students.\n");
                continue;
            }

            printf("\nEnter Roll No: ");
            scanf("%d", &listStudent[lastStudentIndex].roll);
            
            // Consume trailing newline character from buffer before reading string
            getchar(); 
            printf("Enter Name: ");
            fgets(listStudent[lastStudentIndex].name, sizeof(listStudent[lastStudentIndex].name), stdin);
            listStudent[lastStudentIndex].name[strcspn(listStudent[lastStudentIndex].name, "\n")] = '\0'; // Remove newline character

            printf("\nEnter marks:\n");
            printf("C      : ");
            scanf("%d", &listStudent[lastStudentIndex].Cmarks);
            printf("Java   : ");
            scanf("%d", &listStudent[lastStudentIndex].Javamarks);
            printf("DB     : ");
            scanf("%d", &listStudent[lastStudentIndex].DBmarks);

            // Calculations
            listStudent[lastStudentIndex].total = listStudent[lastStudentIndex].Cmarks + 
                                                 listStudent[lastStudentIndex].Javamarks + 
                                                 listStudent[lastStudentIndex].DBmarks;
            
            listStudent[lastStudentIndex].average = listStudent[lastStudentIndex].total / 3.0;

            // Grade Assignment logic mapping precisely to your table
            if (listStudent[lastStudentIndex].average >= 90) {
                strcpy(listStudent[lastStudentIndex].grade, "A");
            } else if (listStudent[lastStudentIndex].average >= 75) {
                strcpy(listStudent[lastStudentIndex].grade, "B");
            } else if (listStudent[lastStudentIndex].average >= 60) {
                strcpy(listStudent[lastStudentIndex].grade, "C");
            } else if (listStudent[lastStudentIndex].average >= 50) {
                strcpy(listStudent[lastStudentIndex].grade, "D");
            } else {
                strcpy(listStudent[lastStudentIndex].grade, "F");
            }

            printf("\nStudent added successfully!\n");
            lastStudentIndex++;
        }
        else if (choice == 2) 
        {
            if (lastStudentIndex == 0) {
                printf("\nNo student records found.\n");
            } else {
                printf("\n%-11s %-11s %-9s %-10s %-5s\n", "Roll No", "Name", "Total", "Average", "Grade");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < lastStudentIndex; i++) {
                    printf("%-11d %-11s %-9.0f %-10.2f %-5s\n",
                           listStudent[i].roll,
                           listStudent[i].name,
                           listStudent[i].total,
                           listStudent[i].average,
                           listStudent[i].grade);
                }
            }
        }
        else if (choice == 3)
        {
            if (lastStudentIndex == 0) {
                printf("\nNo student records found.\n");
            } else {
                int searchRoll;
                int foundIndex = -1;
                printf("\nEnter Roll No to search: ");
                scanf("%d", &searchRoll);

                for (int i = 0; i < lastStudentIndex; i++) {
                    if (listStudent[i].roll == searchRoll) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    printf("\nStudent Found:\n");
                    printf("--------------------------------------------------\n");
                    printf("Roll No    : %d\n", listStudent[foundIndex].roll);
                    printf("Name       : %s\n", listStudent[foundIndex].name);
                    printf("C Marks    : %d\n", listStudent[foundIndex].Cmarks);
                    printf("Java Marks : %d\n", listStudent[foundIndex].Javamarks);
                    printf("DB Marks   : %d\n", listStudent[foundIndex].DBmarks);
                    printf("Total      : %.0f\n", listStudent[foundIndex].total);
                    printf("Average    : %.2f\n", listStudent[foundIndex].average);
                    printf("Grade      : %s\n", listStudent[foundIndex].grade);
                    printf("--------------------------------------------------\n");
                } else {
                    printf("\nStudent with Roll No %d not found.\n", searchRoll);
                }
            }
        }
        else 
        {
            printf("\nInvalid choice! Please select 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
