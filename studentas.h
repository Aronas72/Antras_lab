#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <limits>
#include <random>

using std::string;
using std::vector;
using std::list;
using std::istream;
using std::ostream;

double mediana(const vector<int>& v);
double vidurkis(const vector<int>& v);

class Studentas {
private:
    string vardas_;
    string pavarde_;
    int egzaminas_;
    vector<int> nd_;

public:
    double med;
    double gal;

    Studentas() : egzaminas_(0), med(0.0), gal(0.0) {}
    ~Studentas() {
        vardas_.clear();
        pavarde_.clear();
        egzaminas_ = 0;
        nd_.clear();}
    
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline int egzaminas() const { return egzaminas_; }
    inline const vector<int>& nd() const { return nd_; }

    double galBalas(double (*nd_skaic)(const vector<int>&) = mediana) const;

    friend istream& operator>>(istream& is, Studentas& s);
    friend ostream& operator<<(ostream& os, const Studentas& s);
};

ostream& operator<<(ostream& os, const Studentas& s);
istream& operator>>(istream& is, Studentas& s);

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalMed(const Studentas& a, const Studentas& b);
bool comparePagalVid(const Studentas& a, const Studentas& b);

#endif
