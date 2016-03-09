#include <stdlib.h>
#include <stdio.h>

typedef unsigned __int32 uint32_t;
typedef __int32 int32_t;
uint32_t CountLeadingZeroes(uint32_t input);
uint32_t L(uint32_t in);
uint32_t CountBitWidth(int32_t input);
int32_t ReverseBits(int32_t in);
void S(int32_t in);
void U(uint32_t in);

uint32_t u[8];
int32_t s[8];
void main()
{
	//uint32_t uin = rand();
	//int32_t sin = rand();
	//uint32_t uin = rand()*rand();
	//int32_t sin = -rand()*rand();
	uint32_t uin = 0;
	int32_t sin = -1;
	uint32_t ur;
	int32_t sr;

	

	printf("using random value ur : %8x \n", uin);
	printf("using random value sr : %8x \n", sin);

	// test CountLeadingZeroes
	ur = CountLeadingZeroes(uin);
	printf("Return from  CountLeadingZeroes(%8x) = %d \n", uin, ur);

	// test L (counting bit length of unsigned int)
	ur = L(uin);
	printf("Return from  L(%8x) = %d \n", uin, ur);

	// test CountBitWidth (counting bit length of signed int)
	ur = CountBitWidth(uin);
	printf("Return from  CountBitWidth(%8x) = %d \n", uin, ur);

	ur = CountBitWidth(sin);
	printf("Return from  CountBitWidth(%8x) = %d \n", sin, ur);


	// test ReverseBits (counting bit length of signed int)
	ur = ReverseBits(uin);
	printf("Return from  ReverseBits(%8x) = %8x \n", uin, ur);
	ur = ReverseBits(ur);
	printf("Return from  ReverseBits(ReverseBits(%8x)) = %8x \n", uin, ur);

	sr = ReverseBits(sin);
	printf("Return from  ReverseBits(%8x) = %8x \n", sin, sr);
	sr = ReverseBits(sr);
	printf("Return from  ReverseBits(ReverseBits(%8x)) = %8x \n", sin, sr);



	// test U (splitting 32 bit unsigned int to an array of 4 bit values)
	U(uin);
	printf("Return from  U(%8x) = \n", uin);

	for (uint32_t i = 0; i < 8; i++)
	{
		printf("Return from  U(%8x)[%d] = %8x \n", uin, i, u[i]);
	}

	// test S (splitting 32 bit signed int to an array of 4 bit values)
	S(sin);
	printf("Return from  U(%8x) = \n", sin);

	for (uint32_t i = 0; i < 8; i++)
	{
		printf("Return from  U(%8x)[%d] = %8x \n", sin, i, s[i]);
	}


	
}

uint32_t CountLeadingZeroes(uint32_t input)
{
	uint32_t rc = 0;

	if (input == 0)
	{
		// Special case when input is zero.
		rc = 32;
	}
	else
	{
		// Test each bit in turn, starting from the MSB, until a non-zero bit is found.
		while ((input & (1 << (31 - rc))) == 0)
		{
			rc++;
		}
	}

	return rc;
}


uint32_t L(uint32_t in)
{
	uint32_t rc = 0;

	while (in)
	{
		rc++;
		in >>= 1;
	}
	
	return rc;
}


uint32_t CountBitWidth(int32_t input)
{
	uint32_t rc;

	if (input == 0 || input == -1)
	{
		// Special case when input is zero or -1.
		rc = 1;
	}
	else
	{ 
		rc = 32;
		// Store value of MSB (sign bit)
		uint32_t tb = (input >> 31) & 0x1;

		// Test each bit in turn starting from MSB, until value different than MSB is found.
		while (tb == ((input >> (rc - 2)) & 0x1))
		{

			rc--;
		}
	}
	return rc;
}

int32_t ReverseBits(int32_t in)
{
	int32_t out = 0;
	// assign LSB bit of in to LSB of out, this will become MSB after end of the loop 
	out |= (in & 0x1);

	// keep shifting ‘in’ right and out left 
	for (uint32_t i = 0; i < 31; i++)
	{
		out <<= 1;
		in >>= 1;
		out |= (in & 0x1);
	}

	return out;
}




void U(uint32_t in)
{
	for (uint32_t i = 0; i < 8; i++)
	{
		u[i] = (in >> (i << 2)) & 0xF;
	}
}



void S(int32_t in)
{
	for (uint32_t i = 0; i < 8; i++)
	{
		s[i] = (in << ((7 - i) << 2)) >> 28;
	}
}
