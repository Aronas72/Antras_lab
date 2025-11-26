#include "funkcijos.h"
#include <sstream>
#include <iostream>
#include <limits>
#include <algorithm>

list<Studentas> nuskaitymas(const string& saltinis, bool is_failo) {
    list<Studentas> grupe;
    if (is_failo){
        ifstream fd(saltinis);
        if (!fd.is_open()){
            std::cout << "Nepavyko atidaryti failo: " << saltinis << std::endl;
            return grupe;}
        
        string antraste;
        std::getline(fd, antraste);
        Studentas st;
        while (fd >> st) { grupe.push_back(std::move(st)); st = Studentas(); }}
    else{
        Studentas st;
        while (std::cin >> st) { grupe.push_back(std::move(st)); st = Studentas();}}
    return grupe;}

void strategija2_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, int pasirinkti){
    for(auto it = grupe.begin(); it != grupe.end(); ){
        double bal = (pasirinkti == 2 ? it->med : it->gal);
        if(bal<5.0){ vargsiukai.push_back(*it); it = grupe.erase(it); } else ++it;}}

void isvedimas(const list<Studentas>& vargsiukai, const list<Studentas>& galvociai, int rik, int balas, bool i_ekrana) {
    list<Studentas> v = vargsiukai;
    list<Studentas> g = galvociai;

    bool (*lyg)(const Studentas&, const Studentas&);
    if (rik == 1) lyg = compare;
    else if (rik == 2) lyg = comparePagalPavarde;
    else { if(balas==1) lyg = comparePagalVid; else lyg=comparePagalMed; }

    v.sort(lyg);
    g.sort(lyg);

    auto spausdinti_antraste = [&](std::ostream& os){
        os << std::setw(15) << std::left << "Vardas" << std::setw(20) << std::left << "Pavarde";
        if(balas==1) os << std::setw(18) << std::right << "Galutinis (Vid.)";
        else if(balas==2) os << std::setw(18) << std::right << "Galutinis (Med.)";
        else os << std::setw(18) << std::right << "Galutinis (Med.)" << std::setw(18) << std::right << "Galutinis (Vid.)";
        os << std::endl << std::string(53 + (balas==3 ? 18:0),'-') << std::endl;};

    auto spausdinti_studentus = [&](std::ostream& os, const list<Studentas>& l){
        for(const auto& st: l){
            os << std::setw(15) << std::left << st.vardas() << std::setw(20) << std::left << st.pavarde();
            if(balas==1) os << std::setw(18) << std::right << std::fixed << std::setprecision(2) << st.gal;
            else if(balas==2) os << std::setw(18) << std::right << std::fixed << std::setprecision(2) << st.med;
            else {
                os << std::setw(18) << std::right << std::fixed << std::setprecision(2) << st.med
                   << std::setw(18) << std::right << std::fixed << std::setprecision(2) << st.gal;}
            os << std::endl;}};

    if(!i_ekrana){
        auto isvesti_i_faila = [&](const string& pav, const list<Studentas>& studentai){
            ofstream fo(pav);
            if(!fo.is_open()){ std::cout << "Klaida: Nepavyko atidaryti failo " << pav << std::endl; return; }
            spausdinti_antraste(fo);
            spausdinti_studentus(fo, studentai);
            fo.close();};
        isvesti_i_faila("vargsiukai.txt", v);
        isvesti_i_faila("galvociai.txt", g);
        std::cout << "Duomenys surikiuoti ir irasyti i vargsiukai.txt ir galvociai.txt failus." << std::endl;}
    else {
        std::cout << "\n--- GALVOCIAI ---" << std::endl;
        spausdinti_antraste(std::cout);
        spausdinti_studentus(std::cout, g);
        std::cout << "\n--- VARGSIUKAI ---" << std::endl;
        spausdinti_antraste(std::cout);
        spausdinti_studentus(std::cout, v);}

    std::cout << "Is viso: " << vargsiukai.size() << " vargsiuku ir " << galvociai.size() << " galvociu." << std::endl;}

void testavimas(){
    string failai[] = {"mano100000.txt","mano1000000.txt"};
    int pal = 5;
    int balas=0;
    std::cout << "Pasirinkite kaip skaiciuoti galutini bala:\n1 - vidurkis\n2 - mediana\n3 - abu\nJusu pasirinkimas: ";
    std::cin >> balas;
    std::cout << "Testavimo pradzia. Naudojamas konteineris: List, Strategija: 2." << std::endl;
    for(const string& failas : failai){
        double lskaitymas=0.0, lskirstymas=0.0;
        for(int p=0;p<pal;p++){
            auto start = std::chrono::high_resolution_clock::now();
            list<Studentas> grupe = nuskaitymas(failas,true);
            auto end = std::chrono::high_resolution_clock::now();
            lskaitymas += std::chrono::duration<double>(end-start).count();

            start = std::chrono::high_resolution_clock::now();
            list<Studentas> vargsiukai, galvociai;
            strategija2_list(grupe, vargsiukai, balas);
            end = std::chrono::high_resolution_clock::now();
            lskirstymas += std::chrono::duration<double>(end-start).count();}
        std::cout << "Failas: " << failas << std::endl;
        std::cout << "Listas: skaitymo vidurkis: " << std::fixed << std::setprecision(5)
                  << (lskaitymas/pal) << " s, dalijimo vidurkis: " << (lskirstymas/pal) << " s" << std::endl;}
    std::cout << "Testavimo pabaiga." << std::endl;}


