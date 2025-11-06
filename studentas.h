#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>

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

double mediana(const vector<double>& v);
double vidurkis(const vector<double>& v);

class Studentas {
private:
    string vardas_;
    string pavarde_;
    double egzaminas_;
    vector<double> nd_;

public:
    Studentas() : egzaminas_(0) {}
    Studentas(istream& is);
    ~Studentas() {}

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline double egzaminas() const { return egzaminas_; }
    inline const vector<double>& nd() const { return nd_; }

    double galBalas(double (*nd_skaic)(const vector<double>&) = mediana) const;

    istream& readStudent(istream& is);
};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas& a, const Studentas& b);

#endif
