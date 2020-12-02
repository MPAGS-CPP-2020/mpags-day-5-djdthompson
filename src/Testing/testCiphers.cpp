//! iUnit tests for all three ciphers using polymorphism
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"
#include "CipherFactory.hpp"

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

TEST_CASE("Test encryption/Decryption with vectors of base class pointers","[base-class-pointers]"){
    std::vector<std::unique_ptr<Cipher>> cipherPtrVector;
    cipherPtrVector.push_back(cipherFactory(CipherType::Caesar,"27"));
    cipherPtrVector.push_back(cipherFactory(CipherType::Playfair,"testKey"));
    cipherPtrVector.push_back(cipherFactory(CipherType::Vigenere,"testKey"));
    std::string testPhrase{"HELLOWORLD"}; //test phrase as used in previous tests
    std::vector<std::string> testAnswersEncrypt = {"IFMMPXPSME","OBQKHQVPQMFX","AIDEYAMKPV"}; //vector of answers to index in require statements for encrypt
    std::vector<std::string> testAnswersDecrypt = {testPhrase,"HELXLOWORLDZ",testPhrase}; //vector of answers to index in require statements for decrypt
    int i{0};
    for(const auto& v : cipherPtrVector){
        REQUIRE(v->applyCipher(testPhrase,CipherMode::Encrypt)==testAnswersEncrypt[i]);
        REQUIRE(v->applyCipher(testAnswersEncrypt[i],CipherMode::Decrypt)==testAnswersDecrypt[i]);
        i++;
    }
}
