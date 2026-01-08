#include <stdio.h>
#include <string.h>

#define AVAILABLE 0
#define BOOKED 1
#define MAX_FILENAME 100
#define MAX_NAME 50
#define MAX_PHONE 15

typedef struct {
    int status;
    char name[MAX_NAME];
    char phone[MAX_PHONE];
} Seat;

int main() {
    int rows, cols;
    Seat seating[20][20] = {{AVAILABLE}};
    int choice;
    int i, j, r, c, new_r, new_c;
    char filename[MAX_FILENAME];
    FILE *file;

    printf("                                           **********************************************************************\n");
    printf("                                           **********************************************************************\n");
    printf("                                           *******                                                        *******\n");
    printf("                                           *******             CEREMONY SEAT MANAGEMENT SYSTEM            *******\n");
    printf("                                           *******                                                        *******\n");
    printf("                                           **********************************************************************\n");
    printf("\n");
    printf("                                            ---------------------------------------------------------------------\n");
    printf("                                            |**********************      CSE103 Project     ********************|\n");
    printf("                                            ---------------------------------------------------------------------\n");
    printf("\n");
    printf("                                           **********************************************************************\n");
    printf("                                           |    ************************************************************    |\n");
    printf("                                           |    **                                                        **    |\n");
    printf("                                           |    **                      WELCOME TO                        **    |\n");
    printf("                                           |    **                    CEREMONY SEAT                       **    |\n");
    printf("                                           |    **                  MANAGEMENT SYSTEM!                    **    |\n");
    printf("                                           |    **                                                        **    |\n");
    printf("                                           |    ************************************************************    |\n");
    printf("                                           **********************************************************************\n");

    do {
        printf("Enter number of rows (1-20): ");
        scanf("%d", &rows);
        if (rows <= 0 || rows > 20) {
            printf("Invalid input. Please enter 1–20.\n");
        }
    } while (rows <= 0 || rows > 20);

    do {
        printf("Enter number of columns (1-20): ");
        scanf("%d", &cols);
        if (cols <= 0 || cols > 20) {
            printf("Invalid input. Please enter 1–20.\n");
        }
    } while (cols <= 0 || cols > 20);

    printf("\n                                      Venue setup complete: %d rows x %d columns\n", rows, cols);

    #define DISPLAY_SEATS() \
        printf("\n============== CURRENT SEATING ARRANGEMENT =============\n\n"); \
        printf("        "); \
        for (j = 0; j < cols; j++) printf("         C%-3d  ", j + 1); \
        printf("\n"); \
        for (i = 0; i < rows; i++) { \
            printf("Row %-2d \t|", i + 1); \
            for (j = 0; j < cols; j++) { \
                if (seating[i][j].status == BOOKED) \
                    printf(" [%-10s] ", seating[i][j].name); \
                else \
                    printf(" [ Available ] "); \
            } \
            printf("\n \n"); \
        } \
        printf("\n");

    while (1) {
        DISPLAY_SEATS();
        printf("\n");
        printf("====================== MAIN MENU ======================\n");
        printf("\n");
        printf("1. Book a seat\n");
        printf("2. Cancel a booking\n");
        printf("3. Update booking details\n");
        printf("4. Save seating arrangement\n");
        printf("5. Load seating arrangement\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        if (choice == 1) { // Book a seat
            printf("\n=== BOOK A SEAT ===\n");
            do {
                printf("Enter row (1-%d): ", rows);
                scanf("%d", &r);
                printf("Enter column (1-%d): ", cols);
                scanf("%d", &c);
                while (getchar() != '\n');

                if (r < 1 || r > rows || c < 1 || c > cols) {
                    printf("Invalid seat location.\n ");
                    continue;
                }
                if (seating[r-1][c-1].status == BOOKED) {
                    printf("Seat already booked by %s.\n", seating[r-1][c-1].name);
                    continue;
                }

                printf("Enter guest name: ");
                fgets(seating[r-1][c-1].name, MAX_NAME, stdin);
                seating[r-1][c-1].name[strcspn(seating[r-1][c-1].name, "\n")] = '\0';

                printf("Enter guest phone number: ");
                fgets(seating[r-1][c-1].phone, MAX_PHONE, stdin);
                seating[r-1][c-1].phone[strcspn(seating[r-1][c-1].phone, "\n")] = '\0';

                seating[r-1][c-1].status = BOOKED;
                printf("Seat booked successfully for %s!\n", seating[r-1][c-1].name);
                break;
            } while (1);
        }
        else if (choice == 2) {
            printf("\n=== CANCEL A BOOKING ===\n");
            do {
                printf("Enter row (1-%d): ", rows);
                scanf("%d", &r);
                printf("Enter column (1-%d): ", cols);
                scanf("%d", &c);
                while (getchar() != '\n');

                if (r < 1 || r > rows || c < 1 || c > cols) {
                    printf("Invalid seat location.\n");
                    continue;
                }
                if (seating[r-1][c-1].status == AVAILABLE) {
                    printf("Seat is not booked.\n");
                    continue;
                }

                printf("Cancelling booking for %s (%s)\n", seating[r-1][c-1].name, seating[r-1][c-1].phone);
                seating[r-1][c-1].status = AVAILABLE;
                seating[r-1][c-1].name[0] = '\0';
                seating[r-1][c-1].phone[0] = '\0';
                printf("Booking cancelled.\n");
                break;
            } while (1);
        }
        else if (choice == 3) {
            printf("\n=== UPDATE BOOKING DETAILS ===\n");
            do {
                printf("Enter current row (1-%d): ", rows);
                scanf("%d", &r);
                printf("Enter current column (1-%d): ", cols);
                scanf("%d", &c);
                while (getchar() != '\n');

                if (r < 1 || r > rows || c < 1 || c > cols) {
                    printf("Invalid seat location.\n");
                    continue;
                }
                if (seating[r-1][c-1].status == AVAILABLE) {
                    printf("Seat is not booked.\n");
                    continue;
                }

                printf("\nCurrent booking details:\n");
                printf("Name: %s\n", seating[r-1][c-1].name);
                printf("Phone: %s\n", seating[r-1][c-1].phone);
                printf("Seat: Row %d, Column %d\n", r, c);

                printf("\nWhat would you like to update?\n");
                printf("1. Change guest name\n");
                printf("2. Change phone number\n");
                printf("3. Move to different seat\n");
                printf("4. Cancel update\n");
                printf("Enter choice (1-4): ");
                scanf("%d", &choice);
                while (getchar() != '\n');

                if (choice == 1) {
                    printf("Enter new name: ");
                    fgets(seating[r-1][c-1].name, MAX_NAME, stdin);
                    seating[r-1][c-1].name[strcspn(seating[r-1][c-1].name, "\n")] = '\0';
                    printf("Name updated successfully!\n");
                    break;
                }
                else if (choice == 2) {
                    printf("Enter new phone number: ");
                    fgets(seating[r-1][c-1].phone, MAX_PHONE, stdin);
                    seating[r-1][c-1].phone[strcspn(seating[r-1][c-1].phone, "\n")] = '\0';
                    printf("Phone number updated successfully!\n");
                    break;
                }
                else if (choice == 3) {
                    printf("Enter new row (1-%d): ", rows);
                    scanf("%d", &new_r);
                    printf("Enter new column (1-%d): ", cols);
                    scanf("%d", &new_c);
                    while (getchar() != '\n');

                    if (new_r < 1 || new_r > rows || new_c < 1 || new_c > cols) {
                        printf("Invalid seat location.\n");
                        continue;
                    }
                    if (seating[new_r-1][new_c-1].status == BOOKED) {
                        printf("Target seat is already booked by %s.\n", seating[new_r-1][new_c-1].name);
                        continue;
                    }

                    // Move booking to new seat
                    seating[new_r-1][new_c-1] = seating[r-1][c-1];
                    seating[r-1][c-1].status = AVAILABLE;
                    seating[r-1][c-1].name[0] = '\0';
                    seating[r-1][c-1].phone[0] = '\0';
                    printf("Booking moved from Row %d Column %d to Row %d Column %d\n", r, c, new_r, new_c);
                    break;
                }
                else if (choice == 4) {
                    printf("Update cancelled.\n");
                    break;
                }
                else {
                    printf("Invalid choice.\n");
                }
            } while (1);
        }
        else if (choice == 4) {
            printf("\n=== SAVE SEATING ARRANGEMENT ===\n");
            printf("Enter filename to save: ");
            fgets(filename, MAX_FILENAME, stdin);
            filename[strcspn(filename, "\n")] = '\0';

            file = fopen(filename, "wb");
            if (file == NULL) {
                printf("Error opening file for writing.\n");
                continue;
            }

            fwrite(&rows, sizeof(int), 1, file);
            fwrite(&cols, sizeof(int), 1, file);

            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    fwrite(&seating[i][j], sizeof(Seat), 1, file);
                }
            }

            fclose(file);
            printf("Seating arrangement saved to '%s' successfully!\n", filename);
        }
        else if (choice == 5) {
            printf("\n=== LOAD SEATING ARRANGEMENT ===\n");
            printf("Enter filename to load: ");
            fgets(filename, MAX_FILENAME, stdin);
            filename[strcspn(filename, "\n")] = '\0';

            file = fopen(filename, "rb");
            if (file == NULL) {
                printf("Error opening file for reading.\n");
                continue;
            }

            if (fread(&rows, sizeof(int), 1, file) != 1 ||
                fread(&cols, sizeof(int), 1, file) != 1) {
                printf("Error reading file dimensions.\n");
                fclose(file);
                continue;
            }

            if (rows <= 0 || rows > 20 || cols <= 0 || cols > 20) {
                printf("Invalid dimensions in file.\n");
                fclose(file);
                continue;
            }

            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (fread(&seating[i][j], sizeof(Seat), 1, file) != 1) {
                        printf("Error reading seating data.\n");
                        fclose(file);
                        break;
                    }
                }
            }

            fclose(file);
            printf("Seating arrangement loaded from '%s' successfully!\n", filename);
        }
        else if (choice == 6) {
            printf("\n                                     Thank you for using the ceremony seat management system!\n");
            return 0;
        }
        else {
            printf("Invalid choice. Please select 1-6.\n");
        }
    }
}
