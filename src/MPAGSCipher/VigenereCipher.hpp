#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include <string>
#include <map>

// Our project headers
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "Cipher.hpp"

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenèreCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenère cipher with the given key
 */

class VigenereCipher : public Cipher {
public:
    /**
     * Create a new VigenèreCipher with the given key
     * TESTESTESTEST
     *
     * \param key the key to use in the cipher
     */
    explicit VigenereCipher( const std::string& key );

    /**
     * Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */
    void setKey( const std::string& key );

    /**
     * Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    virtual std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const override; 
    //writing virtual and override indicates that it HAS to be overriding a virtual function: if it can't find one matching
    //it will fail. if didnt have it, and couldn't find one it would just make a new one, this is good for explicit definitions

private:
    /// The cipher key
    std::string key_ {""};

    ///lookup table to map from a certain charachter key to corresponding caesar cipher
    std::map<char,CaesarCipher> charLookup_;
};

#endif
