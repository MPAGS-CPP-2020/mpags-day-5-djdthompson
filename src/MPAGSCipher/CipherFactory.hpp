#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include <memory>
#include "Cipher.hpp"
#include "CipherType.hpp"
/**
 * \file CipherFactory.hpp
 * \brief Contains the declaration of the cipher factory function which creates a unique pointer to a cipher of any type
 */


/**
     * Create a cipher according to input type
     *
     * \param type the type of cipher to create
     * \param key the key for the cipher being constructed
     * \return a unique pointer to the cipher that is created
     */
std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key );
//prototype function which takes an input cipher type and key then creates instance of cipher,
//returning unique pointer to it




#endif