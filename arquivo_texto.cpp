#include <iostream>
#include <sstream>
#include <fstream>

int hahahsd()
{
	std::ifstream ifs;
	std::string str;

	try
	{
		// Tenta abrir o arquivo "arquivo.txt".
		ifs.open("arquivo.txt");
    
		if (ifs.is_open())
		{
			// Lê a primeira linha do arquivo e salva o conteúdo na string str.
			std::getline(ifs, str);

			// Fecha o arquivo.
			ifs.close();
		}
	}
	catch (...)
	{
	}

	// Cria um istringstream com o conteúdo da string str
	// (a string que contém a primeira linha do arquivo "arquivo.txt").
	std::istringstream iss(str);

	std::string data;

	// Separa o conteúdo de iss usando a vírgula como caractere delimitador.
	// Cada pedaço que foi separado é copiado na string data.
	while (std::getline(iss, data, ','))
	{
		std::cout << data << '\n';
	}
}
