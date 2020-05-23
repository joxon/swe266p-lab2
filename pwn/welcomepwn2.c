// ------------------------------------------------------------------------------------------------
//	PURDUE CS527 - Software Security - Spring 2016
//
//  Name       : Welcome Pwn #2
//  Category   : Pwning
//	Difficulty : medium
//  Points     : 100
//  Flag       : cs527{H3y_m0MmY_I_l3aRn3d_wHa7_3nD14nEs5_1zzz}
//  Information: Simple overflow of "id" variable, but this time some important variables may get
//		corrupted too. A brutal overflow won't work.
//
//  Description: Similar to Welcome Pwn #1, but this time you must be careful...
//
//	Hints      : Just be careful with endianess.
//
//	Compile    : gcc -m32 -fno-stack-protector -O0 -o welcomepwn2 welcomepwn2.c
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define die(s) { puts(s); return 0; }
// ------------------------------------------------------------------------------------------------
int main( void )
{
	int  id;
	int  birth;
	char gender;
	char name[32];

	
	srand(time(NULL));						// initialize random seed
	id = rand();							// get a random value

	// read some info
	printf("Year of birth?: "); scanf("%d",   &birth );
	printf("Gender (M/F)?: ");  scanf("\n%c", &gender);
	printf("Name?: ");          scanf("%s",   name   );

	// validate user's input
	if( birth < 1930 ) die("You're too old :\\\n")
	else if( birth > 2000 ) die("You're too young :)\n")

	if( gender != 'M' && gender != 'F' )
		die( "Non-binary? :$\n" )

	// if user is lucky, give him the flag
	if( id == 13371337 )
	{	
		puts("It seems that this is your lucky day! Here's your flag:\n");
		system( "cat flag" );
	}
	else printf("Welcome stranger! Here's your id: %d\n", id );
}
// ------------------------------------------------------------------------------------------------
