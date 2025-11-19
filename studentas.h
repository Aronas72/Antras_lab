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
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;
using std::right;
using std::sort;
using std::ios_base;

double mediana(const vector<int>& v);
double vidurkis(const vector<int>& v);

class Studentas {
private:
    string vardas_;
    string pavarde_;
    int egzaminas_;           // Pakeista į int
    vector<int> nd_;          // Pakeista į int

public:
    double med;
    double gal;

    Studentas() : egzaminas_(0), med(0.0), gal(0.0) {}
    Studentas(istream& is);

    ~Studentas() {
        vardas_.clear();
        pavarde_.clear();
        egzaminas_=0;
        nd_.clear();
    }

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline int egzaminas() const { return egzaminas_; }
    inline const vector<int>& nd() const { return nd_; }

    double galBalas(double (*nd_skaic)(const vector<int>&) = mediana) const;

    istream& readStudent(istream& is);

    friend istream& operator>>(istream& is, Studentas& studentas);
    friend ostream& operator<<(ostream& os, const Studentas& studentas);
};

ostream& operator<<(ostream& os, const Studentas& studentas);
istream& operator>>(istream& is, Studentas& studentas);

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalMed(const Studentas& a, const Studentas& b);
bool comparePagalVid(const Studentas& a, const Studentas& b);

#endif
