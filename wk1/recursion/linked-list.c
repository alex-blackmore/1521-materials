#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

void append(struct node *head, struct node *new) {
    if (head->next == NULL) {
        head->next = new;
        new->next = NULL;
    }
    else {
        append(head->next, new);
    }
}

int length(struct node *head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + length(head->next);
}

int main(void) {
    struct node head = {1, NULL};
    struct node A = {2, NULL};
    struct node B = {3, NULL};
    struct node C = {4, NULL};
    struct node D = {5, NULL};
    append(&head, &A);
    append(&head, &B);
    append(&head, &C);
    append(&head, &D);
    printf("%d\n", length(&head));
}

