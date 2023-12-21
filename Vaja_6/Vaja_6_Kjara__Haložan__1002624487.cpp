#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <cfloat>
#include <limits.h>
using namespace std;

 const char *scenarij1 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **             \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


 const char *scenarij2 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


 const char *scenarij3 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *        |     \n"
 "       *        |     \n"
 "       *       /      \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


 const char *scenarij4 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *        |     \n"
 "       *        |     \n"
 "       *       / \\    \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";

 const char *scenarij5 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *        |=     \n"
 "       *        |     \n"
 "       *       / \\    \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";

 const char *scenarij6 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *       =|=    \n"
 "       *        |     \n"
 "       *       / \\    \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";

 const char *scenarij7 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *       =|=-   \n"
 "       *        |     \n"
 "       *       / \\    \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";

 const char *scenarij8 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *      -=|=-   \n"
 "       *        |     \n"
 "       *       / \\    \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";

 const char *scenarij9 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *      -=|=--  \n"
 "       *        |     \n"
 "       *       / \\    \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";



 const char *scenarij10 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *     --=|=--  \n"
 "       *        |     \n"
 "       *       / \\  \n"
 "       *              \n"
 "      * *  GAME OVER! \n"
 "     *   *            \n";

const char *scenariji[] = {scenarij1, scenarij2, scenarij3,scenarij4,scenarij5,scenarij6,scenarij7,scenarij8,scenarij9, scenarij10};


struct igralci {
    string ime;
    int vpisna_st;
    string trenutno_ugibano_geslo;
    int ugibane_crke;
    int potreben_cas;
};

string geslo(){
    srand(time(NULL));
    int index_gesla = rand() % 100;
    string izbrano_geslo;
    string words[100] = {
        "programiranje", "razvoj", "jezik", "racunalnik", "algoritem", "strojno", "umetna", "inteligentnost", "podatki", "nastavitev",
        "koda", "izjava", "pogoj", "zanka", "razred", "funkcija", "metoda", "spremenljivka", "objekt", "operacija",
        "indeks", "kompilacija", "interpretacija", "spremenljivka", "konstanta", "uporabniski", "vmesnik", "grafika", "podpora", "knjiznica",
        "programer", "razvijalec", "testiranje", "debugiranje", "napaka", "algoritmiCni", "strokovnjak", "integracija", "optimizacija", "konfiguracija",
        "sistemska", "arhitektura", "raCunalniski", "virus", "varnost", "sifriranje", "avtentikacija", "avtorizacija", "uporabnik", "geslo",
        "analogno", "digitalno", "elektronika", "senzor", "aktuator", "mikroprocesor", "operacijski", "sistem", "disk", "tiskalnik",
        "pomnilnik", "vgrajeni", "mreza", "streznik", "klient", "protokol", "usmerjevalnik", "modem", "brskalnik", "koda",
        "platforma", "aplikacija", "mobilni", "naprava", "operater", "frekvenca", "valovanje", "elektromagnetno", "radijski", "optiCni",
        "satelit", "komunikacija", "internet", "podatkovna", "prenos", "multimedija", "e-posta", "socialno", "omrezje", "spletna",
        "stran", "podpora", "podjetje", "inovacija", "trzenje", "prodaja", "stranka", "partner", "projekt", "management"
    };
    izbrano_geslo = words[index_gesla];
    return izbrano_geslo;


}


int main (){
    string stevilo_ugibanja_najboljski[5][2];
    string sortiram_izpis[5][4];
    int st_igralca = 1;
    igralci igralci_array[5];
    int st = 0;
    string ime;
    int vpisna_st;
    while(st < 5){
        cout << "Vnesite ime:";
        cin >> ime;
        igralci_array[st].ime = ime;
        cout << "Vnesite vpisno st: ";
        cin >>vpisna_st;
        igralci_array[st].vpisna_st = vpisna_st;
        igralci_array[st].trenutno_ugibano_geslo = geslo();
        st += 1;
    }
    /*for (int i = 0; i <2; i++){
        cout << igralci_array[i].trenutno_ugibano_geslo;
    }*/

    for (int k = 0; k <5;k++){
        clock_t start = clock();
        int dolzina_gesla = (igralci_array[k].trenutno_ugibano_geslo).length();
        int stevec_crk = 0;
        string beseda = igralci_array[k].trenutno_ugibano_geslo;
        string array_besede[dolzina_gesla];
        int st_ugibanih_crk = 0;
        cout << beseda << endl;
        string najdene_besede[dolzina_gesla];
        string ugibana_crka;
        string izpis = "";
        int index_scenarijev = 0;
        bool konec = false;
        bool if_true = true;
        bool vse_crke_najdene = false;
        for (int i = 0; i < dolzina_gesla; i++){
            array_besede[i] = beseda[i];
        }   
        cout << "Na vrsti je: "<<igralci_array[k].ime << endl;
        while (index_scenarijev <= 9 && konec == false){
            izpis = "";
            for (int q = 0; q < beseda.length(); q++){
                if (najdene_besede[q] == ""){
                    izpis += " _ ";
                }else{
                    izpis += " "+najdene_besede[q]+"";
                }
            }
                stevec_crk = 0;
                cout << scenariji[index_scenarijev]; 
                if(index_scenarijev != 9){
                cout << izpis<< endl;
                cout << "Prosim vpisite ugibana crko: ";
                cin >> ugibana_crka;
                st_ugibanih_crk += 1;
                igralci_array[k].ugibane_crke = st_ugibanih_crk;
                if (beseda.find(ugibana_crka) != std::string::npos){
                    for (int m = 0; m < beseda.length(); m++){
                    if (vse_crke_najdene != true){
                        if(array_besede[m] == ugibana_crka){
                            stevec_crk +=1;
                        }
                        for( int l = 0; l < stevec_crk; l++){
                            if_true = true;
                            for(int d = 0; d < beseda.length(); d++){
                                if(array_besede[d] == ugibana_crka && if_true == true){
                                    najdene_besede[d] = ugibana_crka;
                                    array_besede[d] = "";
                                    if_true = false;
                                }
                            
                            }
                        }
                        vse_crke_najdene = true;
                        for(int m= 0; m < beseda.length(); m++){
                            if(array_besede[m] !=  ""){
                                vse_crke_najdene = false;
                            }
                        }
                        if (vse_crke_najdene == true){
                            konec = true;
                            clock_t end = clock();
                            cout << "Bravo uganili ste! Beseda je: " << beseda << endl;
                            igralci_array[k].potreben_cas = ((int ) (end - start)/ CLOCKS_PER_SEC);
                        }
                    }
                    }

                    
                }else{
                    index_scenarijev += 1;

                }}else{
                    index_scenarijev += 1;
                }

        }
        if(index_scenarijev == 10){
            igralci_array[k].potreben_cas = 1000 ;
            clock_t end = clock();
        }
    }

for (int s = 0; s < 5; s++){
    stevilo_ugibanja_najboljski[s][0]= igralci_array[s].ime;
    stevilo_ugibanja_najboljski[s][1]= to_string(igralci_array[s].ugibane_crke);
}


for (int i = 0; i < 5 ; i++) {
    for (int j = 0; j < 5 - i - 1; j++) {
        if (stoi(stevilo_ugibanja_najboljski[j][1]) > stoi(stevilo_ugibanja_najboljski[j + 1][1])) {
            swap(stevilo_ugibanja_najboljski[j], stevilo_ugibanja_najboljski[j + 1]);
        }
    }
}

cout << "Najboljsi glede na stevilo ugibanj je: " << stevilo_ugibanja_najboljski[0][0] << endl;


for (int b = 0; b < 5; b++){
    sortiram_izpis[b][0]= igralci_array[b].ime;
    sortiram_izpis[b][1]= to_string(igralci_array[b].potreben_cas);
    sortiram_izpis[b][2]= to_string(igralci_array[b].ugibane_crke);
    sortiram_izpis[b][3]= igralci_array[b].trenutno_ugibano_geslo;
}


for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5 - i - 1; j++) {
        if (stoi(sortiram_izpis[j][1]) > stoi(sortiram_izpis[j + 1][1])) {
            swap(sortiram_izpis[j], sortiram_izpis[j + 1]);
        }
    }
}

string html_izpis ="";
for(int i = 0; i <5; i++) {
    html_izpis += "<tr>\n";
    html_izpis += "\t<td>"+sortiram_izpis[i][0]+"</td>\n";
    html_izpis += "\t<td>"+sortiram_izpis[i][3]+"</td>\n";
    html_izpis += "\t<td>"+sortiram_izpis[i][2]+"</td>\n";
    html_izpis += "\t<td>"+sortiram_izpis[i][1]+"</td>\n";
    html_izpis += "</tr>\n";
}
html_izpis += "\t</table>\n</body>\n</html>";



string file = "C:\\Users\\BlackHeart\\Desktop\\Programiranje 1\\Vaja_6\\izpis.html";
ofstream Output_html(file, std::ios::out | std::ios::app);
    if (!Output_html.is_open()) {
        cerr << "Napaka pri odpiranju datoteke: " << file << endl;
        return 1;  
    }
    Output_html << html_izpis;
    Output_html.close();



}