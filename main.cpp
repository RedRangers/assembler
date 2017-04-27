#include<iostream>
#include<fstream>
#include<vector>
#include"assembler1.h"
#include"assembler2.h"


using std::cin;
using std::cout;
using std::endl;

int main()
{

    std::map<std::string, int> link;
    std::vector<int> code;
    std::vector<int> StackRet;

    ToCode( code, link );

    if( !link.empty() )
        FindLink( code, link );

    std::fstream Code( "code.txt" );

    for( size_t i = 0; i< code.size(); ++i )
        Code << code[ i ] << "\n";

    system( "notepad.exe code.txt" );

    Code.close();

    return 0;
}
