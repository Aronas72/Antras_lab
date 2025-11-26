#include "studentas.h"
#include <random>
#include <cmath>
#include <iostream>

double vidurkis(const vector<int>& v) {
    if (v.empty()) return 0.0;
    double sum = 0.0;
    for (int p : v) sum += p;
    return sum / v.size();}

double mediana(const vector<int>& v) {
    if (v.empty()) return 0.0;
    vector<int> temp = v;
    std::sort(temp.begin(), temp.end());
    size_t n = temp.size();
    return (n % 2 == 0) ? (temp[n/2-1]+temp[n/2])/2.0 : temp[n/2];}

Studentas::Studentas(const Studentas& other) :
    vardas_(other.vardas_),
    pavarde_(other.pavarde_),
    egzaminas_(other.egzaminas_),
    nd_(other.nd_),
    med(other.med),
    gal(other.gal) {}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        egzaminas_ = other.egzaminas_;
        nd_ = other.nd_;
        med = other.med;
        gal = other.gal;}
    
    return *this;}

double Studentas::galBalas(double (*nd_skaic)(const vector<int>&)) const {
    return nd_skaic(nd_)*0.4 + egzaminas_*0.6;}


istream& operator>>(istream& is, Studentas& s) {
    s.nd_.clear();

    if (&is == &std::cin) {
        std::cout << "Iveskite varda: ";
        if (!(is >> s.vardas_)) return is;

        std::cout << "Iveskite pavarde: ";
        if (!(is >> s.pavarde_)) return is;

        std::cout << "Ar generuoti atsitiktinius ND ir egzamino balus? (1-taip,0-ne): ";
        int ats = 0;
        if (!(is >> ats)) ats = 0;

        if (ats == 1) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(1,10);

            int nd_kiek = 5;
            std::cout << "Kiek ND sugeneruoti? ";
            if (!(is >> nd_kiek) || nd_kiek <= 0) nd_kiek = 5;

            for(int i=0;i<nd_kiek;i++) s.nd_.push_back(dist(gen));
            s.egzaminas_ = dist(gen);

            std::cout << "Sugeneruoti ND: ";
            for(auto d : s.nd_) std::cout << d << " ";
            std::cout << "Egzaminas: " << s.egzaminas_ << std::endl;}
        else {
            std::cout << "Iveskite ND (1-10, pabaigai - ne skaiciu):" << std::endl;
            int paz;
            while(std::cout<<"ND: " && (is>>paz) && paz>=1 && paz<=10) s.nd_.push_back(paz);

            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            std::cout<<"Egzaminas (1-10): ";
            if(!(is>>s.egzaminas_) || s.egzaminas_<1 || s.egzaminas_>10){
                s.egzaminas_=0;
                is.setstate(std::ios_base::failbit);
                return is;}}}
    else{
        string eil;
        if(!std::getline(is,eil)){ is.setstate(std::ios_base::failbit); return is; }
        std::istringstream iss(eil);

        if(!(iss>>s.vardas_>>s.pavarde_)){ is.setstate(std::ios_base::failbit); return is; }

        vector<int> paz;
        int x;
        while(iss>>x) paz.push_back(x);

        if(!paz.empty()){ s.egzaminas_=paz.back(); paz.pop_back(); } else s.egzaminas_=0;

        s.nd_ = std::move(paz);}

    double nd_vid = vidurkis(s.nd_);
    double nd_med = mediana(s.nd_);
    s.med = nd_med*0.4 + s.egzaminas_*0.6;
    s.gal = nd_vid*0.4 + s.egzaminas_*0.6;

    return is;}

ostream& operator<<(ostream& os, const Studentas& s) {
    os << std::setw(15) << std::left << s.vardas_ << std::setw(20) << std::left << s.pavarde_ << std::setw(18) << std::right << std::fixed << std::setprecision(2) << s.med << std::setw(18) << std::right << std::fixed << std::setprecision(2) << s.gal << std::endl;
    return os;}

bool compare(const Studentas& a, const Studentas& b){ return a.vardas() < b.vardas();}
bool comparePagalPavarde(const Studentas& a, const Studentas& b){ return a.pavarde() < b.pavarde();}
bool comparePagalMed(const Studentas& a, const Studentas& b){ return a.med < b.med;}
bool comparePagalVid(const Studentas& a, const Studentas& b){ return a.gal < b.gal;}
