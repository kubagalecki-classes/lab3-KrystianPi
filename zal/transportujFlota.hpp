#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if(towar = 0){
       return 0;
    }else{
      Stocznia stocznia{};
      Statek* s1 = stocznia(); 
      int przewieziony_towar = 0; 
      int liczba_zaglowcow = 0;
      while(przewieziony_towar<towar){
        przewieziony_towar = s1->transportuj()+przewieziony_towar; 
        if( s1 == dynamic_cast<Zaglowiec*>(s1)){
            liczba_zaglowcow ++; 
        }
      }
    return liczba_zaglowcow; 
    }
   
}