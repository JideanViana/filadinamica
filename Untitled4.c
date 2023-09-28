

    typedef struct No{
        int x;
        struct No* proximo;
    }No;
    typedef struct{
        No* inicio;
        No* fim;
    }Fila;

    Fila* CriarFila () {

        Fila* fila = malloc(sizeof(Fila));
        fila->inicio = NULL;
        fila->fim = NULL;

        return fila;
    }

    void inserir(Fila *fila, int valor){

        No* novoNo = malloc(sizeof(No));
        novoNo->x = valor;
        novoNo->proximo = NULL;

        if(fila->inicio == NULL){
            fila->inicio = novoNo;
            fila->fim = novoNo;
        } else {
            fila->fim->proximo = novoNo;
            fila->fim = novoNo;
        }
    }
    void remover(Fila *fila){
        if(fila->inicio == NULL) {
            printf("vazia.\n");
            return;
        }
        No* noRemovido = fila->inicio;
        int valorRemovido = noRemovido->x;

        fila->inicio = fila->inicio->proximo;
        free(noRemovido);
        printf("%d tirado", valorRemovido);

        if(fila->inicio == NULL)
        fila->fim = NULL;

        return;
    }
