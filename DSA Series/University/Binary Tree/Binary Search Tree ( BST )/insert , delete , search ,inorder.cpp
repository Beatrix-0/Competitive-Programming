#include <bits/stdc++.h>
using namespace std;

struct BST
{
    int data;
    BST *right;
    BST *left;
};

BST *insert_val(BST *root, int val)
{
    if (root == NULL)
    {
        BST *temp = new BST();
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (val <= root->data)
    {
        root->left = insert_val(root->left, val);
    }
    else
    {
        root->right = insert_val(root->right, val);
    }
    return root;
}

BST *min_val(BST *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

bool search_val(BST *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    else if (val < root->data)
    {
        return search_val(root->left, val);
    }
    else
    {
        return search_val(root->right, val);
    }
}

BST *delete_val(BST *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (val < root->data)
    {
        root->left = delete_val(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete_val(root->right, val);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        else
        {
            BST *temp = min_val(root->right);
            root->data = temp->data;
            root->right = delete_val(root->right, temp->data);
        }
    }
    return root;
}

void inorder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BST *root = NULL;

    root = insert_val(root, 10);
    root = insert_val(root, 58);
    root = insert_val(root, 13);
    root = insert_val(root, 90);
    root = insert_val(root, 73);

    inorder(root);
    cout << '\n';

    root = delete_val(root, 58);

    inorder(root);
    cout << '\n';

    return 0;
}
