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
    int geração;
    int lendario; // na verdade é bool aqui
    char cor[20];
    float altura;
    float peso;
    int taxa_captura;
    int proxima_evolucao;
    int pre_eveolucao;

}Pokemon;


typedef struct{
    /*
    Defina uma estrutura Mochila que deve armazenar a relação de até 6 Pokémons já
    capturados e que poderão ser utilizados em batalha, para isso armazene apenas o
    número(códigos).
    
    */
    // diz quantos pokemons tem na mochila
    int pokemon_mochila;
    int codigos_pokemon[6];

}Mochila;


typedef struct{
    
   /*
   ◦ Defina uma estrutura Coleção que deve armazenar a relação dos Pokémons já
   capturados, para isso armazene apenas o número(códigos). Essa relação deve
   aumentar e diminuir dinamicamente. Você deve prever o caso de Pokémons duplicados.
   O sistema deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os pokémons
   já capturados.
   */


}Colecao;

/*
◦
// string formatada


feito: struct pokemon
Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.

◦ Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas;
◦ A lista com os dados iniciais para o Pokédex será construída lendo os dados de um
arquivo .csv (valores separados por vírgula) disponibilizado que deve ser lido e
carregado em um vetor de tamanho dinâmico na primeira abertura do programa.
◦ Ao sair do programa, todos os dados devem ser salvos em arquivos binários no HD e
1
recarregados novamente ao iniciar. Caso os arquivos não existam, eles devem ser
criados e uma mensagem de boas vindas deve ser apresentada ao usuário;
◦ O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por v

*/
#include <stdlib.h>
#include <stdio.h>
#include <menu.h>

int main(){
	while (true){
		int opcao = menu_principal();
		switch (opcao){
		case 1:
			/* code */
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}
	}
    return 0;
}