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
    setBitmap my_imgs;
    my_imgs.create_new_bitmap(600,800,0x999999);
    my_imgs.text_over(0,"Hola mundo con Allegro Obj!!",160,25,0xFFFFFF,0x999999);
    my_imgs.print(0,0,0,0,0,600,800);

    readkey();

    return 0;
}
END_OF_MAIN();
