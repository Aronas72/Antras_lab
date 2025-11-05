#include "generavimas.h"

void generavimas(const string & failpav, size_t kiekis, mt19937 & gener){
    uniform_int_distribution<int> pazym(1, 10);
    uniform_int_distribution<int> nd_kiekis(1, 10);
    ofstream fr(failpav);
    if(!fr.is_open()){
        cout<<"Nepavyko sukurti failo: "<<failpav<<endl;
        return;}
    
    int ndkiek = nd_kiekis(gener);

    fr<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";
    for(int i=1;i<=ndkiek; i++){
        fr<<setw(7)<<right<<("ND"+to_string(i));}
    fr<<setw(10)<<right<<"Egzaminas"<<endl;

    for(size_t i=1; i<=kiekis; i++){
        fr<<setw(15)<<left<<("Vardas"+to_string(i))<<setw(20)<<left<<("Pavarde"+to_string(i));
        for(int j=1; j<=ndkiek; j++){
            fr<<setw(7)<<right<<pazym(gener);}
        fr<<setw(10)<<right<<pazym(gener)<<endl;}
    fr.close();
    cout<<"Sugeneruotas failas: "<<failpav<<". "<<kiekis<<" irasu, "<<ndkiek<<" ND irasu."<<endl;}
