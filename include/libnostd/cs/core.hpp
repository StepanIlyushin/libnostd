
#ifndef LIBNOSTD_CORE_HPP
#define LIBNOSRD_CS_CORE_HPP

#include <string>
/**
 * @brief BAsic Computer science utils
 */
namespace cs {
        /**
         *  @brief Преобразует целое десятичное в 16-ричное
         *
         * @param[in] decimal целое десятичное число
         *
         * @return std::string число в 16-ой системе счисления
        */
        std::string dec2hex(unsigned int decimal);
        unsigned int hex2dec(const std::string & hexademal);
        std::string dec2bin(unsigned int decimal);
}

#endif
