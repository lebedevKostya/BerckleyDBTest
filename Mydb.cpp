#include "Mydb.h"
#include "db_cxx.h"
#include "iostream"



// Передаем конструктору адрес папки где
//будет распологаться файл базы и имя файла базы
Mydb::Mydb(std::string &path, std::string &dbName)
    : db_(NULL, 0),
      dbFileName_(path + dbName),
      cFlags_(DB_CREATE)

{
    try
    {
        // Открытие базы
        db_.open(NULL, dbFileName_.c_str(), NULL, DB_BTREE, cFlags_, 0);
    }
    // DbException не является подклассом
    //std :: exception, поэтому
    catch(DbException &e)
    {
        std::cerr << "Ошибка при открытие: " << dbFileName_ << "\n";
        std::cerr << e.what() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Ошибка при открытие: " << dbFileName_ << "\n";
        std::cerr << e.what() << std::endl;
    }
}

// Закрытие базы
void Mydb::close()
{
    try
    {
        db_.close(0);
        std::cout << "\nБаза " << dbFileName_
                  << " закрыта." << std::endl;
    }
    catch(DbException &e)
    {
        std::cerr << "Ошибка при закрытие: " << dbFileName_ << "\n";
        std::cerr << e.what() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Ошибка при закрытие: " << dbFileName_ << "\n";
        std::cerr << e.what() << std::endl;
    }
}
