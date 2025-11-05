#include "funkcijos.h"
#include "generavimas.h"
#include <sstream>

double vidurkis(const vector<double>& v);
double mediana(const vector<double>& v);

list<Studentas> nuskaitymas(const string& failpav) {
    list<Studentas> grupe;
    ifstream fd(failpav);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failpav << endl;
        return grupe;}

    string antraste;
    std::getline(fd, antraste);
    Studentas st;
    while (st.readStudent(fd)) {
        grupe.push_back(std::move(st));
        st=Studentas();}
    return grupe;}

void strategija3_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai) {
    auto is_vargsiukas=[](const Studentas& st) {
        return st.galBalas(mediana)<5.0;};

    for (auto it=grupe.begin(); it!=grupe.end(); ){
        if (is_vargsiukas(*it)){
            vargsiukai.splice(vargsiukai.end(), grupe, it++);
        } else{
            galvociai.splice(galvociai.end(), grupe, it++);}}}

void isvedimas(const list<Studentas>& vargsiukai, const list<Studentas>& galvociai) {
    list<Studentas> v=vargsiukai;
    list<Studentas> g=galvociai;
    
    v.sort(comparePagalEgza);
    g.sort(comparePagalEgza);
    ofstream fv("vargsiukai.txt");
    fv<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Galutinis (Med.)"<<endl;
    fv<<string(45, '-')<<endl;
    for(const auto& st : v) {
        fv<<setw(15)<<left<<st.vardas()<<setw(20)<<left<<st.pavarde()<<setw(10)<<left<<fixed<<setprecision(2)<<st.galBalas(mediana)<<endl;}
    fv.close();

    ofstream fg("galvociai.txt");
    fg<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Galutinis (Med.)"<<endl;
    fg<<string(45, '-')<<endl;
    for(const auto& st : g) {
        fg<<setw(15)<<left<<st.vardas()<<setw(20)<<left<<st.pavarde()<<setw(10)<<left<<fixed<<setprecision(2)<<st.galBalas(mediana)<<endl;}
    fg.close();

    cout << "Is viso: " << vargsiukai.size() << " vargsiuku ir " << galvociai.size() << " galvociu." << endl;}

void testavimas(){
    string failai[]={"mano100000.txt", "mano1000000.txt"};
    int pal=5;

    cout<<"Testavimo pradzia. Naudojamas konteineris: List, Strategija: 3."<<endl;
    for (const string& failas : failai){
        double lskaitymas=0.0, lskirstymas=0.0;
        
        for (int p=0; p<pal; p++) {
            auto start=std::chrono::high_resolution_clock::now();
            list<Studentas> grupe=nuskaitymas(failas);
            auto end=std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff=end-start;
            lskaitymas += diff.count();

            start=std::chrono::high_resolution_clock::now();
            list<Studentas> vargsiukai, galvociai;
            strategija3_list(grupe, vargsiukai, galvociai);
            end=std::chrono::high_resolution_clock::now();
            diff=end-start;
            lskirstymas += diff.count();}

        cout<<"Failas: "<<failas<<endl;
        cout<<"Listas: skaitymo vidurkis: "<<fixed<<setprecision(5)<<(lskaitymas/pal)<<" s, dalijimo vidurkis: "<<(lskirstymas/pal)<<" s"<<endl;}
    cout<<"Testavimo pabaiga."<<endl;}
