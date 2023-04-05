void removeNode(Node** root, int key) {
    Node *toRemove = search(*root, key);

    // Caso base: nó não encontrado
    if (toRemove == NULL) {
        printf("Nó com chave %d não encontrado na árvore.\n", key);
        return;
    }

    Node *temp;

    // Caso 1: nó sem filhos
    if (toRemove->left == NULL && toRemove->right == NULL) {
        temp = toRemove;
        if (toRemove->parent == NULL)
            *root = NULL;
        else {
            if (isOnLeft(toRemove))
                toRemove->parent->left = NULL;
            else
                toRemove->parent->right = NULL;
        }
    }

    // Caso 2: nó com um filho
    else if (toRemove->left == NULL || toRemove->right == NULL) {
        temp = toRemove->left ? toRemove->left : toRemove->right;
        if (toRemove->parent == NULL)
            *root = temp;
        else {
            if (isOnLeft(toRemove))
                toRemove->parent->left = temp;
            else
                toRemove->parent->right = temp;
        }
        temp->parent = toRemove->parent;
    }

    // Caso 3: nó com dois filhos
    else {
        Node *successor = getSuccessor(toRemove);
        toRemove->key = successor->key;
        removeNode(root, successor->key);
        return;
    }
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

bool isOnLeft(Node* node) {
    return node == node->parent->left;
}

Node* getSuccessor(Node* node) {
    Node* current = node->right;
    while (current->left != NULL)
        current = current->left;
    return current;
}