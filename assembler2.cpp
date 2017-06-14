#include"assembler2.h"
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<cstdlib>
#include"key.h"

void FindLink( std::vector<int>& code, std::map< std::string, int>& link )
{
    std::fstream file( "skript.txt" );
    std::string line,substr;

    size_t i = 0;
    size_t j = 0;

    while ( !file.eof() )
    {
        line.clear();
        getline ( file, line );
        i = line.find( ':' );

        if( i > 2 && i < line.length() )
        {
            substr = line.substr( i, line.length() );
            while ( code[ j ] != CHIPER_LINK )
                j++;
            code[ j ] = link[ substr ];

            if( !link[ substr ] )
                std::cout << "Warning!!!\nPointer on the zero position" << std::endl;
        }
    }

    file.close();
}
