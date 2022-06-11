/*
 * Validaciones.h
 *
 *  Created on: 10 jun. 2022
 *      Author: Admin
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#define MAX_INPUT_BUFFER 4096


int validarInt(char *buffer);
int validarStringLetras(char *buffer);
int esNumeroTelefonico(char *buffer);
int esFloat(char *buffer);


#endif /* VALIDACIONES_H_ */
