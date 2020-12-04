#include <memory>
#include "CipherFactory.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"
#include "CipherType.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key ){
    //switch statement chooses which cipher to create
    switch (type){
        case CipherType::Caesar:
            return std::make_unique<CaesarCipher>(key);
        case CipherType::Playfair:
            return std::make_unique<PlayfairCipher>(key);
        case CipherType::Vigenere:
            return std::make_unique<VigenereCipher>(key);
    }
    //in the impossible case of none of the three cases being triggered, return an zero caesar
    //prevents "-Werror=return-type"
    return std::make_unique<CaesarCipher>("0");
}