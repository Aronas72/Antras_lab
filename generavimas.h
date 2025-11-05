#ifndef GENERAVIMAS_H
#define GENERAVIMAS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::ifstream;
using std::ofstream;
using std::to_string;

void generavimas(const string & failpav, size_t kiekis, mt19937 & gener);

#endif
