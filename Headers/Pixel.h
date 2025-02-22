#ifndef _PIXEL_H
#define _PIXEL_H
#include <iostream>

using namespace std;
/**
 * @class Pixel
 *
 * @brief Classe contenant trois variables membres de type charact�re non sign�.
 */
struct Pixel {
    unsigned char r, g, b; /** Charact�res non sign�s */
    /**
     * @brief Constructeur vide d'une variable de type Pixel
     */
    Pixel() {
        r = 0;
        g = 0;
        b = 0;
    }
    /**
     * @brief Constructeur non vide d'une varaiable de type pixel.
     *
     * @param R Charact�re non sign� repr�sentant la couleur rouge.
     * @param G Charact�re non sign� repr�sentant la couleur verte.
     * @param B charact�re non sign� repr�sentant la couleur bleue.
     */
    Pixel(unsigned char R, unsigned char G, unsigned char B) {
        r = R;
        g = G;
        b = B;
    }
};

#endif
