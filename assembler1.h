#ifndef CODER_H
#define CODER_H
#include<map>
#include<vector>

//!
//! \brief Addit processes addresses to memory cells
//! \param code result code
//! \param line string whith names of memory cells
//!
bool Addit( std::vector<int>& code, std::string& line );

//!
//! \brief ToCode translate into code skript without links
//! \param code result code
//! \param link list with links for command jmp and CALL
//! \param StackRet stack whith links for command ret
//!
void ToCode( std::vector<int>& code, std::map< std::string, int >& link );

#endif // CODER_H
