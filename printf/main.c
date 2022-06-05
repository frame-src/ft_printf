
#include "ft_printf.h"

int main (void)
{
	//ft_printf("let me see if you work ***: %c \t %0222.-12s\n", 'V', "hello world");
	//char *s = "dipolo";
	ft_printf("\n/////////////   STRING   ////////////////////\n");
	ft_printf("\nft_printf: *|%10.5s|\n","ciaociaociao");
	printf("\nprintf: ****|%10.5s|\n","ciaociaociao");
	// 		fflush(NULL);
	// printf("\nprintf: ****|%10.7s|\n","ciaociaociao");
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



	// ft_printf("\n//INTEGER /////////////////\n");
	// ft_printf("\nft_printf: \t|%3.22d|", 50002);
	// printf("\n***printf: \t|%3.22d|", 50002);
	// 		fflush(NULL);
	// ft_printf("\nft_printf: \t|%-18.20d|", 1202);
	// printf("\n***printf: \t|%-18.20d|", 1202);
	// 		fflush(NULL);
	// ft_printf("\nft_printf: \t|%28.20d|", -1202);
	// printf("\nprintf: \t|%28.20d|", -1202);
	// 		fflush(NULL);
	// printf("\nprintf: \t|%-28.20d|", 1202);
	// 		fflush(NULL);



	// ft_printf("\n//UNSIGNED /////////////////\n");
	// ft_printf("\nft_printf : %u", 429496724);
	// printf("\n***printf : %u", 429445495);
	// 		fflush(NULL);
	// ft_printf("\nft_printf : %u", -255460);
	// printf("\n***printf : %u", -255460);
	// 		fflush(NULL);
	// ft_printf("\nft_printf : %20u", 42947295);
	// printf("\n***printf : %20u", 42949295);
	// 		fflush(NULL);
	// ft_printf("\nft_printf : %-20.12u", 42945);
	// printf("\n***printf : %-20.12u", 42945);
	// 			fflush(NULL);
	// ft_printf("\nft_printf: \t|%-28.20u|\n", -1202); //flag '+' results in undefined behavior with 'u' conversion specifier
	// printf("\n***printf: \t|%-28.20u|\n", -1202); //flag '+' results in undefined behavior with 'u' conversion specifier
	// 			fflush(NULL);
	// ft_printf("\nft_printf: \t|%+-%|\n");
	// printf("\n***printf: \t|%-+%|\n");
	// 			fflush(NULL);
	return 0;
}
// ft_printf:      |000000000000000001202|$
// ft_printf:      |    000000000000000001202|$
// printf:         |00000000000000001202|$
// printf:         |        00000000000000001202|$