#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//----------ler aposta----------------

void ler_aposta(int *aposta, int n) {
    int x;

    for(x = 0; x < n; x++) {
        printf("Informe os numeros apostados: \n");
        scanf("%d", &aposta[x]);
        if(aposta[x] < 0 || aposta[x] > 100) {
            do {
                printf("Informe apenas numeros entre 0 e 100 \n");
                scanf("%d", &aposta[x]);
            } while(aposta[x] < 0 || aposta[x] > 100);
        }
    }
}

//-----------sorteia valores----------------

void sorteia_valores(int *sorteio, int n) {
    int x, y;

    srand(time(NULL));

    for(x = 0; x < n; x++) {
        sorteio[x] = rand() % 100;
    }

    for(y = 0; y < n; y++) {
        printf("%d ", sorteio[y]);
    }
    printf("\n");
}

//----------------compara aposta--------------

int* compara_aposta(int *aposta, int *sorteio, int *acerto, int *qtdacertos, int na, int ns) {
    int x, y;

    for(x = 0; x < na; x++) {
        for(y = 0; y < ns; y++) {
            if(aposta[x] == sorteio[y]) {
                *qtdacertos += 1;
                acerto[x] = aposta[x];
                printf("%d ", acerto[x]);
                break;
            }
        }
    }

    printf("\nSua quantidade de acertos foi: %d\n", *qtdacertos);

    return acerto;
}

//-----------------main---------------

void main(void)
{
    int *aposta, *sorteio, *acerto, qtdacertos = 0, n, *a;
    int i;

    printf("Informe a quantidade de números da aposta: \n");
    scanf("%d", &n);

    aposta = (int*)calloc(n,sizeof(int));
    sorteio = (int*)calloc(20,sizeof(int));
    acerto = (int*)calloc(n,sizeof(int));

    ler_aposta(aposta, n);
    sorteia_valores(sorteio, 20);
    a = compara_aposta(aposta, sorteio, acerto, &qtdacertos, n, 20);

    free(aposta);
    free(sorteio);
    free(acerto);
}
