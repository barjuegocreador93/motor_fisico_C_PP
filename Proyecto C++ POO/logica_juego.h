/**LOGICAJUEGO_ **/
/***Aquí se programo la variables de tiempo, variables de ubicacion del nivel y su construccion en pantalla, variables de teclado**/
#include<iostream>
#include<string>
using namespace std;


int _LOGICAJUEGO_dia_int, _LOGICAJUEGO_hora_int, _LOGICAJUEGO_minutos_int, _LOGICAJUEGO_segundos_int, _LOGICAJUEGO_milesimas_int;

int _LOGICAJUEGO_nivel_actual_int;
bool _LOGICAJUEGO_reinciar_juego=true;
bool _LOGICAJUEGO_reloj_pintado_bool=true;
bool _LOGICAJUEGO_nivel_actual_mostrado_bool=false;
bool _LOGICAJUEGO_fin_juego_bool_no=true;


/**funciones de inicializacion y de procesos basicos del juego explicadas en el .cpp**/
void fx_LOGICAJUEGO_timepo_inicializar(int _milesimas, int _segundos, int _minutos, int _horas, int _dia)
{
    _LOGICAJUEGO_dia_int=(_dia>0&&_dia<=7)?_dia:1;
    _LOGICAJUEGO_milesimas_int=(_milesimas>=0&&_milesimas<100)?_milesimas:0;
    _LOGICAJUEGO_segundos_int=(_segundos>=0&&_segundos<60)?_segundos:0;
    _LOGICAJUEGO_minutos_int=(_minutos>=0&&_minutos<60)?_minutos:0;
    _LOGICAJUEGO_hora_int=(_horas>=0&&_horas<24)?_horas:0;

}



void fx_LOGICAJUEGO_tiempo_corre()
{

    if(_LOGICAJUEGO_milesimas_int==100)
    {
        _LOGICAJUEGO_milesimas_int=0;
        _LOGICAJUEGO_segundos_int++;


    }
    if(_LOGICAJUEGO_segundos_int==60)
    {
        _LOGICAJUEGO_segundos_int=0;
        _LOGICAJUEGO_minutos_int++;


    }
    if(_LOGICAJUEGO_minutos_int==60)
    {
        _LOGICAJUEGO_minutos_int=0;
        _LOGICAJUEGO_hora_int++;

    }

    if(_LOGICAJUEGO_hora_int==24)
    {
        _LOGICAJUEGO_dia_int++;

    }
    if(_LOGICAJUEGO_dia_int==8)
    {
        _LOGICAJUEGO_dia_int=0;
    }

    _LOGICAJUEGO_milesimas_int++;
    rest(100);

}
void fx_LOGICAJUEGO_inicializar_variables()
{
    _LOGICAJUEGO_fin_juego_bool_no=1;

}

