void insertNode(Node** root, int key) {
    Node *newNode = newNode(key, RED); // Novo nó é sempre inserido como vermelho

    // Caso base: árvore vazia
    if (*root == NULL) {
        *root = newNode;
        fixViolations(root, newNode);
        return;
    }

    // Encontra o lugar correto para inserir o novo nó
    Node *current = *root, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    // Insere o nó
    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    newNode->parent = parent;

    // Corrige as violações da Árvore Red-Black
    fixViolations(root, newNode);
}