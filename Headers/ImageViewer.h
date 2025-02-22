#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEWER_H

#include "Image.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @class ImageViewer
 * @brief Classe permettant d'afficher une image dans une fen�tre avec zoom � l'aide de SDL2.
 *
 * Cette classe g�re la cr�ation d'une fen�tre SDL, l'affichage d'une image dans celle-ci,
 * ainsi que l'application d'un zoom sur l'image.
 */
class ImageViewer {
private:
    /**
    *@details Pointeur qui pointe vers une variable de type SDL_Window, pour la fen�tre graphique.*/
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
    *@brief Proc�dure qui permet d'initialiser une fen�tre et d'afficher l'image pass�e en param�tre dans cette derni�re.*/
    void afficher(const Image& im);

};

#endif // IMAGE_VIEWER_H
