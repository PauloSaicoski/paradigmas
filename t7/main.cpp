#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include <stdexcept>
#include <FL/fl_ask.H>
#include "window.h"
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdio>


class AddSubView : public UserInterface {
private:
  std::vector<int> v;
  int b=0, n=0;
public:
  
  AddSubView() {
    btnReset->callback((Fl_Callback*) cbBtnReset, (void*)(this));
    btnSortear->callback((Fl_Callback*) cbBtnSort, (void*)(this));
  }
  void reset(){
    this->inputQuant->value("");
    this->boxVencedor->label("");
    this->boxNoGanhador->label("");
    this->v.clear();
    this->b = 0;
    this->n = 0;
  }
  
  void show() {
    // Mostra janela
    w->show();
  }
    void vetEmb(int n){
    int i;
    for (i=1; i<=n; i++){
      this->v.push_back(i);
    }
    std::random_shuffle(this->v.begin(),this->v.end());
  }
  int vencedor (){
    int a;
    if (!this->v.empty()){
      a = this->v.back();
      this->v.pop_back();
      return a;
    }
    else{
      fl_alert("Foram todos sorteados.");
      return 0;
    }
  }
  
  // Funcao callback chamada quando pressionado botao '+' ou botao '-'
  static void cbBtnReset(Fl_Widget* btn, void* userdata) { //reset
    AddSubView* gui = static_cast<AddSubView*>(userdata);
    gui->reset();
  }

  // Funcao callback chamada quando pressionado botao 'Clear'
  static void cbBtnSort(Fl_Widget* btn, void* userdata) { //sort
    AddSubView* gui = static_cast<AddSubView*>(userdata);
    int result;
    try {
      int a = std::stoi(gui->inputQuant->value());
      if (gui->b == 0){
        gui->vetEmb(a);
        gui->b++;
      }
      result = gui->vencedor();
      std::string g = "º Ganhador";
      gui->n++;
      g = std::to_string(gui->n).c_str() + g;
      if(result){
        gui->boxNoGanhador->copy_label(g.c_str());
        gui->boxVencedor->copy_label(std::to_string(result).c_str());
      }
      else{
        gui->reset();
      }
    } catch (std::invalid_argument&) {
      fl_alert("Digite um numero.");
    } catch (std::out_of_range&) {
      fl_alert("Argumento fora de faixa.");
    }
  }

};

int main() {
  AddSubView gui;
  gui.show();
  return Fl::run();
}


