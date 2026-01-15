#include<stdio.h>
// using DFS & BFS
int main(){

    int c_a = 8, c_b = 5, c_c = 3;
    int g_a = 4, g_b = 4, g_c = 0;
    int a = 8, b = 0,c = 0;
    int choice;

        // Menu-driven loop
    while (!(a == g_a && b == g_b && c == g_c)) {

        printf("\nCurrent State: A = %d, B = %d, C = %d\n", a, b,c);
        printf("1. Pour A -> B\n");
        printf("2. Pour B -> A\n");
        printf("3. Pour A -> C\n");
        printf("4. Pour C -> A\n");
        printf("5. Pour B -> C\n");
        printf("6. Pour C -> B\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
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

            case 2: {
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
            case 3: {
                int pour = (a < (c_c - c)) ? a : (c_c - c);
                a -= pour;
                c += pour;
                break;
            }
            case 4: {
                int pour = (c < (c_a - a)) ? c : (c_a - a);
                c -= pour;
                a += pour;
                break;
            }
            case 5: {
                int pour = (b < (c_c - c)) ? b : (c_c - c);
                b -= pour;
                c += pour;
                break;
            }
            case 6: {
                int pour = (c < (c_b - b)) ? c : (c_b - b);
                c -= pour;
                b += pour;
                break;
            }

            default:
                printf("Invalid choice.\n");
        }
    }

    printf("\nGoal Reached: A = %d, B = %d, C = %d\n", a, b, c);

return 0;
}


// 