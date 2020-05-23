// ------------------------------------------------------------------------------------------------
//	PURDUE CS527 - Software Security - Spring 2016
//
//  Name       : Welcome Pwn #1
//  Category   : Pwning
//	Difficulty : medium
//  Points     : 100
//  Flag       : cs527{w3Lc0Me_t0_7he_AW3soMe_w0rLd_oF_pWN1nG!!!}
//  Information: Simple overflow of "id" variable.
//
//  Description: How lucky are you?
//
//	Hints      : Just be careful with endianess.
//
//	Compile    : gcc -m32 -fno-stack-protector -O0 -o welcomepwn1 welcomepwn1.c
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
	printf("Name?: ");          scanf("%s",   name   );
	printf("Year of birth?: "); scanf("%d",   &birth );
	printf("Gender (M/F)?: ");  scanf("\n%c", &gender);
	
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
