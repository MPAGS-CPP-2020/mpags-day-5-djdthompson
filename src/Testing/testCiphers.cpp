//! iUnit tests for all three ciphers using polymorphism
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherMode.hpp"

//function returns true if cipher has worked, false if not
bool testCipher (const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& expecOutput){
    return cipher.applyCipher(inputText,mode)==expecOutput;
}

TEST_CASE("Test encryption of three ciphers", "[encryption]"){
    CaesarCipher cc{27};
    PlayfairCipher pc{"testKey"};
    VigenereCipher vc{"testKey"}; 
    std::string testPhrase{"HELLOWORLD"};
    REQUIRE(testCipher(cc,CipherMode::Encrypt,testPhrase,"IFMMPXPSME"));
    REQUIRE(testCipher(pc,CipherMode::Encrypt,testPhrase,"OBQKHQVPQMFX"));
    REQUIRE(testCipher(vc,CipherMode::Encrypt,testPhrase,"AIDEYAMKPV"));
}

TEST_CASE("Test decryption of three ciphers", "[decryption]"){
    CaesarCipher cc{27};
    PlayfairCipher pc{"testKey"};
    VigenereCipher vc{"testKey"}; 
    std::string testPhrase{"HELLOWORLD"};
    REQUIRE(testCipher(cc,CipherMode::Decrypt,"IFMMPXPSME",testPhrase));
    REQUIRE(testCipher(pc,CipherMode::Decrypt,"OBQKHQVPQMFX","HELXLOWORLDZ"));
    REQUIRE(testCipher(vc,CipherMode::Decrypt,"AIDEYAMKPV",testPhrase));
}
