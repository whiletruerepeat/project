#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEWER_H

#include "Image.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @class ImageViewer
 * @brief Classe permettant d'afficher une image dans une fenêtre avec zoom à l'aide de SDL2.
 *
 * Cette classe gère la création d'une fenêtre SDL, l'affichage d'une image dans celle-ci,
 * ainsi que l'application d'un zoom sur l'image.
 */
class ImageViewer {
private:
    /**
    *@details Pointeur qui pointe vers une variable de type SDL_Window, pour la fenêtre graphique.*/
    SDL_Window* window;
    /**
    *@details Pointeur qui pointe vers une variable de type SDL_Renderer, pour le rendu graphique.*/
    SDL_Renderer* renderer;
public:
    /**
    *@brief Constructeur vide d'une variable de type ImageViewer.*/
    ImageViewer();
    /**
    *@brief Destructeur d'une variable de type ImageViewer.*/
    ~ImageViewer();
    /**
    *@brief Procédure qui permet d'initialiser une fenêtre et d'afficher l'image passée en paramètre dans cette dernière.*/
    void afficher(const Image& im);

};

#endif // IMAGE_VIEWER_H
