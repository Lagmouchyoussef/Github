#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *tab, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    tab = (int *)malloc(n * sizeof(int));
    if (tab == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program in case of an error
    }

    printf("Enter the %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &tab[i]);
    }

    printf("The elements of the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);

    return 0;
}
