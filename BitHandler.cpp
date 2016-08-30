#include "BitHandler.h"


Bit::BitHandler::BitHandler()
{
}


Bit::BitHandler::~BitHandler()
{
}


bool Bit::BitHandler::isEven(unsigned __int32 n)
{
	return !(n & 1);
}


bool Bit::BitHandler::isOdd(unsigned __int32 n)
{
	return (n & 1);
}


bool Bit::BitHandler::isPowerOf2(unsigned __int32 n)
{
	return n && !(n & (n - 1));
}


bool Bit::BitHandler::isPowerOf4(unsigned __int32 n)
{
	if (n && !(n & (n - 1)))
	{
		int countDisabledBits = 0;
		while (n > 1)
		{
			n >>= 1;
			countDisabledBits++;
		}
		return !(countDisabledBits & 1);
	}

	return false;
}


bool Bit::BitHandler::isBinaryPalindrome(unsigned __int8 n)
{
	__int8 left = sizeof(n) * 8 - 1;
	__int8 right = 0;

	while (left > right)
	{
		if (((n >> left) & 1) ^ ((n >> right) & 1))
			return false;

		left--;
		right++;
	}

	return true;
}


unsigned __int32 Bit::BitHandler::enableBit(unsigned __int32 n, int position)
{
	n |= 1 << (position - 1);

	return n;
}


unsigned __int32 Bit::BitHandler::disableBit(unsigned __int32 n, int position)
{
	n &= ~(1 << (position) - 1);

	return n;
}


unsigned __int32 Bit::BitHandler::flipBit(unsigned __int32 n, int position)
{
	n ^= 1 << position;

	return n;
}


unsigned __int32 Bit::BitHandler::flipAllBits(unsigned __int32 n)
{
	n ^= 0xffffffff;

	return n;
}


bool Bit::BitHandler::isBitEnabled(unsigned __int32 n, int position)
{
	//return (n & (1 << position)) >> position;
	return (n >> position) & 1;
}


bool Bit::BitHandler::isBitDisabled(unsigned __int32 n, int position)
{
	return !((n >> position) & 1);
}


unsigned __int32 Bit::BitHandler::countEnabledBits(unsigned __int32 n)
{
	__int32 count = 0;

	while (n)
	{
		n = n & (n - 1);
		count++;
	}

	return count;
}


unsigned __int32 Bit::BitHandler::reverseOrder(unsigned __int32 n)
{
	unsigned __int32 result = 0;
	int count = 0;

	while (n)
	{
		result <<= 1;
		result |= (n & 1);
		n >>= 1;
		count++;
	}
	result <<= ((sizeof(n) * 8) - count);

	return result;
}


unsigned __int32 Bit::BitHandler::rotateLeft(unsigned __int32 n)
{
	return (n << 1) | (n >> (sizeof(n) * 8) - 1);
}


unsigned __int32 Bit::BitHandler::rotateRight(unsigned __int32 n)
{
	return ((n & 1) << (sizeof(n) * 8) - 1) | (n >> 1);
}

	
unsigned __int8 Bit::BitHandler::reverseByte(unsigned __int8 n)
{
	n = ((n & 0b11110000) >> 4) | ((n & 0b00001111) << 4);
	n = ((n & 0b11001100) >> 2) | ((n & 0b00110011) << 2);
	n = ((n & 0b10101010) >> 1) | ((n & 0b01010101) << 1);

	return n;
}


unsigned __int32 Bit::BitHandler::reverseOctet(unsigned __int32 n)
{
	n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
	n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);

	return n;
}


unsigned __int32 Bit::BitHandler::swapOddEven(unsigned __int32 n)
{
	return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}


unsigned __int32 Bit::BitHandler::nextPowerOf2(unsigned __int32 n)
{
	if (n && !(n & (n - 1)))
		return n;

	unsigned __int32 result = 1;
	while (result < n)
	{
		result <<= 1;
	}

	return result;
}


bool Bit::BitHandler::isOddParity(unsigned __int32 n)
{
	bool parity = false;

	while (n)
	{
		n = n & (n - 1);
		parity = !parity;
	}

	return parity;
}


bool Bit::BitHandler::isEvenParity(unsigned __int32 n)
{
	bool parity = true;

	while (n)
	{
		n = n & (n - 1);
		parity = !parity;
	}

	return parity;
}


unsigned __int32 Bit::BitHandler::countDifferentBits(unsigned __int32 n1, unsigned __int32 n2)
{
	unsigned __int32 count = 0;

	unsigned __int32 XOR = n1 ^ n2;
	while (XOR)
	{
		XOR = XOR & (XOR - 1);
		count++;
	}

	return count;
}


unsigned __int32 Bit::BitHandler::multiplyBySeven(unsigned __int32 n)
{
	return (n << 3) - n;
}


unsigned __int32 Bit::BitHandler::occurOddTimes(unsigned __int32 * arr, unsigned __int32 size)
{
	unsigned __int32 result = 0;

	for (__int32 i = 0; i < size; i++)
		result ^= arr[i];

	return result;
}


unsigned __int32 Bit::BitHandler::addOne(unsigned __int32 n)
{
	/*
	int i = 0;
	while ((n >> i) & 1)
	{
		n ^= (1 << i++);
	}
	n ^= 1 << i;

	return n;
	*/

	return -(~n);
}


unsigned __int32 Bit::BitHandler::minimum(unsigned __int32 n1, unsigned __int32 n2)
{
	return n2 ^ (n1 ^ n2) & -(n1 < n2);
}


unsigned __int32 Bit::BitHandler::maximum(unsigned __int32 n1, unsigned __int32 n2)
{
	return n1 ^ (n1 ^ n2) & -(n1 < n2);
}


void Bit::BitHandler::swapTwoNumbers(__int32 & n1, __int32 &n2)
{
	n1 ^= n2 ^= n1 ^= n2;
}


unsigned __int32 Bit::BitHandler::getTheOneNonRepeat(unsigned __int32 * arr, unsigned __int32 size)
{
	unsigned __int32 result = 0;

	for (int i = 0; i < size; i++)
		result ^= arr[i];

	return result;
}


void Bit::BitHandler::getTwoNonRepeatElements(int * arr, int size, int * res1, int * res2)
{
	int XOR = 0;
	*res1 = 0;
	*res2 = 0;

	for (int i = 0; i < size; i++)
		XOR ^= arr[i];

	int rightMostBit = XOR & -XOR;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] & rightMostBit)
			*res1 ^= arr[i];
		else
			*res2 ^= arr[i];
	}
}
