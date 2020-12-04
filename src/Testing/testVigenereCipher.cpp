//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"

TEST_CASE("Vigenere Cipher Initialisation and ability to encrypt input text", "[vigenere]"){
    VigenereCipher vC{"testKey"};
    REQUIRE(vC.applyCipher("THISISSOMETESTINPUTTEXT",CipherMode::Encrypt)=="MLALSWQHQWMOWRBRHNDXCQX");
}

TEST_CASE("Vigenere Cipher decrypt text", "[vigenere2]"){
    VigenereCipher vC2{"testKey"};
    REQUIRE(vC2.applyCipher("MLALSWQHQWMOWRBRHNDXCQX",CipherMode::Decrypt)=="THISISSOMETESTINPUTTEXT");
}

TEST_CASE("Vigenere Cipher works as caesar if single character key with encryption", "[vigenere3]"){
    VigenereCipher vC3{"D"};
    CaesarCipher cC{3};
    REQUIRE(vC3.applyCipher("HELLOWORLD",CipherMode::Encrypt)==cC.applyCipher("HELLOWORLD",CipherMode::Encrypt));    
}

TEST_CASE("Vigenere Cipher works as caesar if single character key with decryption", "[vigenere4]"){
    VigenereCipher vC4{"D"};
    CaesarCipher cC2{3};
    REQUIRE(vC4.applyCipher("HELLOWORLD",CipherMode::Decrypt)==cC2.applyCipher("HELLOWORLD",CipherMode::Decrypt));    
}

//REMEMBER: inputs are formatted before being passed to cipher so must provide pre-formatted inputs (remove non-alpha-numeric, convert numbers)