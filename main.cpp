#include <iostream>
#include <fstream>
#include <cstdlib>

#include <loader.h>
#include <reader.h>


using namespace std;



int main()
{

    Loader loader;
    Reader reader;
    std::string basename("/home/konstantin/berkley/");
    std::string databaseHome("/home/konstantin/berkley/DataBase/");
    std::string hDbName("hospitals.db");
    std::string dDbName("doctors.db");
    std::string hospitalsFile = basename + "hospitals.txt";
    std::string doctorsFile = basename + "doctors.txt";



    try
    {
        // Открываем нужные нам базы.
        Mydb hospitalDB(databaseHome, hDbName);
        Mydb doctorDB(databaseHome, dDbName);

//        // Загружаем из текстового файла данные в базу
//        loader.loadHospitalsDB(hospitalDB, hospitalsFile);

//        // Загружаем из текстового файла данные второй базы
//        loader.loadDoctorsDB(doctorDB, doctorsFile);

        reader.replaceData(doctorDB);
        //Выводим содержимое обоих таблиц на консоль
         reader.show_all_records(doctorDB, hospitalDB);




        }catch(DbException &e) {
            std::cerr << "Ошибка при загрузке базы " << std::endl;
            std::cerr << e.what() << std::endl;
            return (e.get_errno());
        } catch(std::exception &e) {
            std::cerr << "Ошибка при загрузке базы " << std::endl;
            std::cerr << e.what() << std::endl;
            return (-1);
        }




    return 0;
}























































