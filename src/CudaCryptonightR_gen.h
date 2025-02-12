#ifndef kitten_CUDACRYPTONIGHTR_GEN_H
#define kitten_CUDACRYPTONIGHTR_GEN_H

#include <cstdint>
#include <vector>
#include <string>

void CryptonightR_get_program(std::vector<char>& ptx, std::string& lowered_name, uint64_t height, int arch_major, int arch_minor, bool background = false);

#endif // kitten_CUDACRYPTONIGHTR_GEN_H
