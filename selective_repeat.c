#include <stdio.h>

int main() {
    int windowsize, sent = 0, ack, i, c;
    printf("Enter window size: ");
    scanf("%d", &windowsize);

    while (1) {
        for (i = 0; i < windowsize; i++) {
            if (sent >= windowsize) {
                break;
            }
            printf("Frame %d transmitted\n", sent);
            sent++;
        }

        printf("\nPlease enter your choice:\n 1. Enter Acknowledgement\n 2. Exit\n");
        scanf("%d", &c);

        if (c == 1) {
            int ack1;
            printf("Enter the frame number for acknowledgement: ");
            scanf("%d", &ack);

            if (ack < 0 || ack >= windowsize) {
                printf("Invalid acknowledgement frame number\n");
                continue;
            }

            if (ack < sent) {
                printf("Frame %d is already received\n", ack);
            } else {
                printf("Frame %d is acknowledged\n", ack);
            }

            if (ack == windowsize - 1) {
                printf("All frames have been acknowledged\n");
                break;
            }
        } else if (c == 2) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice, please enter 1 or 2\n");
        }
    }

    return 0;
}
