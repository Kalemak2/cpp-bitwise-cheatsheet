#include <iostream>
#include <bitset>

unsigned int checkBit(unsigned int number, unsigned int position) {
    std::cout << "\n--- Sprawdzanie bitu ---\n";
    std::cout << "Liczba wejsciowa (8 bitow):      " << std::bitset<8>(number) << '\n';
    std::cout << "Po przesunieciu w prawo:         " << std::bitset<8>(number >> position) << '\n';
    std::cout << "Po nalozeniu maski (& 1):        " << std::bitset<8>((number >> position) & 1u) << '\n';
    return (number >> position) & 1u;
}

unsigned int setBitToOne(unsigned int number, unsigned int position) {
    unsigned int mask = 1u << position;
    std::cout << "\n--- Ustawianie bitu na 1 ---\n";
    std::cout << "Liczba wejsciowa (8 bitow):      " << std::bitset<8>(number) << '\n';
    std::cout << "Maska (1 << pozycja):            " << std::bitset<8>(mask) << '\n';
    std::cout << "Wynik po operacji OR (| maska):  " << std::bitset<8>(number | mask) << '\n';
    return number | mask;
}

unsigned int clearBit(unsigned int number, unsigned int position) {
    unsigned int mask = 1u << position;
    std::cout << "\n--- Zerowanie bitu (ustawianie na 0) ---\n";
    std::cout << "Liczba wejsciowa (8 bitow):      " << std::bitset<8>(number) << '\n';
    std::cout << "Odwrocona maska (~maska):        " << std::bitset<8>(~mask) << '\n';
    std::cout << "Wynik po operacji AND (& ~maska):" << std::bitset<8>(number & ~mask) << '\n';
    return number & ~mask;
}

unsigned int flipBit(unsigned int number, unsigned int position) {
    unsigned int mask = 1u << position;
    std::cout << "\n--- Odwracanie pojedynczego bitu ---\n";
    std::cout << "Liczba wejsciowa (8 bitow):      " << std::bitset<8>(number) << '\n';
    std::cout << "Maska (1 << pozycja):            " << std::bitset<8>(mask) << '\n';
    std::cout << "Wynik po operacji XOR (^ maska): " << std::bitset<8>(number ^ mask) << '\n';
    return number ^ mask;
}

unsigned int flipAllBits(unsigned int number) {
    std::cout << "\n--- Odwracanie wszystkich bitow (maska 8-bitowa) ---\n";
    std::cout << "Liczba wejsciowa (8 bitow):      " << std::bitset<8>(number) << '\n';
    std::cout << "Wynik po operacji NOT (~):       " << std::bitset<8>(~number) << '\n';
    return (~number) & 0xFF;
}

int main() {
    unsigned int number = 0;
    unsigned int position = 0;

    std::cout << "Podaj liczbe calkowita nieujemna: ";
    std::cin >> number;

    std::cout << "Podaj indeks bitu do operacji (0-31, liczac od prawej): ";
    std::cin >> position;

    if (position >= 32) {
        std::cout << "Blad: indeks bitu musi miescic sie w przedziale 0-31.\n";
        return 1;
    }

    unsigned int bit = checkBit(number, position);
    std::cout << "Wartosc bitu na pozycji " << position << ": " << bit << '\n';

    unsigned int updatedNumber = setBitToOne(number, position);
    std::cout << "Wartosc dziesietna po ustawieniu bitu na 1: " << updatedNumber << '\n';

    updatedNumber = clearBit(number, position);
    std::cout << "Wartosc dziesietna po wyzerowaniu bitu: " << updatedNumber << '\n';

    updatedNumber = flipBit(number, position);
    std::cout << "Wartosc dziesietna po odwroceniu bitu: " << updatedNumber << '\n';

    updatedNumber = flipAllBits(number);
    std::cout << "Wartosc dziesietna po odwroceniu 8 mlodszych bitow: " << updatedNumber << '\n';

    return 0;
}