typedef struct{
    int capturados;
    // tamanho representa o espaço de quantos int tenho pra usar
    int tamanho = 10;
    int *codigo_capturados;
}Colecao;


void inicia_vetor(Colecao colecao);
void inserir_pokemon(int codigo, Colecao colecao);
void listar_pokemons(Colecao colecao);
void pesquisar_pokemon(int codigo, Colecao colecao);
void alterar_pokemon(int codigo, Colecao colecao);
void excluir_pokemon(int codigo, Colecao colecao);