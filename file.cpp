//!
//! @file file.cpp
//! Definition functions of Class File
//!
//! @author GeoIrb 2017
//!
#include "file.h"

//-------Puplic------------------
File::File(const string &filename , const std::__cxx11::string &opt)
{
//    if( filename.length() == 0 ) Проверка существования данной директории
//    {
//        string Error = "Incorrect name of file";
//        cout << Error << endl;
//        string *Error_Mes = &Error;
//        throw Error_Mes;
//    }

    if( opt == "new" )
        FCreate( filename );

    filenames_.open( filename );
    names_ = filename;

    if( filenames_.is_open() )
        cout << "\nOpened file " << names_ << endl;
    else
    {
        string Error = "Not opened file";
        cout << Error << endl;
        string *Error_Mes = &Error;
        throw Error_Mes;
    }
}

File::~File()
{
    filenames_.close();
    cout << "File " << names_ << " is closed" << endl;
    names_ = "NOT NAME OF FILE";
}

string File::GetName() const
{
    return names_;
}

string File::ReadLine()
{
    string str;
    getline( filenames_, str );
    return str;
}



bool File::EndFile() const
{
    return filenames_.eof();
}

void File::Dump() const
{
    cout << "File opened " << ( Ok() ? "Correct" : "Incorrct" ) << endl;
    cout << "Name of file " << names_ << endl;
    system( "pause" );
}

void File::ToEnd()
{
    filenames_.seekg(0, std::ios::end );
}

//-------------Private----------------------------
bool File::Ok() const
{
    return !filenames_.is_open();
}

void File::FCreate( const string& filename )
{
    std::ofstream fnew( filename );
    fnew.close();
}



