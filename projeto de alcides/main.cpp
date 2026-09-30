#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include "funcoes.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    // Inicializa o gerador aleatorio apenas uma vez durante o programa.
    srand(time(NULL));

    int op = 0;

    while(op != 5){
        system("cls");
        menu();
        op = lerInteiro("\nEscolha uma opcao: ", 1, 5);

        switch(op){
            case 1:{
                system("cls");
                batalha_naval(); // Inicia o jogo
                break;
            }
            case 2:{
                system("cls");
                regras(); // adicionei as regras pra caso a pessoa esqueça, lembrar na hora. att, Vinicius.
                break;
            }
            case 3:{
                system("cls");
                mostrarHistorico();
                break;
            }
            case 4:{
                system("cls");
                mostrarRanking();
                break;
            }
            case 5:{
                cout << "\nSaindo do jogo... Ate a proxima!\n";
                break;
            }
        }
    }

    return 0;
}