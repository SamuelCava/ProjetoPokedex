typedef struct {
    int numero;
    // mudar esse 20
    char nome[20];
    char tipo1[20];
    char tipo[20];
    int total;
    int ataque;
    int defesa;
    int ataque_especial;
    int defesa_especial;
    int velocidade;
    int geracao;
    int lendario; // na verdade é bool aqui
    char cor[20];
    float altura;
    float peso;
    int taxa_captura;
    int proxima_evolucao;
    int pre_evolucao;

}Pokemon;