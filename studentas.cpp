#include "studentas.h"

double vidurkis(const vector<double>& v) {
    if (v.empty()) return 0.0;
    double sum = 0.0;
    for (double pazymys : v) sum += pazymys;
    return sum / v.size();}

double mediana(const vector<double>& v) {
    if (v.empty()) return 0.0;
    vector<double> temp = v;
    sort(temp.begin(), temp.end());
    size_t x = temp.size();
    if (x % 2 == 0) return (temp[x / 2 - 1] + temp[x / 2]) / 2.0;
    else return temp[x / 2];}

Studentas::Studentas(istream& is) {
    is >> *this;}

double Studentas::galBalas(double (*nd_skaic)(const vector<double>&)) const {
    return nd_skaic(nd_)*0.4+egzaminas_*0.6;}

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

istream& Studentas::readStudent(istream& is) {
    if (&is == &std::cin) {
        
        cout << "Iveskite varda: ";
        if (!(is >> vardas_)) return is;
        
        cout << "Iveskite pavarde: ";
        if (!(is >> pavarde_)) return is;
        
        cout << "Iveskite namu darbu pazymius (1-10, pabaigai ivesti ne skaitmeni (pvz., 'q')): " << endl;
        nd_.clear();
        double k;
        
        while (cout << "ND pazymys: " && (is >> k) && k >= 1 && k <= 10) {
            nd_.push_back(k);}
        
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Iveskite egzamino bala (1-10): ";
        double egz_balas = 0.0;
        if (!(is >> egz_balas) || egz_balas < 1 || egz_balas > 10) {
             cout << "Neteisinga egzamino balu ivestis. Nustatoma 0 ir baigiama ivestis." << endl;
             egzaminas_ = 0.0;
             is.clear();
             is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             is.setstate(ios_base::failbit);
             return is;}
        egzaminas_ = egz_balas;}
        else {
        
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
                nd_=pazymiai;}}
            else {
            is.setstate(ios_base::failbit);
            return is;}}
    
    double nd_vid = vidurkis(nd_);
    double nd_med = mediana(nd_);
    med = nd_med*0.4+egzaminas_*0.6;
    gal = nd_vid*0.4+egzaminas_*0.6;
    
    return is;}

istream& operator>>(istream& is, Studentas& studentas) {
    return studentas.readStudent(is);}

ostream& operator<<(ostream& os, const Studentas& studentas) {
    os << setw(15) << left << studentas.vardas()<< setw(20) << left << studentas.pavarde();
    for (double nd : studentas.nd()) {
    os << setw(5) << right << (int)nd;}
    if (studentas.nd().size() < 5) {
        os << std::string((5 - studentas.nd().size()) * 5, ' ');}
    
    os << setw(8) << right << (int)studentas.egzaminas();
    os << setw(18) << right << fixed << setprecision(2) << studentas.med<< setw(18) << right << fixed << setprecision(2) << studentas.gal << endl;
    return os;}


bool compare(const Studentas& a, const Studentas& b) {
    return a.vardas()<b.vardas();}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde()<b.pavarde();}

bool comparePagalMed(const Studentas& a, const Studentas& b) {
    return a.med < b.med;}

bool comparePagalVid(const Studentas& a, const Studentas& b) {
    return a.gal < b.gal;}
