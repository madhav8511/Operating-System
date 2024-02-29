#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main() {
    int current_policy, new_policy;
    struct sched_param param;

    // Get the current scheduling policy
    current_policy = sched_getscheduler(0);
    if (current_policy == -1) {
        perror("Error getting scheduling policy");
        return 1;
    }

    printf("Current scheduling policy: ");
    switch (current_policy) {
        case SCHED_FIFO:
            printf("FIFO\n");
            break;
        case SCHED_RR:
            printf("Round Robin\n");
            break;
        case SCHED_OTHER:
            printf("Other (default)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Prompt the user to choose a new scheduling policy
    printf("Choose a new scheduling policy:\n");
    printf("1. SCHED_FIFO\n");
    printf("2. SCHED_RR\n");
    printf("3. SCHED_OTHER\n");
    printf("Enter your choice: ");
    scanf("%d", &new_policy);

    // Modify the scheduling policy to the user's choice
    switch (new_policy) {
        case 1:
            param.sched_priority = sched_get_priority_max(SCHED_FIFO);
            if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
                perror("Error setting scheduling policy");
                return 1;
            }
            printf("Scheduling policy modified to FIFO\n");
            break;
        case 2:
            param.sched_priority = sched_get_priority_max(SCHED_RR);
            if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
                perror("Error setting scheduling policy");
                return 1;
            }
            printf("Scheduling policy modified to Round Robin\n");
            break;
        case 3:
            if (sched_setscheduler(0, SCHED_OTHER, &param) == -1) {
                perror("Error setting scheduling policy");
                return 1;
            }
            printf("Scheduling policy modified to Other (default)\n");
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    return 0;
}
