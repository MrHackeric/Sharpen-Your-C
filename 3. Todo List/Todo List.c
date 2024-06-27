#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of tasks
#define MAX_TASKS 100
// Maximum length of a task description
#define MAX_DESC_LENGTH 100

// Task structure
typedef struct {
    char description[MAX_DESC_LENGTH];
    int completed;
} Task;

// Array to store tasks
Task tasks[MAX_TASKS];
int task_count = 0;

// Function prototypes
void addTask();
void viewTasks();
void completeTask();
void deleteTask();
void printMenu();

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to print the menu
void printMenu() {
    printf("\nTo-Do List Menu:\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Complete Task\n");
    printf("4. Delete Task\n");
    printf("5. Exit\n");
}

// Function to add a new task
void addTask() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter task description: ");
    fgets(tasks[task_count].description, MAX_DESC_LENGTH, stdin);
    tasks[task_count].description[strcspn(tasks[task_count].description, "\n")] = '\0'; // Remove newline character
    tasks[task_count].completed = 0;
    task_count++;
    printf("Task added!\n");
}

// Function to view all tasks
void viewTasks() {
    if (task_count == 0) {
        printf("No tasks to display.\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].description);
    }
}

// Function to mark a task as completed
void completeTask() {
    int task_number;

    if (task_count == 0) {
        printf("No tasks to complete.\n");
        return;
    }

    printf("Enter the task number to complete: ");
    scanf("%d", &task_number);
    getchar(); // Consume the newline character left by scanf

    if (task_number < 1 || task_number > task_count) {
        printf("Invalid task number.\n");
        return;
    }

    tasks[task_number - 1].completed = 1;
    printf("Task %d marked as completed.\n", task_number);
}

// Function to delete a task
void deleteTask() {
    int task_number;

    if (task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    printf("Enter the task number to delete: ");
    scanf("%d", &task_number);
    getchar(); // Consume the newline character left by scanf

    if (task_number < 1 || task_number > task_count) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = task_number - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
    printf("Task %d deleted.\n", task_number);
}

/*
Explanation of the Code:

1. Task Structure:
The `Task` struct contains a description of the task and a completed status.

2. Global Variables:
`tasks` is an array that stores all the tasks.
`task_count` keeps track of the number of tasks.

3. printMenu Function:
Prints the menu options for the user.

4. addTask Function:
Prompts the user to enter a task description.
Adds the new task to the `tasks` array.

5. viewTasks Function:
Displays all tasks, indicating whether each task is completed or not.

6. completeTask Function:
Prompts the user to enter the task number to mark as completed.
Updates the task's status to completed.

7. deleteTask Function:
Prompts the user to enter the task number to delete.
Removes the task from the `tasks` array by shifting subsequent tasks.

8. Main Function:
Displays the menu, takes the user's choice, and calls the appropriate function based on the choice.
*/
