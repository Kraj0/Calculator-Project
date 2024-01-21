#include "pch.h"
#include "conver.h"
#include <iostream>
#include <string>

//plik zawiera metody konwersji liczbowej: z jakiegokolwiek systemu na dziesiêtny a nastêpnie z dziesiêtnego na jakikolwiek

using std::endl;
using std::string;

string conver::binary2decimal(const std::string& bin) { //uzycie funkcji string to int do konwersji liczby binarnej na dziesietna
    int dec = std::stoi(bin, nullptr, 2);
    string str = std::to_string(dec);
    return str;
}

string conver::oct2decimal(const std::string& oct) {
    int dec = std::stoi(oct, nullptr, 8);  //uzycie funkcji string to int do konwersji liczby osemkowej na dziesietna
    string str = std::to_string(dec);
    return str;
}

string conver::hex2decimal(const std::string& hex) {

    int dec = 0;

    for (int i = hex.size() - 1, pwr = 0; i >= 0; --i, ++pwr) {
        char ch = hex[i];
        int h_num;

        if (ch >= '0' && ch <= '9') {
             h_num = ch - '0';
        }
        else if (ch >= 'A' && ch <= 'F') {   //duze litery
            h_num = ch - 'A' + 10;
        }
        else if (ch >= 'a' && ch <= 'f') {   //male litery
            h_num = ch - 'a' + 10;
        }
        else {
            std::string error = "error";
            return error;
        }
        dec += h_num * static_cast<int>(std::pow(16, pwr));
    }
    string decim = std::to_string(dec);
    return decim;
}

string conver::decimal2binary(const std::string& dec) {


    if (dec == "error") {
        std::string error = "error, possibly wrong number input";
        return error;
    }

    int dec_int = std::stoi(dec);
    if (dec_int == 0) {
        string binary = "0";
        return binary;
    }

    string binary;
    while (dec_int != 0) {
        binary = (dec_int & 1 ? "1" : "0") + binary; //sprawdzanie czy najmniej znacz¹cy bit wynosi 1 lub 0
        dec_int >>= 1;
    }

    return binary;
}

string conver::decimal2oct(const std::string& dec) {     //inspiracja kodem programiz, kod zosta³ rozszerzony i zmodyfikowany do u¿ycia w moim programie
    if (dec == "error") {
        std::string error = "error, possibly wrong number input";
        return error;
    }

    int dec_int = std::stoi(dec);   //string to int aby funkcja mogla pobierac stringa a przeliczala na intach
    int remnant, i = 1, oct = 0; //(rem -> reszta)
    while (dec_int != 0)
    {
        remnant = dec_int % 8;
        dec_int /= 8;
        oct += remnant * i;
        i *= 10;
    }
    string octal = std::to_string(oct);
    return octal;   //zwraca stringa
}

string conver::decimal2hex(const std::string& dec) {   //funkcja zainspirowana kodem ze strony geeksforgeeks, jednak zmodyfikowana do u¿ycia w moim programie
    if (dec == "error") {
        std::string error = "error, possibly wrong number input";
        return error;
    }

    int dec_int = std::stoi(dec);
    string hex;

    if (dec_int == 0) {
        hex = "0";
        return hex;
    }

    while (dec_int != 0) {
        int remnant = 0;
        char c;
        remnant = dec_int % 16;
        if (remnant < 10) {
            c = remnant + 48;
        }
        else {
            c = remnant + 55;
        }
        hex += c;
        dec_int = dec_int / 16;
    }
    int i = 0, j = hex.size() - 1;

    while (i <= j)   //odwrócenie stringa 
    {
        std::swap(hex[i], hex[j]);
        i++;
        j--;
    }
    return hex; //finalny wynik
}
