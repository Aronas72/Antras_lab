/**
 * @file studentas.h
 * @brief Studentų klasės ir funkcijos galutinių balų skaičiavimui.
 *
 * Šiame faile yra aprašyta abstrakti Zmogus klasė bei ją paveldinti Studentas klasė.
 * Taip pat pateiktos pagalbinės funkcijos mediana, vidurkis ir palyginimo funkcijos rikiavimui.
 */

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

/**
 * @brief Apskaičiuoja mediana iš sveikųjų skaičių vektoriaus.
 * @param v Vektorius su skaičiais.
 * @return Medianą.
 */
double mediana(const vector<int>& v);

/**
 * @brief Apskaičiuoja vidurkį iš sveikųjų skaičių vektoriaus.
 * @param v Vektorius su skaičiais.
 * @return Vidurkį.
 */
double vidurkis(const vector<int>& v);

/**
 * @class Zmogus
 * @brief Abstrakti klasė, apibūdinanti žmogų.
 *
 * Saugo vardą ir pavardę. Reikalauja paveldėtojams realizuoti galutinio balo skaičiavimo funkciją.
 */
class Zmogus {
protected:
    string vardas_;  ///< Vardas
    string pavarde_; ///< Pavardė
public:
    Zmogus() = default;
    Zmogus(const string& v, const string& p) : vardas_(v), pavarde_(p) {}
    virtual ~Zmogus() = default;

    /**
     * @brief Apskaičiuoja galutinį balą.
     * @param nd_skaic Funkcija ND skaičiavimui (pagal nutylėjimą mediana)
     * @return Galutinis balas.
     */
    virtual double galBalas(double (*nd_skaic)(const vector<int>&) = mediana) const = 0;

    inline string vardas() const { return vardas_; }   ///< Grąžina vardą
    inline string pavarde() const { return pavarde_; } ///< Grąžina pavardę

    friend istream& operator>>(istream& is, Zmogus& z) = delete;
    friend ostream& operator<<(ostream& os, const Zmogus& z) = delete;
};

/**
 * @class Studentas
 * @brief Studento klasė, paveldinti Zmogus.
 *
 * Saugo egzaminų ir namų darbų rezultatus, taip pat galutinius balus.
 */
class Studentas : public Zmogus {
private:
    int egzaminas_;       ///< Egzamino rezultatas
    vector<int> nd_;      ///< Namų darbų rezultatai

public:
    double med;           ///< Galutinis balas pagal medianą
    double gal;           ///< Galutinis balas pagal vidurkį

    void setNd(const std::vector<int>& nd) { nd_ = nd; }
    void setEgzaminas(int egz) { egzaminas_ = egz; }
    Studentas() : egzaminas_(0), med(0.0), gal(0.0) {}
    ~Studentas() {
        vardas_.clear();
        pavarde_.clear();
        egzaminas_ = 0;
        nd_.clear();
    }

    Studentas(const Studentas& other);                     ///< Kopijavimo konstruktorius
    Studentas& operator=(const Studentas& other);          ///< Kopijavimo priskyrimo operatorius

    inline int egzaminas() const { return egzaminas_; }   ///< Grąžina egzamino balą
    inline const vector<int>& nd() const { return nd_; }  ///< Grąžina ND balus

    /**
     * @brief Apskaičiuoja galutinį balą.
     * @param nd_skaic Funkcija ND skaičiavimui
     * @return Galutinis balas.
     */
    double galBalas(double (*nd_skaic)(const vector<int>&))const override;

    friend istream& operator>>(istream& is, Studentas& s); ///< Skaitymo operatorius
    friend ostream& operator<<(ostream& os, const Studentas& s); ///< Rašymo operatorius
};

// Funkcijos rikiavimui
bool compare(const Studentas& a, const Studentas& b);                  ///< Rikiuoja pagal vardą
bool comparePagalPavarde(const Studentas& a, const Studentas& b);      ///< Rikiuoja pagal pavardę
bool comparePagalMed(const Studentas& a, const Studentas& b);          ///< Rikiuoja pagal med
bool comparePagalVid(const Studentas& a, const Studentas& b);          ///< Rikiuoja pagal gal (vidurkį)

#endif
