#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *first = NULL;
struct Node *last = NULL;


struct Node* create_node(int x)
{
    struct Node *temp =(struct Node *)malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}


void insert_first(int x)
{
    struct Node *temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }

    cout << "Node inserted at beginning.\n";
}


void insert_last(int x)
{
    struct Node *temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }

    cout << "Node inserted at end.\n";
}

void insert_after(int key, int x)
{
    struct Node *t = first;

    while (t != NULL && t->data != key)
    {
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "Given node not found.\n";
        return;
    }

    struct Node *temp = create_node(x);

    temp->next = t->next;
    temp->prev = t;

    if (t->next != NULL)
    {
        t->next->prev = temp;
    }
    else
    {
        last = temp;
    }

    t->next = temp;

    cout << "Node inserted successfully.\n";
}


void delete_first()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    struct Node *t = first;

    if (first == last)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        first->prev = NULL;
    }

    free (t);

    cout << "First node deleted.\n";
}

void delete_last()
{
    if (last == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    struct Node *t = last;

    if (first == last)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        last->next = NULL;
    }

    free (t);

    cout << "Last node deleted.\n";
}

void delete_after(int key)
{
    struct Node *t = first;

    while (t != NULL && t->data != key)
    {
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "Given node not found.\n";
        return;
    }

    if (t->next == NULL)
    {
        cout << "No node exists after this node.\n";
        return;
    }

    struct Node *temp = t->next;

    t->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = t;
    }
    else
    {
        last = t;
    }

    free (temp);

    cout << "Node deleted successfully.\n";
}


void display_forward()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    struct Node *t = first;

    cout << "Doubly Linked List: ";

    while (t != NULL)
    {
        cout << t->data;

        if (t->next != NULL)
            cout << " <-> ";

        t = t->next;
    }

    cout << endl;
}


void display_backward()
{
    if (last == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    struct Node *t = last;

    cout << "Reverse List: ";

    while (t != NULL)
    {
        cout << t->data;

        if (t->prev != NULL)
            cout << " <-> ";

        t = t->prev;
    }

    cout << endl;
}

int max(){
    struct Node *t;
    t = first;
    int max=0;

    while(t != NULL){
        if(t->data > max);
        max = t->data;

        t = t->next;
    }
    return max;
}

int min(){
    struct Node *t;
    int min = max();
    t=first;
 while(t != NULL){
    if(t->data < min){
        min = t->data;
        
    }
    t = t->next;
}
    return min;
}

int main()
{
    int choice, x, key;

while(1){

        cout << "\n===== DOUBLY LINKED LIST =====\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert After Given Node\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete After Given Node\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Find Maximum Value\n";
        cout << "10.Find Minimum Value\n";
        cout << "11. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            insert_first(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            insert_last(x);
            break;

        case 3:
            cout << "Enter node after which to insert: ";
            cin >> key;

            cout << "Enter value: ";
            cin >> x;

            insert_after(key, x);
            break;

        case 4:
            delete_first();
            break;

        case 5:
            delete_last();
            break;

        case 6:
            cout << "Enter node after which to delete: ";
            cin >> key;

            delete_after(key);
            break;

        case 7:
            display_forward();
            break;

        case 8:
            display_backward();
            break;

        case 9:
            cout << "Maximum number from list is:" << max();
            break;
        
        case 10:
            cout << "Minimum number from list is:" << min();
            break;
        case 11:
            cout << "Program terminated.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }

    }

    return 0;
}