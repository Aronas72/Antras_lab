#include "funkcijos.h"
#include "generavimas.h"
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::random_device;
using std::mt19937;

int main() {
    random_device rd;
    mt19937 gener(rd());

    cout<<"Pasirinkti veiksma:"<<endl;
    cout<<"1 - ivesti studentus (list, strategija 2)."<<endl;
    cout<<"2 - sugeneruoti failus."<<endl;
    cout<<"3 - atlikti testavima su 100000 ir 1000000 dydzio failais."<<endl;
    cout<<"Pasirinkimas: ";
    int pasirinkimas=0;
    cin>>pasirinkimas;

    if (pasirinkimas==2) {
        generavimas("mano1000.txt", 1000, gener);
        generavimas("mano10000.txt", 10000, gener);
        generavimas("mano100000.txt", 100000, gener);
        generavimas("mano1000000.txt", 1000000, gener);
        generavimas("mano10000000.txt", 10000000, gener);}
    else if (pasirinkimas==3){
        testavimas();
        return 0;}
    else if (pasirinkimas==1) {
        string failpav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>failpav;

        auto start = high_resolution_clock::now();
        list<Studentas> grupe=nuskaitymas(failpav);
        auto end = high_resolution_clock::now();
        cout<<"Nuskaitymas uztruko: "<<duration<double>(end-start).count()<<" s"<<endl;

        list<Studentas> vargsiukai;
        
        int gbalas=0;
        cout<<"Pasirinkite kaip skirstyti studentus:"<<endl;
        cout<<"1 - vidurkis"<<endl;
        cout<<"2 - mediana"<<endl;
        cout<<"Jusu pasirinkimas: ";
        cin>>gbalas;

        start = high_resolution_clock::now();
        strategija2_list(grupe, vargsiukai, gbalas);
        end = high_resolution_clock::now();
        cout<<"Skirstymas uztruko: "<<duration<double>(end-start).count()<<" s"<<endl;
        
        int rik=0;
        cout<<"Pasirinkite pagal ka rikiuoti:"<<endl;
        cout<<"1 - vardas"<<endl;
        cout<<"2 - pavarde"<<endl;
        cout<<"3 - balas"<<endl;
        cout<<"Jusu pasirinkimas: ";
        cin>>rik;
        
        int balas=0;
        cout<<"Pasirinkite, kuriuos parametrus rodyti (pagal juos buvo suskaiciuotas ir galutinis balas):"<<endl;
        cout<<"1 - vidurkis"<<endl;
        cout<<"2 - mediana"<<endl;
        cout<<"3 - abu"<<endl;
        cout<<"Jusu pasirinkimas: ";
        cin>>balas;

        start = high_resolution_clock::now();
        isvedimas(vargsiukai, grupe, rik, balas);
        end = high_resolution_clock::now();
        cout<<"Isvedimas uztruko: "<<duration<double>(end-start).count()<<" s"<<endl;}
    return 0;}
