#include "funkcijos.h"
#include "generavimas.h"
#include <sstream>
#include <iostream>
#include <limits>
#include <algorithm>

double vidurkis(const vector<double>& v);
double mediana(const vector<double>& v);

list<Studentas> nuskaitymas(const string& saltinis, bool is_failo) {
    list<Studentas> grupe;
    if (is_failo) {
        ifstream fd(saltinis);
        if (!fd.is_open()) {
            cout << "Nepavyko atidaryti failo: " << saltinis << endl;
            return grupe;}

        string antraste;
        std::getline(fd, antraste);

        Studentas st;
        while (fd >> st) {
            grupe.push_back(std::move(st));
            st = Studentas();}}
    else {
        Studentas st;
        while (std::cin >> st) {
            grupe.push_back(std::move(st));
            st = Studentas();}}
    return grupe;}

void strategija2_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, int pasirinkti){
    for(auto it = grupe.begin(); it != grupe.end(); ){
        double bal = (pasirinkti == 2 ? it->med : it->gal);
        if(bal<5.0){
            vargsiukai.push_back(*it);
            it = grupe.erase(it);}
        else ++it;}}

void isvedimas(const list<Studentas>& vargsiukai, const list<Studentas>& galvociai, int rik, int balas, bool i_ekrana) {
    list<Studentas> v = vargsiukai;
    list<Studentas> g = galvociai;

    bool (*lyg)(const Studentas&, const Studentas&);
    if (rik == 1) lyg = compare;
    else if (rik == 2) lyg = comparePagalPavarde;
    else if (rik == 3) {
        if (balas == 1) lyg = comparePagalVid;
        else lyg = comparePagalMed;}

    v.sort(lyg);
    g.sort(lyg);

    auto spausdinti_antraste = [&](std::ostream& os) {
        os << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde";
        if (balas == 1) os << setw(18) << right << "Galutinis (Vid.)";
        else if (balas == 2) os << setw(18) << right << "Galutinis (Med.)";
        else os << setw(18) << right << "Galutinis (Med.)" << setw(18) << right << "Galutinis (Vid.)";
        os << endl;
        os << string(53 + (balas == 3 ? 18 : 0), '-') << endl;};

    auto spausdinti_studentus = [&](std::ostream& os, const list<Studentas>& l) {
        for (const auto& st : l) {
            os << setw(15) << left << st.vardas() << setw(20) << left << st.pavarde();
            if (balas == 1) os << setw(18) << right << fixed << setprecision(2) << st.gal;
            else if (balas == 2) os << setw(18) << right << fixed << setprecision(2) << st.med;
            else {
                os << setw(18) << right << fixed << setprecision(2) << st.med << setw(18) << right << fixed << setprecision(2) << st.gal;}
            os << endl;}};

    if (!i_ekrana) {
        auto isvesti_i_faila = [&](const string& pav, const list<Studentas>& studentai) {
            ofstream fo(pav);
            if (!fo.is_open()) {
                cout << "Klaida: Nepavyko atidaryti failo " << pav << endl;
                return;}
            spausdinti_antraste(fo);
            spausdinti_studentus(fo, studentai);
            fo.close();};
        isvesti_i_faila("vargsiukai.txt", v);
        isvesti_i_faila("galvociai.txt", g);
        cout << "Duomenys surikiuoti ir irasyti i vargsiukai.txt ir galvociai.txt failus." << endl;}
    else {
        cout << "\n--- GALVOCIAI ---" << endl;
        spausdinti_antraste(cout);
        spausdinti_studentus(cout, g);
        cout << "\n--- VARGSIUKAI ---" << endl;
        spausdinti_antraste(cout);
        spausdinti_studentus(cout, v);}

    cout << "Is viso: " << vargsiukai.size() << " vargsiuku ir " << galvociai.size() << " galvociu." << endl;}


void testavimas(){
    string failai[]={"mano100000.txt", "mano1000000.txt"};
    int pal=5;
    int balas=0;
    cout<<"Pasirinkite kaip skaiciuoti galutini bala:"<<endl;
    cout<<"1 - vidurkis"<<endl;
    cout<<"2 - mediana"<<endl;
    cout<<"3 - abu"<<endl;
    cout<<"Jusu pasirinkimas: ";
    cin>>balas;

    cout<<"Testavimo pradzia. Naudojamas konteineris: List, Strategija: 2."<<endl;
    for (const string& failas : failai){
        double lskaitymas=0.0, lskirstymas=0.0;
        for (int p=0; p<pal; p++) {
            auto start=std::chrono::high_resolution_clock::now();
            list<Studentas> grupe=nuskaitymas(failas, true);
            auto end=std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff=end-start;
            lskaitymas += diff.count();

            start=std::chrono::high_resolution_clock::now();
            list<Studentas> vargsiukai, galvociai;
            strategija2_list(grupe, vargsiukai, balas);
            end=std::chrono::high_resolution_clock::now();
            diff=end-start;
            lskirstymas += diff.count();}

        cout<<"Failas: "<<failas<<endl;
        cout<<"Listas: skaitymo vidurkis: "<<std::fixed<<std::setprecision(5)<<(lskaitymas/pal)<<" s, dalijimo vidurkis: "<<(lskirstymas/pal)<<" s"<<endl;}
        cout<<"Testavimo pabaiga."<<endl;}

