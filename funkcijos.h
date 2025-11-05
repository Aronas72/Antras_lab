#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <random>
#include <chrono>
#include <iomanip>

using std::mt19937;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::left;
using std::right;

list<Studentas> nuskaitymas(const string& failpav);
void isvedimas(const list<Studentas>& vargsiukai, const list<Studentas>& galvociai);
void strategija3_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai);
void testavimas();

#endif
