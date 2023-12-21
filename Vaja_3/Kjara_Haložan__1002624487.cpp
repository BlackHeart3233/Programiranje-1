#include <iostream>
#include <math.h>
using namespace std;
#include <fstream>
#include <cmath>

void Izpis_grafa(int N, float t0) {
  double radij;
  double obhodni_cas;
  float obhod;
  float krozna_hitrost;
  float manjkajoca_pot;
  int perc_manjkajoca_pot;
  int perc_ze_narejena_pot;
  string ime_planeta;
  string beseda;
  int st;
  int stevec_planeta = 1;
  string line;



  ifstream Datoteka("podatki.txt");
    while (getline (Datoteka, line)) {
      st = 0;
      for(int i = 0; i <= (line.length()); i++) {
        if (line[i] == ' '){
            if(st == 0){
              ime_planeta = beseda;
              beseda ="";
              st +=1;
            }else if (st == 1){
              radij = std::stod(beseda);
              beseda ="";
              st +=1;

            }else if(st ==2){
              obhodni_cas = std::stod(beseda);
              beseda ="";
              st +=1;
            }} else{
              beseda += line[i];

            }
      }
      obhod = (2*M_PI*radij);
      krozna_hitrost = obhod/obhodni_cas;
      manjkajoca_pot = obhod-(t0*krozna_hitrost);



      perc_manjkajoca_pot = (manjkajoca_pot/obhod)*100;
      perc_ze_narejena_pot = ((obhod-manjkajoca_pot)/obhod)*100;

      cout << ime_planeta << "  "<< stevec_planeta << "  (" << perc_ze_narejena_pot<<"%)"<<endl<<endl;

      for (int l=0; l<perc_ze_narejena_pot; l++){
        beseda +='*';}
      for (int d=0; d<perc_manjkajoca_pot; d++){
        beseda +='.';}
      for (int k=0; k<N; k++){
      cout << beseda<< endl<<endl;
    }
    stevec_planeta += 1;
    cout << endl<< endl;
    beseda ="";
  }
}


int main(){

float t0;
int N;


cout << "Vnesi stevilo vrstic: ";
cin >> N;
cout << "Vnesi cas opazovanja: ";
cin >> t0;

Izpis_grafa(N, t0);


    
}