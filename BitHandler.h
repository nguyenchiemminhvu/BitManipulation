#ifndef __BIT_HANDLER_H__
#define __BIT_HANDLER_H__

#pragma once

namespace Bit
{

	class BitHandler
	{
	public:
		BitHandler();
		virtual ~BitHandler();

		static bool isEven(unsigned __int32 n);
		static bool isOdd(unsigned __int32 n);
		static bool isPowerOf2(unsigned __int32 n);
		static bool isPowerOf4(unsigned __int32 n);

		static unsigned __int32 enableBit(unsigned __int32 n, int position);
		static unsigned __int32 disableBit(unsigned __int32 n, int position);
		static unsigned __int32 flipBit(unsigned __int32 n, int position);
		static unsigned __int32 flipAllBits(unsigned __int32 n);
		static bool isBitEnabled(unsigned __int32 n, int position);
		static bool isBitDisabled(unsigned __int32 n, int position);
		static unsigned __int32 countEnabledBits(unsigned __int32 n);
		static unsigned __int32 reverseBits(unsigned __int32 n);
		static unsigned __int32 rotateLeft(unsigned __int32 n);
		static unsigned __int32 rotateRight(unsigned __int32 n);

		static unsigned __int32 nextPowerOf2(unsigned __int32 n);
		static bool isOddParity(unsigned __int32 n);
		static bool isEvenParity(unsigned __int32 n);
		static unsigned __int32 countDifferentBits(unsigned __int32 n1, unsigned __int32 n2);

		static unsigned __int32 multiplyBySeven(unsigned __int32 n);
		static unsigned __int32 occurOddTimes(unsigned __int32 *arr, unsigned __int32 size);

		static unsigned __int32 addOne(unsigned __int32 n);
		
		static unsigned __int32 minimum(unsigned __int32 n1, unsigned __int32 n2);
		static unsigned __int32 maximum(unsigned __int32 n1, unsigned __int32 n2);
	};

}
#endif //__BIT_HANDLER_H__