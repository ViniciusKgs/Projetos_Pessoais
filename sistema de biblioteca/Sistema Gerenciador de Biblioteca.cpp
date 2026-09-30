#include <iostream>
#include <limits>
#include <conio.h>
using namespace std;

struct Livro {
    string titulo;
    string Autor;
    string ISBN;
    string categoria;
    int ano_publicacao;
    int quanti_total;
    int quanti_disponivel;
};

struct Usuario {
    string Nome;
    int ID;
    string telefone;
    string status;
};

struct Emprestimo {
    int identificador;
    int ID;
    string ISBN;
    string data_emprestimo;
    string data_devolucao;
};

typedef struct Livro Livro;
typedef struct Usuario Usuario;
typedef struct Emprestimo Emprestimo;

void menu_principal (int &op);
void cadastrar_livro (Livro &cadastrar, int &contador);
void limparBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void pausar()
{
    cout << "\n\tPressione qualquer tecla para continuar...\n";
    _getch();
}
string mostrar_categorias();
void listar_livros (Livro livros[], int contador);
void listar_livros (Livro livros[], int contador, int op);
void buscarLivro_titulo(Livro livros[], int contador, string titulo_livro);
int buscarLivro_isbn(Livro livros[], int contador, string ISBN);
void buscarLivro_autor(Livro livros[], int contador, string Autor);
void buscarLivro_categoria(Livro livros[], int contador, string categoria);
void alterar_livro (Livro livros[], int contador);
void remover_livro(Livro livros[], int &contador);
void cadastrar_usuario(Usuario &cadastrar, int &contador_usu);
void listar_usuarios (Usuario usuarios[], int contador_usu);
void listar_usuarios(Usuario usuarios[],int contador_uso, int retorno);
int busca_id (Usuario usuarios[], int contador_uso, int id);
int busca_avancada_usuario (Usuario usuarios[], int contador_uso, string criterio);
void buscar_usuarios(Usuario usuarios[], int contador_uso);
void alterar_usuario (Usuario usuarios[], int contador_uso);
void remover_usuario(Usuario usuarios[], int &contador_uso);
void realizar_emprestimo (Emprestimo &emprestimos, int &contador_emprestimo, Usuario usuarios[],int contador_uso);
void listar_emprestimos(Emprestimo emprestimos[], int contador_emprestimo);
void registrar_devolucao (Emprestimo emprestimos[], int &contador_emprestimo);


int main(){
    int op = 1, contador = 0, contador_uso = 0, contador_emprestimo = 0;
    Livro livros[200];
    Usuario usuarios[200];
    Emprestimo emprestimos[200];
    while (op != 0){
        menu_principal (op);
        switch (op)
        {
        case 1:
            if (contador <= 199){
                cout << "\t--------------- Cadastrar Livro ---------------\n";
                cadastrar_livro (livros[contador], contador);
            }
            else {
                cout << "\tNao Ha mais espaço para cadastrar Livros!\n";
                cout << "\t----------------------------------------------------\n";
            }
            break;
        case 2:
            if (contador <= 0){
                cout << "\t--------------- Listar Livros ---------------\n";
                cout << "\tNao Ha livros cadastrados!\n";
            }
            else{
                cout << "\t--------------- Listar Livros ---------------\n";
                listar_livros(livros, contador);
            }
        break;
        case 3:{
        int opcao;
        cout << "\t--------------- Busca de Livros ---------------\n";
        cout << "\tQual Criterio Deseja? \n" << "\t1 - Titulo\n" << "\t2 - Autor\n" 
        << "\t3 - Categoria\n" << "\t4 - ISBN\n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:{
            string titulo;
            cout << "Digite o titulo que deseja buscar -> ";
            limparBuffer();
            getline(cin,titulo);
            buscarLivro_titulo(livros, contador, titulo);

        }
            break;
        case 2:{
            string autor;
            cout << "Digite o Autor que deseja buscar -> ";
            limparBuffer();
            getline(cin,autor);
            buscarLivro_autor(livros, contador, autor);
            break;
        }
        case 3:{
            string categoria;
            categoria = mostrar_categorias();
            buscarLivro_categoria(livros, contador, categoria);
            break;
        }
        case 4:{
            string isbn;
            cout << "Digite o ISBN que deseja buscar -> ";
            cin >> isbn;
            buscarLivro_isbn(livros, contador, isbn);
            break;
        }
        default:
            break;
        }
        break;
        }
        case 4:
        cout << "\t--------------- Alterar Livro ---------------\n";
        alterar_livro(livros,contador);
        break;
        case 5:
        cout << "\t--------------- Remover Livro ---------------\n";
        remover_livro(livros,contador);
        break;
        case 6:
        if (contador_uso <= 199){
                cout << "\t--------------- Cadastrar Usuario ---------------\n";
                cadastrar_usuario(usuarios[contador_uso], contador_uso);
            }
            else {
                cout << "\tNao Ha mais espaço para cadastrar Usuarios!\n";
                cout << "\t----------------------------------------------------\n";
            }
            break;
        case 7:
            cout << "\t--------------- Listar Usuarios ---------------\n";
            listar_usuarios(usuarios, contador_uso);
            break;
        case 8:
            cout << "\t--------------- Buscar Usuario ---------------\n";
            buscar_usuarios(usuarios, contador_uso);
            break;
        case 9: 
            cout << "\t--------------- Alterar Usuario ---------------\n";
            alterar_usuario(usuarios, contador_uso);
        case 10:
            cout << "\t--------------- Remover Usuario ---------------\n";
            remover_usuario(usuarios, contador_uso);
        case 11:
            if (contador_emprestimo <= 199){
                cout << "\t--------------- Realizar Emprestimo ---------------\n";
                realizar_emprestimo (emprestimos[contador], contador_emprestimo, usuarios, contador_uso, livros,contador);
            }
            else {
                cout << "\tNao Ha mais espaço para cadastrar emprestimos!\n";
                cout << "\t----------------------------------------------------\n";
            }
            break;
        case 12:

        break;
        default:
            break;
        }
    }
    return 0;
}

void menu_principal (int &op){
    cout << "\t1 - Cadastrar livro \n";
    cout << "\t2 - Listar livros \n";
    cout << "\t3 - Buscar livro \n";
    cout << "\t4 - Alterar livro \n";
    cout << "\t5 - Remover livro \n";
    cout << "\t6 - Cadastrar usuario \n";
    cout << "\t7 - Listar usuarios \n";
    cout << "\t8 - Buscar usuario \n";
    cout << "\t9 - Alterar usuario \n";
    cout << "\t10 - Remover usuario \n";
    cout << "\t11- Realizar emprestimo \n";
    cout << "\t12 - Registrar devolucao \n";
    cout << "\t13 - Listar emprestimos \n";
    cout << "\t14 - Buscar emprestimo \n";
    cout << "\t15 - Relatorios \n";
    cout << "\t16 - Salvar dados \n";
    cout << "\t17 - Carregar dados \n";
    cout << "\t0 - Sair\n";
    cout << "\t-------------------------------------------\n";
    cout << "\tDigite aqui -> ";
    cin >> op;
    cout << "\t-------------------------------------------\n";
    
}
void cadastrar_livro (Livro &cadastrar, int &contador){

    cout << "\tDigite o Titulo do Livro -> ";
    limparBuffer();
    getline (cin, cadastrar.titulo);
    cout << "\tDigite o Autor do Livro -> ";
    getline (cin, cadastrar.Autor);
    cout << "\tDigite o ISBN do Livro -> ";
    cin >> cadastrar.ISBN;
    cout << "\tDigite a categoria do Livro\n";
    cadastrar.categoria = mostrar_categorias();
    cout << "\tAno de Publicao do Livro -> ";
    cin >> cadastrar.ano_publicacao;
    cout << "\tQuantidade total de livros -> ";
    cin >> cadastrar.quanti_total;
    cout << "\tQuantidade disponivel de livros -> ";
    cin >> cadastrar.quanti_disponivel;
    cout << "\t----------------------------------------------------\n";
    contador++;
    pausar();
}
string mostrar_categorias(){
    int op;
    string categorias[27] = {
    "Romance",
    "Fantasia",
    "Ficcao Cientifica",
    "Aventura",
    "Misterio",
    "Suspense",
    "Terror",
    "Drama",
    "Biografia",
    "Historia",
    "Filosofia",
    "Psicologia",
    "Ciencia",
    "Tecnologia",
    "Educacao",
    "Politica",
    "Quadrinhos",
    "Religiao",
    "Poesia",
    "Literatura Infantil",
    "Literatura Juvenil",
    "Autoajuda",
    "Negocios",
    "Direito",
    "Artes",
    "Saude",
    "Viagem"
};
    cout << "\t1 - Romance \n";
    cout << "\t2 - Fantasia \n";
    cout << "\t3 - Ficcao Cientifica \n";
    cout << "\t4 - Aventura \n";
    cout << "\t5 - Misterio \n";
    cout << "\t6 - Suspense \n";
    cout << "\t7 - Terror \n";
    cout << "\t8 - Drama \n";
    cout << "\t9 - Biografia \n";
    cout << "\t10 - Historia \n";
    cout << "\t11- Filosofia \n";
    cout << "\t12 - Psicologia \n";
    cout << "\t13 - Ciencia \n";
    cout << "\t14 - Tecnologia \n";
    cout << "\t15 - Educação \n";
    cout << "\t16 - Politica \n";
    cout << "\t17 - Quadrinhos \n";
    cout << "\t18 - Religiao \n";
    cout << "\t19 - Poesia \n";
    cout << "\t20 - Literatura Infantil \n";
    cout << "\t21 - Literatura Juvenil \n";
    cout << "\t22 - Autoajuda \n";
    cout << "\t23 - Negocios \n";
    cout << "\t24 - Direito \n";
    cout << "\t25 - Artes \n";
    cout << "\t26 - Saude \n";
    cout << "\t27 - Viagem \n";
    cout << "\t-------------------------------------------\n";
    cout << "\tDigite aqui -> ";
    limparBuffer();
    cin >> op;
    //cout << "\t-------------------------------------------\n";
    pausar();
    if (op >= 1 && op <= 27){
        return categorias[op - 1];
    }
    else {
        while (op < 1 || op > 27){
        cout << "\tErro! Opcao Invalida!\n";
        cout << "\tDigite Novamente -> ";
        cin >> op;
        }
        return categorias[op - 1];
    }
}
void listar_livros (Livro livros[], int contador){
    int i, op, valores[contador], auxiliar[contador], j, posicao_menor;
    cout << "\tDe qual forma voce deseja ver os livros? \n" << "\t0 - Ordem de Cadastro\n" << "\t1 - Ano de Publicacao\n" << "\tDigite aqui\n>";
    cin >> op;
    switch (op)
    {
    case 0:
        for (i = 0; i < contador; i++){
        cout << "\t[ " << i+1 << " ]" << "| \tCategoria:  " 
        << livros[i].categoria << endl;
        cout << "\tTitulo: " << livros[i].titulo 
        << " | \tISBN: " << livros[i].ISBN << endl;
        cout << "\tAutor: " << livros[i].Autor 
        << " | \tAno de publicacao: " << livros[i].ano_publicacao << endl;
        cout << "\tQuantidade Disponivel: " << livros[i].quanti_disponivel 
        << "|   Quantidade Total: " << livros[i].quanti_total << endl << endl;
        }
        break;
    case 1:{
    for (i = 0; i < contador; i++){
        valores[i] = livros[i].ano_publicacao;
        auxiliar[i] = i;
    }
    for (i = 0; i < contador; i++){
    posicao_menor = i;
    for (j = i + 1; j < contador; j++){
        if (valores[auxiliar[j]] < valores[auxiliar[posicao_menor]]){
            posicao_menor = j;
        }
    }
    int temp = auxiliar[i];
    auxiliar[i] = auxiliar[posicao_menor];
    auxiliar[posicao_menor] = temp;
    }
    for (i = 0; i < contador; i++)
    {
    cout << "\t[ " << i + 1 << " ]"
         << "| \tCategoria: " << livros[auxiliar[i]].categoria << endl;
    cout << "\tTitulo: " << livros[auxiliar[i]].titulo
         << " | \tISBN: " << livros[auxiliar[i]].ISBN << endl;
    cout << "\tAutor: " << livros[auxiliar[i]].Autor
         << " | \tAno de publicacao: "
         << livros[auxiliar[i]].ano_publicacao << endl;
    cout << "\tQuantidade Disponivel: "
         << livros[auxiliar[i]].quanti_disponivel
         << " | Quantidade Total: "
         << livros[auxiliar[i]].quanti_total << endl << endl;
    }
} 
    default:
        cout << "\tErro! Numero Invalido\n";
        break;
    }
    cout << "\t----------------------------------------------\n";
    pausar();
}
void buscarLivro_titulo(Livro livros[], int contador, string titulo_livro){
    int i;
    for (i = 0; i < contador; i++){
        if (livros[i].titulo == titulo_livro){
            cout << "\t[ " << i+1 << " ]" << "| \tCategoria:  " 
            << livros[i].categoria << endl;
            cout << "\tTitulo: " << livros[i].titulo 
            << " | \tISBN: " << livros[i].ISBN << endl;
            cout << "\tAutor: " << livros[i].Autor 
            << " | \tAno de publicacao: " << livros[i].ano_publicacao << endl;
            cout << "\tQuantidade Disponivel: " << livros[i].quanti_disponivel 
            << "|   Quantidade Total: " << livros[i].quanti_total << endl << endl;
        }
        }
    }
int buscarLivro_isbn(Livro livros[], int contador, string ISBN){
    int i;
    for (i = 0; i < contador; i++){
        if (livros[i].ISBN == ISBN){
            cout << "\t[ " << i+1 << " ]" << "| \tCategoria:  " 
            << livros[i].categoria << endl;
            cout << "\tTitulo: " << livros[i].titulo 
            << " | \tISBN: " << livros[i].ISBN << endl;
            cout << "\tAutor: " << livros[i].Autor 
            << " | \tAno de publicacao: " << livros[i].ano_publicacao << endl;
            cout << "\tQuantidade Disponivel: " << livros[i].quanti_disponivel 
            << "|   Quantidade Total: " << livros[i].quanti_total << endl << endl;
            return i;
    }
    }
    return -1;
}
void buscarLivro_autor(Livro livros[], int contador, string Autor){
    int i;
    for (i = 0; i < contador; i++){
        if (livros[i].Autor == Autor){
            cout << "\t[ " << i+1 << " ]" << "| \tCategoria:  " 
            << livros[i].categoria << endl;
            cout << "\tTitulo: " << livros[i].titulo 
            << " | \tISBN: " << livros[i].ISBN << endl;
            cout << "\tAutor: " << livros[i].Autor 
            << " | \tAno de publicacao: " << livros[i].ano_publicacao << endl;
            cout << "\tQuantidade Disponivel: " << livros[i].quanti_disponivel 
            << "|   Quantidade Total: " << livros[i].quanti_total << endl << endl;
    }
    }

}
void buscarLivro_categoria(Livro livros[], int contador, string categoria){
    int i;
    for (i = 0; i < contador; i++){
        if (livros[i].categoria == categoria){
            cout << "\t[ " << i+1 << " ]" << "| \tCategoria:  " 
            << livros[i].categoria << endl;
            cout << "\tTitulo: " << livros[i].titulo 
            << " | \tISBN: " << livros[i].ISBN << endl;
            cout << "\tAutor: " << livros[i].Autor 
            << " | \tAno de publicacao: " << livros[i].ano_publicacao << endl;
            cout << "\tQuantidade Disponivel: " << livros[i].quanti_disponivel 
            << "|   Quantidade Total: " << livros[i].quanti_total << endl << endl;
    }
    }
}
void alterar_livro (Livro livros[], int contador){ 
        int op, posicao;
        cout << "\tQual posicao deseja alterar? -> ";
        cin >> posicao;
        cout << "\tComo estava: \n";
        listar_livros(livros, contador, posicao);
        cout << "\tDeseja alterar qual? " << "\t1 - Titulo\n" << "\t2 - Autor\n" << "\t3 - ISBN\n" << "\t4 - Categoria\n" 
        << "\t5 - Ano de Publicao\n" << "\t6 - Quantidade Total\n" << "\t7 - Quantidade Disponivel\n>";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "\tReescreva o Titulo -> ";
            limparBuffer();
            getline (cin, livros[posicao-1].titulo);
            cout << "\tComo ficou: \n";
            listar_livros(livros, contador, posicao);
            break;
        case 2:
            cout << "\tReescreva o nome do Autor -> ";
            limparBuffer();
            getline (cin, livros[posicao-1].Autor);
            cout << "\tComo ficou: \n";
            listar_livros(livros, contador, posicao);
            break;
        case 3:
            cout << "\tReescreva o ISBN -> ";
            limparBuffer();
            getline (cin, livros[posicao-1].ISBN);
            cout << "\tComo ficou: \n";
            listar_livros(livros, contador, posicao);
        break;
        case 4:
            cout << "\tCorrija a categoria:  -> ";
            livros[posicao-1].categoria = mostrar_categorias();
            cout << "\tComo ficou: \n";
            listar_livros(livros, contador, posicao);
        break;
        case 5:
            cout << "\tReescreva o ano de publicacao -> ";
            cin >> livros[posicao-1].ano_publicacao;
            cout << "\tComo ficou: \n";
            listar_livros(livros, contador, posicao);
        break;
        case 6:
            cout << "\tReescreva a quantidade total -> ";
            cin >> livros[posicao-1].quanti_total;
            cout << "\tComo ficou: \n";
            listar_livros(livros, contador, posicao);
        break;
        case 7:
            cout << "\tReescreva a quantidade disponivel -> ";
            cin >> livros[posicao-1].quanti_disponivel;
            cout << "\tComo ficou: \n";
            listar_livros(livros, contador, posicao);
        break;
        default:
            cout << "\tIndice Errado!\n";
            break;
        }
}
void listar_livros (Livro livros[], int contador, int op){
    cout << "\t[ " << op << " ]" << "| \tCategoria:  " 
        << livros[op-1].categoria << endl;
        cout << "\tTitulo: " << livros[op-1].titulo 
        << " | \tISBN: " << livros[op-1].ISBN << endl;
        cout << "\tAutor: " << livros[op-1].Autor 
        << " | \tAno de publicacao: " << livros[op-1].ano_publicacao << endl;
        cout << "\tQuantidade Disponivel: " << livros[op-1].quanti_disponivel 
        << "|   Quantidade Total: " << livros[op-1].quanti_total << endl << endl;
    }
void remover_livro(Livro livros[], int &contador){
    cout << "\t Funcao ainda nao implementada\n";
}
void cadastrar_usuario(Usuario &cadastrar, int &contador_uso){
    cout << "\tDigite o seu nome -> ";
    limparBuffer();
    getline (cin, cadastrar.Nome);
    cout << "\tCrie o seu ID -> ";
    cin >> cadastrar.ID;
    cout << "\tDigite o seu Telefone -> ";
    cin >> cadastrar.telefone;
    cadastrar.status = "Ativo";
    contador_uso++;
    pausar();
}
void listar_usuarios (Usuario usuarios[], int contador_uso){
    int i;
    for (i = 0; i < contador_uso; i++){
        cout << "\t[ " << i+1 << " ]" << "| \tID:  " 
        << usuarios[i].ID << endl;
        cout << "\tNome: " << usuarios[i].Nome << endl;
        cout << "\tTelefone: " << usuarios[i].telefone;
        cout << "\tStatus: " << usuarios[i].status << endl << endl;
        }
    cout << "\t-----------------------------------------------\n";
}
void buscar_usuarios(Usuario usuarios[], int contador_uso){
    int op, criterio_id;
    int retorno;
    string criterio_string;

    cout << "\tQual criterio deseja? \n";
    cout << "\t1 - Nome \n";
    cout << "\t2 - ID\n";
    cout << "\t3 - Telefone\n";
    cout << "\tDigite aqui -> ";
    cin >> op;

    if (op == 1){
        cout << "Qual nome deseja buscar? -> ";
        limparBuffer();
        getline(cin, criterio_string);

        retorno = busca_avancada_usuario(usuarios, contador_uso, criterio_string);
        listar_usuarios(usuarios, contador_uso, retorno);
    }
    else if (op == 2){
        cout << "Qual ID deseja buscar? -> ";
        cin >> criterio_id;

        retorno = busca_id(usuarios, contador_uso, criterio_id);
        listar_usuarios(usuarios, contador_uso, retorno);
    }
    else if (op == 3){
        cout << "Qual telefone deseja buscar? -> ";
        limparBuffer();
        getline(cin, criterio_string);

        retorno = busca_avancada_usuario(usuarios, contador_uso, criterio_string);
        listar_usuarios(usuarios, contador_uso, retorno);
    }
    else {
        cout << "\tOpcao invalida!\n";
    }
}
int busca_avancada_usuario (Usuario usuarios[], int contador_uso,string criterio){
    int i;
    for (i = 0; i < contador_uso; i++){
        if (usuarios[i].Nome == criterio ||usuarios[i].telefone == criterio){
            return i;
        }
    }
    return -1;
}
int busca_id (Usuario usuarios[], int contador_uso, int id){
    int i;
    for (i = 0; i < contador_uso; i++){
        if (usuarios[i].ID == id ){
            return i;
        }
    }
    return -1;
}
void listar_usuarios(Usuario usuarios[], int contador_uso, int retorno){
    if (retorno == -1){
        cout << "\tUsuario nao encontrado!\n";
        return;
    }

    cout << "\t[ " << retorno + 1 << " ]" << "| \tID:  "
         << usuarios[retorno].ID << endl;
    cout << "\tNome: " << usuarios[retorno].Nome << endl;
    cout << "\tTelefone: " << usuarios[retorno].telefone;
    cout << "\tStatus: " << usuarios[retorno].status << endl << endl;
}
void alterar_usuario (Usuario usuarios[], int contador_uso){
    int op, posicao;
        cout << "\tQual posicao deseja alterar? -> ";
        cin >> posicao;
        cout << "\tComo estava: \n";
        listar_usuarios(usuarios, contador_uso, posicao-1);
        cout << "\tDeseja alterar qual? \t" << "\t1 - Nome\n" << "\t2 - ID\n" << "\t3 - Telefone\n\t> " ;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "\tReescreva o nome -> ";
            limparBuffer();
            getline (cin, usuarios[posicao-1].Nome);
            cout << "\tComo ficou: \n";
            listar_usuarios(usuarios, contador_uso, posicao-1);
            break;
        case 2:
            cout << "\tReescreva o ID -> ";
            cin >> usuarios[posicao-1].ID;
            cout << "\tComo ficou: \n";
            listar_usuarios(usuarios, contador_uso, posicao-1);
            break;
        case 3:
            cout << "\tReescreva o Telefone -> ";
            limparBuffer();
            getline (cin, usuarios[posicao-1].telefone);
            cout << "\tComo ficou: \n";
            listar_usuarios(usuarios, contador_uso, posicao-1);
        break;
        default:
            cout << "\tIndice Errado!\n";
            break;
        }
}
void remover_usuario(Usuario usuarios[], int &contador_uso){
    cout << "\t Funcao sendo implementada\n";
}
void realizar_emprestimo (Emprestimo &emprestimos, int &contador_emprestimo, Usuario usuarios[], int contador_uso, Livro livros[], int contador){
    int id = 0, indice = 0, indice_livro = 0;
    string isbn;
    cout << "\tDigite o ID do usuario\n\t> ";
    cin >> id;
    indice = busca_id (usuarios, contador_uso, id);
    cout << "\tQual Livro deseja pegar emprestado?\n";
    cout << "Digite aqui o ISBN do livro\n\t> ";
    limparBuffer();
    getline (cin, isbn);
    indice_livro = buscarLivro_isbn (livros,contador, isbn);
    if (indice == -1 || indice_livro == -1){
        cout << "\t Nao é possivel pegar emprestimo!\n";
        return;
    }
    else {
        if (usuarios[indice].status == "Inativo" || livros[indice_livro].quanti_disponivel <= 0){
            cout << "\tNao foi possivel pegar o emprestimo\n";
            return;
        }
        else{
            emprestimos.identificador = contador_emprestimo + 1;
            emprestimos.ID = usuarios[indice].ID;
            emprestimos.ISBN = livros[indice_livro].ISBN;
            cout << "Digite a data de emprestimo\n\t> ";
            limparBuffer();
            getline (cin, emprestimos.data_emprestimo);
            cout << "Digite a data prevista de devolucao\n\t> ";
            getline (cin, emprestimos.data_devolucao);
            contador_emprestimo++;
            livros[indice_livro].quanti_disponivel--;
            usuarios[indice].status = "Com livro";
            cout << "\t Livro pegado emprestado com sucesso!\n";
        }
    }
}
void registrar_devolucao (Emprestimo emprestimos[], int &contador_emprestimo)/*Continuar jaja*/{
    /*int op, i;
    cout << "\t=================== Remover Emprestimo ===================\n";
    if (contador_emprestimo == 0){
        cout << "\tNao Ha emprestimos para remover!";
        return;
    }
    else{
    cout << "\tQual Posicao Deseja Remover? ";
    listar_emprestimos(emprestimos, contador_emprestimo);
    cin >> op;
    if (op > contador_emprestimo || op < 1){
        while (op > contador_emprestimo || op < 1){
            cout << "\tOpcao Invalida! Digite Novamente!";
            cin >> op;
        }
    }
    if (op == contador_emprestimo){
        contador_emprestimo--;
    }

    else{
        int indice = op - 1;
        for (i = indice; i < (contador-1); i++){
            emprestimos[i].identificador = emprestimos[i+1].identificador;
            emprestimos[i].ID = emprestimos[i].ID;
            emprestimos[i].ISBN = emprestimos[i].ISBN
            emprestimos[i].data_emprestimo = emprestimos[i+1].data_emprestimo;
            emprestimos[i].data_devolucao = emprestimos[i+1].data_devolucao;
        }
        contador_emprestimo--;
    }
    cout << "\tMovimentacao Removida com Sucesso!\n";

}
    cout << "\t===========================================================\n";}*/

}
void listar_emprestimos(Emprestimo emprestimos[], int contador_emprestimo){
    int i;
    if (contador_emprestimo == 0){
        cout << "\t Nao Ha emprestimos cadastrados!\n";
        return;
    }
    for (i = 0; i < contador_emprestimo; i++){
        cout << "\t[ " << emprestimos[i].identificador << " ]" << " Data de Emprestimo: " << emprestimos[i].data_emprestimo << endl;
        cout << "\tID: " << emprestimos[i].ID << " ISBN: " << emprestimos[i].ISBN << endl;
        cout << "\tData Prevista para devolucao: " << emprestimos[i].data_devolucao << endl;
    }
}