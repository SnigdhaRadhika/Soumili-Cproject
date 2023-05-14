#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    int id;
    int age;
    char department[50];
};

void addEmployee(struct employee *employees, int *count);
void displayEmployees(struct employee *employees, int count);
void searchEmployee(struct employee *employees, int count, int id);
void deleteEmployee(struct employee *employees, int *count, int id);

int main() {
    struct employee employees[100];
    int count = 0;
    int choice, id;

    do {
        printf("\n1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                searchEmployee(employees, count, id);
                break;
            case 4:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(employees, &count, id);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}

void addEmployee(struct employee *employees, int *count) {
    struct employee newEmployee;

    printf("Enter name: ");
    scanf("%s", newEmployee.name);

    printf("Enter ID: ");
    scanf("%d", &newEmployee.id);

    printf("Enter age: ");
    scanf("%d", &newEmployee.age);

    printf("Enter department: ");
    scanf("%s", newEmployee.department);

    employees[*count] = newEmployee;
    (*count)++;

    printf("Employee added successfully.\n");
}

void displayEmployees(struct employee *employees, int count) {
    if(count == 0) {
        printf("No employees to display.\n");
    } else {
        printf("Name\tID\tAge\tDepartment\n");

        for(int i = 0; i < count; i++) {
            printf("%s\t%d\t%d\t%s\n", employees[i].name, employees[i].id, employees[i].age, employees[i].department);
        }
    }
}

void searchEmployee(struct employee *employees, int count, int id) {
    for(int i = 0; i < count; i++) {
        if(employees[i].id == id) {
            printf("Name: %s\n", employees[i].name);
            printf("ID: %d\n", employees[i].id);
            printf("Age: %d\n", employees[i].age);
            printf("Department: %s\n", employees[i].department);
            return;
        }
    }

    printf("Employee with ID %d not found.\n", id);
}

void deleteEmployee(struct employee *employees, int *count, int id) {
    int found = 0;

    for(int i = 0; i < *count; i++) {
        if(employees[i].id == id) {
            found = 1;

            for(int j = i; j < (*count)-1; j++) {
                employees[j] = employees[j+1];
            }

            (*count)--;
            break;
        }
    }
}
