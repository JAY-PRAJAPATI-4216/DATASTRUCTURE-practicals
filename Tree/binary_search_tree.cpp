
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};


struct Node* createNode(int value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


Node* insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL){
        return ;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root == NULL){

        return;
    }else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root == NULL){
        return;

    }else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}