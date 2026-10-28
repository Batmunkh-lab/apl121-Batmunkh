#include <stdio.h>
#include <stdlib.h>

int readInt(const char *prompt, int min, int max)
{
    int value, valid, ch;

    do {
        printf("%s", prompt);
        valid = scanf("%d", &value);

        if (valid == EOF) {
            exit(0);
        }

        /* Оролтын мөрийн үлдэгдлийг цэвэрлэнэ. */
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch != ' ' && ch != '\t' && ch != '\r') {
                valid = 0;
            }
        }

        if (valid != 1) {
            printf("Buhel too oruulna uu.\n");
        } else if (value < min || value > max) {
            printf("%d-%d hoorond utga oruulna uu.\n", min, max);
        }
    } while (valid != 1 || value < min || value > max);

    return value;
}

int main(void)
{
    int n, total, fee;
    int order[20], service[20], pay[20], used[20] = {0};
    int sum, cumulative = 0, previous = 0;
    int allocated, best;

    n = readInt("Hunii too (5-20): ", 5, 20);
    total = readInt("Hoolnii niit une (1-1000000): ", 1, 1000000);
    fee = readInt("Uilchilgeenii huraamj (0-100000): ", 0, 100000);

    do {
        sum = 0;

        for (int i = 0; i < n; i++) {
            printf("Hun %d\n", i + 1);
            order[i] = readInt("Zahialgiin une: ", 0, total);
            sum += order[i];
        }

        if (sum < total) {
            printf("Niilber niit unees baga. Bugdiig dahin oruul.\n");
        } else if (sum > total) {
            printf("Niilber niit unees ih. Bugdiig dahin oruul.\n");
        } else {
            printf("Zahialgiin niilber taarlaa.\n");
        }
    } while (sum != total);

    for (int i = 0; i < n; i++) {
        cumulative += order[i];

        /* long long нь үржвэр бүхэл тооны хязгаар давахаас сэргийлнэ. */
        allocated = (int)((long long)cumulative * fee / total);
        service[i] = allocated - previous;
        pay[i] = order[i] + service[i];
        previous = allocated;
    }

    printf("\nHun | Zahialga | Uilchilgee | Tuluh dun\n");
    for (int i = 0; i < n; i++) {
        printf("%3d | %8d | %10d | %9d\n",
               i + 1, order[i], service[i], pay[i]);
    }
    printf("NIIT| %8d | %10d | %9d\n",
           total, fee, total + fee);

    printf("\nHamgiin ih tuluh 3 hun:\n");
    for (int rank = 1; rank <= 3; rank++) {
        best = -1;

        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                if (best == -1) {
                    best = i;
                } else if (pay[i] > pay[best]) {
                    best = i;
                }
            }
        }

        used[best] = 1;
        printf("%d-r bair | Hun %d | %d tugrug\n",
               rank, best + 1, pay[best]);
    }

    return 0;
}