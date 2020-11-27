// Standard library includes
#include <string>
#include <algorithm>
#include <iostream>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"


VigenereCipher::VigenereCipher( const std::string& key )
{
  this->setKey( key );
}

void VigenereCipher::setKey( const std::string& key )
{
    key_=key;

    //set key to upper case and remove non-alpha
    // Make sure the key is upper case
    std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

    // Remove non-alphabet characters
    key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
              std::end(key_) );

    if (key_==""){
        key_=="KEY";//if key is now empty, replace with default key "KEY"
    }

    charLookup_.clear();//ensure the map is empty
    //loop over key with i as each character
    CaesarCipher tempCipher{0}; //temporary cipher to fill char loohup map
    for (char i : key_){
        //check if 
        if(charLookup_.find(i)==charLookup_.end()){
            tempCipher=CaesarCipher{Alphabet::alphabet.find(i)}; //create casesar cipher with casear key corresponding to position of vigenere key character in alphabet
            charLookup_.insert(std::make_pair(i,tempCipher)); //insert character caesar pair into lookup table
        }
    }




}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const{
    std::cout<<"This is the cipher key: "<<key_<<" to be used for ";
    switch (cipherMode){
        case CipherMode::Encrypt:
            std::cout<<"encryption"<<std::endl;
            break;
        case CipherMode::Decrypt:
            std::cout<<"decryption"<<std::endl;
            break;
    }


    std::string outputText {""};
    outputText.reserve(inputText.size());//output text will be same size as inputText

    //loop over input text, finding corresponding postion in key and finding the corresponding cipher for thaty key (using map)
    //apply encode/decode on said characther in input text and add to output text
    for (size_t i{0};i<inputText.size();i++){
        outputText+=charLookup_.at(key_[i%key_.size()]).applyCipher(std::string(1,inputText[i]),cipherMode);
    }

    return outputText;

}