#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 128
#define MAX_DATE 64
#define MAX_EMAIL_ADDRESS 128

// Employee structure
typedef struct employee_data {
    int employeeId;
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    char middleName[MAX_NAME];
    char emailAddress[MAX_EMAIL_ADDRESS];
    char title[MAX_EMAIL_ADDRESS];
    float annualSalary;
    char dateOfHire[MAX_DATE];
    struct employee_data *pNext;
} Employee;

Employee *head = NULL; // Start of the linked list

// Insert new employee
void insertEmployee(Employee *newEmp) {
    Employee **current = &head;
    while (*current && (*current)->employeeId < newEmp->employeeId)
        current = &(*current)->pNext;
    newEmp->pNext = *current;
    *current = newEmp;
}

// employee by ID
void displayEmployee(int id) {
    Employee *current = head;
    while (current) {
        if (current->employeeId == id) {
            printf("ID: %d\nName: %s %s\nSalary: %.2f\n", current->employeeId, current->firstName, current->lastName, current->annualSalary);
            return;
        }
        current = current->pNext;
    }
    printf("Employee not found.\n");
}

// edit the salary of a specific employee
void editSalary(int id, float newSalary) {
    Employee *current = head;
    while (current) {
        if (current->employeeId == id) {
            current->annualSalary = newSalary;
            printf("Salary updated.\n");
            return;
        }
        current = current->pNext;
    }
    printf("Employee not found.\n");
}

// Remove an employee by ID
void removeEmployee(int id) {
    Employee **current = &head;
    while (*current) {
        if ((*current)->employeeId == id) {
            Employee *temp = *current;
            *current = (*current)->pNext;
            free(temp);
            printf("Employee removed.\n");
            return;
        }
        current = &(*current)->pNext;
    }
    printf("Employee not found.\n");
}

// List all employees
void listEmployees() {
    Employee *current = head;
    while (current) {
        printf("ID: %d, Name: %s %s, Salary: %.2f\n", current->employeeId, current->firstName, current->lastName, current->annualSalary);
        current = current->pNext;
    }
}

int main() {
    FILE *file = fopen("EmployeeRecords.bin", "rb"); // Open binary file
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    Employee temp;
    // Read records from file
    while (fread(&temp, sizeof(Employee) - sizeof(Employee *), 1, file)) {
        Employee *newEmp = malloc(sizeof(Employee)); // allocate memory
        memcpy(newEmp, &temp, sizeof(Employee) - sizeof(Employee *));
        newEmp->pNext = NULL;
        insertEmployee(newEmp);
    }
    fclose(file);

    int choice, id;
    float newSalary;

    // Menu loop
    while (1) {
        printf("1) Display Employee\n2) Edit Employee Salary\n3) Remove Employee\n4) List All Employees\n5) Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                displayEmployee(id);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter new salary: ");
                scanf("%f", &newSalary);
                editSalary(id, newSalary);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                removeEmployee(id);
                break;
            case 4:
                listEmployees();
                break;
            case 5:
                return 0; // Exit program
            default:
                printf("Invalid choice.\n");
        }
    }
}

