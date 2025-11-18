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

void strategija2_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, int pasirinkti){
    for(auto it = grupe.begin(); it != grupe.end(); ){
            double bal = (pasirinkti == 2 ? it->med : it->gal);
            if(bal<5.0){
                vargsiukai.push_back(*it);
                it = grupe.erase(it);
            } else ++it;}}

void isvedimas(const list<Studentas>& vargsiukai, const list<Studentas>& galvociai, int rik, int balas) {
    list<Studentas> v=vargsiukai;
    list<Studentas> g=galvociai;
    
    bool (*lyg)(const Studentas&, const Studentas&);
    if (rik==1) {
        lyg=compare;}
    else if (rik==2) {
        lyg=comparePagalPavarde;}
    else if(rik==3){
        if (balas==1){
            lyg=comparePagalVid;}
        else{
            lyg = comparePagalMed;
        }}

    v.sort(lyg);
    g.sort(lyg);
        string balas_pav = (balas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";
        auto isvesti_i_faila = [&](const string& pav, const list<Studentas>& studentai) {
            ofstream fo(pav);
            fo<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";
            if (balas == 3) {
                fo<<setw(15)<<left<<"Galutinis (Med.)"<<setw(15)<<left<<"Galutinis (Vid.)"<<endl;
                fo<<string(65, '-')<<endl;}
            else {
                fo<<setw(15)<<left<<balas_pav<<endl;
                fo<<string(50, '-')<<endl;}
            for(const auto& st : studentai) {
                fo<<setw(15)<<left<<st.vardas()<<setw(20)<<left<<st.pavarde();
                if (balas == 3) {
                    fo<<setw(15)<<left<<fixed<<setprecision(2)<<st.med;
                    fo<<setw(15)<<left<<fixed<<setprecision(2)<<st.gal<<endl;}
                else {
                    double final_bal = (balas == 1) ? st.gal : st.med;
                    fo<<setw(15)<<left<<fixed<<setprecision(2)<<final_bal<<endl;}}
            fo.close();};
        isvesti_i_faila("vargsiukai.txt", v);
        isvesti_i_faila("galvociai.txt", g);
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
            strategija2_list(grupe, vargsiukai, balas);
            end=std::chrono::high_resolution_clock::now();
            diff=end-start;
            lskirstymas += diff.count();}

        cout<<"Failas: "<<failas<<endl;
        cout<<"Listas: skaitymo vidurkis: "<<fixed<<setprecision(5)<<(lskaitymas/pal)<<" s, dalijimo vidurkis: "<<(lskirstymas/pal)<<" s"<<endl;}
    cout<<"Testavimo pabaiga."<<endl;}

