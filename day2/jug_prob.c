#include <stdio.h>

// Function to calculate GCD
int gcd(int x, int y) {
    return (y == 0) ? x : gcd(y, x % y);
}

int main() {
    int a = 0, b = 0;        // current water in jugs
    int c_a, c_b;           // capacities
    int g_a, g_b;           // goal state
    int choice;

    // User input
    printf("Enter capacity of Jug A: ");
    scanf("%d", &c_a);
    printf("Enter capacity of Jug B: ");
    scanf("%d", &c_b);

    printf("Enter goal for Jug A: ");
    scanf("%d", &g_a);
    printf("Enter goal for Jug B: ");
    scanf("%d", &g_b);

    // Basic validation
    if (g_a > c_a || g_b > c_b) {
        printf("Goal cannot exceed jug capacity.\n");
        return 0;
    }

    // Solvability check using GCD rule
    int target = (g_a != 0) ? g_a : g_b;

    /*
    Equivalent if-else logic for above ternary:

    int target;
    if (g_a != 0)
        target = g_a;
    else
        target = g_b;
    */

    if (target % gcd(c_a, c_b) != 0) {
        printf("No solution exists for this configuration.\n");
        return 0;
    }

    printf("Solution exists. Start solving...\n");

    // Menu-driven loop
    while (!(a == g_a && b == g_b)) {

        printf("\nCurrent State: A = %d, B = %d\n", a, b);
        printf("1. Fill Jug A\n");
        printf("2. Fill Jug B\n");
        printf("3. Pour A -> B\n");
        printf("4. Pour B -> A\n");
        printf("5. Empty Jug A\n");
        printf("6. Empty Jug B\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                a = c_a;
                break;

            case 2:
                b = c_b;
                break;

            case 3: {
                int pour = (a < (c_b - b)) ? a : (c_b - b);

                /*
                Equivalent if-else logic:

                int pour;
                if (a < (c_b - b))
                    pour = a;
                else
                    pour = (c_b - b);
                */

                a -= pour;
                b += pour;
                break;
            }

            case 4: {
                int pour = (b < (c_a - a)) ? b : (c_a - a);

                /*
                Equivalent if-else logic:

                int pour;
                if (b < (c_a - a))
                    pour = b;
                else
                    pour = (c_a - a);
                */

                b -= pour;
                a += pour;
                break;
            }

            case 5:
                a = 0;
                break;

            case 6:
                b = 0;
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    printf("\nGoal Reached: A = %d, B = %d\n", a, b);
    return 0;
}
