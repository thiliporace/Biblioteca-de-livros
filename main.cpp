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
  getline(cin,isbn);
  cout << "\nDigite o titulo do livro que deseja inserir: ";
  getline(cin,titulo);
  cout << "\nDigite o autor deste livro: ";
  getline(cin,autor);
  cout << "\nDigite a cidade em que este livro foi publicado: ";
  getline(cin,cidade);
  cout << "\nDigite a editora que publicou este livro: ";
  getline(cin,editora);
  cout << "\nDigite a disciplina que o livro aborda: ";
  getline(cin,disciplina);
  cout << "\nDigite a edicao deste livro(1,2,3,4,etc): ";
  cin >> edicao;
  cout << "\nDigite o ano que este livro foi publicado: ";
  cin >> ano;
  cout << "\nDigite S ou N dependendo se o livro possui bibliografia basica ou nao: ";
  cin >> bibliobasica;
  Append(lista,isbn,titulo,autor,cidade,editora,disciplina,edicao,ano,bibliobasica);
}

void AnaliseA(const LinkedList* lista){
  string *estrangeiras {new string[16]{"Elsevier","Pearson","McGraw-Hill","The MIT Press","Addison-Wesley","Dover","Wiley","Cengage Learning","Campus","Brooks Cole","Academic Press","Springer","Packt Publishing","Chapman & Hall","Princeton University Press","CRC Press"}}; //elsevier,pearson,mcgraw-hill,the mit press,Addison-Wesley,dover,wiley,cengage,campus,brooks cole,academic press,springer,packt,chapman & hall,princeton,crc
  string *brasileiras{new string[3]{"LTC","Bookman","Ibpex"}}; //ltc,bookman,ibpex
  Node *aux = new Node;
  aux = lista -> head;
  float count_estrangeira = 0,count_br = 0;
  for (int i = 0;i < lista -> count;i++){
    for (int j = 0;j < 16;j++){
      if (aux -> editora == estrangeiras[j]) count_estrangeira++;
    }
    aux = aux -> next;
  }
  aux = lista -> head;
  for (int i = 0;i < lista -> count;i++){
    for (int j = 0;j < 3;j++){
      if (aux -> editora == brasileiras[j]) count_br++;
    }
    aux = aux -> next;
  }
  aux = nullptr;
  float result = (count_br/(count_br+count_estrangeira))*100;
  cout << "A porcentagem de livros publicados por editoras brasileiras e: " << result << "%\n" << "A porcentagem de livros publicados por editoras estrangeiras e: " << (100-result) << "%\n";
  delete[] estrangeiras;
  delete[] brasileiras;
  delete aux;
}

void AnaliseB(const LinkedList *lista){
  Node *aux = new Node;
  aux = lista -> head;
  float count = 0;
  cout << "\n------------/ " << "LIVROS PUBLICADOS A PARTIR DE 2010 " << "/------------\n";
  for (int i = 0;i < lista -> count;i++){
    if (aux -> ano >= 2010) {
      cout << "\n------------/ " << "LIVRO " << i << " DA LISTA " << "/------------\n";
      cout << "Titulo: " << aux -> titulo << "\n";
      cout << "ISBN: " << aux -> isbn << "\n";
      cout << "Ano: " << aux -> ano << "\n";
      count++;
      }
    aux = aux -> next;
  }
  aux = nullptr;
  float result = (count/lista->count)*100;
  cout << "A porcentagem de livros publicados a partir de 2010 na lista eh: " << result << "%\n";
  delete aux;
}

void AnaliseC(const LinkedList *lista){
  Node *aux = new Node;
  Node *mais_antigo = new Node;
  int count = 0;
  mais_antigo = lista -> head;
  aux = lista -> head;
  for (int i = 0;i < lista -> count;i++){
    if (aux -> ano < mais_antigo -> ano) mais_antigo = aux;
    aux = aux -> next;
  }
  cout << "\n------------/ " << "LIVRO MAIS ANTIGO DA SUA BIBLIOTECA " << "/------------\n";
  cout << "Titulo: " << mais_antigo -> titulo << "\n";
  cout << "ISBN: " << mais_antigo -> isbn << "\n";
  cout << "Ano: " << mais_antigo -> ano << "\n";
  aux = lista -> head;
  for (int i = 0;i < lista -> count;i++){
    if ((mais_antigo -> ano == aux -> ano) && (mais_antigo -> titulo != aux -> titulo)){
      cout << "\n------------/ " << "LIVROS DESTE MESMO ANO " << "/------------\n";
      cout << "Titulo: " << aux -> titulo << "\n";
      cout << "ISBN: " << aux -> isbn << "\n";
      cout << "Ano: " << aux -> ano << "\n";
    }
    aux = aux -> next;
  }
  aux = nullptr;
  mais_antigo = nullptr;
  delete aux;
  delete mais_antigo;
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
      while(true)
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
        if (i == 0) break;
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
        if (temp == nullptr){
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
        AnaliseA(lista);
      break;
      
      case 7:
        AnaliseB(lista);
      break;
      
      case 8:
        AnaliseC(lista);
      break;
      
      case 9:
      cout << "Fechando terminal...\n";
      flag = false;
      break;
    }
  }
}