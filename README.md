# Pirmas laboratorinis darbas
## Versija v0.1
Sukurta pirma versija v0.1, kurioje:

- Sukurta struktūra Studentas, kurioje kaupiami duomenys apie studentą: vardas, pavardė, pažymiai, vidurkis, mediana.
- Iš pradžių išvedamas tik vidurkis, vėliau prijungtas ir skaičiavimas pagal medianą.
- Galimas ir nežinomas namų darbų kiekis, todėl galima ir nežinant tikslaus skaičiaus namų darbų, įvesti jų pažymius.
- Pasirinkimas, kad rodytų galutinį balą pagal vidurkį arba tik pagal medianą arba rodytų abu.
- Pažymių atsitiktinis generavimas.
- Duomenų nuskaitymas iš failo ir išvedimas į rezultatų tekstinį failą.
- Rikiavimo funkcija, kuri surikiuoja studentus pagal vardą arba pavardę.
- Parašius kodą buvo keblumų dėl tam tikrų detalių, kaip o kas jeigu vietoj pažymio būtų įvedama raidė. Tuo atveju programa lūžo, bet pastebėjus tai, ši klaida buvo ištaisyta pačiu paskutiniu commit'u.

Kodą rasti: lab->lab->programa.cpp.

## Versija v0.2

Antrojoje versijoje matome ir kelis pasikeitimus nuo v0.1 versijos:
- Sukurta failų generavimo funkcija, kuri sugeneruoja 1000, 10000, 100000, 1000000 ir 10000000 dydžio studentų failus.
- Sukurtas studentų išskaidymas į dvi grupes: vargšiukus (galutinis balas mažesnis nei 5) ir galvočius (galutinis balas nemažesnis nei 5).
- Įvykdytas kodo reorganizavimas.
- Dabar galima atlikti rikiavimą ir pagal galutinį balą.
- Atlikta programos spartos analizė.

Generavimo vidurkiai:
- 1000 įrašų failas sukuriamas per vidutiniškai 0.013 s.
- 10000 įrašų failas sukuriamas per vidutiniškai 0.023 s.
- 100000 įrašų failas sukuriamas per vidutiniškai 0.22 s.
- 1000000 įrašų failas sukuriamas per vidutiniškai 2.8 s.
- 10000000 įrašų failas sukuriamas per vidutiniškai 28.44 s.

## Versija v0.3

v0.3 versijoje taip pat atlikti keli pakeitimai:
- Pridėtas pasirinkimas kokiame konteineryje norima talpinti studento duomenis (Vector arba List).
- Rankiniu būdu įvedus duomenis galima pamatyti objekto saugojimo atmintyje adresą.
- Atlikta spartos analizė su Vector ir List konteineriais.

Analizė: buvo matuojami 3 parametrai: nuskaitymas iš failo ir talpinimas pasirinktame konteineryje, rūšiavimas į dvi grupes (vargšiukai ir galvočiai), duomenų įrašymas į failą. Analizė atlikta su iš anksto sugeneruotais failais. Visi testai buvo atlikti 5 kartus ir gauti rezultatai surašyti į lenteles.

Rezultatai:

Surūšiavimas į dvi grupes:
|Įrašų skaičius|   Vector (s.)    |   List (s.)  |
|--------------|-----------------:|-------------:|
|1 000         |      0.0003      |     0.0002   |
|10 000        |      0.0026      |     0.0024   |
|100 000       |      0.0243      |     0.0232   |
|1 000 000     |      0.2776      |     0.2757   |
|10 000 000    |      2.9258      |     3.0777   |

Failų skaitymas:
|Įrašų skaičius|   Vector (s.)    |   List (s.)   |
|--------------|-----------------:|--------------:|
|1 000         |      0.0075      |     0.0052    |
|10 000        |      0.0386      |     0.0357    |
|100 000       |      0.3294      |     0.3273    |
|1 000 000     |      4.6707      |     4.6867    |
|10 000 000    |     36.3395      |    37.7434    |

Duomenų įrašymas į failą:
|Įrašų skaičius|   Vector (s.)    |   List (s.)   |
|--------------|-----------------:|--------------:|
|1 000         |      0.0019      |     0.0019    |
|10 000        |      0.0194      |     0.0177    |
|100 000       |      0.1668      |     0.1738    |
|1 000 000     |      1.7955      |     1.8345    |
|10 000 000    |     20.1897      |     21.602    |

IŠVADOS: iš rezultatų matome, kad labai didelių skirtumų tarp konteinerių nėra. Su duomenų kiekiais iki 1000000 įskaitant dirbama labai panašiu tempu, tik galima išskirti 1000000 duomenų įrašymą į failą, kur rezultatas truputį aiškesnis. Nuo 10000000 matome jau Vector konteinerio pranašumą visose testavimo kategorijose, kai skirtumas siekia 1-1.5 sekundės.

Kompiutrio parametrai, su kuriuo buvo atliktas testavimas: 8 GB RAM, SSD 251 GB, procesorius gali būti iki 3.49 GHz.

## Versija v1.0

Išmatuota programos veikimo sparta priklausomai nuo studentų dalijimo į dvi grupes strategijos:
- 1 strategija - anksčiau naudotas būdas, kai bendras studentai konteineris skaidomas ir vargšiukus ir galvočius ir studentas lieka dviejuose konteineriuose: studentai ir vargšiukai arba galvočiai.
- 2 strategija - bendras konteineris studentai skaidomas panaudojant tik vieną naują konteinerį. Tokiu būdu, jeigu studentas yra vargšiukas, jis įkeliamas į vargšiukų konteinerį ir ištrinamas iš studentai konteinerio. Po šio žingsnio studentai konteineryje lieka tik galvočiai.
- 3 strategija - efektyvesnė iš dviejų praeitų strategijų panaudojama taikant "efektyvius" darbo su konteineriais metodus.

Rezultatai (duomenys buvo atlikti 5 kartus kiekvienai strategijai ir matuojama sekundėmis):

**1. Vector konteineris**
|Įrašų skaičius|   1 strategija   |   2 strategija   |   3 strategija   |
|--------------|-----------------:|-----------------:|-----------------:|
|1 000         |      0.0004      |      0.0003      |      0.0004      |
|10 000        |      0.0025      |      0.0033      |      0.0042      |
|100 000       |      0.0239      |      0.0318      |      0.0447      |
|1 000 000     |      0.2557      |      0.3012      |      0.4397      |
|10 000 000    |      2.9507      |      3.0203      |      5.1002      |

**2. List konteineris**
|Įrašų skaičius|   1 strategija   |   2 strategija   |   3 strategija   |
|--------------|-----------------:|-----------------:|-----------------:|
|1 000         |      0.0003      |      0.0002      |      0.0007      |
|10 000        |      0.0023      |      0.0016      |      0.0060      |
|100 000       |      0.0223      |      0.0156      |      0.0605      |
|1 000 000     |      0.2271      |      0.1677      |      0.6668      |
|10 000 000    |      3.0576      |      2.0167      |      6.7021      |

**Išvados:** iš atliktų testavimų galime matyti, kad sąrašo konteineriui pati naudingiausia buvo būtent antra strategija, kuri naudoja tik viena naują konteinerį, tačiau vektoriaus konteineriui greičiausiai suveikė pirma strategija.

# Diegimo instrukcija
1. Įsitikinti, kad kompiuteryje yra įdiegta C++ kompiliatorius, cmake, make ir git, jei ne - reikėtų įsidiegti šiuos dalykus.
2. Atsidaryti savo kompiuteryje terminalą ir įvesti šias eilutes:
  - git clone https://github.com/Aronas72/Pirmas_lab.git
  - cd Pirmas_lab
  - (Jeigu neturite parsisiuntę git, tai ne problema, galite atsisiųsti ZIP failą tiesiai iš GitHub).
3. Sukurkite aplanką, skirtą kompiliavimui:
  - mkdir build
  - cd build
4. Toliau įveskite eilutę cmake ..
5. Kitas žingsnis - kompiliuoti projektą: reikia įvesti eilutę cmake --build
6. Jeigu visi žingsniai buvo atlikti sėkmingai, tai liko tik paleisti programą:
  - Windows: studentai.exe;
  - Linux/macOS: ./studentai

# Paleidimo instrukcija
1. Paleidus programą atsiranda trys galimos pasirinkimo opcijos:
   - Įvesti studentus ranka arba nuskaityti iš failo
   - Sugeneruoti failus pačiam
   - Atlikti testavimą su sugeneruotais failais
Pasirinkus antrą opciją, programa sugeneruoja failus su įrašais nuo 1000 iki 10000000 ir tęsia programą toliau. Pasirinkus trečią opciją galima atlikti testavimą su pasirinktu failu: išmatuoti jo nuskaitymo laiką, dalijimo į dvi grupes ir išvedimo į failą. Turime galimybę įvesti kiek kartų norime testuoti ir kokį failą norime. Kai testavimas atliekamas programa baigia savo darbą.
2. Sugeneravus failus arba pasirinkus pirmą opciją, toliau iššoka pasirinkimas, kuriame konteineryje norime saugoti savo duomenis: Vector arba List.
3. Kai pasirenkame konteinerį, galime pasirinkti, pagal ką skaičiuosime galutinį balą: mediana, vidurkis arba abu.
4. Toliau turime galimybę pasirinkti ir rikiavimą: pagal vardą, pagal pavardę, pagal galutinį balą.
5. Vėliau galime pasirinkti pagal kurią strategiją norime dalinti studentus į vargšiukus ir galvočius. (Visos trys strategijos aprašytos aukščiau ir pateikti testavimo laikai kiekvienai strategijai abiems konteineriams).
6. Toliau turime pasirinkimą ar nuskaityti duomenis iš failo arba galime patys suvesti ranka.
7. Instrukcijos abiems pasirinkimams:
  - Įvedimas ranka: pasirenkame kiek studentų norime įvesti --> įvedame studento vardą ir pavardę --> pasirenkame ar norime automatiškai sugeneruoti duomenis, ar vėl įvesti juos ranka --> studentas pagal formulę **0.4 * (namų darbų vdurkis) + 0.6 * egzaminas** yra priskiriamas vargšiukams, kurių galutinis balas <5, arba galvočiams, jeigu balas >=5.
  - Nuskaitymas iš failo: pasirenkame failą, kurį norime nuskaityti --> parodomas failo nuskaitymo laikas --> parodoma kiek iš viso yra galvočių ir vargšiukų.
8. Atlikę visus šiuos veiksmus ir padarę savo norimus pasirinkimus galime mėgautis rezultatais, kurie yra išvedami į failus pagal mūsų pačių atliktus pasirinkimus.
9. Jei norite duomenis pergrupuoti kitaip arba patikrinti su kitais duomenimis, tai visus žingsnius reiktų pakartoti iš naujo.

# Antras laboratorinis darbas
## Versija v1.1

Naujos versijos pakeitimai:
- Visų pirma, naujas laboratorinis darbas pareikalavo repozitorijos klonavimo, kuri ir buvo atlikta, išlaikant visą istoriją iš anksčiau.
- Objektų laikymas struktūrose buvo pakeistas objektų laikymu klasėse.
- Buvo atliktas programos spartos matavimas, naudojant List 2 strategijos konteinerį, nes jis buvo optimaliausias dalijant studentus į dvi grupes.
- Taip pat buvo atlikta eksperimentinė analizė, priklausomai nuo kompiliatoriaus optimizavimo lygio.

Analizė: buvo matuojami 100000 ir 1000000 įrašų failai ir jų padalijimas į galvočius ir vargšiukus. Kiekvienas failas buvo matuojamas 5 kartus ir išvedamas matavimo vidurkis. Taip pat antras eksperimentas buvo žiūrimas vykdomojo failo dydis, priklausomai nuo optimizavimo lygio.

Rezultatai:

**1. Programos spartos testas, priklausomai nuo: optimizavimo lygio, įrašų skaičiaus ir struktūros arba klasės.**
- **100 000 įrašų matavimas sekundėmis**
  
|Optimizavimo lygis|STRUCT|CLASS |
|------------------|-----:|-----:|
|        O1        |0.0028|0.0023|
|        O2        |0.0024|0.0022|
|        O3        |0.0027|0.0023|

- **1 000 000 įrašų matavimas sekundėmis**
  
|Optimizavimo lygis|STRUCT|CLASS |
|------------------|-----:|-----:|
|        O1        |0.0581|0.0283|
|        O2        |0.0628|0.0287|
|        O3        |0.0599|0.0288|

**2. Vykdomojo failo dydis, priklausomai nuo tipo ir optimizavimo lygio.**
- **STRUCT**
  
|Optimizavimo lygis|Failo dydis (KB)|
|------------------|---------------:|
|        O1        |       157      |
|        O2        |       158      |
|        O3        |       191      |

- **CLASS**

|Optimizavimo lygis|Failo dydis (KB)|
|------------------|---------------:|
|        O1        |        68      |
|        O2        |        68      |
|        O3        |        67      |


**Išvados:**
- Matome, kad dalijimas į grupes nuo optimizavimo lygio beveik nepriklauso, skiriasi tik kelios sekundės dalys.
- Dalijimas į grupes tiek su 100 000, tiek su 1 000 000 įrašų failais buvo greitesnis klasės atveju, skitumas pakankamai žymus, kai matuojama 1 000 000 įrašų skaičius.
- Failų dydžiai struktūroje truputį skiriasi: su O3 optimizavimo lygiu failas buvo didžiausias, o su kitais mažesnis ir jų dydis buvo toks pats.
- Klasės atveju visi failai buvo panašaus dydžio.

## Versija v1.2

Pakeitimai atlikti šioje versijoje:
- Realizuotas "Rule of three" reikalavimas, kurį sudaro: destruktorius (realizuotas jau v1.1 versijoje), kopijavimo konstruktorius, priskyrimo operatorius.
- Realizuoti įvesties ir išvesties operatoriai, kurių pagalba vartotojui duomenis įvesti paprasčiau.

Aikšinimas apie duomenų įvesties ir išvesties metodus:
- **Įvesties operatorius** šioje versijoje galima įvesti studento duomenis ranka: vardą, pavardę, namų darbų pažymius ir egzamino pažymį, kuriuos galima sugeneruoti ir atsitiktinai. Galima taip pat pasirinkti ir kiek pažymių norima įvesti.

<img width="767" height="729" alt="image" src="https://github.com/user-attachments/assets/d3addd28-1c86-46ba-b41c-40b7d42abdd3" />

Šis operatorius realizuojamas vėliau programoje:

<img width="88" height="27" alt="image" src="https://github.com/user-attachments/assets/08300061-421e-4059-b062-ffd31d69b0be" />


- **Išvesties operatorius** šioje versijoje galima išvesti studento duomenis naudojant << operatorių. Vartotojas, išvedęs duomenis, visada matys studentų vardus ir pavardes, taip pat galės pasirinkti ar matyti tik galutinį balą suskaičiuotą tsikant vidurkio formulę, galutinį balą, suskaičiuotą taikant medianos formulę, galutinį balą pagal vidurkį ir medianą kartu.

<img width="1078" height="76" alt="image" src="https://github.com/user-attachments/assets/86c2790d-0a5f-4fc1-ba72-2e868d2197a1" />


Vartotojui taip pat šioje versijoje atsirado galimybė pamatyti rezultatus iškart konsolėje, jeigu tai yra nedidelis duomenų kiekis, kas yra patogu, kai nėra daug duomenų. Taip pat vartotojas gali ir pasirinkti išvesti duomenis į failą. Tai visiškai laisvas vartotojo pasirinkimas, priklausomas nuo norų. 

**Po minimalaus pataisymo buvo realizuotas ir dabar programoje demonstruojamas RULE OF THREE testas.**

## Versija v1.5

Pakeitimai, kurie realizuoti šioje versijoje:
- Vietoje turimos klasės **Studentas** sukurtos dvi naujos: bazinė klasė, skirta aprašyti žmogų, išvestinė klasė - **Studentas**.
- Žmogui skirta bazinė klasė yra abstrakti.

Sukurta abstrakti klasė Zmogus:

<img width="676" height="281" alt="image" src="https://github.com/user-attachments/assets/7ce46569-e24e-4de6-867b-3590c87b39c7" />

Studentas klasė yra išvestinė iš sios klasės Zmogus.
Studentas klasė vis dar palaiko RULE OF THREE, nors ir dabar yra išvestinė iš klasės Zmogus.

Kad klasė Zmogus yra tikrai abstrakti pabandome patikrinti:

<img width="79" height="25" alt="image" src="https://github.com/user-attachments/assets/3916c78e-6170-4e3b-a660-eaaaff8879bc" />

Ir iškart gauname klaidą:

<img width="296" height="35" alt="image" src="https://github.com/user-attachments/assets/d98e4b32-cf23-46d3-a58d-277264627b01" />

## Versija 2.0

Kas buvo atlikta šioje versijoje:
- Sukurta doxygen dokumentacija.
- Realizuoti unit testai.
- Galutinai sutvarkyta repozitorija ir baigtas v2.0 kūrimas.
