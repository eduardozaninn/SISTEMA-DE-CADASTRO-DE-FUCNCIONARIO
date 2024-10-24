#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <locale.h>


//==================================================================



typedef struct {

  int codigo;

   char nome[100];

   char endereco[50];

   char cargo[50];

   char dt_adimissao[50];

   char telefone[15];
    
   float salario; 
    

} Regs_funcionarios;



typedef struct  TipoItem *TipoApontador;

typedef struct TipoItem {

    Regs_funcionarios conteudo;
    TipoApontador prox;

} TipoItem;

typedef struct {

    TipoApontador Primeiro;
    TipoApontador Ultimo;

} TipoLista;




//==================================================================



#define LARGURA_TELA 80


// função para ler cadastro de pessoas


void cursor(int x, int y) {
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}




//==================================================================

void tela() {

    
    //Desenha o rodapé com o título
    const char *titulo = "UNICV             --SISTEMA DE CONTROLE--        EDUARDO ZANIN";
                                                                                   
    int largura = strlen(titulo) + 4; // minima para "UNICV          SISTEMA DE CONTROLE         EDUARDO ZANIN"
    int inicioX = (LARGURA_TELA - largura) / 2;  //Centraliza o roda
    int inicioY = 1;   // Linha rodape superior
    cursor(inicioX, inicioY);

    // Borda esquerda do rodape
    printf("%c", 201);


    // Linhas horizontais superiores
    for (int i = 1; i < largura - 1; i++) {
    printf("%c", 205);
    } 
    // canto superior direito do rodape
    printf("%c\n", 187);


   // Linha do meio com a frase "UNICV          SISTEMA DE CONTROLE         EDUARDO ZANIN"
    cursor(inicioX, inicioY + 1);
    printf("%c %s %c", 186, titulo, 186);


  // Canto inferior esquerdo
    cursor(inicioX, inicioY + 2);
    printf("%c", 200);


    // Linhas horizontais inferior
    for (int i = 1; i < largura - 1; i++) {
    printf("%c", 205);
    }

    // Canto inferior direito
    printf("%C",188);


//==================================================================
    

    // Desenha o rodapé inferior
    cursor(0,22);  // linha inferior
    printf("%c", 201);  // borda esquerda 
    
    for (int i = 1; i < 79; i++) {
    printf("%c", 205); //linha horizontal
    }

    
    printf("%c\n", 187);  // borda direita   
    cursor(1, 23);
    printf("MSG:|| ");
    cursor(6, 23);
    

//==================================================================



   //tela 
    cursor(0, 0);
    printf("%c", 201);  // borda esquerda superior


    for (int i = 1; i < 79; i++) {
    cursor(i,0);
    printf("%c", 205);  //linha horizontal
    }


    cursor(79,0);
    printf("%c\n", 187);  // borda direita superior


    cursor(0,24);
    printf("%c", 200);  // borda esquerda inferior


    for (int i = 1; i < 79; i++) {
    cursor(i,24);
    printf("%c", 205); 
    }


    cursor(79, 24);
    printf("%c\n", 188);  // borda direita inferior



    for (int i = 1; i < 24; i++) { 
    cursor(0,i);
    printf("%c", 186); // Borda Vertical
    cursor(79, i);
    printf("%c", 186);  // Borda vertical direita

    


}
}
//================================================================== 


void setColor(int color) {
    HANDLE hsConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hsConsole, color);
}



void ExibirMenuFuncionarios() {

    
    cursor(4,6);
    printf("  Codigo...........:  ");
    cursor(4, 8);
    printf("1-Nome.............:  ");
    cursor(4, 10);
    printf("2-Endereco.........:  ");
    cursor(4, 12);
    printf("3-Cargo............:  ");
    cursor(4, 14);
    printf("4-Data de Admissao.:  ");
    cursor(4, 16);
    printf("5-Telefone.........:  ");
    cursor(4, 18);
    printf("6-Salario..........:  ");
}


//================================================================== 


TipoApontador pesquisa(TipoLista * L, int cod) {
    TipoApontador aux;
    aux = L->Primeiro;
    while(aux!= NULL){
        if(aux->conteudo.codigo == cod){
            return aux;
        }
        aux = aux -> prox;
    }
    return NULL;
}


//================================================================== 


int contador(TipoLista * L) {
    TipoApontador aux ;
    int cont = 0;
    aux = L->Primeiro;
    while(aux!= NULL){
        cont++;
        aux = aux -> prox;
    
    }
    return cont;
}


//================================================================== 


void cadastro_funcionarios (TipoLista *L, int opc) {
    
   
    TipoApontador p;
    Regs_funcionarios regs_func;
    TipoApontador aux2;
    int resp;
    int x;

do{

  do{

    tela();
    ExibirMenuFuncionarios();

    cursor(13, 4);
    printf("CADASTRAMENTO FUNCIONARIOS");

    cursor(39, 4);
    if (opc == 1) {
        printf(" - INSERIR NO FINAL");
    } else if (opc == 2) {
        printf(" - INSERIR NO INICIO");
    } else if (opc == 3) {
        printf(" - INSERIR NA POSICAO");
    }
    
    cursor(7,23);
    printf(" Digite 0 para retornar...");
    

    cursor(26, 6);
    printf("      ");
    cursor(26, 6);
    scanf("%d", &regs_func.codigo);
    if (regs_func.codigo == 0) {
        fflush(stdout);
        return;
    }

    
    aux2 = pesquisa(L, regs_func.codigo);


    if (aux2!= NULL) {
        cursor(7,23);
        printf(" Funcionario ja cadastrado!");
        getch();
        
      }

  } while (aux2 != NULL);

    


    cursor(26, 8);
    fflush(stdin);
    fgets(regs_func.nome, 50, stdin);
    cursor(26, 10);
    fflush(stdin);
    fgets(regs_func.endereco, 50, stdin);
    cursor(26, 12);
    fflush(stdin);
    fgets(regs_func.cargo, 50, stdin);
    cursor(26, 14);
    fflush(stdin);
    fgets(regs_func.dt_adimissao, 50, stdin);
    cursor(26, 16);
    fflush(stdin);
    fgets(regs_func.telefone, 15, stdin);
    cursor(26, 18);
    scanf("%f", &regs_func.salario);
    getchar();

    
    cursor(7,23);
    printf(" Deseja gravar os dados [1 = Sim; 2 =  Nao]: ");    
    scanf("%d", &resp);
    if (resp == 1) {
        

        p = (TipoApontador) malloc(sizeof(TipoItem));
        p->prox = NULL;

        p->conteudo = regs_func;
        if (opc == 1) {
        if (L -> Primeiro == NULL) {

        L->Primeiro = p;
        L->Ultimo = p;

    } else {
        L->Ultimo->prox = p;
        L->Ultimo = p;
    }

    } else if (opc == 2) {
    if (L ->Primeiro == NULL) {

        L->Primeiro = p;
        L->Ultimo = p;
    }

    else {

        p -> prox = L -> Primeiro;
        L -> Primeiro = p;
    }

  } else if (opc == 3) {

    do {
    cursor(7,23);
    printf("                                                             ");
    cursor(7,23);
    printf(" Qual posicao voce escolhe? ");
    scanf("%d", &resp);
    cursor(7,23);
    printf("                                   ");
 

    if (resp < 1|| resp > contador(L)) {
        cursor(7,23);
        printf(" Posicao invalida!");
        getch();
        }

    } while (resp < 0 || resp > contador(L));

    aux2 = (TipoApontador) malloc (sizeof(TipoItem));
    aux2 ->conteudo = regs_func;

    p = L -> Primeiro;    
    for(x = 1; x <= resp - 2; x++) {
        p = p->prox;
    }
    aux2 -> prox = p ->prox;
    p->prox = aux2;
    
    }

    
    cursor(7,23);
    printf("               ");
    printf(" Funcionario cadastrado com sucesso!");
    getch();
    }

    
    
    cursor(7,23);
    printf(" Deseja cadastrar outro Funcionario, [ 1 = Sim;  2 =  Nao ?]: ");
    scanf("%d", &resp);
    system("cls");
    } while (resp == 1);
    
    if (resp == 2) {
       
        tela();
        

    } 
}
  

//==================================================================


void listar_funcionario(TipoLista *L) {

    TipoApontador p;
    p = L->Primeiro;
    while (p != NULL) {

        tela();
        ExibirMenuFuncionarios();
        cursor(26,6);
        printf("%d", p->conteudo.codigo);
        cursor(26, 8);
        printf("%s", p ->conteudo.nome);
        cursor(26, 10);
        printf("%s", p -> conteudo.endereco);
        cursor(26, 12);
        printf("%s", p -> conteudo.cargo);
        cursor(26, 14);
        printf("%s", p -> conteudo.dt_adimissao);
        cursor(26, 16);
        printf("%s", p -> conteudo.telefone);
        cursor(26, 18);
        printf("%.2f", p -> conteudo.salario);
        p = p -> prox;
        getch();
        


        cursor(7,23);
        printf(" Pressione qualquer tecla para continuar...");
        getch();
        system("cls");
    }
}


//==================================================================


void remover_final(TipoLista *L) {
    //VERIFICA SE A LISTA ESTA VAZIA
    if (L->Primeiro == NULL) {
        cursor(7,23);
        printf(" A lista esta vazia! Nao ha funcionario para remover.");
        getch();
        system("cls");
        return;
    }

    //CASO A LISTA TENHA APENAS UM FUNCIONARIO
    if (L->Primeiro == L->Ultimo) {
        free(L->Primeiro);
        L->Primeiro = NULL;
        L->Ultimo = NULL;
        cursor(7,23);
        printf(" Funncionario removido com sucesso. A lista agora, esta vazia."); 
        fflush(stdout);
        getch();
        cursor(7,23);
        printf("                                                                       ");
    
        
        return;
    }


    //CASO A LISTA TENHA MAIS DE UM FUNCIONARIO
    TipoApontador atual = L ->Primeiro;
    while (atual->prox!= L->Ultimo) {
        atual = atual -> prox; // PERCORRE ATE O PENULTIMO ELEMENTO
    }


    // REMOVE O ULTIMO FUNCIONARIO
    free(L->Ultimo);
    L->Ultimo = atual;
    L -> Ultimo -> prox = NULL; //

    cursor(7,23);
    printf(" Funcionario removido com sucesso.");
    getch();
    system("cls");
}


//==================================================================

void remover_inicio(TipoLista *L) {

    tela(); 

    // VERIFICA SE A LISTA ESTA VAZIA
    if (L->Primeiro == NULL) {
        cursor(7,23);
        printf(" A lista esta vazia! Nao ha funcionario para remover.");
        getch();
        system("cls");
        return;
    }


    // PONTEIRO TEMPORARIO PARA ARMAZENAR O NÓ
    TipoApontador temp = L->Primeiro;


    // AJUSTA O PONTEIRO "PRI" PARA PROXIMO NO
    L->Primeiro = L->Primeiro->prox;

    // SE A LISTA FICOU VAZIA APOS A REMOÇÃO, AJUSTA O PONTEIRO
    if (L->Primeiro == NULL) {
        L->Ultimo = NULL;
    }

    // LIBERA A MEMORIA DO FUNCIONARIO REMOVIDO
    free(temp);

    cursor(7,23);
    printf(" Funcionario removido com sucesso do inicio da lista.");
    getch();
    system("cls");
}


//==================================================================


void remover_posicao(TipoLista *L) {
    

    if (L-> Primeiro == NULL) {
        tela();
        cursor(7,23);
        printf(" A lista esta vazia! Nao ha funcionario para remover.");
        getch();
        system("cls");
        return;
        }

        int posicao;
        tela();
        cursor(7,23);
        printf(" Digite a posicao do funcionario a ser removido: ");
        scanf("%d", &posicao);
        fflush(stdout);
        system("cls");

        TipoApontador atual = L->Primeiro;
        TipoApontador anterior = NULL;
        int contador = 1;


        if(posicao == 1) {
            L -> Primeiro = atual -> prox;
            free(atual);
        

           if ( L -> Primeiro == NULL) {
            L->Ultimo = NULL;
           }

            tela();
            cursor(7,23);
            printf(" Funcionario removido com sucesso do inicio da lista.");
            getch();
            system("cls");
            return;
            }

            while (atual != NULL && contador < posicao) {
            anterior = atual;
            atual = atual -> prox;
            contador++;
        }

        if (atual == NULL) {
            cursor(7,23);
            printf(" Posicao invalida! Nao ha funcionario na posicao %d", posicao);
            getch();
            system("cls");
            return;
        }
        
        anterior -> prox = atual -> prox;

        if (atual -> prox == NULL) {
            L->Ultimo = anterior;
        }

        free(atual);
        tela();
        cursor(7,23);
        printf(" Funcionario removido da posicao %d! \n", posicao);
        getch();
        system("cls");
}

//==================================================================

void alterar_funcionario(TipoLista *L) {
    
    TipoApontador aux2;
    Regs_funcionarios regs_func;
    int resp;
    int campo;
    
    
    do {
        do {

        tela();
        ExibirMenuFuncionarios();
        cursor(25,4);
        printf("ALTERARACAO DE FUNCIONARIO");
        cursor(7, 23);
        printf(" Digite 0 para estar saindo...");
        cursor(7, 23);
        printf("                             ");
        cursor(26, 6);
        scanf("%d", &regs_func.codigo);
        



        aux2 = pesquisa(L, regs_func.codigo);
        if (aux2 == NULL && regs_func.codigo != 0) {
            cursor(7,23);
            printf(" Funcionario nao encontrado!");
            getch();
            system("cls");
            return;
            }


        } while (aux2 == NULL && regs_func.codigo != 0);


        if (regs_func.codigo != 0) {
            regs_func = aux2 -> conteudo;

            cursor(26,8);
            printf("%s", regs_func.nome);
            cursor(26,10);
            printf("%s", regs_func.endereco);
            cursor(26,12);
            printf("%s", regs_func.cargo);
            cursor(26,14);
            printf("%s", regs_func.dt_adimissao);
            cursor(26,16);
            printf("%s", regs_func.telefone);
            cursor(26,18);
            printf("%.2f", regs_func.salario);

           do {
              do {
            cursor(7,23);
            printf("                                               ");

            cursor(7,23);
            printf(" Escolha o campo a ser alterado [0 - SAIR]:");
            scanf("%d", &campo);
            fflush(stdin);
            
            if (campo < 0 || campo > 6) {
                cursor(7,23);
                printf("                                               ");
                cursor(7,23);
                printf(" Campo invalido! Escolha um numero entre 1 e 6.");
                getch();
               }

           } while (campo < 0 || campo > 6);
           if (campo != 0) {
              
              
              switch (campo) {
                case 1:
                    cursor(26,8);
                    printf("                                      ");
                    cursor(24,8);
                    fflush(stdin);
                    fgets(regs_func.nome,50,stdin);
                    break;
                    
                case 2:
                    cursor(26,10);
                    printf("                                      ");
                     cursor(26,10);
                     fflush(stdin);
                     fgets(regs_func.endereco,50,stdin);
                     break;

                case 3:
                    cursor(26,12);
                    printf("                                      ");
                     cursor(26,12);
                     fflush(stdin);
                     fgets(regs_func.cargo,50,stdin);
                     break;

                case 4:
                    cursor(26,14);
                    printf("                                      ");
                     cursor(26,14);
                     fflush(stdin);
                     fgets(regs_func.dt_adimissao,50,stdin);
                     break;


                case 5:
                    cursor(26,16);
                    printf("                                      ");
                      cursor(26,16);
                      fflush(stdin);
                      fgets(regs_func.telefone,15,stdin);
                      break;

                case 6:
                    cursor(26,18);
                    printf("                                      ");
                     cursor(26,18);
                     scanf("%f", &regs_func.salario);
                     break;
                }
             }
           } while (campo != 0);
           cursor(7,23);
           printf("                                                  ");
           cursor(7,23);
           printf(" Confirma a alteracao [1 - Sim / 2 - Nao]? ");
           scanf("%d", &resp);
        
           
           
            if (resp == 1) {

                aux2 -> conteudo = regs_func;
            }
        }
      
        tela();
        cursor(7,23);
        printf(" Deseja Alterar outro Funcionario [1 - Sim  / 2 - Nao]? ");
        scanf("%d", &resp);
        cursor(7,23);
        printf(" ");
        system("cls");


    } while (resp == 1);
}


//==================================================================


void salvarfuncionarios(TipoLista * L) {    
    FILE *arquivofunc = fopen("funcionarios.dat", "wb");
    if (arquivofunc == NULL) {
        tela();
        cursor(7,23);
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    TipoApontador aux = L-> Primeiro;
    while (aux != NULL) {
        fwrite(&aux->conteudo, sizeof(Regs_funcionarios), 1, arquivofunc);
        aux = aux->prox;
    }

    fclose(arquivofunc);
    cursor(7,23);
    printf("Funcionarios salvos com sucesso!");
    getch();
}


//==================================================================


void lerDoArquivo(TipoLista *L) {
    tela();
    FILE *arquivofunc = fopen("funcionarios.dat", "rb");
    if (arquivofunc == NULL) {
    tela();
    cursor(7,23);
    printf(" Erro ao abrir o arquivo!");
    getch();
    system("cls");
    return;
    
    
    
}

Regs_funcionarios temp;
 while (fread(&temp, sizeof(Regs_funcionarios), 1, arquivofunc)) {
    TipoApontador novo = (TipoApontador) malloc(sizeof(TipoItem));
    novo->conteudo = temp;
    novo->prox = NULL;

    if ( L -> Primeiro == NULL) {
        L -> Primeiro = novo;
    } 
    else {
        L -> Ultimo->prox = novo;   
    }
    L -> Ultimo = novo;

 }
    
    
    
    fclose(arquivofunc);
    cursor(7,23);
    printf(" Dados Lidos com sucesso do arquivo!");
    getch();
    system("cls");


    
}

int main() {
    tela();
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    int opc;
   
    
    system("color B"); //cor do console
    do{
        
        tela();
        cursor(25, 4);
        printf("CADASTRAMENTO DE FUNCIONARIO");
        cursor(10,6);
        printf("1 - Cadastrar Funcionario no Final");
        cursor(10, 8);  
        printf("2 - Cadastrar Funcionario no Inicio ");
        cursor(10,10);
        printf("3 - Cadastrar Funcionario na Posicao ");
        cursor(10,12);
        printf("4 - Remover Funcionario no final ");
        cursor(10,14);
        printf("5 - Remover Funcionario no incio ");
        cursor(10,16);
        printf("6 - Remover Funcionario na Posicao ");
        cursor(10,18);
        printf("7 - Alteracao do Funcionario ");
        cursor(10,20);
        printf("8 - Listar Funcionarios ");
        cursor(53,6);
        printf("9 - Sair ");
        cursor(53, 8);
        printf("10 - Salvar Backup");
        cursor(53, 10);
        printf("11- Restaurar Backup");
        cursor(7,23);
        printf(" Digite sua opcao: "); 
        scanf("%d", &opc);
        cursor(7,23);
        printf("                                                     ");

    
        
        
        system("cls");
        
        switch (opc) {


         case 1:

            system("cls");
            tela();
            cadastro_funcionarios(&L, opc);
            system("cls");
            cursor(51,23);   
            
                   
            break;


        case 2:

            cadastro_funcionarios(&L, opc);
            system("cls");
            break;
        

        case 3:

             cadastro_funcionarios(&L, opc);
             system("cls");
             break;
            

        case 4:
            
            tela();
            remover_final(&L);
            break;
        

        case 5:
  
            remover_inicio(&L);
            break;

        case 6:
            tela();
            remover_posicao(&L);
            break;

        case 7:
            tela();
            alterar_funcionario(&L);
            break;


        case 8:
             listar_funcionario(&L);
             break;

        case 9:
            tela();
            cursor(30,12);
            printf("Saindo do programa...\n");
            getch();
            system("cls");
            return 0;
            break;

        case 10:
            tela();
            salvarfuncionarios(&L);
            cursor(7,23);
            printf("                                       ");
            break;
        
        case 11:
            tela();
            lerDoArquivo(&L);
            break;

        default:
            system("cls");
            tela();
            cursor(30,12);
            printf("Opcao invalida!\n");
            getch(); 
            break;   
        }
    } while (opc!= 0);


    return 0;
}