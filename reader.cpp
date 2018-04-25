#include "reader.h"






int Reader::show_all_records(Mydb &doctorDB, Mydb &hospitalDB)
{
    Dbc *cursorp;
    try {

        doctorDB.getDb().cursor(NULL, &cursorp, 0);
        Dbt key, data;
        int ret;
        while ((ret = cursorp->get(&key, &data, DB_NEXT)) == 0 )
        {
            Doctor doctorItem(data.get_data());
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


int Reader::show_hospital(Mydb &hospitalDB, const char *hospital)
{
    Dbt data;
    HOSPITAL my_hospital;

    try {

        Dbt key((char *)hospital, (u_int32_t)strlen(hospital) + 1);

        data.set_data(&my_hospital);
        data.set_ulen(sizeof(HOSPITAL));
        data.set_flags(DB_DBT_USERMEM);

        // Get the record
        hospitalDB.getDb().get(NULL, &key, &data, 0);
        std::cout << "Больница: " << my_hospital.name_ << "\n"
                  << "Адрес и телефон: " << my_hospital.street_ << ", "
                  << my_hospital.phone_ << "\n"
                  << "Число коек: " << my_hospital.numOfBeds_
                  << std::endl;

    } catch(DbException &e) {
        hospitalDB.getDb().err(e.get_errno(), "Ошибка при отображении");
        throw e;
    } catch(std::exception &e) {
        throw e;
    }
    return (0);
}

int Reader::SearchData(Mydb &doctorDB)
 {
     char *search_key = "1234";
     char *search_data = "Iva";

     Dbc *cursorp;
     try {

         doctorDB.getDb().cursor(NULL, &cursorp, 0);

         Dbt key(search_key, strlen(search_key) + 1);
         Dbt data(search_data, strlen(search_data) + 1);

         // Курсор устанавливается в первую запись где совпадает ключ и значение.
         cursorp->get(&key, &data, DB_GET_BOTH);

         std::cout << "key: " << (char *)key.get_data()
                          << "data: " << (char *)data.get_data()<< std::endl;
//         DataSet doctorItem(data.get_data());
//         doctorItem.show();

     } catch(DbException &e) {
         doctorDB.getDb().err(e.get_errno(), "Error in show_all_records");
         cursorp->close();
         throw e;
     } catch(std::exception &e) {
         cursorp->close();
         throw e;
     }

     // Close the cursor
     if (cursorp != NULL)
         cursorp->close();
     return (0);

 }

int Reader::puttingData(Mydb &doctorDb)
{
    Doctor doc1("1111","123","Григорьев Григорий","Терапевт");
    Dbc *cursorp;

    try {

        void *buff = (void *)doc1.getDoctorId().c_str();
        size_t size = doc1.getDoctorId().size()+1;
        Dbt key1(buff, (u_int32_t)size);

        buff = doc1.getBuffer();
        size = doc1.getBufferSize();
        Dbt data1(buff, (u_int32_t)size);

        doctorDb.getDb().cursor(NULL, &cursorp, 0);

        cursorp->put(&key1, &data1, DB_KEYFIRST);

    } catch(DbException &e) {
            doctorDb.getDb().err(e.get_errno(), "Error!");
    } catch(std::exception &e) {
            doctorDb.getDb().errx("Error! %s", e.what());
    }

    // Курсор должен быть закрыт
    if (cursorp != NULL)
        cursorp->close();


}

int Reader::deleteData(Mydb &doctorDb)
{
    char *key1str = "1111";
    Dbc *cursorp;

    try {
        doctorDb.getDb().cursor(NULL, &cursorp, 0);
        Dbt key(key1str, strlen(key1str) + 1);
        Dbt data;

        // Проходим по базе
        int ret;
        while ((ret = cursorp->get(&key, &data,DB_SET)) == 0)
        {
            cursorp->del(0);
        }

    } catch(DbException &e) {
        doctorDb.getDb().err(e.get_errno(), "Error!");
    } catch(std::exception &e) {
        doctorDb.getDb().errx("Error! %s", e.what());
    }
    if (cursorp != NULL)
        cursorp->close();

}

int Reader::replaceData(Mydb &doctorDb)
{
    Dbc *cursorp;


    char *key1str = "1234";
    char *replacement_data = "replace me";

    try {
        doctorDb.getDb().cursor(NULL, &cursorp, 0);

        // Set up our DBTs
        Dbt key(key1str, strlen(key1str) + 1);
        Dbt data;

        cursorp->get(&key, &data, DB_SET);

        data.set_data(replacement_data);
        data.set_size(strlen(replacement_data) + 1);
        cursorp->put(&key, &data, DB_CURRENT);

    } catch(DbException &e) {
        doctorDb.getDb().err(e.get_errno(), "Error!");
    } catch(std::exception &e) {
        doctorDb.getDb().errx("Error! %s", e.what());
    }

    // Cursors must be closed
    if (cursorp != NULL)
        cursorp->close();

}
