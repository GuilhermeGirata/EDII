boolean eh_espelho(Arvore * arv_a, Arvore * arv_b);
    if (arv_a==NULL && arv_b==NULL)
        return true;

    if (arv_a==NULL || arv_b == NULL)
        return false;

    return  arv_a->data == arv_b->data &&
    	eh_espelho(arv_a->left, arv_b->right) &&
    	eh_espelho(arv_a->right, arv_b->left);
}

Arvore * cria_espelho(Arvore * arv_a);
{
    if (arv_a == NULL)
        return;
    else {
        int temp;

        mirror(arv_a->left);
        mirror(arv_a->right);

        temp = arv_a->left;
        arv_a->left = arv_a->right;
        arv_a->right = temp;
    }
}
