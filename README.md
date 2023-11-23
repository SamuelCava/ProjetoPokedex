# ProjetoPokedex
Segue neste arquivo as instruções referentes a 1º Entrega do Projeto Pokedex da Disciplina (parte básica) Grupo: Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br) Data de entrega: 22/11/2023

-> A versão de entrega será a branche v8. Essa versão contém os arquivos em que trabalhamos até o momento, com a parte básica de cadastro e manipulação dos dados funcionando conforme solicitado. A versão também, já contempla conteúdos como (Variáveis, funções, arquivos etc...) escritos como esqueleto inicial para a parte criativa, aos quais ainda não estão operacionais, por exemplo, as opções exibir itens e batalha pokemon.

-> COMPILAR o código: Para compilar o código já foi gerado um arquivo MAKEFILE ao qual (obs. Até pelo o que realizamos testes no mesmo dia mais cedo, dia 22/11/2023) concluímos que está executando com êxito, rodar somente no Linux.

No entanto como medida de precaução ou opcao para o Windows, também deixo em questão o comando necessário a ser digitado no terminal:

gcc pokemon.c pokedex.c abre_arquivo.c busca_pokemon.c mochila.c colecao.c carrega.c menu.c main.c sair.c -o main ./main

-> OBSERVAÇÕES sobre o código

Nesta versão, conforme o projeto foi se desenvolvendo partimos da ideia de manter as exibições do terminal somente operacional para controle de compreensão sobre as funções que estariam sendo feitas. Já que o grupo se propôs a implementar a exibição usando o Raylib, por este motivo o terminal o não possue acabamentos e formatações de exibição de texto, uma vez que toda essa parte seria transformada para outro método. No entando, deixo esclarecido que ao analisar as determinadas funcionalidades do código, é possível identificar o êxito das funções, por exemplo, sugiro que execute o comando Pokedex > Excluir e logo após Pokedex > Pesquisar, realizando essa sequência para um mesmo código de pokemon informado, será possível observar que a função foi executada com sucesso. Provando a regularidade do código nos aspectos exigidos inicialmente.
