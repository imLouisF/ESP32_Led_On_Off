#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"


#define Pulsador GPIO_NUM_23
#define Led GPIO_NUM_22
void app_main(void)
{
	//Variables de entradas y salidas
	gpio_set_direction(Pulsador, GPIO_MODE_INPUT);
	gpio_set_direction(Led, GPIO_MODE_OUTPUT);
	//Se declara el boton como PullUp
	gpio_set_pull_mode(Pulsador, GPIO_PULLUP_ONLY);

    while (true) {

    	int EstadoPulsador = gpio_get_level(Pulsador);

    	if(EstadoPulsador == 1)
    	{
    		gpio_set_level(Led, 0);
    	}
    	else
    	{
    		gpio_set_level(Led, 1);
    	}
    }
}
