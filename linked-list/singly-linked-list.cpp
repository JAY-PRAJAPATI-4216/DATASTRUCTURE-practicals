#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node *first = NULL;

struct Node *create_node(int data) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp; // temp returning a pointer to the newly created node
}

void insert_first(int x) {
    struct Node *t;
    t= create_node(x);
    if (first == NULL) {
        first = t;
    } else {
        t->next = first;
        first = t;
    }
}

void insert_last(int x) {
    struct Node *t, *p;
    t = create_node(x);
    if (first == NULL) {
        first = t;
    } else {
        p = first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
    }
}

void insert_at_position(int x, int pos) {
    struct Node *t, *p;
    t = create_node(x);
    if (pos == 1) {
        t->next = first;
        first = t;
    } else {
        p = first;
        for (int i = 1; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }
        if (p != NULL) {
            t->next = p->next;
            p->next = t;
        } else {
            cout << "Position out of bounds" << endl;
            free(t);
        }
    }
}

void delete_first(){
    struct Node *p;
    if (first == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    p = first;
    first = first->next;
    free(p);
}

void delete_last(){
    struct Node *p, *q;
    if (first == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (first->next == NULL) {
        free(first);
        first = NULL;
        return;
    }
    p = first;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
}
void display() {
    struct Node *p = first;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void delete_at_position(int pos) {
    struct Node *p, *q;
    if (first == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (pos == 1) {
        p = first;
        first = first->next;
        free(p);
        return;
    }
    p = first;
    for (int i = 1; i < pos && p != NULL; i++) {
        q = p;
        p = p->next;
    }
    if (p != NULL) {
        q->next = p->next;
        free(p);
    } else {
        cout << "Position out of bounds" << endl;
    }
}

int main(){
     
    int x,ch;

    while(1){
        cout << "1. Insert at first" << endl;
        cout << "2. Insert at last" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete first" << endl;
        cout << "5. Delete last" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Enter the value of node : ";
                cin >> x;
                insert_first(x);
                break;
            case 2:
                cout << "Enter the value of node : ";
                cin >> x;
                insert_last(x);
                break;
            case 3:
                cout << "Enter the value of node : ";
                cin >> x;
                cout << "Enter the position : ";
                int pos;
                cin >> pos;
                insert_at_position(x, pos);
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                cout << "Enter the position : ";
                int p;
                cin >> p;
                delete_at_position(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}