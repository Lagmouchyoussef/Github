#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    char day[3];
    char month[3];
    char year[5];
} Date;

typedef struct Product {
    char *ProductName;  // A pointer for the product name
    char Reference[100];
    float Amount;
    Date PurchaseDate;
} Product;

typedef struct List {
    Product cell;
    struct List *next;
} List;

List* create_product_list() {
    return NULL;
}

int is_empty(List* head) {
    return head == NULL;
}

List* create_product() {
    List *p = (List*)malloc(sizeof(List)); 

    if (p != NULL) {
        p->cell.ProductName = (char*)malloc(100 * sizeof(char)); // Dynamic allocation for the product name

        // Enter data for each product
        printf("Enter the product name: ");
        scanf("%99s", p->cell.ProductName);  // Use scanf for product name input

        printf("Enter the reference: ");
        scanf("%s", p->cell.Reference); 

        printf("Enter the amount: ");
        scanf("%f", &p->cell.Amount); 

        // Enter the purchase date in the form day month year
        printf("Enter the purchase date (day month year): ");
        scanf("%s %s %s", p->cell.PurchaseDate.day, p->cell.PurchaseDate.month, p->cell.PurchaseDate.year);

        p->next = NULL; 
    }

    return p;
}

List* add_to_end(List *head) {
    List *p = create_product();
    if (head == NULL) {
        return p;
    }
    List *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
    return head;
}

void display_product(List* product, int number) {
    printf("\nProduct %d:\n", number);
    printf("Name: %s\n", product->cell.ProductName);
    printf("Reference: %s\n", product->cell.Reference);
    printf("Amount: %.2f\n", product->cell.Amount);
    printf("Purchase Date: %s/%s/%s\n", product->cell.PurchaseDate.day, product->cell.PurchaseDate.month, product->cell.PurchaseDate.year);
    printf("-----------------------------\n");
}

void display_total(List* head) {
    float total = 0;
    List* temp = head;
    int number = 1;

    while (temp != NULL) {
        display_product(temp, number);  // Display the product with its number
        total += temp->cell.Amount;
        temp = temp->next;
        number++;
    }

    // Display only the total amount at the end
    printf("The total amount to pay is: %.2f\n", total);
}

int main() {
    List* productList = create_product_list();
    int n;

    printf("How many products do you want to add? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProduct %d\n", i + 1);  // Displays "Product 1", "Product 2", etc.
        productList = add_to_end(productList);
    }

    // Display all products and the total at the end
    display_total(productList);

    return 0;
}