#include "studentas.h"
#include <gtest/gtest.h>
#include <vector>

TEST(FunkcijosTest, Vidurkis) {
    std::vector<int> v{5, 6, 7, 8, 9};
    EXPECT_DOUBLE_EQ(vidurkis(v), 7.0);
}

TEST(FunkcijosTest, Mediana) {
    std::vector<int> v{5, 6, 7, 8, 9};
    EXPECT_DOUBLE_EQ(mediana(v), 7.0);
}

TEST(StudentasTest, GalutinisBalasVidurkis) {
    Studentas s;
    s.setNd({5, 5, 5});
    s.setEgzaminas(10);

    double gal = s.galBalas(vidurkis);
    EXPECT_DOUBLE_EQ(gal, 0.4*5 + 0.6*10); // tikimasi 7.0
}

TEST(StudentasTest, GalutinisBalasMediana) {
    Studentas s;
    s.setNd({5, 7, 9});
    s.setEgzaminas(6);
    
    double gal = s.galBalas(mediana);
    EXPECT_DOUBLE_EQ(gal, 0.4*7 + 0.6*6);} // mediana=7 -> galutinis 6.4

TEST(StudentasTest, KopijavimoKonstruktorius) {
    Studentas s1;
    s1.setNd({8,9,10});
    s1.setEgzaminas(10);

    Studentas s2 = s1; // copy constructor
    EXPECT_DOUBLE_EQ(s2.galBalas(vidurkis), s1.galBalas(vidurkis));
}

TEST(StudentasTest, PriskyrimoOperatorius) {
    Studentas s1;
    s1.setNd({1,2,3});
    s1.setEgzaminas(6);

    Studentas s2;
    s2 = s1; // assignment
    EXPECT_DOUBLE_EQ(s2.galBalas(vidurkis), s1.galBalas(vidurkis));
}
