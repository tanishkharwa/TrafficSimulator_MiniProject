#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define MAX_SIGNALS 10
#define MAX_VEHICLES 20
#define MAX_VEHICLE_SPEED 5
#define ROAD_LENGTH 100

typedef struct {
    char name[50];
    int signalNumber;
    int vehicleCount;
    char lightColor[10];
    int waitingQueue;
    int timer;
} TrafficSignal;

typedef struct {
    int id;
    int position;
    int speed;
    int destination;
    int isWaiting;
} Vehicle;

TrafficSignal signals[MAX_SIGNALS];
int numSignals = 0;
Vehicle vehicles[MAX_VEHICLES];
int numVehicles = MAX_VEHICLES;

void updateLightColors() {
    for (int i = 0; i < numSignals; i++) {
        signals[i].timer--;
        if (signals[i].timer <= 0) {
            if (strcmp(signals[i].lightColor, "Red") == 0) {
                strcpy(signals[i].lightColor, "Green");
                signals[i].timer = 10;
            } else if (strcmp(signals[i].lightColor, "Green") == 0) {
                strcpy(signals[i].lightColor, "Yellow");
                signals[i].timer = 3;
            } else {
                strcpy(signals[i].lightColor, "Red");
                signals[i].timer = 7;
            }
        }
    }
}

void initializeSignals() {
    strcpy(signals[0].name, "Bandra Signal");
    signals[0].signalNumber = 1;
    signals[0].vehicleCount = 10;
    signals[0].waitingQueue = 5;
    strcpy(signals[0].lightColor, "Red");
    signals[0].timer = 7;

    strcpy(signals[1].name, "Dadar Signal");
    signals[1].signalNumber = 2;
    signals[1].vehicleCount = 7;
    signals[1].waitingQueue = 3;
    strcpy(signals[1].lightColor, "Green");
    signals[1].timer = 10;

    strcpy(signals[2].name, "Andheri Signal");
    signals[2].signalNumber = 3;
    signals[2].vehicleCount = 8;
    signals[2].waitingQueue = 2;
    strcpy(signals[2].lightColor, "Yellow");
    signals[2].timer = 3;

    numSignals = 3;
}

void generateVehicles() {
    srand(time(0));
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i].id = i + 1;
        vehicles[i].position = rand() % ROAD_LENGTH;
        vehicles[i].speed = rand() % MAX_VEHICLE_SPEED + 1;
        vehicles[i].destination = rand() % numSignals;
        vehicles[i].isWaiting = 0;
    }
}

void redistributeVehicles() {
    int totalVehicles = numVehicles;
    int remainingVehicles = totalVehicles;

    for (int i = 0; i < numSignals; i++) {
        if (i == numSignals - 1) {
            signals[i].vehicleCount = remainingVehicles;
        } else {
            signals[i].vehicleCount = rand() % (remainingVehicles / 2 + 1);
            remainingVehicles -= signals[i].vehicleCount;
        }
    }

    for (int i = 0; i < numSignals; i++) {
        signals[i].waitingQueue = rand() % (signals[i].vehicleCount / 2 + 1);
    }
}

void simulateWaitingQueues() {
    for (int i = 0; i < numSignals; i++) {
        if (strcmp(signals[i].lightColor, "Red") == 0) {
            signals[i].waitingQueue += rand() % 5 + 1;
        } else if (strcmp(signals[i].lightColor, "Yellow") == 0) {
            signals[i].waitingQueue += rand() % 3;
        } else {
            signals[i].waitingQueue = 0;
        }
    }
}

void moveVehicles() {
    for (int i = 0; i < numVehicles; i++) {
        if (vehicles[i].isWaiting == 0) {
            vehicles[i].position += vehicles[i].speed;
            if (vehicles[i].position >= ROAD_LENGTH) {
                vehicles[i].position = 0;
                vehicles[i].destination = (vehicles[i].destination + 1) % numSignals;
            }
        } else if (strcmp(signals[vehicles[i].destination].lightColor, "Green") == 0) {
            vehicles[i].isWaiting = 0;
        }
    }
    redistributeVehicles();
}

void viewDashboard() {
    updateLightColors();
    simulateWaitingQueues();
    redistributeVehicles();
    time_t t;
    time(&t);

    printf("\n=== Traffic Dashboard ===\n");
    for (int i = 0; i < numSignals; i++) {
        printf("Signal Name: %s\n", signals[i].name);
        printf("Signal Number: %d\n", signals[i].signalNumber);

        if (strcmp(signals[i].lightColor, "Red") == 0) {
            printf("Waiting Queue: %d\n", signals[i].waitingQueue);
        } else {
            printf("Vehicle Count: %d\n", signals[i].vehicleCount);
            printf("Waiting Queue: %d\n", signals[i].waitingQueue);
        }

        if (strcmp(signals[i].lightColor, "Red") == 0) {
            printf("\033[0;31mLight Color: %s\033[0m\n", signals[i].lightColor);
        } else if (strcmp(signals[i].lightColor, "Green") == 0) {
            printf("\033[0;32mLight Color: %s\033[0m\n", signals[i].lightColor);
        } else if (strcmp(signals[i].lightColor, "Yellow") == 0) {
            printf("\033[0;33mLight Color: %s\033[0m\n", signals[i].lightColor);
        }

        printf("Time Remaining: %d seconds\n", signals[i].timer);
        printf("\033[0;34mCurrent Time: %s\033[0m", ctime(&t));
        printf("-------------------------\n");
    }
}

void editRules() {
    int choice;
    do {
        printf("\n=== Edit Rules Menu ===\n");
        printf("1. Modify Signal\n");
        printf("2. Add New Signal\n");
        printf("3. Back to Traffic Engineer Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int signalNumber;
            char newColor[10];

            printf("\nEnter the signal number to edit: ");
            scanf("%d", &signalNumber);

            for (int i = 0; i < numSignals; i++) {
                if (signals[i].signalNumber == signalNumber) {
                    printf("Current Light Color: %s\n", signals[i].lightColor);
                    printf("Enter new light color (Red, Yellow, Green): ");
                    scanf("%s", newColor);
                    strcpy(signals[i].lightColor, newColor);
                    printf("Light color updated successfully!\n");
                    break;
                }
            }
        } else if (choice == 2) {
            if (numSignals < MAX_SIGNALS) {
                printf("\nEnter signal name: ");
                scanf("%s", signals[numSignals].name);
                signals[numSignals].signalNumber = numSignals + 1;
                signals[numSignals].vehicleCount = rand() % 20;
                signals[numSignals].waitingQueue = rand() % 10;
                strcpy(signals[numSignals].lightColor, "Red");
                signals[numSignals].timer = 7;
                numSignals++;
                printf("New signal added successfully!\n");
            } else {
                printf("Maximum number of signals reached. Cannot add more.\n");
            }
        } else if (choice != 3) {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}

void trafficEngineerMenu() {
    int choice;

    do {
        printf("\n=== Traffic Engineer Menu ===\n");
        printf("1. View Dashboard\n");
        printf("2. Edit Rules\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewDashboard();
                break;
            case 2:
                editRules();
                break;
            case 3:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}

void cityPlannerMenu() {
    int choice;

    do {
        printf("\n=== City Planner Menu ===\n");
        printf("1. View Dashboard\n");
        printf("2. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewDashboard();
                break;
            case 2:
                printf("Exiting City Planner Menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);
}

int main() {
    int choice;

    initializeSignals();
    generateVehicles();

    do {
        printf("\n=== Main Menu ===\n");
        printf("1. Traffic Engineer\n");
        printf("2. City Planner\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                trafficEngineerMenu();
                break;
            case 2:
                cityPlannerMenu();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        updateLightColors();
        moveVehicles();
        sleep(1);
    } while (choice != 3);

    return 0;
}
