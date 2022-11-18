// Lucas Goulart de Farias Meres - 42127459
// Thiago Leandro Liporace - 42128481

//Referencias:

//TODO.
#include "LinkedList.h"

using namespace std;

void Append(LinkedList *lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao, int ano, char bibliobasica);

void Print(const LinkedList* lista)
{
  cout << "----------------------------------------------------------------------\n";
  cout << "A sua biblioteca possui atualmente " << lista -> count << " livros, sendo estes:\n";
  Node *aux = lista -> head;
  for (int i = 0;i < lista -> count;i++){
    cout << "\n------------/ " << "LIVRO " << i+1 << " /------------\n"; 
    cout <<"Titulo: " << aux -> titulo << "\n";
    cout <<"ISBN: " << aux -> isbn << "\n";
    cout <<"Autor: " << aux -> autor << "\n";
    cout <<"Cidade: " << aux -> cidade << "\n";
    cout <<"Editora: " << aux -> editora << "\n";
    cout <<"Disciplina: " << aux -> disciplina << "\n";
    cout <<"Edicao: " << aux -> edicao << "\n";
    cout <<"Ano de sua publicacao: " << aux -> ano << "\n";
    cout <<"Bibliografia basica: " << aux -> bibliobasica << "\n";
    aux = aux -> next;
  }
}

Node *RemoverLivro(LinkedList *lista,std::string isbn,std::string titulo){
  int opcao;
  cout << "Quer remover um livro pelo ISBN(1) ou pelo Titulo(2)? Digite o numero correspondente.\n";
  cin >> opcao;
  cin.ignore();
  Node *livro = new Node;
  if (opcao == 1){
    titulo = "";
    cout << "Digite o ISBN do livro que deseja remover:";
    getline(cin,isbn);
    livro = RemoveNode(lista,isbn,titulo);
  }
  if(opcao == 2){
    isbn = "";
    cout << "Digite o Titulo do livro que deseja remover:";
    getline(cin,titulo);
    livro = RemoveNode(lista,isbn,titulo);
  }
  return livro;
}

void SalvarLivros(LinkedList *lista){
  std::fstream file;
  file.open("teste.csv"); //depois trocar pra bibliografia
  Node *aux = lista -> head;
  file << "Disciplina;ISBN;T�tulo;Autor;Edi�o;Cidade;Editora;Ano;Bibliografia b�sica\n";
  for (int i = 0;i < lista -> count;i++){
    file << aux -> disciplina << ';' << aux -> isbn << ';' << aux -> titulo << ';' << aux -> autor << ';' << aux -> edicao << ';' << aux -> cidade << ';' << aux -> editora << ';' << aux -> ano << ';' << aux -> bibliobasica << '\n';
    aux = aux -> next;
  }
  file.close();
}
// Disciplina;ISBN;T�tulo;Autor;Edi�o;Cidade;Editora;Ano;Bibliografia b�sica
// isbn,titulo,autor,cidade,editora,disciplina,edicao,ano,bibliobasica
void InserirLivro(LinkedList* lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao,int ano, char bibliobasica){
  cout << "\nDigite o ISBN deste livro: ";
  cin >> isbn;
  cout << "\nDigite o titulo do livro que deseja inserir: ";
  cin >> titulo;
  cout << "\nDigite o autor deste livro: ";
  cin >> autor;
  cout << "\nDigite a cidade em que este livro foi publicado: ";
  cin >> cidade;
  cout << "\nDigite a editora que publicou este livro: ";
  cin >> editora;
  cout << "\nDigite a disciplina que o livro aborda: ";
  cin >> disciplina;
  cout << "\nDigite a edicao deste livro(1,2,3,4,etc): ";
  cin >> edicao;
  cout << "\nDigite o ano que este livro foi publicado: ";
  cin >> ano;
  cout << "\nDigite S ou N dependendo se o livro possui bibliografia basica ou nao: ";
  cin >> bibliobasica;
  Append(lista,isbn,titulo,autor,cidade,editora,disciplina,edicao,ano,bibliobasica);
}


int main() {
  int entry;
  bool flag = true;
  std::string str;
  std::fstream file;
  std::string data;
  int edicao,ano;
  std::string isbn,titulo,autor,cidade,editora,disciplina;
  char bibliobasica;
  LinkedList *lista = Create();
  while(flag == true){
    cout << "\n----------------------- BIBLIOTECA DE LIVROS ;-;-----------------------\n";
    cout << "1. Ler dados\n2. Exibir dados\n3. Salvar dados\n4. Inserir livro\n5. Remover livro\n6. Análise de dados A\n7. Análise de dados B\n8. Análise de dados C\n9. Encerrar\n";
    cout << "Digite o numero da opcao desejada: ";
    cin >> entry;
    cin.ignore();
    switch(entry){
      case 1:{
      file.open("bibliografia.csv");
  		if (file.is_open())
  		  {
  			std::getline(file, str);
  		  }
  	  else{
        cout << "Nao foi possivel abrir o arquivo.";
        break;
      }
      while(true)//desfazer isso depois
      {
        if (file.eof()) break;
        std::getline(file, str);
        std::istringstream texto(str);
        int i = 0;
        while(std::getline(texto,data,';')){
          if (i == 0){
            disciplina = data;
          }
          else if (i == 1){
            isbn = data;
          }
          else if (i == 2){
            titulo = data;
          }
          else if (i == 3){
            autor = data;
          }
          else if (i == 4){
            edicao = stoi(data);
          }
          else if (i == 5){
            cidade = data;
          }
          else if (i == 6){
            editora = data;
          }
          else if (i == 7){
            ano = stoi(data);
          }
          else if (i == 8){
            const char *c = data.c_str();
            bibliobasica = *c;
          }
          i++;
        }
        Append(lista,isbn,titulo,autor,cidade,editora,disciplina,edicao,ano,bibliobasica);
      }
      break;
      }
      case 2:
        Print(lista);
      break;
      case 3:
        SalvarLivros(lista);
      break;
      case 4:
        InserirLivro(lista,isbn,titulo,autor,cidade,editora,disciplina,edicao,ano,bibliobasica);
      break;
      case 5:{
        Node* temp = RemoverLivro(lista,isbn,titulo);
        if (temp == NULL){
          cout << "Nao existe nenhum livro com este titulo.\n";
          break;
        }
        cout << "\n------------/ " << "LIVRO REMOVIDO " << "/------------\n";
        cout << "Titulo: " << temp -> titulo << "\n";
        cout << "ISBN: " << temp -> isbn << "\n";
        delete temp;
        break;
        }
      
      case 6:
      break;
      
      case 7:
      break;
      
      case 8:
      break;
      
      case 9:
      cout << "Fechando terminal.........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................\n";
      flag = false;
      break;
    }
  }
}