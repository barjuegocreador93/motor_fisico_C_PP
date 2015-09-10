#include <allegro.h>
#include "inicia.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

/** Include tus .h **/
#include "AllegroObj.h"
//..
/** Include ends **/

int main()
{
    inicia_allegro(600,800);
    inicia_audio(70,70);/**Sonido*/

    /**Crear imagenes*/
    img buffer;
    vImg.push_back(buffer);

    vImg[0] = create_bitmap(600,800);/**Crear una imagen con tamaño de alto x ancho*/
    clear_to_color(vImg[0],0x999999);/**limpiar la imagen y darle un color*/

    textout_centre_ex(vImg[0], font,"Hola Mundo con Allegro!",160,25,0xFFFFFF,0x999999);/**Escribir un texto!*/

    blit(vImg[0],screen,0,0,0,0,600,800);
    readkey();

    /**DESTRUCTORES: */


    return 0;
}
END_OF_MAIN();
