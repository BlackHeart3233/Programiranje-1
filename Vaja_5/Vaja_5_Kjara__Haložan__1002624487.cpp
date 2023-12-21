#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <typeinfo> 

#include <ctime>




string gen_podatko(int(&tabela)[166][5], string(&imena_primek)[166]){
    int tocke;
    srand(time(0));
    string ImeInPrimek;
     //1 index imena, KV, RV, VI in OC
    string imena[30] = {
        "Ana", "Boris", "Cilka", "David", "Eva",
        "Franc", "Greta", "Hugo", "Ivana", "Janko",
        "Klara", "Luka", "Maja", "Niko", "Olga",
        "Peter", "Qwerty", "Rok", "Sara", "Tomaz",
        "Uros", "Vanja", "Wanda", "Xavier", "Yana",
        "Zala", "Andrej", "Barbara", "crt", "ziva"
    };
    string primek[20]={
        "Abram", "Bianchi", "Cvetko", "Dolinar", "Erjavec",
        "Furlan", "Golob", "Hribar", "Ivancic", "Jerman",
        "Kos", "Lah", "Mlakar", "Novak", "Oblak",
        "Petrovic", "Quaresma", "Rus", "stih", "Tratar",
    };
    for(int i = 0; i <166; i++){
        float skupne_tocke = 0;
        int  index_imena = rand()%29;
        int index_primka = rand()%19;
        ImeInPrimek = imena[index_imena] + " " + primek[index_primka];
        imena_primek[i] = ImeInPrimek;
        tabela[i][0] = i;
        for (int x = 1; x <4; x++){
            tocke = rand() % 101;
            skupne_tocke = skupne_tocke + tocke;
            tabela[i][x] = tocke;
        }
        skupne_tocke = (skupne_tocke/300)*10;
        tabela[i][4] = skupne_tocke;
    }
}


void UrejanjeSeznama(int (&tabela)[166][5]) {
    for (int l = 0; l < 166; l++) {
        for (int k = 0; k < (166 - 1 - l); k++) { 
            if (tabela[k][4] < tabela[k + 1][4]) {
                swap(tabela[k], tabela[k + 1]);
            }
        }
    }
}


string IzpisOcen (int(&tabela)[166][5],string(&imena_primek)[166]){
         //1 index imena, KV, RV, VI in OC
        string izpis ="";
        string kocna_zapis = "";
        int izpisek;
        int st_pass = 0;
        float skupno_st_tock_pass = 0;
        int velikost;
        bool tocke = true;
        int stevec_vnosa = 0;
        for (int d=0; d<166; d++) {
            if(tabela[d][1] < 50 || tabela[d][2]<50 || tabela[d][3]<50){
                tocke = false;
        }else{
                st_pass += 1;
            }
        }
        int tabela_uspesnih[st_pass][2];



        izpis =  "Zaporedno stevilo:  Ime in primek:  KV  RV VI OC \n";
        for(int l = 0; l < 166; l++){
            kocna_zapis = "";
            for(int m = 0; m < 5;m++){
                if(m == 0){
                    int number =tabela[l][m];
                    izpis += to_string(number) + + " "+imena_primek[number]+ " ";
                }else if(m == 1){
                    if(tabela[l][m] < 50){
                        kocna_zapis +=  "KV, ";
                    }
                    izpisek = tabela[l][m];
                    izpis += to_string(izpisek) + " ";
                }else if(m == 2){
                    if(tabela[l][m] < 50){
                        kocna_zapis += "RV, ";
                    }
                    izpisek = tabela[l][m];
                    izpis +=to_string(izpisek) + " ";
                }else if(m == 3){
                    if(tabela[l][m] < 50){
                        kocna_zapis += "RV ";
                }
                    izpisek = tabela[l][m];
                    izpis += to_string(izpisek) + " ";
                }else if( m == 4){
                    if (kocna_zapis == ""){
                        tabela_uspesnih[stevec_vnosa][0] = tabela[l][0];
                        tabela_uspesnih[stevec_vnosa][1] = tabela[l][4];
                        //cout << tabela_uspesnih[stevec_vnosa][0] <<"  "<< tabela_uspesnih[stevec_vnosa][1] << endl;
                        izpisek = tabela[l][m];
                        izpis += to_string(izpisek)+ " \n";
                        skupno_st_tock_pass += izpisek;
                        //cout << izpisek << endl;
                        stevec_vnosa +=1;
                    }else{
                        if(kocna_zapis[kocna_zapis.length() - 2] == ','){
                            kocna_zapis[kocna_zapis.length() - 2] = ' ';
                        }

                        izpis += kocna_zapis + "\n";
                    }
                }

            }


        }

        /*for (int i= 0; i < st_pass; i++){
            cout << tabela_uspesnih[i][0] << " " << tabela_uspesnih[i][1]<< endl;
        }*/


        int prvi[2]; //  0-zaporedna st 1-tocke
        prvi[1] = 10;  //0 zaporedna 1-tocke
        int drugi[2];
        drugi[1] = 10;



        //cout << skupno_st_tock_pass <<"  "<< st_pass<< endl; // NEKAJ NAROBE Z OC 
        skupno_st_tock_pass = skupno_st_tock_pass/st_pass;
        /*cout << skupno_st_tock_pass << endl;
        cout << "im here" << endl;*/
        for (int k = 0; k <st_pass; k++ ){
            if(abs(skupno_st_tock_pass-tabela_uspesnih[k][1] < abs(skupno_st_tock_pass-prvi[1]))){
                prvi[0] = tabela_uspesnih[k][0];
                prvi[1] = tabela_uspesnih[k][1];
                //cout << tabela_uspesnih[k][1] << endl;

            }else if(abs(skupno_st_tock_pass-tabela_uspesnih[k][1] < abs(skupno_st_tock_pass-drugi[1]))){
                drugi[0] = tabela_uspesnih[k][0];
                drugi[1] = tabela_uspesnih[k][1];

        }

        }

        //cout << to_string(prvi[0]) << " tuki si  "<< to_string(drugi[0]) << endl;

        izpis += "\n Povprecna ocena studentov, ki so opravili izpit je " + to_string(static_cast<int>(skupno_st_tock_pass));
        izpis += "." +to_string(static_cast<int>((skupno_st_tock_pass - static_cast<int>(skupno_st_tock_pass)) * 10))+" ";;
        izpis += "(najblizje pod zaporedno st.: "+to_string(prvi[0])+","+to_string(drugi[0])+")";
        return izpis;
}


int main(){
    string imena_primek[166];
    int tabela[166][5];
    gen_podatko(tabela,imena_primek);
    //cout << tabela[0][4]<<endl;
    UrejanjeSeznama(tabela);
    //cout << tabela[0][4]<<endl;
    cout << IzpisOcen(tabela,imena_primek);



}