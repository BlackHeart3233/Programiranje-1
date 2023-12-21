#include <iostream>
#include <math.h>
using namespace std;

int main(){

float radij;
float cas_opazovanja;
float obhodni_cas;

float obhod;
float krozna_hitrost;
float manjkajoca_pot;


cout << "Vnesi radij: ";
cin >> radij;
cout << "Vnesi cas opazovanja: ";
cin >> cas_opazovanja;
cout << "Vnesi obhodni cas: ";
cin >> obhodni_cas;

cout << radij << " " << cas_opazovanja << " " << obhodni_cas << "  \n \n";

obhod = 2*M_PI*radij;
krozna_hitrost = obhod/obhodni_cas;

manjkajoca_pot = obhod-(cas_opazovanja*krozna_hitrost);

cout << obhod << " - (" << cas_opazovanja << " * " << krozna_hitrost << ") = " << manjkajoca_pot <<"\n \n";

if (manjkajoca_pot == 0){
    cout << "En obhod";
}else if(manjkajoca_pot<0){
    cout <<"Ni obhoda";
}else if(manjkajoca_pot>0){
    cout << "Vec kot en obhod";
}


}