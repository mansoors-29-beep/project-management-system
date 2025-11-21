#include <stdio.h>

struct Task {
    int id;         // Task ID
    int priority;   // 1 to 5
    int status;     // 0 = Pending, 1 = Completed
    int progress;   // 0 to 100
    int day, month, year;   // Deadline
};

int main() {
    struct Task tasks[100];
    int count = 0, choice, id, i;

    while (1) {
        printf("\n==== PROJECT MANAGEMENT SYSTEM (NO STRINGS) ====\n");
        printf("1. Add Task\n");
        printf("2. View All Tasks\n");
        printf("3. Update Task Status\n");
        printf("4. Update Task Progress\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        // ---------------------------------------------
        // 1. Add Task
        // ---------------------------------------------
        case 1:
            printf("\nEnter Task ID: ");
            scanf("%d", &tasks[count].id);

            printf("Enter Priority (1–5): ");
            scanf("%d", &tasks[count].priority);

            printf("Enter Deadline (day month year): ");
            scanf("%d %d %d", &tasks[count].day, &tasks[count].month, &tasks[count].year);

            tasks[count].status = 0;      // Pending
            tasks[count].progress = 0;    // Not started

            count++;
            printf("Task Added Successfully!\n");
            break;


        // ---------------------------------------------
        // 2. View All Tasks
        // ---------------------------------------------
        case 2:
            printf("\n--- TASK LIST ---\n");
            for (i = 0; i < count; i++) {
                printf("ID: %d | Priority: %d | Deadline: %02d-%02d-%04d | Progress: %d%% | Status: %s\n",
                       tasks[i].id,
                       tasks[i].priority,
                       tasks[i].day, tasks[i].month, tasks[i].year,
                       tasks[i].progress,
                       tasks[i].status == 0 ? "Pending" : "Completed");
            }
            break;


        // ---------------------------------------------
        // 3. Update Task Status
        // ---------------------------------------------
        case 3:
            printf("\nEnter Task ID to update status: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++) {
                if (tasks[i].id == id) {
                    printf("Enter status (0 = Pending, 1 = Completed): ");
                    scanf("%d", &tasks[i].status);
                    printf("Status Updated!\n");
                    break;
                }
            }
            if (i == count)
                printf("Task Not Found!\n");
            break;


        // ---------------------------------------------
        // 4. Update Task Progress
        // ---------------------------------------------
        case 4:
            printf("\nEnter Task ID to update progress: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++) {
                if (tasks[i].id == id) {
                    printf("Enter new progress (0–100): ");
                    scanf("%d", &tasks[i].progress);
                    printf("Progress Updated!\n");
                    break;
                }
            }
            if (i == count)
                printf("Task Not Found!\n");
            break;


        // ---------------------------------------------
        // 5. Exit
        // ---------------------------------------------
        case 5:
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
