#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

struct node *first = NULL;


struct node *create_node(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}


void insert_first(int x) {
        struct node *temp = create_node(x);

    if (first == NULL) {
        first = temp;
        temp->next = first;
    }
    else {
        struct node *t = first;

        while (t->next != first) {
            t = t->next;
        }

        temp->next = first;
        t->next = temp;
        first = temp;
    }
}


void insert_last(int x) {
    node *temp = create_node(x);

    if (first == NULL) {
        first = temp;
        temp->next = first;
    }
    else {
        node *t = first;

        while (t->next != first) {
            t = t->next;
        }

        t->next = temp;
        temp->next = first;
    }
}


void insert_at_position(int x, int pos) {

    if (pos == 1) {
        insert_first(x);
        return;
    }

    if (first == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    node *temp = create_node(x);
    node *t = first;

    for (int i = 1; i < pos - 1; i++) {

        if (t->next == first) {
            cout << "Position out of bounds" << endl;
            free (temp);
            return;
        }

        t = t->next;
    }

    temp->next = t->next;
    t->next = temp;
}

void delete_first() {
    if (first == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node *t = first;

    if (first->next == first) {
        first = NULL;
        free (t);
        return;
    }

    node *last = first;

    while (last->next != first) {
        last = last->next;
    }

    first = first->next;
    last->next = first;

    free (t);
}

void delete_last() {
    if (first == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    
    if (first->next == first) {
        delete first;
        first = NULL;
        return;
    }

    node *t = first;
    node *prev = NULL;

    while (t->next != first) {
        prev = t;
        t = t->next;
    }

    prev->next = first;

    delete t;
}

void delete_at_position(int pos) {
    if (first == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (pos == 1) {
        delete_first();
        return;
    }

    node *t = first;
    node *prev = NULL;

    for (int i = 1; i < pos; i++) {
        if (t->next == first) {
            cout << "Position out of bounds" << endl;
            return;
        }
        prev = t;
        t = t->next;
    }

    prev->next = t->next;

    delete t;
}
void display() {

    if (first == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node *t = first;

    do {
        cout << t->data << " -> ";
        t = t->next;
    } while (t != first);

}

int main() {

    int x, ch, pos;

    while (1) {

        cout << "\n1. Insert at first" << endl;
        cout << "2. Insert at last" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete first" << endl;
        cout << "5. Delete last" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {

            case 1:
                cout << "Enter the value to insert: ";
                cin >> x;
                insert_first(x);
                break;

            case 2:
                cout << "Enter the value to insert: ";
                cin >> x;
                insert_last(x);
                break;

            case 3:
                cout << "Enter the value to insert: ";
                cin >> x;

                cout << "Enter the position: ";
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
                
                cout << "enter a position to delete : " ;
                cin >> pos;
                delete_at_position(pos);
            
            case 7:
               display();
               break;

            case 8:
                exit(0);
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}