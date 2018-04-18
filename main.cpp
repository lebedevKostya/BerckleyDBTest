//#include <iostream>
//#include <fstream>
//#include <cstdlib>

//#include "Mydb.h"
//#include "dataset.h"

//using namespace std;

//// Forward declarations
//void loadHospitalsDB(Mydb &, std::string &);
//void loadDoctorsDB(Mydb &, std::string &);

//int main()
//{


//    std::string basename("/home/konstantin/berkley/");
//    std::string databaseHome("/home/konstantin/berkley/DataBase/");

//    std::string hDbName("hospitals.db");
//    std::string dDbName("doctors.db");



//    std::string hospitalsFile = basename + "hospitals.txt";
//    std::string doctorsFile = basename + "doctors.txt";

//    try
//    {
//        // Open all databases.
//        Mydb hospitalDB(databaseHome, hDbName);
//        Mydb doctorDB(databaseHome, dDbName);


//        // Load the hospital database
//        loadHospitalsDB(hospitalDB, hospitalsFile);

//        // Load doctor database
//        loadDoctorsDB(doctorDB, doctorsFile);


//        }catch(DbException &e) {
//            std::cerr << "Error loading databases. " << std::endl;
//            std::cerr << e.what() << std::endl;
//            return (e.get_errno());
//        } catch(std::exception &e) {
//            std::cerr << "Error loading databases. " << std::endl;
//            std::cerr << e.what() << std::endl;
//            return (-1);
//        }
//    return 0;
//}

//int getNextPound(std::string &theString, std::string &substring)
//{
//    int pos = theString.find("#");
//    substring.assign(theString, 0, pos);
//    theString.assign(theString, pos + 1, theString.size());
//    return pos;
//}

//void loadHospitalsDB(Mydb &hospitalsdb, std::string &hospitalsfile)
//    {
//        std::ifstream inFile(hospitalsfile.c_str(), std::ios::in);
//        if ( !inFile )
//        {
//            std::cerr << "Could not open file '" << hospitalsfile
//                      << "'. Giving up." << std::endl;
//            throw std::exception();
//        }

//        HOSPITAL my_hospital;
//        while (!inFile.eof())
//        {
//            std::string stringBuf;
//            std::getline(inFile, stringBuf);
//            memset(&my_hospital, 0, sizeof(HOSPITAL));

//             // Scan the line into the structure.
//            sscanf(stringBuf.c_str(),
//            "%20[^#]#%20[^#]#%20[^#]#%20[^#]#%20[^\n]",
//            my_hospital.hosp_id,
//            my_hospital.name_,my_hospital.street_, my_hospital.phone_,
//            my_hospital.numOfBeds_);


//            Dbt key (my_hospital.hosp_id, (u_int32_t)strlen(my_hospital.hosp_id) + 1);
//            Dbt data (&my_hospital, sizeof(HOSPITAL));

//            hospitalsdb.getDb().put(NULL, &key, &data, 0);
//        }

//        inFile.close();
//    }

//void loadDoctorsDB(Mydb &doctorDB, std::string &doctorsFile)
//{
//    DataSet doctor;
//    std::string substring;
//    size_t nextPound;

//    std::ifstream inFile(doctorsFile.c_str(), std::ios::in);
//    if ( !inFile )
//    {
//        std::cerr << "Could not open file '" << doctorsFile
//                  << "'. Giving up." << std::endl;
//        throw std::exception();
//    }
//    while (!inFile.eof())
//    {
//        doctor.clear();
//        std::string stringBuf;
//        std::getline(inFile, stringBuf);

//        // Now parse the line
//        if (!stringBuf.empty())
//        {
//            nextPound = getNextPound(stringBuf, substring);
//            doctor.setDoctorId(substring);

//            nextPound = getNextPound(stringBuf, substring);
//            doctor.setDoctorCode(substring);

//            nextPound = getNextPound(stringBuf, substring);
//            doctor.setDoctorName_(substring);

//            nextPound = getNextPound(stringBuf, substring);
//            doctor.setDoctorSpec_(substring);

//             void *buff = (void *)doctor.getDoctorId().c_str();
//             size_t size = doctor.getDoctorId().size()+1;
//             Dbt key(buff, (u_int32_t)size);

//             buff = doctor.getBuffer();
//             size = doctor.getBufferSize();
//             Dbt data(buff, (u_int32_t)size);

//             doctorDB.getDb().put(NULL, &key, &data, 0);
//        }

//    }

//    inFile.close();
//}




















































