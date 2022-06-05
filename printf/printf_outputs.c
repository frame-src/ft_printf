/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_outputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:57:21 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/05 19:45:00 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <unistd.h> // printf(char * content, ...)

int main()
{
	// int a,b;
	// float c,d;
	char h[] = "DOOM";

	// a = -123456789;
	// b = a / 2;
	// printf("i would like to %*d\n see\n\n",10,b);	//decimal
	// printf("%12.5d\n",b);	//precision 3
	// printf("%-100d\n",b);
	// printf("\n",b);

	// c = 15.3;
	// d = c / 3;
	// printf("%-f\n",d);
	// printf("%0f\n",d);
	// printf("precision I: %0.0s\n",h);
	// printf("precision II: % 032.2s\n",h);
	// printf("%f\n",d);
	// printf("%#f\n",d);
	// printf("%f\n",d);
	// printf("%+f\n",d);

	// printf("\n\n****************** char c **************");
	// printf("\n%0s",h);
	// printf("\n% s",h);
	// printf("\nQUESTO_______:|%.70s|",h);
	// printf("\n        DOOM",h);
	// printf("\n%#s",h);
	// printf("\n%+s",h);
	// printf("\n%-s",h);
	// printf("********NUMBER*******\n");
	// printf("%d\n", 1208);
	// printf("precision and wdt: \t|%-10.-15d|\n", a);
	// printf("null prec and wdt: \t|%-18.20d|\n", a);
	// printf("null prec and wdt: \t|%-28.20d|\n", a);
	// printf("lft nll prc & wdt: \t|%-15.12d|\n", a);
	// printf("neg preci and wdt: \t|%-50.-12d|\n", a);
	// printf("null precision: \t|%.d|\n", a);
	// printf("null neg precsion: \t|%.-2d|\n", a);
	// printf("# flag:\t \t\t|%#d|\n", a);
	// printf("# flag:\t \t\t|%#d|\n", a);
	// printf("#WTF|%.s|WTF\n", "DOOM");
	// printf("#WTF|%-0100s|WTF\n", "DOOM");

	// // unsigned
	// printf("\nunsigned uunsigned: %u", 42949672454545495);
	// printf("\nunsigned u: %u", -2554600000);
	// printf("\nunsigned u: %20u", 4294967295);
	// printf("\nunsigned u: %-020.12u", 4294967295);
	
	printf("/****** TEST **********/\n");
	printf("/* printf |%5.3s|\t*/\n",h);
	printf("/* printf |%4.60s|\t*/\n",h);
	printf("/* printf |% 04.1s|\t*/\n",h);
	printf("/* printf |%012.-12s|\t*/\n","ciao patata");
	printf("/****** END TEST ******/\n");
	//printf("%10.5%\n");
}