#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;


const int TAM = 10;            // tabuleiro TAM x TAM
const int QTD_NAVIOS = 5;      // navios por frota
const int TOTAL_CASAS = 17;    // 5 + 4 + 3 + 3 + 2 casas de navio
const int MAX_PARTIDAS = 500;  // limite de partidas lidas para o ranking

struct Navio{
    string nome;
    string identificador;
    int tamanho;
    int acertos;
    bool afundado;
};

struct Estatisticas{
    string dataHora;
    string nomeJogador;
    string resultado;
    int ataques;
    int acertos;
    int erros;
    int naviosAfundados;
    double precisao;
};

int lerInteiro(string mensagem, int minimo, int maximo);
void limparBuffer();
string obterDataHora();
int letraParaNumero(char coluna);
void menu();
void regras();
void desenhar_tabuleiro(string tabuleiro[TAM][TAM]);
void desenhar_tabuleiro(string tabuleiro_a[TAM][TAM], string tabuleiro_b[TAM][TAM], string tabuleiro_ataques[TAM][TAM]);
void inicializarTabuleiro(string tabuleiro[TAM][TAM]);
void posicionarNavio(string tabuleiro[TAM][TAM], int tamanho, string identificador);
void posicionarNavioJogador(string tabuleiro[TAM][TAM], int tamanho, string identificador, string nomeNavio);
void setarTabuleiro(string tabuleiro_a[TAM][TAM], string tabuleiro_b[TAM][TAM], Navio naviosJogador[], Navio naviosComputador[]);
bool atacar(string tabuleiro_inimigo[TAM][TAM], string tabuleiro_visao[TAM][TAM], int &acertos, int &tentativas, Navio naviosInimigo[], int quantidadeNavios);
bool ataqueComputador(string tabuleiro_jogador[TAM][TAM], string tabuleiro_ataques[TAM][TAM], int &acertos, Navio naviosJogador[], int quantidadeNavios);
void atualizarNavios(string tabuleiroReal[TAM][TAM], string tabuleiroVisao[TAM][TAM], Navio navios[], int quantidade, bool mostrarMensagem);
bool verificarVitoria(int acertos);
void mostrarEstatisticas(Estatisticas estatisticas);
void salvarHistorico(Estatisticas estatisticas);
void mostrarHistorico();
void mostrarRanking();
void batalha_naval();

#endif