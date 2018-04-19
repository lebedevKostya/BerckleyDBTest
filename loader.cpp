#include <iostream>
#include <fstream>
#include <cstdlib>
#include "loader.h"



void Loader::loadDoctorsDB(Mydb &doctorDB, std::string &doctorsFile)

{
    DataSet doctor;
    std::string substring;
    size_t nextPound;

    std::ifstream inFile(doctorsFile.c_str(), std::ios::in);

    if ( !inFile )
    {
        std::cerr << "Не получилось открыть файл '" << doctorsFile
                  << "'. Попробуйте снова." << std::endl;
        throw std::exception();
    }

    while (!inFile.eof())
    {
        doctor.clear();
        std::string stringBuf;
        std::getline(inFile, stringBuf);

        // парсим строку из файла
        if (!stringBuf.empty())
        {
            nextPound = getNextPound(stringBuf, substring);
            doctor.setDoctorId(substring);

            nextPound = getNextPound(stringBuf, substring);
            doctor.setDoctorCode(substring);

            nextPound = getNextPound(stringBuf, substring);
            doctor.setDoctorName_(substring);

            nextPound = getNextPound(stringBuf, substring);
            doctor.setDoctorSpec_(substring);

             void *buff = (void *)doctor.getDoctorId().c_str();
             size_t size = doctor.getDoctorId().size()+1;
             Dbt key(buff, (u_int32_t)size);

             buff = doctor.getBuffer();
             size = doctor.getBufferSize();
             Dbt data(buff, (u_int32_t)size);

             doctorDB.getDb().put(NULL, &key, &data, 0);
        }

    }

    inFile.close();
}

void Loader::loadHospitalsDB(Mydb &hospitalsdb, std::string &hospitalsfile)
{
    std::ifstream inFile(hospitalsfile.c_str(), std::ios::in);

    if ( !inFile )
    {
        std::cerr << "Не получилось открыть файл " << hospitalsfile
                      << "'. Попробуйте снов" << std::endl;
        throw std::exception();
    }
    HOSPITAL my_hospital;
    while (!inFile.eof())
    {
        std::string stringBuf;
        std::getline(inFile, stringBuf);
        memset(&my_hospital, 0, sizeof(HOSPITAL));
        // сканируем линию в структуре
        sscanf(stringBuf.c_str(),
               "%20[^#]#%20[^#]#%20[^#]#%20[^#]#%20[^\n]",
               my_hospital.hosp_id,
               my_hospital.name_,my_hospital.street_, my_hospital.phone_,
               my_hospital.numOfBeds_);
        Dbt key (my_hospital.hosp_id, (u_int32_t)strlen(my_hospital.hosp_id) + 1);
        Dbt data (&my_hospital, sizeof(HOSPITAL));
        hospitalsdb.getDb().put(NULL, &key, &data, 0);
    }
    inFile.close();

}


int Loader::getNextPound(std::string &theString, std::string &substring)
{
    int pos = theString.find("#");
    substring.assign(theString, 0, pos);
    theString.assign(theString, pos + 1, theString.size());
    return pos;
}









