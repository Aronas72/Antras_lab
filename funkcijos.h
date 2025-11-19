#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>

using std::mt19937;
using std::string;
using std::ifstream;
using std::ofstream;

list<Studentas> nuskaitymas(const string& saltinis, bool is_failo);
void isvedimas(const list<Studentas>& vargsiukai, const list<Studentas>& galvociai, int rik, int balas, bool i_ekrana);
void strategija2_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, int pasirinkti);
void testavimas();

#endif
