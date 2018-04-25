#ifndef READER_H
#define READER_H
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Mydb.h"
#include "doctor.h"

class Reader
{
public:

    Reader(){}
    ~Reader(){}

    int show_all_records(Mydb &doctorDB, Mydb &hospitalDB);

    int show_hospital(Mydb &hospitalDB, const char *hospital);

    int SearchData(Mydb &DB);

    int puttingData(Mydb &DB);

    int deleteData(Mydb &DB);
    int replaceData(Mydb &DB);


};

#endif // READER_H
