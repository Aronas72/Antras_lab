#include "funkcijos.h"
#include "generavimas.h"
#include <chrono>
#include <limits>
#include <sstream>
#include <utility>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::random_device;
using std::mt19937;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::list;

list<Studentas> rankinisNuskaitymas(int kiekis) {
    list<Studentas> grupe;
    Studentas st;
    int i = 0;
    cout << "--- Rankinis ivedimas: Ivesite " << kiekis << " studentu. ---" << endl;
    while (i < kiekis) {
        cout << "Ivedamas " << i + 1 << "-as studentas is " << kiekis << ": " << endl;
        if (cin >> st) {
            grupe.push_back(std::move(st));
            st = Studentas();
            i++;}
        else {
            cout << "\nNeteisinga ivestis. Rankinis ivedimas nutrauktas." << endl;
            break;}}
    return grupe;}

void rule_of_three_testas() {
    cout << "--- RULE OF THREE TESTAS ---"<<endl;
    Studentas st_orig;
    cout << "Iveskite pirmojo studento duomenis (pvz. Jonas Petraitis 5 6 7 8 9 10): "<<endl;
    cin >> st_orig;
    
    cout<<endl<<"Kopijavimo konstruktoriaus testas:"<<endl;
    Studentas st_copy = st_orig;
    cout << "st_copy vardas: " << st_copy.vardas() << ", pavarde: " << st_copy.pavarde() << endl;
    
    cout <<endl<< "Kopijavimo priskyrimo operatoriaus testas:"<<endl;
    Studentas st_assign;
    cout << "Iveskite antrojo studento duomenis (pvz. Ona Kazlauskaite 1 2 3 4 5 6): "<<endl;
    cin >> st_assign;
    
    st_assign = st_orig;
    cout << "st_assign naujas vardas: " << st_assign.vardas() << ", pavarde: " << st_assign.pavarde() << endl;
    
    cout <<endl<<"--- TESTO PABAIGA. Destruktoriai bus iškviesti dabar ---"<<endl;}

int main() {
    random_device rd;
    mt19937 gener(rd());

    cout << "Pasirinkite veiksma:" << endl;
    cout << "1 - ivesti studentus (list, strategija 2)." << endl;
    cout << "2 - sugeneruoti failus." << endl;
    cout << "3 - atlikti testavima su 100000 ir 1000000 dydzio failais." << endl;
    cout << "4 - RULE OF THREE demonstracija." << endl;
    cout << "Pasirinkimas: ";

    int pasirinkimas = 0;
    cin >> pasirinkimas;

    if (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Neteisinga ivestis. Programa baigia darba." << endl;
        return 1;}

    if (pasirinkimas == 2){
        generavimas("mano1000.txt", 1000, gener);
        generavimas("mano10000.txt", 10000, gener);
        generavimas("mano100000.txt", 100000, gener);
        generavimas("mano1000000.txt", 1000000, gener);
        generavimas("mano10000000.txt", 10000000, gener);}
    else if (pasirinkimas == 3){
        testavimas();
        return 0;}
    else if (pasirinkimas == 4) {
        rule_of_three_testas();
        return 0;}
    else if (pasirinkimas == 1){
        list<Studentas> grupe;
        auto start = high_resolution_clock::now();

        cout << "Pasirinkite kaip ivesti duomenis:" << endl;
        cout << "1 - failas" << endl;
        cout << "2 - ranka" << endl;
        cout << "Pasirinkimas: ";
        int duom = 0;
        cin >> duom;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (duom == 1) {
            string failpav;
            cout << "Iveskite failo pavadinima: ";
            std::getline(cin, failpav);
            grupe = nuskaitymas(failpav, true);}
        else if (duom == 2) {
            int kiekis;
            cout << "Kiek studentu noresite vesti rankiniu budu? Kiekis: ";
            if (!(cin >> kiekis) || kiekis <= 0) {
                cout << "Neteisingas studentu skaicius. Programa baigia darba." << endl;
                return 1;}
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            grupe = rankinisNuskaitymas(kiekis);}
        else {
            cout << "Neteisingas ivesties saltinio pasirinkimas. Programa baigia darba." << endl;
            return 1;}

        auto end = high_resolution_clock::now();
        cout << "Nuskaitymas uztruko: " << duration<double>(end - start).count() << " s" << endl;

        if (grupe.empty()) {
            cout << "Nepavyko nuskaityti studentu. Programa baigia darba." << endl;
            return 0;}

        list<Studentas> vargsiukai;
        int gbalas = 0;
        cout << "Pasirinkite kaip skirstyti studentus:" << endl;
        cout << "1 - vidurkis" << endl;
        cout << "2 - mediana" << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> gbalas;

        start = high_resolution_clock::now();
        strategija2_list(grupe, vargsiukai, gbalas);
        end = high_resolution_clock::now();
        cout << "Skirstymas uztruko: " << duration<double>(end - start).count() << " s" << endl;

        int rik = 0;
        cout << "Pasirinkite pagal ka rikiuoti:" << endl;
        cout << "1 - vardas" << endl;
        cout << "2 - pavarde" << endl;
        cout << "3 - balas" << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> rik;

        int balas = 0;
        cout << "Pasirinkite, kuriuos parametrus rodyti (pagal juos buvo suskaiciuotas ir galutinis balas):" << endl;
        cout << "1 - vidurkis" << endl;
        cout << "2 - mediana" << endl;
        cout << "3 - abu" << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> balas;

        int isved;
        cout << "Kur norite isvesti rezultatus?" << endl;
        cout << "1 - I faila (vargsiukai.txt ir galvociai.txt)" << endl;
        cout << "2 - I ekrana (konsole)" << endl;
        cout << "Pasirinkimas: ";
        cin >> isved;

        start = high_resolution_clock::now();
        if (isved == 2) {
            isvedimas(vargsiukai, grupe, rik, balas, true);}
        else {
            isvedimas(vargsiukai, grupe, rik, balas, false);}
        end = high_resolution_clock::now();
        cout << "Isvedimas uztruko: " << duration<double>(end - start).count() << " s" << endl;

        if (isved != 2) {
            cout << "Rezultatai irasyti i failus." << endl;}}
    return 0;}
