#include <iostream> // Entrada e Saída Básica: Dá acesso aos objetos principais de terminal.
#include <cctype> // Manipulação e Teste de Caracteres: Contém funções para verificar o tipo de um caractere ou alterá-lo.
#include <limits> // Limites de Tipos de Dados: Fornece informações sobre as propriedades dos tipos numéricos (como os valores mínimo e máximo que um int ou float suporta).
#include <locale.h> // Acentuação e Região: Controla configurações locais, como a codificação de caracteres e acentuação (idioma do sistema).
#include <stdlib.h> // Funções Utilitárias Gerais: Contém rotinas para conversão de números, alocação de memória, controle de processos e geração de números aleatórios.
#include <time.h> // Manipulação de Data e Hora: Utilizado para obter o tempo atual do sistema.
#include <fstream> // Manipulação de Arquivos: Permite criar, ler e escrever dados em arquivos salvos no computador (como .txt).
#include <iomanip> // Formatação de Saída: Sigla para Input/Output Manipulators. Permite formatar a exibição de dados na tela.
#include <string> // Manipulação de Textos: Adiciona o tipo de dado string, permitindo trabalhar com cadeias de texto de forma simples.
#include "funcoes.h" // 

using namespace std;
/* 
 * FUNÇÃO: lerInteiro
 * OBJETIVO: Garante a leitura de um número inteiro dentro de um intervalo válido (minimo ate maximo).
 * COMO FUNCIONA:
 * - Entra em um loop continuo pedindo a entrada do usuario.
 * - Se o valor for um numero e estiver dentro do intervalo [minimo, maximo], retorna o valor.
 * - Se o valor for um numero fora do intervalo, exibe mensagem de alerta.
 * - Se o usuario digitar letras ou caracteres invalidos, limpa o estado de erro do cin (cin.clear())
 *   e descarta o buffer de entrada (cin.ignore()) para evitar loops infinitos.
 */
int lerInteiro(string mensagem, int minimo, int maximo){
    int valor;
    while(true){
        cout << mensagem;

        if(cin >> valor){
            if(valor >= minimo && valor <= maximo){
                return valor;
            }

            cout << "[!] Valor invalido! Digite um numero entre "
                 << minimo << " e " << maximo << ".\n";
        }else{
            cout << "[!] Entrada invalida! Digite apenas numeros.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
/* 
 * FUNÇÃO: letraParaNumero
 * OBJETIVO: Converte a letra que representa a coluna do tabuleiro ('A' a 'J') em um indice numerico (1 a 10).
 * COMO FUNCIONA:
 * - Converte o caractere recebido para maiusculo usando toupper().
 * - Verifica se a letra esta entre 'A' e 'J'.
 * - Calcula a posição da letra subtraindo 'A' do seu valor ASCII e somando 1.
 * - Retorna -1 caso a letra esteja fora do intervalo permitido.
 */
int letraParaNumero(char coluna){
    coluna = toupper(static_cast<unsigned char>(coluna));

    if(coluna >= 'A' && coluna <= 'J'){
        return coluna - 'A' + 1;
    }

    return -1;
}
/* 
 * FUNÇÃO: limparBuffer
 * OBJETIVO: Descarta o que sobrou na linha de entrada (normalmente o '\n' deixado por cin >> ...).
 * COMO FUNCIONA:
 * - Usa cin.ignore() para remover caracteres ate encontrar o fim da linha.
 * - Deve ser chamada antes de getline() ou cin.get() quando a leitura anterior foi feita com cin >>.
 */
void limparBuffer(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
/* 
 * FUNÇÃO: obterDataHora
 * OBJETIVO: Retorna a data e a hora atuais no formato "dd/mm/aaaa hh:mm".
 * COMO FUNCIONA:
 * - Pega o horario do sistema com time() e converte para horario local com localtime().
 * - Formata o resultado em texto com strftime() e devolve como string.
 */
string obterDataHora(){
    time_t agora = time(NULL);
    tm *info = localtime(&agora);
    char buffer[20];

    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M", info);

    return string(buffer);
}
/* 
 * FUNÇÃO: menu
 * OBJETIVO: Imprime no terminal o menu principal com as opções de navegação do jogo.
 * COMO FUNCIONA:
 * - Apenas exibe o layout do menu formatado na tela com cout (nao realiza leitura de dados).
 */
void menu(){
    cout << "\n========================================\n"
         << "              BATALHA NAVAL             \n"
         << "========================================\n"
         << "[1] - Jogar single-player\n"
         << "[2] - Regras do jogo\n"
         << "[3] - Historico de partidas\n"
         << "[4] - Ranking (melhores vitorias)\n"
         << "[5] - Sair\n"
         << "========================================\n";
}
/* 
 * FUNÇÃO: regras
 * OBJETIVO: Exibe as instrucoes e regras do jogo para o usuario.
 * COMO FUNCIONA:
 * - Imprime um texto explicativo com o objetivo do jogo, dimensoes do tabuleiro, tipos de navios e marcadores.
 * - Utiliza system("pause") para pausar a tela ate que o jogador pressione alguma tecla antes de retornar.
 */
void regras(){
    cout << "\n========================================\n"
         << "              REGRAS DO JOGO             \n"
         << "========================================\n\n"
         << "OBJETIVO\n"
         << "Destrua todos os navios do computador antes\n"
         << "que ele destrua todos os seus navios.\n\n"
         << "TABULEIRO\n"
         << "- O tabuleiro possui " << TAM << " linhas e " << TAM << " colunas.\n"
         << "- As linhas vao de 1 a " << TAM << ".\n"
         << "- As colunas vao de A a J.\n\n"
         << "SEUS NAVIOS\n"
         << "[P] Porta-avioes       - 5 casas\n"
         << "[N] Navio-tanque       - 4 casas\n"
         << "[C] Contratorpedeiro   - 3 casas\n"
         << "[C] Contratorpedeiro   - 3 casas\n"
         << "[S] Submarino          - 2 casas\n\n"
         << "POSICIONAMENTO\n"
         << "- Cada navio deve ser colocado na horizontal\n"
         << "  ou na vertical.\n"
         << "- Um navio nao pode ultrapassar o tabuleiro.\n"
         << "- Dois navios nao podem ocupar a mesma casa.\n\n"
         << "ATAQUES\n"
         << "- A cada turno, informe uma linha e uma coluna.\n"
         << "- [X] significa que um tiro acertou um navio.\n"
         << "- [O] significa que o tiro acertou a agua.\n"
         << "- Uma coordenada que ja foi atacada nao pode\n"
         << "  ser escolhida novamente.\n\n"
         << "NAVIO AFUNDADO\n"
         << "- Um navio e afundado quando todas as suas casas\n"
         << "  forem atingidas.\n"
         << "- O jogo informa qual navio foi destruido.\n\n"
         << "ESTATISTICAS\n"
         << "- Ao final da partida sao exibidos ataques,\n"
         << "  acertos, erros, precisao e navios afundados.\n"
         << "- O resultado tambem pode ser salvo no historico.\n\n"
         << "VITORIA\n"
         << "- Voce vence ao acertar todas as " << TOTAL_CASAS << " casas dos\n"
         << "  navios do computador.\n"
         << "- O computador vence se acertar todas as " << TOTAL_CASAS << "\n"
         << "  casas dos seus navios.\n\n"
         << "========================================\n";

    system("pause");
}
/* 
 * FUNÇÃO: simboloVisivel
 * OBJETIVO: Padronizar a exibicao dos contratorpedeiros na interface.
 * COMO FUNCIONA:
 * - Como o programa diferencia internamente dois contratorpedeiros ("C1" e "C2"), esta função 
 *   converte ambos para a string "[C]", escondendo essa diferenca tecnica da tela do jogador.
 */
string simboloVisivel(string valor){
    if(valor == "[C1]" || valor == "[C2]") return "[C]";
    return valor;
}
/* 
 * FUNÇÃO: imprimirCabecalhoColunas (auxiliar)
 * OBJETIVO: Imprime a linha de letras das colunas (A, B, C...) acima de um tabuleiro.
 */
void imprimirCabecalhoColunas(){
    cout << "    ";
    for(int j = 0; j < TAM; j++){
        cout << "  " << static_cast<char>('A' + j);
    }
}
/* 
 * FUNÇÃO: imprimirTabuleiroProprio (auxiliar)
 * OBJETIVO: Desenha o tabuleiro do jogador, com os navios visiveis.
 * COMO FUNCIONA:
 * - Se 'ataques' nao for nullptr, os tiros do computador ([X] ou [O]) sao desenhados por cima dos navios.
 * - Se for nullptr (fase de posicionamento), mostra apenas os navios.
 */
void imprimirTabuleiroProprio(string tabuleiro[TAM][TAM], string ataques[TAM][TAM]){
    imprimirCabecalhoColunas();

    for(int i = 0; i < TAM; i++){
        cout << "\n";
        if(i + 1 < 10) cout << " ";
        cout << (i + 1) << "    ";

        for(int j = 0; j < TAM; j++){
            if(ataques != nullptr && ataques[i][j] != "[ ]"){
                cout << ataques[i][j];
            }else{
                cout << simboloVisivel(tabuleiro[i][j]);
            }
        }
    }
}
/* 
 * FUNÇÃO: desenhar_tabuleiro (versao com 1 tabuleiro)
 * OBJETIVO: Desenha somente o tabuleiro do jogador. Usada na fase de posicionamento dos navios.
 * COMO FUNCIONA:
 * - Sobrecarga de desenhar_tabuleiro: o compilador escolhe esta versao quando a chamada tem 1 argumento.
 */
void desenhar_tabuleiro(string tabuleiro[TAM][TAM]){
    cout << "\n------------- SEU TABULEIRO -------------\n\n";
    imprimirTabuleiroProprio(tabuleiro, nullptr);
    cout << "\n";
}
/* 
 * FUNÇÃO: desenhar_tabuleiro (versao com 3 tabuleiros)
 * OBJETIVO: Renderiza os dois tabuleiros (jogador e inimigo) durante a partida.
 * COMO FUNCIONA:
 * - Tabuleiro A (Jogador): Mostra seus navios e, por cima, os tiros do computador ([X] acerto, [O] agua).
 * - Tabuleiro B (Inimigo): Aplica uma "nevoa de guerra". Exibe apenas acertos ([X]), agua ([O])
 *   ou casas nao exploradas ([ ]). Oculta os navios inimigos ate que sejam atingidos.
 */
void desenhar_tabuleiro(string tabuleiro_a[TAM][TAM], string tabuleiro_b[TAM][TAM], string tabuleiro_ataques[TAM][TAM]){
    cout << "\n------------- SEU TABULEIRO -------------\n\n";
    imprimirTabuleiroProprio(tabuleiro_a, tabuleiro_ataques);

    cout << "\n\n--------- TABULEIRO INIMIGO ---------\n\n";
    imprimirCabecalhoColunas();

    for(int i = 0; i < TAM; i++){
        cout << "\n";
        if(i + 1 < 10) cout << " ";
        cout << (i + 1) << "    ";

        for(int j = 0; j < TAM; j++){
            if(tabuleiro_b[i][j] == "[X]" || tabuleiro_b[i][j] == "[O]" || tabuleiro_b[i][j] == "[ ]"){
                cout << tabuleiro_b[i][j];
            }else{
                cout << "[ ]";
            }
        }
    }

    cout << "\n\nLegenda: [X] Acerto | [O] Agua | [ ] Nao explorado\n"
         << "No seu tabuleiro, [X] e [O] sao os tiros do computador.\n";
}
/* 
 * FUNÇÃO: inicializarTabuleiro
 * OBJETIVO: Limpa e reseta a matriz 10x10 preenchendo todas as posicoes.
 * COMO FUNCIONA:
 * - Percorre todas as linhas e colunas com dois loops "for" encadeados, preenchendo cada casa com "[ ]".
 */
void inicializarTabuleiro(string tabuleiro[TAM][TAM]){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = "[ ]";
        }
    }
}
/* 
 * FUNÇÃO: posicionarNavio
 * OBJETIVO: Posiciona um navio de forma completamente aleatoria no tabuleiro do computador.
 * COMO FUNCIONA:
 * - Sorteia linha, coluna e direcao (horizontal ou vertical) usando rand().
 * - Verifica se o navio cabe dentro dos limites do tabuleiro.
 * - Checa se nenhuma das casas necessarias esta ocupada por outro navio.
 * - Se o espaco estiver livre, grava a identificacao do navio nessas coordenadas.
 */
void posicionarNavio(string tabuleiro[TAM][TAM], int tamanho, string identificador){
    bool posicionado = false;

    while(!posicionado){
        int linha = rand() % TAM;
        int coluna = rand() % TAM;
        int direcao = rand() % 2;
        bool livre = true;

        if(direcao == 0 && coluna + tamanho > TAM) continue;
        if(direcao == 1 && linha + tamanho > TAM) continue;

        for(int i = 0; i < tamanho; i++){
            int linhaAtual = linha;
            int colunaAtual = coluna;

            if(direcao == 1) linhaAtual += i;
            if(direcao == 0) colunaAtual += i;

            if(tabuleiro[linhaAtual][colunaAtual] != "[ ]"){
                livre = false;
                break;
            }
        }

        if(livre){
            for(int i = 0; i < tamanho; i++){
                int linhaAtual = linha;
                int colunaAtual = coluna;

                if(direcao == 1) linhaAtual += i;
                if(direcao == 0) colunaAtual += i;

                tabuleiro[linhaAtual][colunaAtual] = identificador;
            }

            posicionado = true;
        }
    }
}
/* 
 * FUNÇÃO: posicionarNavioJogador
 * OBJETIVO: Permite que o jogador escolha a posicao dos seus proprios navios no inicio do jogo.
 * COMO FUNCIONA:
 * - Solicita as coordenadas inicial e final (linha e coluna) do navio.
 * - Converte as letras em números e valida se formam uma linha reta (horizontal ou vertical)
 *   com o tamanho exato do navio.
 * - Verifica se nao ha colisao com navios ja posicionados no tabuleiro.
 * - Se tudo estiver correto, insere a identificacao do navio na matriz; caso contrario, pede nova tentativa.
 */
void posicionarNavioJogador(string tabuleiro[TAM][TAM], int tamanho, string identificador, string nomeNavio){
    while(true){
        int linhaInicial, linhaFinal;
        char colunaInicial, colunaFinal;

        system("cls");
        desenhar_tabuleiro(tabuleiro);

        cout << "\n========================================\n"
             << "        POSICIONANDO SEU NAVIO         \n"
             << "========================================\n"
             << "Navio: " << nomeNavio << " [" << identificador[1] << "]\n"
             << "Tamanho: " << tamanho << " casas\n\n"
             << "Informe a coordenada INICIAL do navio.\n"
             << "Linha: 1 a 10 | Coluna: A a J\n\n";

        linhaInicial = lerInteiro("Digite a linha inicial: ", 1, TAM);

        cout << "Digite a coluna inicial (A-J): ";
        cin >> colunaInicial;

        cout << "\nAgora informe a coordenada FINAL do navio.\n"
             << "A coordenada final deve formar um navio de " << tamanho << " casas.\n\n";

        linhaFinal = lerInteiro("Digite a linha final: ", 1, TAM);

        cout << "Digite a coluna final (A-J): ";
        cin >> colunaFinal;

        int colunaInicialNumero = letraParaNumero(colunaInicial) - 1;
        int colunaFinalNumero = letraParaNumero(colunaFinal) - 1;
        int linhaInicialNumero = linhaInicial - 1;
        int linhaFinalNumero = linhaFinal - 1;

        bool coordenadasValidas = colunaInicialNumero >= 0 && colunaInicialNumero < TAM
            && colunaFinalNumero >= 0 && colunaFinalNumero < TAM;

        bool horizontal = coordenadasValidas
            && linhaInicial == linhaFinal
            && abs(colunaFinalNumero - colunaInicialNumero) == tamanho - 1;

        bool vertical = coordenadasValidas
            && colunaInicialNumero == colunaFinalNumero
            && abs(linhaFinalNumero - linhaInicialNumero) == tamanho - 1;

        if(!coordenadasValidas || (!horizontal && !vertical)){
            cout << "\n[!] Posicao invalida!\n"
                 << "Confira as coordenadas, o tamanho e a direcao do navio.\n";
            system("pause");
            continue;
        }

        int passoLinha = (linhaFinalNumero > linhaInicialNumero) ? 1 : -1;
        int passoColuna = (colunaFinalNumero > colunaInicialNumero) ? 1 : -1;
        bool livre = true;

        for(int i = 0; i < tamanho; i++){
            int linhaAtual = linhaInicialNumero;
            int colunaAtual = colunaInicialNumero;

            if(vertical) linhaAtual += i * passoLinha;
            if(horizontal) colunaAtual += i * passoColuna;

            if(tabuleiro[linhaAtual][colunaAtual] != "[ ]"){
                livre = false;
                break;
            }
        }

        if(!livre){
            cout << "\n[!] Posicao invalida!\n"
                 << "O navio nao pode sobrepor outro navio.\n";
            system("pause");
            continue;
        }

        for(int i = 0; i < tamanho; i++){
            int linhaAtual = linhaInicialNumero;
            int colunaAtual = colunaInicialNumero;

            if(vertical) linhaAtual += i * passoLinha;
            if(horizontal) colunaAtual += i * passoColuna;

            tabuleiro[linhaAtual][colunaAtual] = identificador;
        }

        cout << "\n[OK] " << nomeNavio << " posicionado com sucesso!\n";
        system("pause");
        return;
    }
}
/* 
 * FUNÇÃO: setarTabuleiro
 * OBJETIVO: Configura o estado inicial completo do jogo.
 * COMO FUNCIONA:
 * - Limpa as matrizes de ambos os jogadores.
 * - Instancia o conjunto de navios com nomes, identificadores e tamanhos para jogador e computador.
 * - Chama posicionarNavioJogador() para cada navio da frota do jogador.
 * - Chama posicionarNavio() para distribuir aleatoriamente a frota do computador.
 */
void setarTabuleiro(string tabuleiro_a[TAM][TAM], string tabuleiro_b[TAM][TAM], Navio naviosJogador[], Navio naviosComputador[]){
    inicializarTabuleiro(tabuleiro_a);
    inicializarTabuleiro(tabuleiro_b);

    naviosJogador[0] = {"Porta-avioes", "[P]", 5, 0, false};
    naviosJogador[1] = {"Navio-tanque", "[N]", 4, 0, false};
    naviosJogador[2] = {"Contratorpedeiro 1", "[C1]", 3, 0, false};
    naviosJogador[3] = {"Contratorpedeiro 2", "[C2]", 3, 0, false};
    naviosJogador[4] = {"Submarino", "[S]", 2, 0, false};

    naviosComputador[0] = {"Porta-avioes", "[P]", 5, 0, false};
    naviosComputador[1] = {"Navio-tanque", "[N]", 4, 0, false};
    naviosComputador[2] = {"Contratorpedeiro 1", "[C1]", 3, 0, false};
    naviosComputador[3] = {"Contratorpedeiro 2", "[C2]", 3, 0, false};
    naviosComputador[4] = {"Submarino", "[S]", 2, 0, false};

    posicionarNavioJogador(tabuleiro_a, 5, "[P]", "porta-avioes");
    posicionarNavioJogador(tabuleiro_a, 4, "[N]", "navio-tanque");
    posicionarNavioJogador(tabuleiro_a, 3, "[C1]", "contratorpedeiro 1");
    posicionarNavioJogador(tabuleiro_a, 3, "[C2]", "contratorpedeiro 2");
    posicionarNavioJogador(tabuleiro_a, 2, "[S]", "submarino");

    posicionarNavio(tabuleiro_b, 5, "[P]");
    posicionarNavio(tabuleiro_b, 4, "[N]");
    posicionarNavio(tabuleiro_b, 3, "[C1]");
    posicionarNavio(tabuleiro_b, 3, "[C2]");
    posicionarNavio(tabuleiro_b, 2, "[S]");
}
/* 
 * FUNÇÃO: atualizarNavios
 * OBJETIVO: Atualiza a contagem de acertos dos navios e verifica se algum foi destruido.
 * COMO FUNCIONA:
 * - Percorre a matriz comparando as posicoes do navio no tabuleiro real com os disparos acertados ([X]).
 * - Atualiza o campo 'acertos' da struct do navio.
 * - Se o numero de acertos atingir o tamanho total e o navio ainda nao constar como afundado,
 *   muda a flag afundado para true e exibe mensagem avisando a destruicao.
 */
void atualizarNavios(string tabuleiroReal[TAM][TAM], string tabuleiroVisao[TAM][TAM], Navio navios[], int quantidade, bool mostrarMensagem){
    for(int n = 0; n < quantidade; n++){
        int acertos = 0;

        for(int i = 0; i < TAM; i++){
            for(int j = 0; j < TAM; j++){
                if(tabuleiroReal[i][j] == navios[n].identificador && tabuleiroVisao[i][j] == "[X]"){
                    acertos++;
                }
            }
        }

        navios[n].acertos = acertos;

        if(acertos == navios[n].tamanho && !navios[n].afundado){
            navios[n].afundado = true;

            if(mostrarMensagem){
                cout << "\n*** NAVIO AFUNDADO! ***\n"
                     << navios[n].nome << " foi destruido!\n";
            }
        }
    }
}
/* 
 * FUNÇÃO: atacar
 * OBJETIVO: Gerencia a jogada de ataque executada pelo jogador humano.
 * COMO FUNCIONA:
 * - Pede linha e coluna ao jogador, validando se a casa ja nao foi atacada previamente.
 * - Contabiliza o numero de tentativas do jogador.
 * - Se atingir uma posicao contendo um navio, marca a casa como acerto ([X]), incrementa acertos
 *   e aciona atualizarNavios().
 * - Se atingir espaco vazio, marca como agua ([O]) e passa o turno.
 */
bool atacar(string tabuleiro_inimigo[TAM][TAM], string tabuleiro_visao[TAM][TAM], int &acertos, int &tentativas, Navio naviosInimigo[], int quantidadeNavios){
    int linha;
    char coluna;

    while(true){
        cout << "\n========================================\n"
             << "              SEU ATAQUE               \n"
             << "========================================\n"
             << "Escolha uma coordenada do tabuleiro inimigo.\n"
             << "Linha: 1 a 10 | Coluna: A a J\n\n";

        linha = lerInteiro("Digite a linha do ataque: ", 1, TAM);

        cout << "Digite a coluna do ataque (A-J): ";
        cin >> coluna;

        int colunaNumero = letraParaNumero(coluna) - 1;
        int linhaNumero = linha - 1;

        if(colunaNumero < 0 || colunaNumero >= TAM){
            cout << "\n[!] Coluna invalida! Digite uma letra entre A e J.\n";
            continue;
        }

        if(tabuleiro_visao[linhaNumero][colunaNumero] != "[ ]"){
            cout << "\n[!] Essa coordenada ja foi atacada. Escolha outra.\n";
            continue;
        }

        tentativas++;

        char colunaMaiuscula = static_cast<char>(toupper(static_cast<unsigned char>(coluna)));
        cout << "\nVoce escolheu: " << linha << " " << colunaMaiuscula << "\n";

        if(tabuleiro_inimigo[linhaNumero][colunaNumero] != "[ ]"){
            cout << "[X] ACERTOU! Um navio inimigo foi atingido.\n";
            tabuleiro_visao[linhaNumero][colunaNumero] = "[X]";
            acertos++;
            atualizarNavios(tabuleiro_inimigo, tabuleiro_visao, naviosInimigo, quantidadeNavios, true);
            return true;
        }

        cout << "[O] AGUA! Nenhum navio foi atingido.\n";
        tabuleiro_visao[linhaNumero][colunaNumero] = "[O]";
        return false;
    }
}
/* 
 * FUNÇÃO: ataqueComputador
 * OBJETIVO: Executa o ataque automatizado da IA contra o tabuleiro do jogador.
 * COMO FUNCIONA:
 * - Utiliza rand() para sortear coordenadas repetidamente ate achar uma casa nao atacada.
 * - Exibe na tela qual casa a IA atacou.
 * - Marca o tabuleiro de ataques com [X] se atingir navio do jogador, ou [O] se der na agua.
 * - Dispara atualizarNavios() para verificar se algum navio do jogador afundou.
 */
bool ataqueComputador(string tabuleiro_jogador[TAM][TAM], string tabuleiro_ataques[TAM][TAM], int &acertos, Navio naviosJogador[], int quantidadeNavios){
    int linha;
    int coluna;

    do{
        linha = rand() % TAM;
        coluna = rand() % TAM;
    }while(tabuleiro_ataques[linha][coluna] != "[ ]");

    cout << "\n----------------------------------------\n"
         << "           ATAQUE DO COMPUTADOR        \n"
         << "----------------------------------------\n"
         << "Coordenada escolhida: " << linha + 1 << " "
         << static_cast<char>('A' + coluna) << "\n";

    if(tabuleiro_jogador[linha][coluna] != "[ ]"){
        cout << "[X] O computador acertou seu navio!\n";
        tabuleiro_ataques[linha][coluna] = "[X]";
        acertos++;
        atualizarNavios(tabuleiro_jogador, tabuleiro_ataques, naviosJogador, quantidadeNavios, true);
        return true;
    }

    cout << "[O] O computador errou! Era agua.\n";
    tabuleiro_ataques[linha][coluna] = "[O]";
    return false;
}
/* 
 * FUNÇÃO: verificarVitoria
 * OBJETIVO: Checa se a condicao de fim de partida foi atingida.
 * COMO FUNCIONA:
 * - Retorna true se a contagem de acertos for igual ou superior a TOTAL_CASAS (17, a soma de todas as casas de navios).
 */
bool verificarVitoria(int acertos){
    return acertos >= TOTAL_CASAS;
}
/* 
 * FUNÇÃO: mostrarEstatisticas
 * OBJETIVO: Imprime o relatorio final de desempenho do jogador ao termino da partida.
 * COMO FUNCIONA:
 * - Recebe a struct Estatisticas preenchida e exibe os dados organizados no console.
 * - Usa fixed e setprecision(2) da biblioteca <iomanip> para exibir a precisão com duas casas decimais.
 */
void mostrarEstatisticas(Estatisticas estatisticas){
    cout << "\n========================================\n"
         << "          ESTATISTICAS DA PARTIDA      \n"
         << "========================================\n"
         << "Data: " << estatisticas.dataHora << "\n"
         << "Jogador: " << estatisticas.nomeJogador << "\n"
         << "Resultado: " << estatisticas.resultado << "\n"
         << "Ataques: " << estatisticas.ataques << "\n"
         << "Acertos: " << estatisticas.acertos << "\n"
         << "Erros: " << estatisticas.erros << "\n"
         << "Navios afundados: " << estatisticas.naviosAfundados << "/" << QTD_NAVIOS << "\n"
         << fixed << setprecision(2)
         << "Precisao: " << estatisticas.precisao << "%\n"
         << "========================================\n";
}
/* 
 * FUNÇÃO: salvarHistorico
 * OBJETIVO: Salva o resumo da partida em um arquivo de texto permanente.
 * COMO FUNCIONA:
 * - Abre/cria o arquivo "historico.txt" usando ofstream com a flag ios::app (adiciona ao final).
 * - Se a abertura falhar, avisa o usuario; senao, grava o relatorio de estatisticas no arquivo e o fecha.
 */
void salvarHistorico(Estatisticas estatisticas){
    ofstream arquivo("historico.txt", ios::app);

    if(!arquivo.is_open()){
        cout << "\n[!] Nao foi possivel abrir o arquivo de historico.\n";
        return;
    }

    arquivo << "========================================\n"
            << "Data: " << estatisticas.dataHora << "\n"
            << "Jogador: " << estatisticas.nomeJogador << "\n"
            << "Resultado: " << estatisticas.resultado << "\n"
            << "Ataques: " << estatisticas.ataques << "\n"
            << "Acertos: " << estatisticas.acertos << "\n"
            << "Erros: " << estatisticas.erros << "\n"
            << "Navios afundados: " << estatisticas.naviosAfundados << "/" << QTD_NAVIOS << "\n"
            << fixed << setprecision(2)
            << "Precisao: " << estatisticas.precisao << "%\n"
            << "========================================\n\n";

    arquivo.close();
    cout << "[OK] Partida salva no historico.\n";
}
/* 
 * FUNÇÃO: mostrarHistorico
 * OBJETIVO: Le e exibe todas as partidas gravadas no arquivo de historico.
 * COMO FUNCIONA:
 * - Abre o arquivo "historico.txt" para leitura com ifstream.
 * - Caso nao exista, exibe aviso de que nenhuma partida foi registrada.
 * - Le o arquivo linha por linha usando getline() e imprime cada linha no console.
 */
void mostrarHistorico(){
    ifstream arquivo("historico.txt");

    cout << "\n========================================\n"
         << "          HISTORICO DE PARTIDAS        \n"
         << "========================================\n\n";

    if(!arquivo.is_open()){
        cout << "Nenhuma partida foi registrada ainda.\n";
        cout << "========================================\n";
        system("pause");
        return;
    }

    string linha;
    while(getline(arquivo, linha)){
        cout << linha << "\n";
    }

    arquivo.close();
    cout << "========================================\n";
    system("pause");
}
/* 
 * FUNÇÃO: batalha_naval
 * OBJETIVO: Funcao principal que coordena o fluxo de uma partida do jogo.
 * COMO FUNCIONA:
 * - Declara matrizes e dados de navios do jogo.
 * - Executa a configuracao inicial (setarTabuleiro).
 * - Solicita o nome do jogador.
 * - Executa o loop principal de jogo alternando entre atacar() e ataqueComputador().
 * - Interrompe o loop quando verificarVitoria() retornar true para algum dos participantes.
 * - Calcula todas as estatisticas finais, exibe na tela e salva no arquivo com salvarHistorico().
 */
void batalha_naval(){
    string tabuleiro_a[TAM][TAM];
    string tabuleiro_b[TAM][TAM];
    string tabuleiro_visao[TAM][TAM];
    string tabuleiro_ataques[TAM][TAM];

    Navio naviosJogador[QTD_NAVIOS];
    Navio naviosComputador[QTD_NAVIOS];

    int acertosJogador = 0;
    int acertosComputador = 0;
    int tentativasJogador = 0;

    setarTabuleiro(tabuleiro_a, tabuleiro_b, naviosJogador, naviosComputador);
    inicializarTabuleiro(tabuleiro_visao);
    inicializarTabuleiro(tabuleiro_ataques);

    system("cls");

    cout << "\n========================================\n"
         << "       POSICIONAMENTO CONCLUIDO!       \n"
         << "========================================\n"
         << "Todos os seus navios foram posicionados.\n"
         << "Agora a batalha vai comecar!\n";
    system("pause");
    system("cls");

    string nomeJogador;
    cout << "Digite o nome do jogador: ";
    limparBuffer();
    getline(cin, nomeJogador);

    if(nomeJogador.empty()){
        nomeJogador = "Jogador";
    }

    string resultado;

    while(true){
        cout << "\n========================================\n"
             << "             BATALHA NAVAL             \n"
             << "========================================\n";

        desenhar_tabuleiro(tabuleiro_a, tabuleiro_visao, tabuleiro_ataques);

        cout << "\nSeu progresso: " << acertosJogador << "/" << TOTAL_CASAS << " acertos"
             << " | Tentativas: " << tentativasJogador << "\n";

        atacar(tabuleiro_b, tabuleiro_visao, acertosJogador, tentativasJogador, naviosComputador, QTD_NAVIOS);

        if(verificarVitoria(acertosJogador)){
            resultado = "Vitoria";
            cout << "\n========================================\n"
                 << "             VOCE VENCEU!              \n"
                 << "========================================\n"
                 << "Todos os navios inimigos foram destruidos!\n";
            break;
        }

        ataqueComputador(tabuleiro_a, tabuleiro_ataques, acertosComputador, naviosJogador, QTD_NAVIOS);

        if(verificarVitoria(acertosComputador)){
            resultado = "Derrota";
            cout << "\n========================================\n"
                 << "         O COMPUTADOR VENCEU!          \n"
                 << "========================================\n"
                 << "Todos os seus navios foram destruidos!\n";
            break;
        }

        system("pause");
        system("cls");
    }

    int naviosAfundados = 0;
    for(int i = 0; i < QTD_NAVIOS; i++){
        if(naviosComputador[i].afundado){
            naviosAfundados++;
        }
    }

    Estatisticas estatisticas;
    estatisticas.dataHora = obterDataHora();
    estatisticas.nomeJogador = nomeJogador;
    estatisticas.resultado = resultado;
    estatisticas.ataques = tentativasJogador;
    estatisticas.acertos = acertosJogador;
    estatisticas.erros = tentativasJogador - acertosJogador;
    estatisticas.naviosAfundados = naviosAfundados;
    estatisticas.precisao = tentativasJogador > 0
        ? (static_cast<double>(acertosJogador) / tentativasJogador) * 100.0
        : 0.0;

    mostrarEstatisticas(estatisticas);
    salvarHistorico(estatisticas);

    // Corrige o bug: sobrou um '\n' no buffer (do cin >> coluna), que fazia o cin.get()
    // retornar na hora e o menu apagar as estatisticas da tela.
    limparBuffer();
    cout << "\nPressione ENTER para voltar ao menu...";
    cin.get();
}
/* 
 * FUNÇÃO: mostrarRanking
 * OBJETIVO: Exibe as 10 melhores vitorias (menos ataques) registradas no historico.
 * COMO FUNCIONA:
 * - Le o "historico.txt" linha por linha e monta cada partida a partir dos prefixos
 *   ("Jogador: ", "Ataques: " etc.). A linha "Precisao: " e a ultima de cada registro e fecha a partida.
 * - Guarda so as vitorias em um vetor de Estatisticas (ate MAX_PARTIDAS).
 * - Ordena com bubble sort por numero de ataques (crescente) e mostra as 10 primeiras.
 * - Partidas antigas, salvas antes de existir data, aparecem com "-" na coluna de data.
 */
void mostrarRanking(){
    ifstream arquivo("historico.txt");

    cout << "\n========================================\n"
         << "      RANKING - MELHORES VITORIAS       \n"
         << "========================================\n\n";

    if(!arquivo.is_open()){
        cout << "Nenhuma partida foi registrada ainda.\n";
        cout << "========================================\n";
        system("pause");
        return;
    }

    Estatisticas partidas[MAX_PARTIDAS];
    int total = 0;

    Estatisticas atual;
    atual.dataHora = "-";
    atual.resultado = "";
    atual.nomeJogador = "";
    atual.ataques = 0;
    atual.acertos = 0;

    string linha;
    while(getline(arquivo, linha)){
        // rfind(texto, 0) == 0 significa "a linha comeca com este texto"
        if(linha.rfind("Data: ", 0) == 0){
            atual.dataHora = linha.substr(6);
        }else if(linha.rfind("Jogador: ", 0) == 0){
            atual.nomeJogador = linha.substr(9);
        }else if(linha.rfind("Resultado: ", 0) == 0){
            atual.resultado = linha.substr(11);
        }else if(linha.rfind("Ataques: ", 0) == 0){
            atual.ataques = atoi(linha.substr(9).c_str());
        }else if(linha.rfind("Acertos: ", 0) == 0){
            atual.acertos = atoi(linha.substr(9).c_str());
        }else if(linha.rfind("Precisao: ", 0) == 0){
            if(atual.resultado == "Vitoria" && total < MAX_PARTIDAS){
                partidas[total] = atual;
                total++;
            }

            atual.dataHora = "-";
            atual.resultado = "";
            atual.nomeJogador = "";
            atual.ataques = 0;
            atual.acertos = 0;
        }
    }

    arquivo.close();

    if(total == 0){
        cout << "Ainda nao ha vitorias registradas.\n";
        cout << "\n========================================\n";
        system("pause");
        return;
    }

    // Bubble sort: menos ataques primeiro (empates mantem a ordem cronologica)
    for(int i = 0; i < total - 1; i++){
        for(int j = 0; j < total - 1 - i; j++){
            if(partidas[j].ataques > partidas[j + 1].ataques){
                Estatisticas aux = partidas[j];
                partidas[j] = partidas[j + 1];
                partidas[j + 1] = aux;
            }
        }
    }

    cout << left << setw(5) << "Pos" << setw(16) << "Jogador" << setw(9) << "Ataques"
         << setw(8) << "Prec." << "Data\n"
         << "------------------------------------------------------\n";

    int limite = (total < 10) ? total : 10;

    for(int i = 0; i < limite; i++){
        double precisao = partidas[i].ataques > 0
            ? (static_cast<double>(partidas[i].acertos) / partidas[i].ataques) * 100.0
            : 0.0;

        cout << left << setw(5) << (i + 1)
             << setw(16) << partidas[i].nomeJogador.substr(0, 14)
             << setw(9) << partidas[i].ataques
             << fixed << setprecision(1) << right << setw(5) << precisao << "%  "
             << left << partidas[i].dataHora << "\n";
    }

    cout << "\n========================================\n";
    system("pause");
}