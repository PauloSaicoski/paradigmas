#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>

class Biscoito {
protected:
   std::string formato;
   double area;
   double preco;
public:
   std::string getFormato(){
      return this->formato;
   }
   double getArea(){
      return this->area;
   }
   double getPreco(){
      return this->preco;
   }
   //virtual double calculaArea() = 0;
   void calcPreco(){
      if (this->area <= 50)
         this->preco = 1.5;
      else if (this->area > 75)
         this->preco = 2.5;
      else
         this->preco = 2;
   }
   bool operator>(Biscoito &e)
   {
      return this->area > e.area;
   }
};

bool cmpArea(Biscoito* b1, Biscoito* b2) {
   return b1->getArea() > b2->getArea();
}

class Quadrado : public Biscoito {
   double altura;
   double base;

public:
   double calcArea(){
      this->area = this->altura * this->base;
      return this->area;
   }
   Quadrado(){
      this->altura = (rand()%500 +500); //geralmente os biscoitos não são quadrados perfeitos
      this->base = (rand()%500 +500);
      this->altura /= 100;
      this->base /= 100;
      this->formato = "Quadrado";
      calcArea();
      calcPreco();
   }
};

class Triangulo : public Biscoito {
   double altura;
   double base;

public:
   double calcArea(){
      this->area = this->altura * this->base / 2;
      return area = altura*base/2;
   }
   Triangulo(){
      this->altura = (rand()%697 +717); //numeros calculados para area ser semelhante a area do quadrado
      this->base = (rand()%697 +717);
      this->altura /= 100;
      this->base /= 100;
      this->formato = "Triangulo";
      calcArea();
      calcPreco();
   }
};

class Circulo : public Biscoito {
   double raio;

public:
   double calcArea(){
      this->area = this->raio * this->raio * 3.14;
      return this->area;
   }
   Circulo(){
      this->raio = (rand()%282+282); //numeros calculados para area ser semelhante a area do quadrado
      this->raio /= 100;
      this->formato = "Circulo";
      calcArea();
      calcPreco();
   }
};

int main(){
   int n;
   //srand (time(NULL));
   std::vector<Biscoito*> biscoitos;
   std::cout << "Insira a quantia de biscoitos:" << std::endl;
   std::cin >> n;
   for (int i = 0; i < n; i++){
      int a = rand()%3;
      if (a == 0){
         Circulo* c = new Circulo();
         biscoitos.push_back(c);
      }
      if (a == 1){
         Quadrado* c = new Quadrado();
         biscoitos.push_back(c);
      }
      if (a == 2){
         Triangulo* c = new Triangulo();
         biscoitos.push_back(c);
      }
   }
   std::sort(biscoitos.begin(), biscoitos.end(), cmpArea);
   double g=0, m=0, p=0;
   for(auto it = biscoitos.begin(); it != biscoitos.end(); it++){
      std::cout << (*it)->getFormato() << " com area " << (*it)->getArea() << std::endl;
      if ((*it)->getPreco() == 1.5){
         p++; //conta pequenos
      }
      else if ((*it)->getPreco() == 2)
         m++; //conta medios
      else
         g++; //conta grandes
   }
   std::cout << p << " biscoitos pequenos, " << p*1.5 << " reais" << std::endl;
   std::cout << m << " biscoitos medios, " << m*2 << " reais" << std::endl;
   std::cout << g << " biscoitos grandes, " << g*2.5 << " reais" << std::endl;

}
