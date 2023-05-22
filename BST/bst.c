#include "bst.h"



struct Node * create_node(int i){
    struct Node * ret = (struct Node *) malloc (sizeof(ret));
    ret->val = i;
    return ret;
}


struct Node * insert(struct Node * root, int i){
    if (root == NULL){
        root = create_node(i);
    }
    else if (i < root->val){
        root->left = insert(root->left, i);
    }
    else if (i > root->val){
        root->right = insert(root->right, i);
    }

    return root;
}


struct Node * search(struct Node * root, int i){
    if (root == NULL || root->val == i){
        return root;
    }
    else if (i < root->val){
        return search(root->left, i);
    }
    else{
        return search(root->right, i);
    }
}


struct Node * find_min(struct Node * n){
    struct Node * cur = n;
    while (cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}


struct Node * find_max(struct Node * n){
    struct Node * cur = n;
    while (cur->right != NULL){
        cur = cur->right;
    }
    return cur;
}


struct Node * delete(struct Node * root, int i){
    if (root == NULL){
        return root;
    }
    else if (root->val > i){
        root->left = delete(root->left, i);
    }
    else if (root->val < i){
        root->right = delete(root->right, i);
    }
    else {
        struct Node * temp;
        if (root->left == NULL){
            temp = root->right;
            deallocate_node(root);
            return temp;
        }
        else if (root->right == NULL){
            temp = root->left;
            deallocate_node(root);
            return temp;
        }
        temp = find_min(root->right);
        root->val = temp->val;
        root->right = delete(root->right, temp->val);
    }
    return root;
}


void in_order_print(struct Node * root){
    if (root != NULL){
        in_order_print(root->left);
        printf("%d\n",root->val);
        in_order_print(root->right);
    }
}


void delete_tree(struct Node * root){
    if (root == NULL){
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    deallocate_node(root);
}

void deallocate_node(struct Node * root){
    free(root);
}
