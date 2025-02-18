#include <stdio.h>
#include <stdlib.h>

typedef struct Date {
    char day[3];
    char month[3];
    char year[5];
} Date;

typedef struct Product {
    char *ProductName;  
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
        p->cell.ProductName = (char*)malloc(100 * sizeof(char)); 

        printf("Enter the product name: ");
        scanf("%s", p->cell.ProductName); 

        printf("Enter the reference: ");
        scanf("%s", p->cell.Reference); 

        printf("Enter the amount: ");
        scanf("%f", &p->cell.Amount); 

        printf("Enter the purchase day: ");
        scanf("%s", p->cell.PurchaseDate.day); 
        printf("Enter the purchase month: ");
        scanf("%s", p->cell.PurchaseDate.month); 
        printf("Enter the purchase year: ");
        scanf("%s", p->cell.PurchaseDate.year);

        p->next = NULL; 
    }

    return p;
}

void display_product(List *product) {
    if (product != NULL) {
        printf("Name: %s\n", product->cell.ProductName);
        printf("Reference: %s\n", product->cell.Reference);
        printf("Amount: %.2f\n", product->cell.Amount);
        printf("Purchase Date: %s/%s/%s\n", product->cell.PurchaseDate.day, product->cell.PurchaseDate.month, product->cell.PurchaseDate.year);
    }
    printf("\n");
}

List* add_to_start(List *head) {
    List *p = create_product();
    p->next = head;
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

void display_products(List* head) {
    List* temp = head; 
    while (temp != NULL) {
        display_product(temp); 
        temp = temp->next;
    }
}

int length(List* head) {
    int count = 0;
    List* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void filter_by_date(List* head, Date dt) {
    List* temp = head;
    while (temp != NULL) {
        int day_match = 1, month_match = 1, year_match = 1;

        for (int i = 0; i < 3; i++) {
            if (temp->cell.PurchaseDate.day[i] != dt.day[i]) {
                day_match = 0;
                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (temp->cell.PurchaseDate.month[i] != dt.month[i]) {
                month_match = 0;
                break;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (temp->cell.PurchaseDate.year[i] != dt.year[i]) {
                year_match = 0;
                break;
            }
        }

        if (day_match && month_match && year_match) {
            display_product(temp);
        }
        temp = temp->next;
    }
}

List* delete_from_start(List* head) {
    if (head == NULL) {
        return NULL;
    }
    List* temp = head;
    head = head->next;
    free(temp->cell.ProductName);    
    free(temp);
    return head;
}

void delete_from_end(List* head) {
    if (head == NULL) return;
    else if (head->next == NULL) {
        free(head->cell.ProductName);  
        free(head);
        return;
    }
    List* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next->cell.ProductName); 
    free(temp->next);
    temp->next = NULL;
}

List* refund(List* head, char* refer) {
    if (head == NULL) return NULL;
    if (strcmp(head->cell.Reference, refer) == 0) {
        return delete_from_start(head);
    } else {
        List* temp = head;
        while (temp->next != NULL && strcmp(temp->next->cell.Reference, refer) != 0) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            if (temp->next->next == NULL) {
                delete_from_end(head);
            } else {
                List* elementToDelete = temp->next;
                temp->next = temp->next->next;
                free(elementToDelete->cell.ProductName);
                free(elementToDelete);
            }
        }
        return head;
    }
}

void sort_list(List* head) {
    if (head == NULL) return;
    List* i = head;
    while (i != NULL) {
        List* j = i->next;
        while (j != NULL) {
            if (i->cell.Amount > j->cell.Amount) {
                Product temp = i->cell;
                i->cell = j->cell;
                j->cell = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

List* merge_lists(List* head1, List* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    List* last = head1;
    while (last->next != NULL) last = last->next;
    last->next = head2;
    return head1;
}

List* clone_list(List* head) {
    if (head == NULL) return NULL;
    List* clone = (List*) malloc(sizeof(List));
    clone->cell = head->cell;
    clone->next = clone_list(head->next);
    return clone;
}

List* insert_at_position(List* head, List* product, int position) {
    if (position == 0) {
        product->next = head;
        return product;
    }
    List* previous = head;
    while (previous != NULL && position > 1) {
        previous = previous->next;
        position--;
    }
    if (previous != NULL) {
        product->next = previous->next;
        previous->next = product;
    }

    return head;
}

int main() {
    List* productList = create_product_list();
    int n;

    printf("How many products do you want to add? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        productList = add_to_end(productList);
    }

    printf("\n-----Product List ---\n");
    display_products(productList);
    printf("List length: %d\n", length(productList));

    Date testDate = {"08", "01", "2025"};
    printf("Filtering products for the date %s/%s/%s\n", testDate.day, testDate.month, testDate.year);
    filter_by_date(productList, testDate);

    float total = 0;
    List* temp = productList;
    while (temp != NULL) {
        total += temp->cell.Amount;
        temp = temp->next;
    }

    printf("The total amount to pay is: %.2f $\n", total);

    return 0;
}