#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>

class Escores2 {
	std::string nome;
	int pontos;
public:
	Escores2(std::string nome, int pontos){
		this->nome = nome;
		this->pontos = pontos;
	}
	void altera_Nome(std::string nome){
		this->nome = nome;
	}
	void soma_Pontos(int pontos){
		this->pontos += pontos;
	}
	std::string getNome(){
   	  return nome;
   }
   int getPontos(){
   	  return pontos;
   }
   bool operator<(Escores2& e) {
      return this->pontos < e.pontos;
   }

};

class Escores {
   std::string nome;
   std::string atividade;
   int pontos;
public:
   Escores(std::string nome, std::string atividade, int pontos) {
      this->nome = nome;
      this->atividade = atividade;
      this->pontos = pontos;
   }
   std::string getNome() {
      return nome;
   }
   std::string getAtividade() {
   	  return atividade;
   }
   int getPontos() {
      return pontos;
   }
   // operador '<' sobrecarregado (overload)
   // permite comparar Persons pela idade
   bool operator<(Escores& e) {
      return this->pontos < e.pontos;
   }

};

// comparador de Persons pelo nome
bool cmpEscoreNome(Escores& e1, Escores& e2) {
   return e1.getNome() < e2.getNome();
}

int main() {

   std::ifstream data("data.csv");

   std::string line;
   std::string cell[3];
   std::vector<Escores> t;
   std::map <std::string, Escores2*> Competidor;

   while (std::getline(data, line)) {
      std::stringstream linestream(line);
      std::getline(linestream, cell[0], ',');
      std::getline(linestream, cell[1], ',');
	  std::getline(linestream, cell[2], ',');
      t.push_back(Escores(cell[0], cell[1] , std::atoi(cell[2].data())));
      Escores2 b = Escores2(cell[0], std::atoi(cell[2].data()));
      Competidor[cell[0]]= new Escores2(cell[0], 0);
   }

   std::vector<Escores>::iterator it;

   // Ordem original
   std::cout<< "Ordem original dos escores dos jogadores" << std::endl;
   std::cout << std::endl;
   for (it = t.begin(); it != t.end(); it++){
      std::cout<< it->getNome() << " - ";
      std::cout<< it->getAtividade() << " - ";
	  std::cout<< it->getPontos() << std::endl;
	  Competidor[it->getNome()]->soma_Pontos(it->getPontos());
	}
	std::cout << std::endl;

   // Ordenando pelos pontos
   std::cout<< "Ordenacao dos escores por ordem crescente dos pontos dos jogadores" << std::endl;
   std::cout << std::endl;
   std::sort(t.begin(), t.end());
   for (it = t.begin(); it != t.end(); it++){
      std::cout<< it->getNome() << " - ";
      std::cout<< it->getAtividade() << " - ";
	  std::cout<< it->getPontos() << std::endl;
	}
	std::cout << std::endl;


	std::vector<Escores2> u;
	std::string itens[2];
	std::map<std::string, Escores2*>::iterator c;
	for (c = Competidor.begin(); c!=Competidor.end(); c++){
        u.push_back(*(c->second));
	}
    std::sort(u.begin(), u.end());
    std::vector<Escores2>::iterator it_u;
    for (it_u = u.begin(); it_u != u.end(); it_u++){
      std::cout<< it_u->getNome() << " - ";
	  std::cout<< it_u->getPontos() << std::endl;
	}

   /*
   // Ordenando pelos nomes (usando a classe Escores [3 argumentos])
   std::cout<< "Ordenacao dos escores por ordem alfabetica dos nomes dos jogadores" << std::endl;
   std::cout << std::endl;
   std::sort(t.begin(), t.end(), cmpEscoreNome);
   for (it = t.begin(); it != t.end(); it++){
      std::cout<< it->getNome() << " - ";
      std::cout<< it->getAtividade() << " - ";
	  std::cout<< it->getPontos() << std::endl;
	}
	std::cout << std::endl;
   */

}
