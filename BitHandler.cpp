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


unsigned __int32 Bit::BitHandler::enableBit(unsigned __int32 n, int position)
{
	n |= 1 << position;

	return n;
}


unsigned __int32 Bit::BitHandler::disableBit(unsigned __int32 n, int position)
{
	n &= !(1 << position);

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


unsigned __int32 Bit::BitHandler::reverseBits(unsigned __int32 n)
{
	unsigned __int32 result = 0;

	while (n)
	{
		result <<= 1;
		result |= (n & 1);
		n >>= 1;
	}

	return result;
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

	while (n1 && n2)
	{
		count += (n1 & 1) ^ (n2 & 1);

		n1 >>= 1;
		n2 >>= 1;
	}

	while (n1)
	{
		count++;
		n1 >>= 1;
	}

	while (n2)
	{
		count++;
		n2 >>= 1;
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
