#include "studentas.h"

double vidurkis(const vector<double>& v) {
    if (v.empty()) return 0.0;
    double sum = 0.0;
    for (double pazymys : v) sum += pazymys;
    return sum / v.size();}

double mediana(const vector<double>& v) {
    if (v.empty()) return 0.0;
    vector<double> temp = v;
    std::sort(temp.begin(), temp.end());
    size_t x = temp.size();
    if (x % 2 == 0) return (temp[x / 2 - 1] + temp[x / 2]) / 2.0;
    else return temp[x / 2];}

Studentas::Studentas(istream& is) {
    readStudent(is);}

double Studentas::galBalas(double (*nd_skaic)(const vector<double>&)) const {
    return nd_skaic(nd_)*0.4+egzaminas_*0.6;}

istream& Studentas::readStudent(istream& is) {
    string eilute;
    if (std::getline(is, eilute)) {
        std::istringstream iss(eilute);
        if (!(iss>>vardas_>>pavarde_)) return is;
        
        nd_.clear();
        vector<double> pazymiai;
        double k;
        while (iss>>k){
            pazymiai.push_back(k);}
        
        if (pazymiai.empty()){
            egzaminas_=0.0;}
        else{
            egzaminas_=pazymiai.back();
            pazymiai.pop_back();
            nd_=pazymiai;}
        double nd_vid = vidurkis(nd_);
        double nd_med = mediana(nd_);
        med = nd_med*0.4+egzaminas_*0.6;
        gal = nd_vid*0.4+egzaminas_*0.6;}
    return is;}

bool compare(const Studentas& a, const Studentas& b) {
    return a.vardas()<b.vardas();}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde()<b.pavarde();}

bool comparePagalMed(const Studentas& a, const Studentas& b) {
    return a.med < b.med;}

bool comparePagalVid(const Studentas& a, const Studentas& b) {
    return a.gal < b.gal;}
