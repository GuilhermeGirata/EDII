void fixViolations(Node** root, Node* current) {
    Node *parent, *grandParent;

    while ((parent = current->parent) && parent->color == RED) {
        grandParent = parent->parent;

        // Caso esquerdo-esquerdo
        if (parent == grandParent->left) {
            Node *uncle = grandParent->right;

            // Caso 1: tio vermelho
            if (uncle && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                current = grandParent;
            } else {
                // Caso 2: tio preto, filho à direita
                if (current == parent->right) {
                    leftRotate(root, parent);
                    current = parent;
                    parent = current->parent;
                }

                // Caso 3: tio preto, filho à esquerda
                rightRotate(root, grandParent);
                swapColors(parent, grandParent);
                current = parent;
            }
        }

        // Caso direito-direito
        else {
            Node *uncle = grandParent->left;

            // Caso 1: tio vermelho
            if (uncle && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                current = grandParent;
            } else {
                // Caso 2: tio preto, filho à esquerda
                if (current == parent->left) {
                    rightRotate(root, parent);
                    current = parent;
                    parent = current->parent;
                }

                // Caso 3: tio preto, filho à direita
                leftRotate(root, grandParent);
                swapColors(parent, grandParent);
                current = parent;
            }
        }
    }

    (*root)->color = BLACK;
}

void leftRotate(Node** root, Node* current) {
    Node *newParent = current->right;
    current->right = newParent->left;

    if (current->right != NULL)
        current->right->parent = current;

    newParent->parent = current->parent;

    if (current->parent == NULL)
        *root = newParent;
    else if (current == current->parent->left)
        current->parent->left = newParent;
    else
        current->parent->right = newParent;

    newParent->left = current;
    current->parent = newParent;
}

void rightRotate(Node** root, Node* current) {
    Node *newParent = current->left;
    current->left = newParent->right;

    if (current->left != NULL)
        current->left->parent = current;

    newParent->parent = current->parent;

    if (current->parent == NULL)
        *root = newParent;
    else if (current == current->parent->left)
        current->parent->left = newParent;
    else
        current->parent->right = newParent;

    newParent->right = current;
    current->parent = newParent;
}

void swapColors(Node* x, Node* y) {
    Color temp = x->color;
    x->color = y->color;
    y->color = temp;
}