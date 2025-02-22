#include "Image.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

Image::Image(){
    dimx = 0;
    dimy = 0;
    tab = nullptr;
}
    
Image::Image(unsigned int dX, unsigned int dY){ 
    dimx = dX;
    dimy = dY;
    tab = new Pixel [dimx*dimy];
}
    
Image::~Image(){
    dimx = 0;
    dimy = 0;
    if(&tab[0]!=nullptr){
    delete [] tab; 
}
}
    
Pixel &Image::getPix(unsigned int x, unsigned int y){
    assert(x>=0 && x<dimx && y>=0 && y<dimy);
    return tab[y*dimx+x];
}
    
Pixel Image::getPix(unsigned int x, unsigned int y) const{
    assert(x<dimx && y<dimy);
    return tab[y*dimx+x];
}
    
void Image::setPix(unsigned int x,  unsigned int y, const Pixel &c)
{
    assert(x<dimx && y<dimy);
    tab[y*dimx+x] = c;
}

void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel c){
    assert(Xmin<Xmax && Ymin<Ymax && Xmax<dimx && Ymax<dimy);
    for (unsigned int x = Xmin; x<=Xmax; x++)
    {
        for(unsigned int y = Ymin; y<=Ymax; y++){
            setPix(x, y, c);
        }
    } 
}

void Image::effacer(Pixel c){
    dessinerRectangle(0, 0, dimx-1, dimy-1, c);
}
    

void Image::testRegression(){
    Image * im1 = new Image;
    cout<<"Déclaration im1 pointeur de type Image OK."<<endl;
    Image * im2 = new Image(20, 20);
    cout<<"Déclaration im2 pointeur de type Image avec dimensions x = 20 | y = 20 OK."<<endl;
    assert(im1->dimx == 0 && im1->dimy == 0);
    cout<<"Tests dimensions im1 OK."<<endl;
    assert(im2->dimx == 20 && im2->dimy == 20);
    cout<<"Tests dimensions im2 OK."<<endl;
    im2->getPix(15, 15);
    cout<<"Test fonction getPix OK."<<endl;
    im2->setPix(10, 10, {255, 255, 255});
    cout<<"Test fonction setPix OK."<<endl;
    assert(im2->tab[10*im2->dimx+10].r == 255 && im2->tab[10*im2->dimx+10].g == 255 && im2->tab[10*im2->dimx+10].b == 255);
    cout<<"Vérification du fonctionnement de setPix dans le tableau de pixel OK."<<endl;
    im2-> dessinerRectangle(2, 4, 8, 9, {255, 255, 255});
    cout<<"Test fonction dessinerRectangle OK."<<endl;
    assert(im2->tab[4*im2->dimx+2].r == 255 && im2->tab[4*im2->dimx+2].g == 255 && im2->tab[4*im2->dimx+2].b == 255);
    cout<<"Vérification du fonctionnement de dessinerRectangle dans le tableau de pixel OK."<<endl;
    im2->effacer({0, 0, 0});
    cout<<"Test fonction effacer OK."<<endl;
    assert(im2->tab[10*im2->dimx+10].r == 0 && im2->tab[10*im2->dimx+10].g == 0 && im2->tab[10*im2->dimx+10].b == 0);
    cout<<"Vérification de l'effacement de l'image suite à l'appel de la fonction effacer OK."<<endl;
    delete im1;
    cout<<"Destruction de im1 OK."<<endl;
    delete im2;
    cout<<"Destruction de im2 OK."<<endl;
    im1 = nullptr;
    cout<<"nullptr assigné au pointeur im1 OK."<<endl;
    im2 = nullptr;
    cout<<"nullptr assigné au pointeur im2 OK."<<endl;
}

void Image::sauver(const string &filename) const
{
    ofstream fichier(filename.c_str());
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << endl;
        return;
    }
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for (unsigned int y = 0; y < dimy; ++y)
        for (unsigned int x = 0; x < dimx; ++x)
        {
            Pixel pix = getPix(x, y);
            fichier << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}
void Image::ouvrir(const string &filename)
{
    ifstream fichier(filename.c_str());
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << endl;
        return;
    }
    char r, g, b;
    string mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    if (tab != nullptr)
        delete[] tab;
    tab = new Pixel[dimx * dimy];
    for (unsigned int y = 0; y < dimy; ++y)
        for (unsigned int x = 0; x < dimx; ++x)
        {
            fichier >> r >> g >> b;
            getPix(x, y).r = r;
            getPix(x, y).g = g;
            getPix(x, y).b = b;
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}
void Image::afficherConsole()
{
    cout << dimx << " " << dimy << endl;
    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            Pixel pix = getPix(x, y);
            cout << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
        cout << endl;
    }
}

unsigned int Image::getWidth() const{
    return dimx;
}

unsigned int Image::getHeight() const{
    return dimy;
}
