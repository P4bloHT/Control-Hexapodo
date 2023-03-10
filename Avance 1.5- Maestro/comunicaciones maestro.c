#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Nokia5110.h"

#define ButtonC 0x08
#define ButtonD 0x10
#define ButtonB 0x04
#define ButtonE 0x02
/*****************************************************************************
Defininimos variables que manejan 
los graficos de la pantalla nokia*/
/****************************************************************************/

uint8_t ActualizarPantalla;
uint8_t contActualizarPantalla=0;

uint8_t mov;




/*****************************************************************************
Declaramos las funciones empleadas */
/****************************************************************************/
void PortF_Init(void);
void ConfiguraSysTick(void);
void SysTick_Handler(void);
void config_portF(void);


/*****************************************************************************
Definimos los 2 elementos graficos en mapas de bits */ 
/****************************************************************************/
const unsigned char tablaBienvenida[504] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0xa0, 0x40, 0x00, 0x00, 0x00, 0x20, 0xe0, 0x20, 0x00, 0x00, 0x00, 0xe0, 0x20, 0x20, 0x20, 0x00, 0x00, 0xe0, 0x40, 0x80, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x20, 0x20, 0x20, 0x00, 0xe0, 0x40, 0x80, 0xe0, 0x00, 0x20, 0xe0, 0x20, 0x00, 0x00, 0xe0, 0x20, 0x20, 0xc0, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x09, 0x06, 0x00, 0x00, 0x10, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x1f, 0x11, 0x11, 0x10, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x1f, 0x00, 0x03, 0x0c, 0x10, 0x0c, 0x03, 0x00, 0x00, 0x1f, 0x11, 0x11, 0x10, 0x00, 0x1f, 0x00, 0x00, 0x1f, 0x00, 0x10, 0x1f, 0x10, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x0f, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x02, 0x01, 0x00, 0x0e, 0x02, 0x02, 0x00, 0x0f, 0x0a, 0x0a, 0x00, 0x09, 0x0a, 0x04, 0x00, 0x0e, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00, 0x0e, 0x02, 0x0e, 0x00, 0x0f, 0x0a, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x04, 0x02, 0x04, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char tabla1[504]= //MOVIMIENTO ARRIBA
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x38, 0x3c, 0x3e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3c, 0x38, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char tabla2[504]= //MOVIMIENTO DERECHA
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char tabla3[504]= //MOVIMIENTO ABAJO
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char tabla4[504]= //MOVIMIENTO IZQUIERDA
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void ConfiguraSysTick(void){		// Temporiza 1mseg, Fclksys=16MHz	
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
	NVIC_ST_RELOAD_R = (NVIC_ST_RELOAD_R&0xFF000000)|0x00003E7F;//16000-1
	NVIC_ST_CURRENT_R &= ~(0x00FFFFFF);
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_INTEN | NVIC_ST_CTRL_ENABLE;
}


volatile uint32_t contadorGlobal=0;
void SysTick_Handler(void){	
	  contadorGlobal++;
		// Actualizar la pantalla cada 16ms
		if(++contActualizarPantalla>15){
			contActualizarPantalla=0;
			ActualizarPantalla=1;
		}

}

void delayms(uint32_t cantidad){
  
	contadorGlobal=0;
	while(contadorGlobal<cantidad);

}

void ConfigUART0( void )
{	  
    //Configuracion del periferico UART
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;             	// Se activa el reloj UART
    while( (SYSCTL_PRUART_R & SYSCTL_PRUART_R0)==0) {}   	// Espera activacion
    //Configuracion pines de UART       	
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; //Activacion reloj Puerto A 
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R0)==0) {} //Espera activacion  	
         
    UART0_CTL_R  &= ~(UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
    UART0_IBRD_R  = (UART0_IBRD_R & ~UART_IBRD_DIVINT_M)|104;                                                                 // DIVINT:16MHz/(16*9600)
    UART0_FBRD_R  = (UART0_FBRD_R & ~UART_FBRD_DIVFRAC_M)|10; //Se configura DIVFRAC
                                                              //Parte fraccionaria*64
    UART0_LCRH_R  = ((UART0_LCRH_R & ~0x000000FF)|(UART_LCRH_WLEN_8)|(UART_LCRH_FEN));
//Configuraciones:
// los 8 bits de datos,
// 1 bit de parada, sin paridad y habilita el FIFO                                                                              	
    UART0_CTL_R  |= UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE;  // Se habilita UART
     
    //Configuracion pines de UART       	
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; //Activacion reloj Puerto A 
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R0)==0) {} //Espera activacion  	
         
    GPIO_PORTA_AFSEL_R |= 0x03;          	// Se activan las funciones alternas de PA0 y PA1.
    GPIO_PORTA_DEN_R   |= 0x03;          	// Habilitaci?n PA0 y PA1 para se?ales digitales. 
} 

void ConfigUART2(void){

	 //Configuracion del periferico UART
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2;             	// Se activa el reloj UART
    while( (SYSCTL_PRUART_R & SYSCTL_PRUART_R2)==0) {}   	// Espera activacion
    //Configuracion pines de UART       	
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3; //Activacion reloj Puerto D
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R3)==0) {} //Espera activacion  	
        
		UART2_CTL_R  &= ~(UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
    UART2_IBRD_R  = (UART2_IBRD_R & ~UART_IBRD_DIVINT_M)|104;                                                                 // DIVINT:16MHz/(16*9600)
    UART2_FBRD_R  = (UART2_FBRD_R & ~UART_FBRD_DIVFRAC_M)|10; //Se configura DIVFRAC
                                                              //Parte fraccionaria*64
    UART2_LCRH_R  = ((UART2_LCRH_R & ~0x000000FF)|(UART_LCRH_WLEN_8)|(UART_LCRH_FEN));
//Configuraciones:
// los 8 bits de datos,
// 1 bit de parada, sin paridad y habilita el FIFO                                                                              	
    UART2_CTL_R  |= UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE;  // Se habilita UART

		//Configuraci?n de pines de UART
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3; //Activacion reloj Puerto D 
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R3)==0) {} //Espera activacion  	
			
			GPIO_PORTD_LOCK_R = 0x4c4f434b; 
			GPIO_PORTD_CR_R |= 0xC0; 
			
			GPIO_PORTD_AFSEL_R |= 0xC0;          	// Se activan las funciones alternas de PD6 y PD7.
			GPIO_PORTD_PCTL_R  |= 0x11000000;
      GPIO_PORTD_DEN_R   |= 0xC0;          	// Habilitaci?n PD6 y PD7 para se?ales digitales. 



}

void setupADC(void){
  SYSCTL_RCGCADC_R |= 0x0003;   // 1) activamos ADC0
  SYSCTL_RCGCGPIO_R |= 0x10;    // 2) activamos el clock para el puerto E
  while((SYSCTL_PRGPIO_R&0x10) != 0x10){};  // 3) esperamos a que el clock se estabilice
  GPIO_PORTE_DIR_R &= ~0x0C;    // 4) configuramos PE3 y PE2 como entrada
  GPIO_PORTE_AFSEL_R |= 0x0C;   // 5) habilitamos la funcion alterna de PE3 y PE2
  GPIO_PORTE_DEN_R &= ~0x0C;    // 6) deshabilitamos la funcion digital I/O de PE3 y PE2
  GPIO_PORTE_AMSEL_R |= 0x0C;   // 7) habilitamos la funcionalidad analoga de PE3 Y PE2
  //while((SYSCTL_PRADC_R&0x0001) != 0x0001){}; // no implementado en el simulador
  ADC0_PC_R &= ~0xF;
  ADC0_PC_R |= 0x1;             // 8) configuro a 125K samples/sec
  ADC0_SSPRI_R = 0x0123;        // 9) el secuenciador 3 tiene la mas alta prioridad
  ADC0_ACTSS_R &= ~0x0008;      // 10) deshabilitamos el muestreo del secuenciador 3
  ADC0_EMUX_R &= ~0xF000;       // 11) el seq3 es el disparador del software
  ADC0_SSMUX3_R = 0;            // 12) obtenemos la entrada desde el canal 0 PE3
  //ADC0_SSMUX3_R &= ~0x000F;
		
/*ADC1*/
	ADC1_PC_R &= ~0xF;
  ADC1_PC_R |= 0x1;             // 8) configuro a 125K samples/sec
  ADC1_SSPRI_R = 0x0123;        // 9) el secuenciador 3 tiene la mas alta prioridad
  ADC1_ACTSS_R &= ~0x0008;      // 10) deshabilitamos el muestreo del secuenciador 3
  ADC1_EMUX_R &= ~0xF000;       // 11) el seq3 es el disparador del software
  ADC1_SSMUX3_R = 1;            // 12) obtenemos la entrada desde el canal 1  PE2
		
  //ADC0_SSMUX3_R += 9;           // 12) obtenemos la entrada desde el canal 0
  ADC0_SSCTL3_R = 0x0006;       // 13) no TS0 D0, si IE0 END0
  ADC0_IM_R &= ~0x0008;         // 14) deshabilitamos interrupciones SS3 
  ADC0_ACTSS_R |= 0x0008;       // 15) habilitamos el muestreo del secuenciador 3
	
/*ADC1*/
  ADC1_SSCTL3_R = 0x0006;       // 13) no TS0 D0, si IE0 END0
  ADC1_IM_R &= ~0x0008;         // 14) deshabilitamos interrupciones SS3 
  ADC1_ACTSS_R |= 0x0008;       // 15) habilitamos el muestreo del secuenciador 3
}
	

void config_portF(void) {
	// Activamos la se?al de reloj del puerto F
	SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R5;
	// Se espera a que realmente se active
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)==0) {}
	GPIO_PORTF_LOCK_R = 0x4C4F434B; // Desbloquear puerto F
	GPIO_PORTF_CR_R |= 0x01;				//0x1F; // Se habilita del PF0 al PF4

	// Configuraciones de pines de entrada
	// SW1 est? conectado al pin PF4 y SW2 al PF0.
//	GPIO_PORTF_DIR_R &=~((1<<1)|(1<<2))|((1<<3)|(1<<4)); // PF4 PF3 PF2 PF1 como entrada
//	GPIO_PORTF_AFSEL_R &=~((1<<1)|(1<<2))|((1<<3)|(1<<4));			//~(0x11); // No utilizar funciones alternas
//	GPIO_PORTF_PUR_R |= ((1<<1)|(1<<2))|((1<<3)|(1<<4));				//0x11; // Activar resistencias de pull-up en pines PF4 y PF0
//	GPIO_PORTF_DEN_R |= ((1<<1)|(1<<2))|((1<<3)|(1<<4));				//0x11; // Habilitar pines PF4 y PF0 en funcion digital
//	// Configuraciones de pines de salida
//	// El LED rojo conectado a PF1, azul a PF2 y verde a PF3.
//	GPIO_PORTF_DIR_R |= (1<<1)|(1<<2)|(1<<3);		//0x0E; // Configura los pines PF1, PF2 y PF3 como salida
//	GPIO_PORTF_DR8R_R |=(1<<1)|(1<<2)|(1<<3);		//0x0E; // se activa el driver de 8 mA para cada pin.
//	GPIO_PORTF_DEN_R |=(1<<1)|(1<<2)|(1<<3); 		//0x0E; // se activa los pines PF1,PF2 y PF3 como salida digital.

	//GPIO_PORTF_DATA_R&= ~((1<<1)|(1<<2)|(1<<3));
} // fin config_portF

//Transmisor para UART0
void TxCarU0( uint8_t Car )
{
  while((UART0_FR_R & UART_FR_TXFF) != 0 ) ; //Espera mientras pila llena
  UART0_DR_R = Car; 
}

/****************************************************************************************/
void TransmiteCadena( char *str ){
  uint8_t i = 0;
  while( str[i] ){
    TxCarU0( str[i] );
    i += 1;
  }
}
//Receptor para UART0
uint8_t RxCarU0( void )
{ 
   while((UART0_FR_R & UART_FR_RXFE) != 0 ) ; //Espera mientra pila vac?a
  return UART0_DR_R & 0xFF;
}

//Transmisor para UART2
void TxCarU2( uint8_t Car )
{
  while((UART2_FR_R & UART_FR_TXFF) != 0 ) ; //Espera mientras pila llena
  UART2_DR_R = Car; 
}

//Receptor para UART2
uint8_t RxCarU2( void )
{ 
   while((UART2_FR_R & UART_FR_RXFE) != 0 ) ; //Espera mientra pila vac?a
  return UART2_DR_R & 0xFF;
}



//Recibe la altura emitida por los sensores


//Generador de secuencias
void genera_secuencia(void){
	uint8_t pul_mov, cont;
	uint8_t secuencia[4];
	cont=1;
	
	while(cont<2){
	pul_mov=RxCarU0();
		
	if (pul_mov=='I'){
		
	
	
	}
	}	
}


//Evalua el movimiento del hex?podo
void mov_joystick_ShowNokia(void){
	
	switch(RxCarU0()){
		case 'U':
			Nokia5110_DrawFullImage((char*)tabla1);
			mov='U';
				
			break;
		case 'R':
			Nokia5110_DrawFullImage((char*)tabla2);
			mov='R';
			break;
		case 'D':
			Nokia5110_DrawFullImage((char*)tabla3);
			mov='D';
			break;
		case 'L':
			Nokia5110_DrawFullImage((char*)tabla4);
			mov='L';
			break;
		case 'C':
			Nokia5110_DrawFullImage((char*)tablaBienvenida);
			mov='C';
			break;
	}
}

//Funcion de los pulsadores
void accion_hexapodo(void){
	
	//
	if ((GPIO_PORTF_DATA_R & ButtonC) == 0){
			while ((GPIO_PORTF_DATA_R & ButtonC) != ButtonC);
		
	}
	
	//Bot?n que muestra la distancia que arrojan los sensores, tambien permite deshabilitar el bloqueo
	if ((GPIO_PORTF_DATA_R & ButtonD) == 0){
			while ((GPIO_PORTF_DATA_R & ButtonD) != ButtonD);
		
	}
	
	//Boton especial que permite guardar un serie de movimientos: HASTA 4 MOVIMIENTOS
	if ((GPIO_PORTF_DATA_R & ButtonB) == 0){
			while ((GPIO_PORTF_DATA_R & ButtonB) != ButtonB);
		genera_secuencia();
	}
	
	//Funcion que permite Encender y apagar el control remoto
	if ((GPIO_PORTF_DATA_R & ButtonE) == 0){
			while ((GPIO_PORTF_DATA_R & ButtonE) != ButtonE);
		
		
	}


}


int main(void)
{
	// Inicializacion
	Nokia5110_Init();
	Nokia5110_ClearBuffer();
	config_portF();	
	ConfiguraSysTick(); 
	ConfigUART0();
	ConfigUART2();
	  setupADC();
	
	uint32_t resultado1;
	delayms(1000);
	TxCarU0('H');
	TxCarU0('0');
	TxCarU0('5');
	TxCarU0('2');
	TxCarU0('C');
	TxCarU0('\n');
	TxCarU0('\r');
	//Nokia5110_DrawFullImage((char*)tablaBienvenida);


		//mov_joystick();
		//uint8_t car = RxCarU0();
		//TxCarU0(car);
		//TxCarU2(car);

	while(1){
		
  uint32_t result_x, result_y, previous = 0;
  char str[32];

  
  TransmiteCadena("CURSOR POSITION\r\n");
  //while(1){
	ADC0_PSSI_R |= 0x0008;            // comenzar la conversion del secuenciador 3
	while((ADC0_RIS_R & 0x08) == 0);  // espera por conversion completa
	result_x = ADC0_SSFIFO3_R&0xFFF;    // lee el resultado de la conversion
	ADC0_ISC_R = 0x0008;              // pone en 0 el flag de fin de proceso
	
	ADC1_PSSI_R |= 0x0008;            // comenzar la conversion del secuenciador 3
	while((ADC1_RIS_R & 0x08) == 0);  // espera por conversion completa
	result_y = ADC1_SSFIFO3_R&0xFFF;    // lee el resultado de la conversion
	ADC1_ISC_R = 0x0008;              // pone en 0 el flag de fin de proceso
	
		
	result_x = 3.3*result_x/4095;
  result_y = 3.3*result_y/4095;		
	
	
	
	if(result_x>2) {
		TxCarU2('U');
		TxCarU0('U');
		Nokia5110_DrawFullImage((char*)tabla1);
		for(int i=0;i<800000;i++){}
	}  
	if(result_x<1) {
		TxCarU2('D');
		TxCarU0('D');
		Nokia5110_DrawFullImage((char*)tabla3);
		for(int i=0;i<800000;i++){}
	}  	
	if(result_y>2){
		TxCarU2('R');
		TxCarU0('R');
		Nokia5110_DrawFullImage((char*)tabla2);
		for(int i=0;i<800000;i++){}
	}  
	if(result_y<1) {
		TxCarU2('L');
		TxCarU0('L');
		Nokia5110_DrawFullImage((char*)tabla4);
		for(int i=0;i<800000;i++){}			
	}  
	
	if(result_x>=1&&result_x<=2&&result_y<=2&&result_y>=1) {
		//TxCarU2('C');
		TxCarU0('C');
		Nokia5110_DrawFullImage((char*)tablaBienvenida);
		
	}  
	
	//Evalua los sensores
	
	

	}
	
}	