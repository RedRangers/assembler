#ifndef ASSEMBLER2_H
#define ASSEMBLER2_H
#include<map>
#include<vector>

//!
//! \brief FindLink translates into the code all links used in the script
//! \param code result code
//! \param link list with links for command jmp and CALL
//!
void FindLink( std::vector<int>& code, std::map<std::string, int>& link );

#endif // ASSEMBLER2_H
