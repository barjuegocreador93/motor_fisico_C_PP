#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED

typedef BITMAP *img;
class Uni;

class ob
{
public:
    ob(double=0, double=0, double=0, double=0, double=0, double=0, int=0, int=0, double=0, string="humano", string="movible");
    ~ob(){destroy_bitmap(cuerpo);}
    void crear_ob(double _posicion_x, double _posicion_y, double _velocidad_x, double _velocidad_y, double _acceleracion_x, double _acceleracion_y, int _ancho, int _largo, double _coeficinte_de_friccion);
    void entrar_cuerpo(char *_dirrecion_foto);
    void controlado_por(string _control, string _estado);
    void cuerpo_buffer(string _color);
    void pintar_ob();
    ob &operator=(ob &_otro);
    bool coliciones(ob _objeto2);
    bool coliciones_ar(ob _objeto2);
    bool coliciones_ab(ob _objeto2);
    bool coliciones_iz(ob _objeto2);
    bool coliciones_de(ob _objeto2);


private:
    double fr, u;
    double _x, _y;
    double Vx, Vy;
    double Ax, Ay;
    int ancho, largo;
    img cuerpo;
    string contro, estado;
    bool mov_ar, mov_ab, mov_iz, mov_de;
    friend class Uni;
};
ob::ob(double _posicion_x, double _posicion_y, double _velocidad_x, double _velocidad_y, double _acceleracion_x, double _acceleracion_y, int _ancho, int _largo, double _coeficinte_de_friccion, string _control,string _estado)
{
    crear_ob(_posicion_x,  _posicion_y,  _velocidad_x,  _velocidad_y, _acceleracion_x, _acceleracion_y,  _ancho, _largo, _coeficinte_de_friccion);
    controlado_por(_control,_estado);
}
void ob::crear_ob(double _posicion_x, double _posicion_y, double _velocidad_x, double _velocidad_y, double _acceleracion_x, double _acceleracion_y, int _ancho, int _largo,double _coeficinte_de_friccion)
{
    _x=_posicion_x;
    _y=_posicion_y;
    Vx=_velocidad_x;
    Vy=_velocidad_y;
    Ax=_acceleracion_x;
    Ay=_acceleracion_y;
    u=_coeficinte_de_friccion;
    ancho=_ancho;
    largo=_largo;
    cuerpo=NULL;
    if(Vx==0){fr=0;mov_iz=false;mov_de=false;}
    else if(Vx>0)mov_de=true;
    else{mov_de=false;}
    if(Vx<0)mov_iz=true;
    if(Vy==0){mov_ab=false;mov_ar=false;}
    else if(Vy>0){mov_ab=true;}
    else mov_ar=true;


}
void ob::entrar_cuerpo(char *_dirrecion_foto)
{
    cuerpo = load_bitmap(_dirrecion_foto,NULL);

}
void ob::pintar_ob()
{
    blit(cuerpo,screen,0,0,_x,_y,ancho,largo);

}
ob &ob::operator=(ob &_otro)
{
    fr=_otro.fr;
    _x=_otro._x;
    _y=_otro._y;
    Vx=_otro.Vx;
    Vy=_otro.Vy;
    Ax=_otro.Ax;
    Ay=_otro.Ay;
    contro=_otro.contro;
    estado=_otro.estado;
    u=_otro.u;
    ancho=_otro.ancho;
    largo=_otro.largo;

    cuerpo=NULL;
    if(Vx==0){fr=0;mov_iz=false;mov_de=false;}
    else if(Vx>0)mov_de=true;
    else{mov_de=false;}
    if(Vx<0)mov_iz=true;
    if(Vy==0){mov_ab=false;mov_ar=false;}
    else if(Vy>0){mov_ab=true;}
    else mov_ar=true;

    return *this;

}
void ob::controlado_por(string _control,string _estado)
{
    contro=_control;
    estado=_estado;
}
void ob::cuerpo_buffer(string _color)
{
    cuerpo= create_bitmap(ancho, largo);
    if(_color=="negro")
         clear_to_color(cuerpo, 0x000000);
    if(_color=="azul")
        clear_to_color(cuerpo, 0x262595);
}

bool ob::coliciones(ob _objeto2)
{

   if(coliciones_ab(_objeto2)||coliciones_ar(_objeto2)||coliciones_iz(_objeto2)||coliciones_de(_objeto2))
    return 1;

    return 0;
}

bool ob::coliciones_ar(ob _objeto2)
{
    if(_y<=_objeto2._y+largo&&(_x+ancho>=_objeto2._x&&_x<=_objeto2._x+_objeto2.ancho))return 1;
    return 0;
}
bool ob::coliciones_ab(ob _objeto2)
{

    if(_y+largo+1==_objeto2._y&&(_x+ancho>=_objeto2._x&&_x<=_objeto2._x+_objeto2.ancho))return 1;
    return 0;
}
bool ob::coliciones_iz(ob _objeto2)
{
    if(_x-1==_objeto2._y+ancho&&(_y+largo>=_objeto2._y&&_y<=_objeto2._y+_objeto2.ancho))return 1;
    return 0;
}
bool ob::coliciones_de(ob _objeto2)
{
    if(_x+ancho+1==_objeto2._x&&(_y+largo>=_objeto2._y&&_y<=_objeto2._y+_objeto2.ancho))return 1;
    return 0;
}


#endif // OBJ_H_INCLUDED
