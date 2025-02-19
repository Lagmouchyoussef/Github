TP 1: Singly Linked Lists
Problem Statement: Product Stock Management
In this problem, we aim to automate a product purchasing system for a store. To meet our requirements, we propose the following structures to model the given problem.

**Date Structure:**
typedef struct Date {
    char day[3];
    char month[3];
    char year[5];
} date;
**Product Structure:**
typedef struct Product {
    char *ProductName;
    char Reference[100];
    float Amount;
    date PurchaseDate;
} product;
**List Structure:**
typedef struct List {
    product cell;
    struct List* next;
} list;
**Required Functions:**
Write a program that includes the following functions:

1) function list* create_product_list() that initializes an empty list and returns it.

2) function int is_empty(list *head) that returns 1 if the list is empty, otherwise returns 0.

3) function list* create_product() that returns a created product by assigning its data (product name, reference, etc.).

4) function void display_product(list* product) that displays the details of the given product (see display example on page 2).

Functions to add products to the list:

5) list* add_at_beginning(list* head): Adds a created product at the beginning of the linked list.
void add_at_end(list* head): Adds a created product at the end of the linked list.
6) function void display_products(list* head) that prints the entire content of the list (see display example below).

7) function int length(list* head) that returns the number of products in the list.

8) function void filter_by_date(list* head, Date dt) that displays only products purchased on the given date.

9) function list* remove_first(list* head) that removes the first product in the list.

10) function void remove_last(list* head) that removes the last product in the list.

11) function list* refund(list* head, char* reference) that removes a product with the given reference. If the product is first in the list, it calls remove_first(), otherwise, if it is last, it calls remove_last().

12) Implement a function void sort_list(list* head) that sorts the list based on a criterion (e.g., product name, reference, or date).

13) Implement a function list* merge_lists(list* head1, list* head2) that merges two linked lists into a single list.

15) Write a function list* clone_list(list* head), which creates a deep copy of the linked list.

16) Implement a function list* insert_at_position(list* head, list* product, int position) to insert a product at a specific position.

Test all these functions in the main() program
**Number: 1**  
Product Name: chicken 0.60kg  
Reference: AXCF14V0VG8027  
Purchase Date: 02/03/2023  
Amount: 48.33 $ 

**Number: 2**  
Product Name: Yogo 1/2 L  
Reference: XXCF1400VC8666  
Purchase Date: 03/03/2023  
Amount: 05.50 $

Total to pay: 53.83 $  
**Author** 
Developed by Youssef Lagmouch as part of a lab assignment on singly linked lists
