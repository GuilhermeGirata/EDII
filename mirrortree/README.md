# mirrorTree

O espelho de uma árvore binária T, esp(T), é a árvore binária definida recursivamente da seguinte forma:

- Se T for vazia então esp(T) é a árvore vazia;
- Se T tem raiz Tr, subárvore da esqueda Te e suárvore da direita Td, então esp(T) é a árvore binária com raiz Tr, subárvore esquerda esp(Td) e subárvore direita esp(Te).

Com base nessa definição implemente duas funções:

1) A função "eh_espelho¨ que retorna 1 se duas árvores são espelhos entre si e 0 em contrário.
int eh_espelho(Arvore * arv_a, Arvore * arv_b);

2) A função "cria_espelho" que retorna uma nova árvore que é espelho à árvore passada como parâmetro;
Arvore * cria_espelho(Arvore * arv_a);

Funções eh_espelho e cria_espelho
