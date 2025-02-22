#ifndef _IMAGE_H
#define _IMAGE_H
#include "Pixel.h"

using namespace std;

/**
* @class Image
* @brief Une classe représentant une image */
class Image {
private:
    /**
    *@details Tableau contenant des variables de type Pixel.*/
    Pixel* tab;
    /**
    *@details Dimensions du tableau (Variables de type entier non signé*/
    unsigned int dimx, dimy;
public:
    /**
    *@brief Constructeur de la classe Image sans paramètres */
    Image();
    /**
    * @brief Constructeur n°2 de la classe Image avec des paramètres
    * @param dX taille max du tableau de pixels en X
    * @param dY taille max du tableau de pixels en Y */
    Image(unsigned int dX, unsigned int dY);
    /**
    * @brief Destructeur de la classe Image */
    ~Image();
    /**
    * @brief Fonction retournant le Pixel aux coordonnées données ou sinon un pixel noir en retour
    * @param X point en X
    * @param Y point en Y
    * @return Pixel */
    Pixel& getPix(unsigned int x, unsigned int y);
    /**
    * @brief Fonction retournant le Pixel (par copie) aux coordonnées données ou sinon un pixel noir en retour
    * @param X point en X
    * @param Y point en Y
    * @return Pixel */
    Pixel getPix(unsigned int x, unsigned int y) const;
    /**
    * @brief Fonction modifiant le Pixel aux coordonnées données par le Pixel fourni
    * @param X point en X
    * @param Y point en Y */
    void setPix(unsigned int x, unsigned int y, const Pixel& c);
    /**
    * @brief Fonction déssinant un rectangle de taille (Xmin,Ymin) - (Xmax, Ymax)
    * @param Xmin premier point X
    * @param Ymin premier point Y
    * @param Xmax second point X
    * @param Ymax second point Y */
    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel c);

    /**
    *@brief Fonction qui efface l'image en la remplissant de la couleur en paramètre
    *@param c un pixel */
    void effacer(Pixel c);

    /**
     * @brief Récupère la dimension des x de l'image.
     */
    unsigned int getWidth() const;

    /**
     * @brief Récupère la dimension des y de l'image.
     */
    unsigned int getHeight() const;
    /**
    *@brief Sauvegarde l'image dans le fichier choisi.
    *@param filename Chemin vers le fichier.*/
    void sauver(const string& filename) const;
    /**
    *@brief Charge l'image se trouvant dans un fichier.
    *@param filename Chemin vers le fichier.*/
    void ouvrir(const string& filename);
    /**
    *@brief Affiche chaque pixel de l'image dans le terminal*/
    void afficherConsole();
    /**
    *@brief Fonction qui teste toute les fonctions membres de la classe pour s'assurer qu'elles ne provoquent pas d'erreur.*/
    static void testRegression();
};



#endif

