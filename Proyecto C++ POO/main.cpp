#include <allegro.h>
#include "inicia.h"
#include <math.h>
#include "logica_juego.h"
#include "obj/obj.h"
#include "obj/universo.h"
//#include "libs.h"



/**Rpogramado por: Camilo Andrés Barbosa**/




    void fx_llenar_universo(Uni &b, ob &a)
    {

        b.crear_ob(a);
        b.crear_fondo();
        b.aplicar_gravedad(0.002);
        b.modificar_cuerpo_ob(1," ","negro");
        a.crear_ob(0,800,0,0,0,0,1200,25,0);
        a.controlado_por("maquina","estatico");
        b.crear_ob(a);
        b.modificar_cuerpo_ob(2," ","azul");



    }

 ob a(200,50,0,0,0,0,25,25,0,"humano","movible");
    Uni b(1200,913,0,0,true);

int main()
{


    /**Parte grafica: **/
    int pa=1200, pl=913;
    inicia_allegro(pa,pl);
    inicia_audio(70,70);
    fx_LOGICAJUEGO_timepo_inicializar(0,0,0,0,1);

    install_mouse();


    BITMAP *buffer = create_bitmap(pa, pl);
    clear_to_color(buffer, 0xffffff);
    blit(buffer,screen,0,0,0,0,pa,pl);
    /**------------------------------------**/



    fx_llenar_universo(b,a);
    b.pintar_uni_antes();
    while(!key[KEY_ESC])
    {
        b.actuar_juego_plano();
        b.pintar_uni();



    }




    readkey();


    destroy_bitmap(buffer);


    return 0;
}
END_OF_MAIN();
