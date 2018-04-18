#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Mydb.h"
#include "dataset.h"

using namespace std;



// Forward declarations
int show_all_records(Mydb &doctorDB, Mydb &hospitalDB);
int show_hospital(Mydb &hospitalDB, const char *hospital);



int main ()
{
    std::string databaseHome("/home/konstantin/berkley/DataBase/");


    std::string hDbName("hospitals.db");
    std::string dDbName("doctors.db");


    try
    {
        // Open all databases.
        Mydb hospitalDB(databaseHome, hDbName);
        Mydb doctorDB(databaseHome, dDbName);

        show_all_records(doctorDB, hospitalDB);
    } catch(DbException &e) {
        std::cerr << "Error reading databases. " << std::endl;
        return (e.get_errno());
    } catch(std::exception &e) {
        std::cerr << "Error reading databases. " << std::endl;
        std::cerr << e.what() << std::endl;
        return (-1);
    }

    return (0);
}


int show_all_records(Mydb &doctorDB, Mydb &hospitalDB)
{

    // Get a cursor to the inventory db
    Dbc *cursorp;
    try {
        doctorDB.getDb().cursor(NULL, &cursorp, 0);

        // Iterate over the inventory database, from the first record
        // to the last, displaying each in turn
        Dbt key, data;
        int ret;
        while ((ret = cursorp->get(&key, &data, DB_NEXT)) == 0 )
        {
            DataSet doctorItem(data.get_data());
            doctorItem.show();

        show_hospital(hospitalDB, doctorItem.getDoctorCode().c_str());
        }
    } catch(DbException &e) {
        doctorDB.getDb().err(e.get_errno(), "Error in show_all_records");
        cursorp->close();
        throw e;
    } catch(std::exception &e) {
        cursorp->close();
        throw e;
    }

    cursorp->close();
    return (0);
}

int show_hospital(Mydb &hospitalDB, const char *hospital)
{
    Dbt data;
    HOSPITAL my_hospital;

    try {
        // Set the search key to the hospital's name
        // hospital is explicitly cast to char * to stop a compiler
        // complaint.
        Dbt key((char *)hospital, (u_int32_t)strlen(hospital) + 1);

        // Make sure we use the memory we set aside for the VENDOR
        // structure rather than the memory that DB allocates.
        // Some systems may require structures to be aligned in memory
        // in a specific way, and DB may not get it right.

        data.set_data(&my_hospital);
        data.set_ulen(sizeof(HOSPITAL));
        data.set_flags(DB_DBT_USERMEM);

        // Get the record
        hospitalDB.getDb().get(NULL, &key, &data, 0);
        std::cout << "        " << my_hospital.name_ << "\n"
                  << "        " << my_hospital.street_ << ", "
                  << my_hospital.phone_ << "\n"
                  << "        " << my_hospital.numOfBeds_
                  << std::endl;

    } catch(DbException &e) {
        hospitalDB.getDb().err(e.get_errno(), "Error in show_vendor");
        throw e;
    } catch(std::exception &e) {
        throw e;
    }
    return (0);
}
