#include "LinkedList.h"

LinkedList *Create(){
  LinkedList *lista = new LinkedList;
  lista -> count = 0;
  lista -> head = lista -> tail = nullptr;
  return lista;
}

bool IsEmpty(const LinkedList *lista){
  if ((lista -> head == nullptr) && (lista -> tail == nullptr)) return true;
  return false;
}

void Insert(LinkedList *lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao, int ano, char bibliobasica){
  Node *nodo = new Node;
  nodo -> isbn = isbn;
  nodo -> titulo  = titulo;
  nodo -> autor  = autor;
  nodo -> cidade  = cidade;
  nodo -> editora  = editora;
  nodo -> disciplina  = disciplina;
  nodo -> edicao  = edicao;
  nodo -> ano  = ano;
  nodo -> bibliobasica = bibliobasica;
  if (IsEmpty(lista) == true){
    lista -> head = nodo;
    lista -> tail = nodo;
  }
  lista -> head -> previous = nodo;
  nodo -> next = lista -> head;
  lista -> head = nodo;
  lista -> count++;
  lista -> head -> previous = lista -> tail;
  lista -> tail -> next = lista -> head;
}

void Append(LinkedList *lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao, int ano, char bibliobasica){
  Node *nodo = new Node;
  nodo -> isbn = isbn;
  nodo -> titulo  = titulo;
  nodo -> autor  = autor;
  nodo -> cidade  = cidade;
  nodo -> editora  = editora;
  nodo -> disciplina  = disciplina;
  nodo -> edicao  = edicao;
  nodo -> ano  = ano;
  nodo -> bibliobasica = bibliobasica;
  if (IsEmpty(lista) == true){
    lista -> head = nodo;
    lista -> tail = nodo;
  }
  lista -> tail -> next = nodo;
  nodo -> previous = lista -> tail;
  lista -> tail = nodo;
  lista -> count++;
  lista -> head -> previous = lista -> tail;
  lista -> tail -> next = lista -> head;
}

// Node* RemoveHead(LinkedList *lista){
//   if (lista -> count == 0) return NULL;
//   Node *toRemove = new Node;
//   toRemove -> id = lista -> head -> id;
//   toRemove -> nome = lista -> head -> nome;
//   lista -> head -> previous -> next = nullptr;
//   lista -> head -> previous = nullptr;
//   lista -> head = lista -> head -> next;
//   lista -> count--;
//   return toRemove;
// }

// Node* RemoveTail(LinkedList *lista){
//   if (lista -> head == lista -> tail) RemoveHead(lista);
//   Node *toRemove = new Node;
//   toRemove -> id = lista -> tail -> id;
//   toRemove -> nome = lista -> tail -> nome;
//   lista -> tail = lista -> tail -> previous;
//   lista -> tail -> next -> previous = nullptr;
//   lista -> tail -> next = nullptr;
//   lista -> count--;
//   return toRemove;
// }

Node *RemoveNode(LinkedList *lista,std::string isbn,std::string titulo){
  Node *toRemove = new Node;
  int i = lista -> count;
  toRemove = lista -> head;
  while((toRemove -> titulo != titulo) && (toRemove -> isbn != isbn)){
    toRemove = toRemove -> next;
    i--;
    if (i == 0) break;
  }
  if (toRemove -> isbn == isbn){
    toRemove -> previous -> next = toRemove -> next;
    toRemove -> next -> previous = toRemove -> previous;
    toRemove -> next = nullptr;
    toRemove -> previous = nullptr;
    lista -> count--;
    return toRemove;
    }
  else if (toRemove -> titulo == titulo){
    toRemove -> previous -> next = toRemove -> next;
    toRemove -> next -> previous = toRemove -> previous;
    toRemove -> next = nullptr;
    toRemove -> previous = nullptr;
    lista -> count--;
    return toRemove;
  }
  else{
    delete toRemove;
    return nullptr;
  }
}

void Clear(LinkedList *lista){
  Node *aux = new Node;
  while (lista -> count != 0){
    aux = lista -> head;
    lista -> head = lista -> head -> next;
    delete aux;
    lista -> count--;
  }
  lista -> tail = nullptr;
  lista -> head = nullptr;
}

void Destroy(LinkedList *lista){
  Clear(lista);
  delete lista;
}

Node *GetHead(const LinkedList *lista){
  return lista -> head;
}

Node *GetTail(const LinkedList *lista){
  return lista -> tail;
}

// Node *GetNode(const LinkedList *lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao, int ano, char bibliobasica){
//   Node* nodo = new Node;
//   int i = lista -> count;
//   nodo  = lista -> head;
//   while ((nodo -> titulo != titulo) || (nodo -> isbn != isbn) ||(nodo -> autor != autor) ||(nodo -> cidade != cidade) ||(nodo -> editora != editora) ||(nodo -> disciplina != disciplina) ||(nodo -> edicao != edicao ||nodo -> ano != ano) || (nodo -> bibliobasica != bibliobasica)){
//     if (nodo -> titulo == titulo){
//       std::cout << "Titulo:\n" << "[" << nodo -> titulo << "]" << " " <<    nodo -> titulo << "\n";
//       return nodo;
//       }
//     nodo = nodo -> next;
//     i--;
//     if (i == 0) break;
//   }
//   std::cout << "Nao ha nodo com o titulo solicitado.\n";
//   delete nodo;
//   return nullptr;
// }

int Count(LinkedList *lista){
  return lista -> count;
}