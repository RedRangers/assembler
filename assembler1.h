#ifndef CODER_H
#define CODER_H
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<cassert>
#include<vector>
#include<cstdlib>
#include"key.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

//!
//! \brief Addit processes addresses to memory cells
//! \param code result code
//! \param line string whith names of memory cells
//!
bool Addit( std::vector<int>& code, string& line )
{

    if( line == STR_X0 )
    {
        code.push_back( CODE_X0 );
        return true;
    }

    if( line == STR_X1 )
    {
        code.push_back( CODE_X1 );
        return true;
    }

    if( line == STR_X2 )
    {
        code.push_back( CODE_X2 );
        return true;
    }

    return false;
}

//!
//! \brief ToCode translate into code skript without links
//! \param code result code
//! \param link list with links for command jmp and CALL
//! \param StackRet stack whith links for command ret
//!
void ToCode( std::vector<int>& code, std::map< string, int >& link )
{
    bool flag = true;
    int  i    = -1;

    system( "notepad.exe skript.txt" );
    std::fstream file( "skript.txt" );
    assert( file.is_open() );

    string line;
    string substr1;
    string substr2;

    while ( !file.eof() && flag )
    {
        flag = false;
        ++i;

        line.clear();
        getline ( file, line );

        //Separate processing of commands consisting of 2 parts and 1 part
        if( line.find( ' ' ) < line.length() )
        {
            substr1.clear();
            substr2.clear();
            substr2 = line.substr( line.find( ' ' ) + 1, line.length());
            substr1 = line.substr( 0, line.find( ' ' ) );

            if( substr1 == STR_PUSH )
            {
                code.push_back( CODE_PUSH );

                if( atoi( substr2.c_str() ) != 0 || substr2 == "0" )
                {
                    code.push_back( atoi( substr2.c_str() ) );
                    flag = true;
                }
                else
                {
                    flag = Addit( code, substr2 );
                }
            }

            if( substr1 == STR_POP )
            {
                code.push_back( CODE_POP );

                flag = Addit( code, substr2 );

            }

            if( substr1 == STR_POW )
            {
                code.push_back( CODE_POW );

                if( atoi( substr2.c_str() ) != 0 || substr2 == "0" )
                {
                    code.push_back( atoi( substr2.c_str() ) );
                    flag = true;
                }
                else
                {
                    cout << "Incorrect type of degree " << endl;
                }
            }

            if( substr1 == STR_JMP )
            {
                code.push_back( CODE_JMP );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( substr1 == STR_CALL )
            {
                code.push_back( CODE_CALL );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( substr1 == STR_JE )
            {
                code.push_back( CODE_JE );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( substr1 == STR_JA )
            {
                code.push_back( CODE_JA );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( substr1 == STR_JAE )
            {
                code.push_back( CODE_JAE );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( line == STR_JB )
            {
                code.push_back( CODE_JB );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( substr1 == STR_JBE )
            {
                code.push_back( CODE_JBE );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( substr1 == STR_JNE )
            {
                code.push_back( CODE_JNE );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

        }
        else
        {
            if( line[ 0 ] == ':' )
            {
                link.insert( std::pair< string, int > ( line, code.size() ) );

                flag = true;
            }

            if( line == STR_ADD )
            {
                code.push_back( CODE_ADD );

                flag = true;
            }

            if( line == STR_SUB )
            {
                code.push_back( CODE_SUB );

                flag = true;
            }

            if( line == STR_DIV )
            {
                code.push_back( CODE_DIV );

                flag = true;
            }

            if( line == STR_MULT )
            {
                code.push_back( CODE_MULT );

                flag = true;
            }

            if( line == STR_RET )
            {
                code.push_back( CODE_RET );
                code.push_back( CHIPER_LINK );

                flag = true;
            }

            if( line == STR_END )
            {
                code.push_back( CODE_END );
                flag = false;
            }
        }
    }

    if( !flag && line != STR_END )
        cout << "Error in line: " << i + 1 << " Line: " << line << endl;
    else
        cout << "The coding is finished" << endl;

    file.close();
}

#endif // CODER_H
