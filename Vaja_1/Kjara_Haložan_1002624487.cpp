#include <iostream>
#include <string>
using namespace std;

int jutro_min = 40;
int popoldan_max = 0;
string jutro_name="";
string popoldan_name="";
string jutro_vir ="";
string popoldan_vir="";

int main() {
  string imena[10] = {"Mariboru","Ljubljani", "Kranju", "Kopru", "Celju","Novem Mestu","Postojni","Grosuplju","Ptuju","Jesenicah"};
  int temperature[10][2]={{19, 14,},{15 ,15},{19, 12},{22,17},{20, 13},{20, 14},{16, 14},{18, 14},{16, 14},{18, 14}};
  string viri[10] = {"https://vreme.arso.gov.si/napoved/Maribor/graf", "https://vreme.arso.gov.si/napoved/Ljubljana/graf", "https://vreme.arso.gov.si/napoved/Kranj/graf", 
  "https://vreme.arso.gov.si/napoved/Koper/graf","https://vreme.arso.gov.si/napoved/Celje/graf","https://vreme.arso.gov.si/napoved/Novo%20mesto/graf","https://vreme.arso.gov.si/napoved/Postojna/graf",
  "https://vreme.arso.gov.si/napoved/Grosuplje/graf","https://vreme.arso.gov.si/napoved/Ptuj/graf","https://vreme.arso.gov.si/napoved/Jesenice/graf"};

  for (int i = 0; i < 10; i++) {
  cout <<"V " << imena[i] << " zjutraj: "<< temperature[i][0] << " stopinj in popoldan: "<< temperature[i][1] << " stopinj \n ";
  cout << "Podatki se nahajajo: " << viri[i]<<"\n \n";
}

for (int i = 0; i < 10; i++) {
  if(jutro_min >= temperature[i][0] ){
    jutro_min = temperature[i][0];
    jutro_name=imena[i];
    jutro_vir = viri[i];

  }
}
cout << "Najmanjsa temperatura zjutraj je v "<< jutro_name << " in je: " << jutro_min << " stopinj \n ";
cout << "Podatki se nahajajo: " << jutro_vir << "\n\n";

for (int i = 0; i < 10; i++) {
  if(jutro_min <= temperature[i][1] ){
    popoldan_max = temperature[i][1];
    popoldan_name = imena[i];
    popoldan_vir = viri[i];
  }
}
cout << "Najvecja temperatura popoldan je v "<< popoldan_name << " in je: " << popoldan_max <<  " stopinj \n ";
cout << "Podatki se nahajajo: " << popoldan_vir << "\n\n";


}