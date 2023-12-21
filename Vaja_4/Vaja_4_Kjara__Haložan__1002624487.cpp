#include <iostream>
#include <math.h>
using namespace std;
#include <limits.h>

int prastevilo(int stevilo);
int vsota_prastevil();
int povprecje_prastevil(int polje[20], int st);

int prastevilo(int stevilo){
    bool prastevilo = true;

    if (stevilo <= 1 || stevilo ==1){
            prastevilo = false;
    }else{
        for(int i=1; i<stevilo; i++){
            if (stevilo%i == 0 &&  i != 1){
                prastevilo = false;
            }
        }
    }
    return prastevilo;

}

int vsota_prastevil(){
    int vsota =0;
    for (int i=-256; i <=512; i++){
        if(prastevilo(i)==1){
            vsota += i;
        }
    }
    return vsota;
}


int povprecje_prastevil(int polje[20], int st){

int stevec = 0;
int povprecje = 0;

while(stevec <20){
    if(prastevilo(st)==1){
           polje[stevec]=st;
           stevec += 1;
           povprecje += st;
        }
    st +=1;
}
povprecje = povprecje/20;
return povprecje;
}

int main(){
int stevilo;
int seznam[20];
int st1;
int st3;
int neko_novo;

cout << "Vsota prastevil med -256 in 512 je: "<<vsota_prastevil()<<endl;




cout << "Vnesite stevilo za prvo funkcijo: ";
cin >> st1;
cout << "Vnesite stevilo za tretjo funkcijo: ";
cin >> st3;


if (prastevilo(st1) == 0){
    cout << "Stevilo: "<<st1<< " ni prastevilo" << endl;
}else{
    cout << "Stevilo: "<<st1<< " je prastevilo" << endl;
}
cout << "Povprecje prastevil je: " << povprecje_prastevil(seznam,st3) << endl;

cout << "Vnesite neko novo stevilo: ";
cin >> neko_novo;

povprecje_prastevil(seznam,neko_novo);

neko_novo = neko_novo * neko_novo;


int naj_st = INT_MAX;
int naj_st_razlika=0;
int racunanje;

for (int i = 0; i <= 20; i++){
    if(neko_novo>seznam[i]){
        racunanje = neko_novo - seznam[i];
    }else{
        racunanje = seznam[i]-neko_novo;
    }
    if(naj_st>racunanje){
        naj_st_razlika = racunanje;
        naj_st = seznam[i];
    }


}
cout<<"Stevilu "<<neko_novo <<" je najblizje stevilo: " << naj_st << " in razlika med njima je: "<< naj_st_razlika <<endl;
}
