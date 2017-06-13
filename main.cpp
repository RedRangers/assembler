#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include"assembler1.h"
#include"assembler2.h"


int main()
{

    std::map<std::string, int> link;
    std::vector<int> code;

    ToCode( code, link );

    if( !link.empty() )
        FindLink( code, link );

    std::remove( "code.txt" );
    std::ofstream Code( "code.txt" );

    for( size_t i = 0; i< code.size(); ++i )
        Code << code[ i ] << "\n";

    Code.close();

    system( "notepad.exe code.txt" );

    return 0;
}
