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
    cout<<"1 - ivesti studentus (list, strategija 3)."<<endl;
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
        list<Studentas> galvociai;

        start = high_resolution_clock::now();
        strategija3_list(grupe, vargsiukai, galvociai);
        end = high_resolution_clock::now();
        cout<<"Skirstymas uztruko: "<<duration<double>(end-start).count()<<" s"<<endl;

        start = high_resolution_clock::now();
        isvedimas(vargsiukai, galvociai);
        end = high_resolution_clock::now();
        cout<<"Isvedimas uztruko: "<<duration<double>(end-start).count()<<" s"<<endl;}
    return 0;}
