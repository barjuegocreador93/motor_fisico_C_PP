/**ARQUITECTURA**/

jugador _mega_man;
img fondo =create_bitmap(640, 380);


void fx_ARQUITECTURA_juagdor()
{
    _mega_man.jugador_posicionado_en(100,200,'d');
    _mega_man.jugador_numero_imagenes_correr_der(3);
    _mega_man.jugador_numero_imagenes_correr_izq(3);
    _mega_man.jugador_numero_imagenes_quieto(2);


    _mega_man.jugador_entrar_imagen_correr_izq("megcorr5.bmp",0,120,72,79);
    _mega_man.jugador_entrar_imagen_correr_izq("megcorr2.bmp",1,100,82,79);
    _mega_man.jugador_entrar_imagen_correr_izq("megcorr1.bmp",2,100,81,79);

    _mega_man.jugador_entrar_imagen_correr_der("megcorr6.bmp",0,120,72,79);
    _mega_man.jugador_entrar_imagen_correr_der("megcorr3.bmp",1,100,82,79);
    _mega_man.jugador_entrar_imagen_correr_der("megcorr4.bmp",2,100,81,79);

    _mega_man.jugador_entrar_imagen_quieto("meg1.bmp",0,0,76,78);
    _mega_man.jugador_entrar_imagen_quieto("meg2.bmp",1,0,76,78);


}


void jugador::jugador_quieto()
{

    if(_dir=='d')
    {
        blit(_quieto[0], screen, 0, 0, _posx, _posy,76,78);
    }
    else
    {
        blit(_quieto[1], screen, 0, 0, _posx, _posy,76,78);
    }
}
void jugador::jugador_correr_de(BITMAP *_a)
{
    _posx += 40;
    blit(_a, screen, 0, 0, 0, 0, 640, 380);
    blit(_correr_derecha[0],screen,0, 0, _posx, _posy, 72,79 );
    rest(120);
    blit(_a, screen, 0, 0, 0, 0, 640, 380);
    _posx += 60;
    blit(_correr_derecha[1],screen,0, 0, _posx, _posy, 82,79 );
    rest(120);
    blit(_a, screen, 0, 0, 0, 0, 640, 380);
    _posx += 50;
    blit(_correr_derecha[2],screen,0, 0, _posx, _posy, 81,79 );
    rest(120);

}
void jugador::jugador_correr_iz(BITMAP *_a)
{
    _posx += 40;
    blit(_a, screen, 0, 0, 0, 0, 640, 380);
    blit(_correr_izquierda[0],screen,0, 0, _posx, _posy, 72,79 );
    rest(120);

    blit(_a, screen, 0, 0, 0, 0, 640, 380);
    _posx += 60;
    blit(_correr_izquierda[1],screen,0, 0, _posx, _posy, 82,79 );
    rest(120);
    blit(_a, screen, 0, 0, 0, 0, 640, 380);
    _posx += 50;
    blit(_correr_izquierda[2],screen,0, 0, _posx, _posy, 81,79 );
    rest(120);

}


void jugador::jugador_mover(BITMAP *_a)
{
    jugador_quieto();
    if(key[KEY_RIGHT])
    {
        jugador_correr_de(_a);
    }
    if(key[KEY_LEFT])
    {
        jugador_correr_iz(_a);
    }

}

