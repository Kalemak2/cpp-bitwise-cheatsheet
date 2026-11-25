# C++ Bitwise Operations Cheatsheet

Prosty program konsolowy w C++ demonstrujący w praktyce działanie podstawowych operatorów bitowych oraz masek z wizualizacją binarną krok po kroku (`std::bitset`).

## Zaimplementowane operacje

| Funkcja | Operacja | Wzór | Opis |
| :--- | :--- | :--- | :--- |
| `checkBit` | Sprawdzenie bitu | `(number >> pos) & 1u` | Odczytuje wartość bitu (`0` lub `1`) na wybranej pozycji |
| `setBitToOne` | Ustawienie bitu | `number \| (1u << pos)` | Włącza wybrany bit (ustawia na `1`) |
| `clearBit` | Wyzerowanie bitu | `number & ~(1u << pos)` | Wyłącza wybrany bit (ustawia na `0`) |
| `flipBit` | Odwrócenie bitu | `number ^ (1u << pos)` | Przełącza wybrany bit (`0` → `1`, `1` → `0`) |
| `flipAllBits` | Negacja bitowa | `(~number) & 0xFF` | Odwraca wszystkie bity (maska na 8 młodszych bitów) |
