
#include "ft_printf.h"
#include <limits.h>
int main (void)
{
	//ft_printf("let me see if you work ***: %c \t %0222.-12s\n", 'V', "hello world");
	//char *s = "dipolo";
	// ft_printf("\n/////////////   STRING   ////////////////////\n");
	// printf("%d",ft_printf("\nft_printf: *|%10.5s|\n","ciaociaociao"));
	// fflush(NULL);
	// printf("%d",printf("\nprintf: ****|%10.5s|\n","ciaociaociao"));
	// fflush(NULL);
	// printf("%d",ft_printf("\nft_printf:* |%10.5s|\n","ciaociaociao"));
	// fflush(NULL);
	// printf("%d",printf("\nprintf: ****|%10.7s|\n","ciaociaociao"));
	// 		fflush(NULL);
	// printf("%d",printf("\nprintf: ****|%10.7s|\n","ciaociaociao"));
	// 	fflush(NULL);
	// ft_printf("\nft_printf: *|%10.3s|\n","ciaociaociao");//'0' results in undefined behavior with 's' conversion specifier
	// printf("\nprintf: ****|%10.3s|\n","ciaociaociao");//'0' results in undefined behavior with 's' conversion specifier
	// 		fflush(NULL);
	// printf("\n   printf:|%010.-7-s|","ciaociaociao");
	// printf("\ntest%0#-+ 18.15stest", "4294967295");
	// ft_printf("\ntest%0#-+ 18.15stest\n", "4294967295");
	//printf("%p",printf("\n printf %p\n", NULL)); 
	//printf("%c\n", *s);// Is looking for the dereferentiation of a null, wich is supposed to be in 0x0 so i seg_fault
	//ft_printf("\nft_printf:%p\n", "HLlloa fAenn21af..?fkW2+_dakf");
	// printf("%d",printf("%p\n", s));
	// 	fflush(NULL);
	//ft_printf("%d\n", 466487);


	// ft_printf("\n//CHAR /////////////////\n");
	// printf("%d",ft_printf("\nft_printf: \t|%-2c|",'D'));
	// printf("%d",printf("\n***printf: \t|%-2c|", 'D'));
	// 		fflush(NULL);
	// printf("%d",ft_printf("\nft_printf: \t|%-3c|", 'D'));
	// printf("%d",printf("\n***printf: \t|%-3c|", 'D'));
	// 		fflush(NULL);
	// printf("%d",printf("\n***printf: \t|%028c|", 'D'));
	// 		fflush(NULL);
	// printf("%d",ft_printf("\nft_printf: \t|%028c|", 'D'));
	// printf("%d",printf("\n***printf: \t|%028c|", 'D'));
	// 		fflush(NULL);
	// ft_printf("\n//INTEGER /////////////////\n");
	// printf("%d",ft_printf("\nft_printf: \t|% d|", 0));
	// printf("%d",printf("\n***printf: \t|% d|", 0));
	// 		fflush(NULL);
	// printf("%d",ft_printf("\nft_printf: \t|%-1d|", 1));
	// printf("%d",printf("\n***printf: \t|%-1d|", 1));
	// 		fflush(NULL);
	// printf("%d",printf("\n***printf: \t|% 1i|", LONG_MIN));
	// 		fflush(NULL);
	// printf("%d",ft_printf("\nft_printf: \t|% i|", LONG_MIN));
	// printf("%d",printf("\n***printf: \t|% i|", -1202));
	// 		fflush(NULL);


	ft_printf("\n//UNSIGNED /////////////////\n");
	ft_printf("\nft_printf : %u", 429496724);
	printf("\n***printf : %u", 429445495);
			fflush(NULL);
	ft_printf("\nft_printf : %u", -255460);
	printf("\n***printf : %u", -255460);
			fflush(NULL);
	ft_printf("\nft_printf : %20u", 42947295);
	printf("\n***printf : %20u", 42949295);
			fflush(NULL);
	ft_printf("\nft_printf : %-20.12u", 42945);
	printf("\n***printf : %-20.12u", 42945);
				fflush(NULL);
	ft_printf("\nft_printf: \t|%-28.20u|\n", -1202); //flag '+' results in undefined behavior with 'u' conversion specifier
	printf("\n***printf: \t|%-28.20u|\n", -1202); //flag '+' results in undefined behavior with 'u' conversion specifier
				fflush(NULL);
	
	ft_printf("\n//% PERCENT/////////////////\n");
	ft_printf("\nft_printf: \t|%+-%|\n");
	printf("\n***printf: \t|%-+%|\n");
				fflush(NULL);
	return (0);
}
// ft_printf:      |000000000000000001202|$
// ft_printf:      |    000000000000000001202|$
// printf:         |00000000000000001202|$
// printf:         |        00000000000000001202|$