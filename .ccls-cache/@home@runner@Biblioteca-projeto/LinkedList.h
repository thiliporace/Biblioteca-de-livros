#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//Disciplina Texto
// ISBN Texto
// Título Texto
// Autor Texto
// Edição Numérico
// Cidade Texto
// Editora Texto
// Ano Numérico
// Bibliografia básica Booleano

struct Node{
  int edicao,ano;
  std::string isbn,titulo,autor,cidade,editora,disciplina;
  char bibliobasica;
  Node *next;
  Node *previous;
};

struct LinkedList{
  int count;
  Node *head;
  Node *tail;
};

LinkedList *Create();
bool IsEmpty(const LinkedList *lista);
void Insert(LinkedList *lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao, int ano, char bibliobasica);
void Append(LinkedList *lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao, int ano, char bibliobasica);
// Node *RemoveHead(LinkedList *lista);
// Node *RemoveTail(LinkedList *lista);
Node *RemoveNode(LinkedList *lista,std::string isbn,std::string titulo);
void Clear(LinkedList *lista);
void Destroy(LinkedList *lista);
Node *GetHead(LinkedList *lista);
Node *GetTail(LinkedList *lista);
Node *GetNode(LinkedList *lista,std::string isbn,std::string titulo,std::string autor,std::string cidade,std::string editora,std::string disciplina,int edicao, int ano, char bibliobasica);
int Count(LinkedList *lista);