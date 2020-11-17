#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if(towar = 0){
       return 0;
    }else{
      int przewieziony_towar = 0; 
      int liczba_zaglowcow = 0;
      while(przewieziony_towar<towar){
        Stocznia stocznia{};
        Statek* s1 = stocznia(); 
        przewieziony_towar = s1->transportuj()+przewieziony_towar; 
        if(dynamic_cast<Zaglowiec*>(s1)){
            liczba_zaglowcow ++; 
        }
        delete s1; 
      }
    return liczba_zaglowcow; 
    }
   
}