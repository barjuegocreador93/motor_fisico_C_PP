#include <allegro.h>
#include "inicia.h"
#include <math.h>
//#include "libs.h"

typedef BITMAP *img;

/**Rpogramado por: Camilo Andrés Barbosa**/


int main()
{
    /**Parte grafica: **/
    int pa=1200, pl=913;
    inicia_allegro(pa,pl);
    inicia_audio(70,70);

    install_mouse();


    BITMAP *buffer = create_bitmap(pa, pl);
    clear_to_color(buffer, 0xffffff);
    blit(buffer,screen,0,0,0,0,pa,pl);
    /**------------------------------------**/

    /**Tamaño del cuerpo: ancho, largo */
    double a=25,l=25;
    /**gravedad, suelo ancho, suelo largo, sulo en eje y**/
    double g=9.81, sa=pa, sl=25, sy=800;
    /**(posicion (x, y) Velocidad( x, y), Aceleracion(x, y)) del cuerpo)**/
    double x=300, y=12, Vx=0, Vy=0;
    double u=0.0002,  m=55, fr=u*m*g;
    double t;
    double reb=5, cont=0;


    /**Parte Grafica: **/
    img mak=create_bitmap(a,l), suelo=create_bitmap(pa,25);
    clear_to_color(mak, 0x265445);
    clear_to_color(suelo, 0x262595);
    blit(mak,screen,0,0,x,y,a,l);

    img cursor =  load_bitmap("cursor.bmp",NULL);
    /**-------------------------**/

    while(!key[KEY_ESC])/**Ciclo Universal**/
    {


        {
            /**EL EJE Y ESTA INVERTIDO*/
            if(Vx>0)fr=-u*m*g;
                else if(Vx<0)fr=u*m*g;

            if(x>=0&&x<=pa-a-1)x = x + Vx;/**Movimiento de x a razon del la velocidad cuando el
                                        cuerpo es difenrente a las paredes de la ventana**/
            else if(x<0){Vx=-Vx;x=1;}/**Colisiones de la ventana**/
                    else if(x>=pa-a-1){Vx= -Vx;x=pa-a-1;}


            if(y==sy-a)Vx= Vx + fr;

            if(y<=sy-a)y = y + Vy;/**Movimiento de y a razon del la velocidad
                                cuando el cuerpo esta sobre el suelo o por ensima de él**/

            if(y<sy-a)
            {
                Vy= Vy + (g*t*t/2);
            }/**La velocidad de la dsitancia de la caida libre
                                            esta es positiva a estar sobre el suelo**/
            else /**Si la psocion y traspasa la psocion del suelo*/
            {
                if(y>sy-a)
                {
                    y=sy-a;
                    cont++;
                }/**El limite de y es cuando toca el suelo
                                                y se mira cuantas veces lo toca
                                                para determinar el numero de los rebotes**/
                if(cont!=reb)Vy = - Vy + (g*t*t/2);/***/
                else {Vy=0;t=0;}
            }


            if(key[KEY_SPACE])
            {
                if(y==sy-a)
                {
                    Vy=0;

                    Vy = Vy - 100;/**Vlocidad incial al saltar**/


                        t=0;/**fin del moviminto para el tiempo*/
                        cont=0;

                }
            }
            if(key[KEY_LEFT])
            {
                if(x>=0&&x<=pa-a&&(y==sy-a))Vx=-10;

            }
            else if(key[KEY_RIGHT])
            {
                if(x>=0&&x<=pa-a&&(y==sy-a))Vx=10;
            }


            /**Parte Grafica: **/
            if (Vx!=0||Vy!=0)
                {
                    rest(100);
                    blit(buffer,screen,0,0,0,0,pa,pl);
                    blit(suelo,screen,0,0,0,sy,sa,sl);
                }



            if(Vy!=0 || Vx !=0 || cont==reb)
                {blit(mak,screen,0,0,x,y,a,l);}


            masked_blit(cursor,screen,0,0,mouse_x,mouse_y,13,22);
            /**-------------------------**/


            t++;




        }


    }



    readkey();

    destroy_bitmap(buffer);
    destroy_bitmap(suelo);
    destroy_bitmap(mak);


    return 0;
}
END_OF_MAIN();
