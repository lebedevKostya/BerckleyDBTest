#ifndef READER_H
#define READER_H
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Mydb.h"
#include "dataset.h"

class Reader
{
public:

    Reader(){}
    ~Reader(){std::cout << "Объект считывателя разрушился" << std::endl;}

    int show_all_records(Mydb &doctorDB, Mydb &hospitalDB);

    int show_hospital(Mydb &hospitalDB, const char *hospital);

};

#endif // READER_H
