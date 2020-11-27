#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP
#include <string>
#include <map>

// Our project headers
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the pure abstract base class "CIPHER" from whcih the three types of ciphers
 * will be derived 
 */

/**
 * \class Cipher
 * \brief Pure abstract base class with pure virtual apply cipher function to be defined differently in derived classes.
 * Provides an interface for ciphers in general.
 */

class Cipher {
    public:
        Cipher()= default;
        Cipher(const Cipher& rhs)= default; //copy constructor, by copying an exisiting instance
        Cipher(Cipher&& rhs) = default; //move constructor, move an existing instance 
        Cipher& operator=(const Cipher& rhs)=default;//copy assignment
        Cipher& operator=(Cipher&& rhs)=default; //move assignment 
        virtual ~Cipher() =default;


        virtual std::string applyCipher(const std::string& text, const CipherMode mode ) const = 0;

};

#endif