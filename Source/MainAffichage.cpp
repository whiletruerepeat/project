#include "Image.h"
#include "ImageViewer.h"

int main(int argc, char** argv) {
    Image image(12, 12);
    Pixel blanc(255, 255, 255);
    Pixel noir(0, 0, 0);
    Pixel rouge(232, 37, 37);
    Pixel beige(247, 208, 153);
    Pixel vert(166, 222, 135);
    image.effacer(vert);
    image.dessinerRectangle(1, 1, 10, 6, rouge);
    image.dessinerRectangle(1, 2, 2, 5, blanc);
    image.dessinerRectangle(4, 2, 7, 5, blanc);
    image.dessinerRectangle(9, 2, 10, 5, blanc);
    image.dessinerRectangle(2, 7, 9, 10, beige);
    image.setPix(4, 8, noir);
    image.setPix(4, 9, noir);
    image.setPix(7, 8, noir);
    image.setPix(7, 9, noir);
    ImageViewer imview;
    imview.afficher(image);
    return 0;
}
