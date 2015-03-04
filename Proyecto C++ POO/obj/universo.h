#ifndef UNIVERSO_H_INCLUDED
#define UNIVERSO_H_INCLUDED


class Uni
{


public:
    Uni(int=0,int=0,int=0,int=0,bool=false);
    ~Uni();
    void crear_ob(ob _nuevo_ob);
    void modficar_fisicas();
    void actuar_fisicas();
    void crear_fondo();
    void pintar_uni();
    void aplicar_gravedad(double);
    void pintar_uni_antes();
    void actuar_juego_plano();

    double devover_x(int n);
    double devover_y(int n);


    bool colicion_obs_uni_de(ob &_objeto);
    bool colicion_obs_uni_iz(ob &_objeto);
    bool colicion_obs_uni_ar(ob &_objeto);
    bool colicion_obs_uni_ab(ob &_objeto);


    void modificar_cuerpo_ob(int, string, string);


private:
    int _x, _y;
    int ancho, largo;
    struct nodo_ob
    {
        ob _objeto;
        int tiempo;
        int cont, reb;
        struct nodo_ob *sig;
    }*prim, *ultim, *nuevo;


    double gravedad;
    img fondo;
    bool fisicas;

};

Uni::~Uni()
{
    nodo_ob *aux, *aux2=prim->sig;
    aux=prim;
    while(aux2!=NULL)
    {
        if(aux2==ultim)
        {
            aux->sig=NULL;
            delete ultim;
            ultim=aux;
            aux2=prim->sig;
        }
        aux2=aux2->sig;
        aux=aux->sig;

    }
    delete prim;
destroy_bitmap(fondo);



}
Uni::Uni(int _ancho,int _largo,int _posicion_x,int _posicion_y, bool _activar_fiscas_bool)
{
    ancho=_ancho;
    largo=_largo;
    prim=ultim=NULL;
    fondo=NULL;
    fisicas=_activar_fiscas_bool;
    _x=_posicion_x;
    _y=_posicion_y;

}
void Uni::crear_ob(ob _nuevo_ob)
{
    nuevo = new nodo_ob;
    nuevo->_objeto=_nuevo_ob;
    nuevo->sig=NULL;
    nuevo->cont=nuevo->tiempo=0;
    nuevo->reb=3;
    if(prim==NULL)
    {
        prim=nuevo;
    }
    else
    {
        ultim->sig=nuevo;

    }
    ultim=nuevo;
}
bool Uni::colicion_obs_uni_ab(ob &_objeto)
{
    nodo_ob *aux=prim;
    double tamax=_objeto._x+_objeto.ancho;
    double tamay=_objeto._y+_objeto.largo;
    double px=_objeto._x;
    if(_objeto._y>largo + _y)
        {
            if(fisicas){_objeto._y=(largo + _y) - _objeto.largo ;
            aux->cont++;}
            return 1;
        }
    while(aux!=NULL)
    {
        double _tamax=aux->_objeto._x+aux->_objeto.ancho-1;
        double _tamay=aux->_objeto._y+aux->_objeto.largo;
        double _px=aux->_objeto._x+1;


        if(tamay==aux->_objeto._y&&((tamax<=_tamax&&tamax>=_px)||(px<=_tamax&&px>=_px)||tamax-1==_tamax))
        {

            return 1;
        }
        aux=aux->sig;
    }
    return 0;
}
bool Uni::colicion_obs_uni_ar(ob &_objeto)
{
    nodo_ob *aux=prim;
    double tamax=_objeto._x+_objeto.ancho;
    double tamay=_objeto._y;
    double px=_objeto._x;
    if(tamay<=_y)return 1;
    while(aux!=NULL)
    {
        double _tamax=aux->_objeto._x+aux->_objeto.ancho-1;
        double _tamay=aux->_objeto._y+aux->_objeto.largo;
        double _px=aux->_objeto._x+1;


        if(tamay==_tamay&&((tamax<=_tamax&&tamax>=_px)||(px<=_tamax&&px>=_px)||tamax-1==_tamax))return 1;
        aux=aux->sig;
    }
    return 0;
}
bool Uni::colicion_obs_uni_de(ob &_objeto)
{
    nodo_ob *aux=prim;
    double tamax=_objeto._x+_objeto.ancho;
    double tamay=_objeto._y+_objeto.largo;
    double py=_objeto._y;
    if(tamax>=ancho)
        return 1;

    while(aux!=NULL)
    {
        double _tamax=aux->_objeto._x;
        double _tamay=aux->_objeto._y+aux->_objeto.largo-1;
        double _py=aux->_objeto._y+1;


        if(tamax==_tamax&&((tamay<=_tamay&&tamay>=_py)||(py<=_tamay&&py>=_py)||tamay-1==_tamay))return 1;
        aux=aux->sig;
    }
    return 0;
}
bool Uni::colicion_obs_uni_iz(ob &_objeto)
{
    nodo_ob *aux=prim;
    double tamax=_objeto._x;
    double tamay=_objeto._y+_objeto.largo;
    double py=_objeto._y;
    if(tamax<=_x)return 1;
    while(aux!=NULL)
    {
        double _tamax=aux->_objeto._x+aux->_objeto.ancho;
        double _tamay=aux->_objeto._y+aux->_objeto.largo-1;
        double _py=aux->_objeto._y+1;


        if(tamax==_tamax&&((tamay<=_tamay&&tamay>=_py)||(py<=_tamay&&py>=_py)||tamay-1==_tamay))return 1;
        aux=aux->sig;
    }
    return 0;
}


void Uni::actuar_juego_plano()
{
    nodo_ob *aux=prim;/**Primera fisica: gravedad***/
    while(aux!=NULL)
    {
        if(aux->_objeto.contro=="humano"&&aux->_objeto.estado=="movible"){
            if(key[KEY_LEFT]&&!colicion_obs_uni_iz(aux->_objeto)){aux->_objeto._x -= aux->_objeto.Vx;aux->_objeto.mov_iz=true;aux->_objeto.mov_de=false;}
            if(key[KEY_RIGHT]&&!colicion_obs_uni_de(aux->_objeto)){aux->_objeto._x += aux->_objeto.Vx;aux->_objeto.mov_iz=false;aux->_objeto.mov_de=true;}
            if(key[KEY_UP]&&!colicion_obs_uni_ar(aux->_objeto)){aux->_objeto._y -= aux->_objeto.Vy;aux->_objeto.mov_ar=true;aux->_objeto.mov_ab=false;}
            if(key[KEY_DOWN]&&!colicion_obs_uni_ab(aux->_objeto)){aux->_objeto._y += aux->_objeto.Vy;aux->_objeto.mov_ar=false;aux->_objeto.mov_ab=true;}
            if(key[NULL]) {aux->_objeto.Vx;aux->_objeto.mov_iz=false;aux->_objeto.mov_de=false;
                    aux->_objeto.Vy;aux->_objeto.mov_ar=false;aux->_objeto.mov_ab=false;}
            aux->_objeto.Vx=10;
            aux->_objeto.Vy=10;

        }


            aux=aux->sig;


    }


}
void Uni::actuar_fisicas()
{

   nodo_ob *aux=prim;
   while(aux!=NULL)
    {
        if(aux->_objeto.estado=="movible"&&fisicas)
        {



            if(!colicion_obs_uni_ab(aux->_objeto)&&aux->_objeto.mov_ar||aux->_objeto.mov_ab)
            {
                aux->_objeto.Vy= aux->_objeto.Vy + (gravedad * aux->tiempo *  aux->tiempo )/2;
                aux->_objeto.mov_ab=true;
                aux->_objeto.mov_ar=false;
            }
            else
            {

                if(aux->cont!=aux->reb)
                {
                    aux->_objeto.Vy= - aux->_objeto.Vy + (gravedad * aux->tiempo * aux->tiempo)/2;
                    aux->_objeto.mov_ab=false;
                    aux->_objeto.mov_ar=true;
                }
                else
                {
                    aux->_objeto.Vy=0;
                    aux->cont=0;
                    aux->tiempo=0;
                    aux->_objeto.mov_ab=false;
                    aux->_objeto.mov_ar=false;
                }
            }



            if(aux->_objeto.mov_iz||aux->_objeto.mov_de)aux->_objeto._x= aux->_objeto._x + aux->_objeto.Vx;
            if(aux->_objeto.mov_ar||aux->_objeto.mov_ab)aux->_objeto._y= aux->_objeto._y + aux->_objeto.Vy;
            aux->tiempo++;



        }
        else
        {
                    aux->_objeto.mov_ab=false;
                    aux->_objeto.mov_ar=false;
                    aux->_objeto.mov_iz=false;
                    aux->_objeto.mov_de=false;
        }

        aux=aux->sig;
    }


}




void Uni::crear_fondo()
{
    fondo = create_bitmap(ancho, largo);
    clear_to_color(fondo, 0xffffff);
}
void Uni::modificar_cuerpo_ob(int _posicion, string _tipo_de_bitmap, string _color)
{
   nodo_ob *aux=prim;
   int i=0;
   while(aux!=NULL)
   {
       i++;
       if(i==_posicion)
       {
           aux->_objeto.cuerpo_buffer(_color);

       }
       aux=aux->sig;
   }
}



void  Uni::pintar_uni_antes()
{
    nodo_ob *aux=prim;
    while(aux!=NULL)
    {
        aux->_objeto.pintar_ob();
        aux=aux->sig;
    }
}
void Uni::pintar_uni()
{
    nodo_ob *aux=prim;
    pintar_uni_antes();

    while(aux!=NULL)
    {

        if(aux->_objeto.mov_ab||aux->_objeto.mov_ar||aux->_objeto.mov_iz||aux->_objeto.mov_de)
        {
            blit(fondo,screen,0,0,_x,_y,ancho,largo);
            aux->_objeto.pintar_ob();
            rest(100);




        }


        if(aux!=NULL)aux=aux->sig;
    }
}
void Uni::aplicar_gravedad(double _gravedad)
{
    gravedad=_gravedad;
}

#endif // UNIVERSO_H_INCLUDED
