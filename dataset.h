#ifndef DATASET
#define DATASET
#include <cstdlib>
#include <cstring>



class DataSet
{

private:
    std::string doctor_id_;
    std::string doctor_code;
    std::string doctorName_;
    std::string doctorSpec_;
    size_t bufLen_;
    char databuf_[1000];



public:
    inline void setDoctorId(std::string doctorId)
    {
       doctor_id_ = doctorId;
    }
    inline void setDoctorCode(std::string doctorCode)
    {
        doctor_code = doctorCode;
    }
    inline void setDoctorName_(std::string doctorName)
    {
        doctorName_ = doctorName;
    }
    inline void setDoctorSpec_(std::string doctorSpec)
    {
        doctorSpec_ = doctorSpec;
    }

    inline std::string &getDoctorId ()
    {
       return doctor_id_;
    }
    inline std::string &getDoctorCode ()
    {
       return doctor_code;
    }
    inline std::string &getDocName ()
    {
        return doctorName_;
    }
    inline std::string &getDocSpec ()
    {
        return doctorSpec_;
    }



    /* Initialize our data members */
    void clear()
    {
        doctor_id_ = "";
        doctor_code ="";
        doctorName_ = "";
        doctorSpec_ = "";
    }


    // Default constructor
    DataSet()
    {
        clear();
    }

    DataSet(void *buffer)
    {
        char *buf = (char *)buffer;

        doctor_id_ = buf;
        bufLen_ =  doctor_id_.size()+1;

        doctor_code = buf + bufLen_;
        bufLen_ +=  doctor_code.size()+1;

        doctorName_ = buf + bufLen_;
        bufLen_ +=  doctorName_.size()+1;

        doctorSpec_ = buf + bufLen_;
        bufLen_ += doctorSpec_.size()+1;
    }

    char * getBuffer()
    {
        memset(databuf_, 0, 1000);
        bufLen_ = 0;
        packString(databuf_, doctor_id_);
        packString(databuf_, doctor_code);
        packString(databuf_, doctorName_);
        packString(databuf_, doctorSpec_);

        return databuf_;
    }

    inline size_t getBufferSize()
    {
        return bufLen_;
    }

    void show() {
        std::cout << "\nID: " << doctor_id_ << std::endl;
        std::cout << "Doctor Code: " << doctor_code << std::endl;
        std::cout << "Name: " << doctorName_ << std::endl;
        std::cout << "Specialization: " << doctorSpec_ << std::endl;
    }


private:
    void packString(char *buffer, std::string &theString)
    {
        size_t string_size = theString.size() + 1;
        memcpy(buffer+bufLen_, theString.c_str(), string_size);
        bufLen_ += string_size;
    }
};

typedef struct hospital
{
     char hosp_id[20];
     char name_[20];                    /* Hospital name */
     char street_[20];                  /* Street name and number */
     char phone_[20];                   /* Phone number */
     char numOfBeds_[20];               /* number of beds */
} HOSPITAL;
#endif // DATASET

