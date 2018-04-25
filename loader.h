#ifndef LOADER_H
#define LOADER_H
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "doctor.h"
#include "Mydb.h"


using namespace std;

class Loader
{

public:
    Loader(){}
    ~Loader(){}

    void loadHospitalsDB(Mydb &hospitalsdb, std::string &hospitalsfile);

    void loadDoctorsDB(Mydb &doctorDB, std::string &doctorsFile);

    int getNextPound(std::string &theString, std::string &substring);



};

#endif // LOADER_H
