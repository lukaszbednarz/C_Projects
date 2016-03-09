// Bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bits.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

unsigned int log2(unsigned int x)
{
	unsigned int ans = 0;
	while (x >>= 1) ans++;
	return ans;
}


int main()
{

	int a = rand();
	int b = rand();
	int c, d, e;

	// Test bitAnd for random integer
#pragma region [Test bitAnd()]
	c = bitAnd(a, b);
	d = a & b;
	printf("Testing bitAnd()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);
#pragma endregion

	// Test bitXor for random integer
#pragma region [Test bitXor()]
	c = bitXor(a, b);
	d = a^b;
	printf("Testing bitAnd()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);
#pragma endregion

	// Test thirdBits
#pragma region [Test thirdBits()]
	c = thirdBits();
	//d = (?1 <<0 )|(1<<3)|(1<<6) | (1 << 9) | (1 << 12) | (1 << 15) | (1 << 18) | (1 << 21) | (1 << 24) | (1 << 27) | (1 << 30);
	d = 0x49 | (0x49 << 9) | (0x49 << 18) | (0x49 << 27);
	printf("Testing thirdBits()\n\tc: %8x\n\td: %8x\n", c, d);
#pragma endregion

	// Test fitsBits
#pragma region [Test fitsBits()]
	a = -1;
	b = 32;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1;
	b = 1;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1 << 31;
	b = 32;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1 << 31;
	b = 31;
	c = fitsBits(a, b);
	d = 0;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);


	a = 0;
	b = 32;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 0;
	b = 31;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 0;
	b = 1;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 32;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 31;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 1;
	c = fitsBits(a, b);
	d = 0;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 2;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = (1 << 31) - 1;
	b = 32;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = (1 << 31) - 1;
	b = 31;
	c = fitsBits(a, b);
	d = 0;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 5;
	b = 3;
	c = fitsBits(a, b);
	d = 0;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -4;
	b = 3;
	c = fitsBits(a, b);
	d = 1;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);
#pragma endregion

	// Test sign()
#pragma region [Test sign()]
	a = -1;
	c = sign(a);
	d = -1;
	printf("Testing sign()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = 1;
	c = sign(a);
	d = 1;
	printf("Testing sign()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = 0;
	c = sign(a);
	d = 0;
	printf("Testing sign()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = -1 << 31;
	c = sign(a);
	d = -1;
	printf("Testing sign()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = (1 << 31) - 1;
	c = sign(a);
	d = 1;
	printf("Testing sign()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = rand();
	c = sign(a);
	d = (a > 0) - (a < 0);
	printf("Testing sign()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = -rand();
	c = sign(a);
	d = (a > 0) - (a < 0);
	printf("Testing sign()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

#pragma endregion

	// Test getByte()
#pragma region [Test getByte()]
	a = -1;
	b = 0;
	c = getByte(a, b);
	d = 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1;
	b = 1;
	c = getByte(a, b);
	d = 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1;
	b = 2;
	c = getByte(a, b);
	d = 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1;
	b = 3;
	c = getByte(a, b);
	d = 0x01;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 0;
	c = getByte(a, b);
	d = 0x00;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 1;
	c = getByte(a, b);
	d = 0x00;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 2;
	c = getByte(a, b);
	d = 0x00;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = 1;
	b = 3;
	c = getByte(a, b);
	d = 0x00;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);


	a = rand();
	b = 0;
	c = getByte(a, b);
	d = a & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	b = 1;
	c = getByte(a, b);
	d = (a >> 8) & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	b = 2;
	c = getByte(a, b);
	d = (a >> 16) & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	b = 3;
	c = getByte(a, b);
	d = (a >> 24) & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -rand();
	b = 0;
	c = getByte(a, b);
	d = a & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	b = 1;
	c = getByte(a, b);
	d = (a >> 8) & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	b = 2;
	c = getByte(a, b);
	d = (a >> 16) & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	b = 3;
	c = getByte(a, b);
	d = (a >> 24) & 0xff;
	printf("Testing fitsBits()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);


#pragma endregion

	// Test logicalShift()
#pragma region [Test logicalShift()]

	a = -1 << 31;
	b = 0;
	c = logicalShift(a, b);
	d = (-1 << 31);
	printf("Testing logicalShift()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1 << 31;
	b = 1;
	c = logicalShift(a, b);
	d = (-1 << 30) & ~(-1 << 31);
	printf("Testing logicalShift()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -1 << 31;
	b = 12;
	c = logicalShift(a, b);
	d = (-1 << 19) & ~(-1 << 20);
	printf("Testing logicalShift()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = rand();
	b = 12;
	c = logicalShift(a, b);
	d = (a >> b) & ~((-1 << 31) >> (b - 1));
	printf("Testing logicalShift()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);

	a = -rand();
	b = 12;
	c = logicalShift(a, b);
	d = (a >> b) & ~((-1 << 31) >> (b - 1));
	printf("Testing logicalShift()\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n", a, b, c, d);


#pragma endregion

	// Test addOK()
#pragma region [Test addOK()]
	a = 0x80000000;
	b = 0x80000000;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x80000000 + 1;
	b = 0x80000000;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x80000000 + 1;
	b = 0x80000000 + 1;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = -1 << 30;
	b = -1 << 30;
	c = addOK(a, b);
	d = 1;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = (-1 << 30) - 1;
	b = (-1 << 30);
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = (-1 << 30) - 1;
	b = (-1 << 30) + 1;
	c = addOK(a, b);
	d = 1;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x80000000;
	b = 0x70000000;
	c = addOK(a, b);
	d = 1;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x70000000;
	b = 0x70000000;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x70000000 - 1;
	b = 0x70000000;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x70000000 - 1;
	b = 0x70000000 - 1;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x7FFFFFFF;
	b = 0x7FFFFFFF;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x7FFFFFFF >> 1;
	b = 0x7FFFFFFF >> 1;
	c = addOK(a, b);
	d = 1;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x7FFFFFFF >> 1;
	b = (0x7FFFFFFF >> 1) + 1;
	c = addOK(a, b);
	d = 1;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = (0x7FFFFFFF >> 1) + 1;
	b = (0x7FFFFFFF >> 1) + 1;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x7FFFFFFF;
	b = 0x1;
	c = addOK(a, b);
	d = 0;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

	a = 0x7FFFFFFF - 1;
	b = 0x1;
	c = addOK(a, b);
	d = 1;
	e = a + b;
	printf("Testing addOK()\n\ta: %8x\n\tb: %8x\n\te: %8x\n\tc: %8x\n\td: %8x\n", a, b, e, c, d);

#pragma endregion


	// Test bang()
#pragma region [Test bang()]
	a = 0x80000000;
	c = bang(a);
	d = 0;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = 0x1;
	c = bang(a);
	d = 0;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = 3;
	c = bang(a);
	d = 0;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = 1;
	c = bang(a);
	d = 0;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = -1;
	c = bang(a);
	d = 0;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = -2;
	c = bang(a);
	d = 0;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = (-1 << 31) - 1;
	c = bang(a);
	d = 0;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

	a = 0;
	c = bang(a);
	d = 1;
	printf("Testing bang()\n\ta: %8x\n\tc: %8x\n\td: %8x\n", a, c, d);

#pragma endregion

	// Test conditional()
#pragma region [Test conditional()]

	a = 0x80000000;
	b = 0x1;
	c = 0x80000000;
	d = ::conditional(a, b, c);
	e = b;
	printf("Testing d = conditional(a, b, c)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n\te: %8x\n", a, b, c, d, e);

	a = 0x0;
	b = 0x1;
	c = 0x80000000;
	d = ::conditional(a, b, c);
	e = c;
	printf("Testing d = conditional(a, b, c)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n\te: %8x\n", a, b, c, d, e);

	a = 0x1;
	b = 0x1;
	c = 0x80000000;
	d = ::conditional(a, b, c);
	e = b;
	printf("Testing d = conditional(a, b, c)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n\te: %8x\n", a, b, c, d, e);

	a = 0x1;
	b = 0x80000000;
	c = 0x1;
	d = ::conditional(a, b, c);
	e = b;
	printf("Testing d = conditional(a, b, c)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n\te: %8x\n", a, b, c, d, e);

	a = 0x0;
	b = 0x80000000;
	c = 0x1;
	d = ::conditional(a, b, c);
	e = c;
	printf("Testing d = conditional(a, b, c)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n\te: %8x\n", a, b, c, d, e);

	a = rand();
	b = rand();
	c = rand();
	d = ::conditional(a, b, c);
	e = a ? b : c;
	printf("Testing d = conditional(a, b, c)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n\te: %8x\n", a, b, c, d, e);

	a = 0;
	d = ::conditional(a, b, c);
	e = a ? b : c;
	printf("Testing d = conditional(a, b, c)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n\td: %8x\n\te: %8x\n", a, b, c, d, e);

#pragma endregion

	// Test isPower2
#pragma region [Test isPower2()]
	a = 0x80000000;
	b = isPower2(a);
	c = 0;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 0x0;
	b = isPower2(a);
	c = 0;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	for (unsigned int i = 0; i <= 30; i++)
	{
		a = 0x1 << i;
		b = isPower2(a);
		c = 1;
		//if (b != c)
		if (true)
		{
			printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);
		}
	}

	a = 0x1 << 1;
	b = isPower2(a);
	c = 1;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 0x1 << 30;
	b = isPower2(a);
	c = 1;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 0x1 << 30;
	b = isPower2(a);
	c = 1;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 0x1 << 30;
	b = isPower2(a);
	c = 1;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 0x1 << 30;
	b = isPower2(a);
	c = 1;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 3;
	b = isPower2(a);
	c = 0;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 5;
	b = isPower2(a);
	c = 0;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	a = 156;
	b = isPower2(a);
	c = 0;
	printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", a, b, c);

	if (0)
	{
		for (unsigned int i = 0; i <= 0xFFFFFFFF; i++)
		{


			b = isPower2(i);


			if (i == (1 << log2(i)))
			{
				c = 1;
			}
			else {
				c = 0;
			}

			if (b != c)
			{
				printf("Testing b = isPower2(a)\n\ta: %8x\n\tb: %8x\n\tc: %8x\n", i, b, c);
			}
		}
	}
#pragma endregion
	return 0;
}

