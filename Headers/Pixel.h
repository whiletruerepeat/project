#ifndef _PIXEL_H
#define _PIXEL_H
#include <iostream>

using namespace std;
/**
 * @class Pixel
 *
 * @brief Classe contenant trois variables membres de type charactère non signé.
 */
struct Pixel {
    unsigned char r, g, b; /** Charactères non signés */
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
     * @param R Charactère non signé représentant la couleur rouge.
     * @param G Charactère non signé représentant la couleur verte.
     * @param B charactère non signé représentant la couleur bleue.
     */
    Pixel(unsigned char R, unsigned char G, unsigned char B) {
        r = R;
        g = G;
        b = B;
    }
};

#endif
