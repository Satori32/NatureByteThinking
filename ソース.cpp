#include <iostream>
#include <array>
#include <cstdint>
#include <vector>

#include "FixedHeapArray.h"

#if 0
static const std::size_t RAWBYTESIZE = 2 * 1024 * 1024 * 1024 * 1024;// 2Peta Natural RawByte.
#else
static const std::size_t RAWBYTESIZE = 16*1024;
#endif
#if 1
template<class BYTE,std::size_t RawByte> using Bit = std::array<BYTE,RawByte>;
#else
template<class BYTE,std::size_t RawByte> using Bit = FixedHeapArray<BYTE,RawByte>;
#endif


template<class BIT,std::size_t Size>
class NBYTE {
public:
	typedef std::array<BIT, Size> BYTE;
	NBYTE() { B.fill(BIT{}); }

	const BYTE& get() {
		return B;
	}

	std::size_t Size() {
		return Size;
	}

	bool Set(std::size_t Idx, const BIT& V) {
		if (Size >= Idx)return false;
		
		B[Idx] = V;
		return true;
	}

protected:
	BYTE B;
};

template<class BIT>
class AirProtocolObject{
public:
	AirProtocolObject() { B.fill(BIT{}); }
	typedef std::array<BIT, 3> BYTE;
	const BYTE& get() {
		return B;
	}

	std::size_t Size() {
		return B.size();
	}

	bool Set(std::size_t Idx, const BIT& V) {
		if (Size >= Idx)return false;
		
		B[Idx] = V;
		return true;
	}

protected:
	BYTE B;
};

using BIT = Bit<std::uint8_t, RAWBYTESIZE>;
using BITMini = Bit<std::uint8_t, (RAWBYTESIZE/30000)? RAWBYTESIZE/30000:1>;


int main() {
	NBYTE<BIT,3> B;
	AirProtocolObject<BITMini> APO;
	
	FixedHeapArray<int, 16> FHA;
	for (std::size_t i = 0; i < FHA.size(); i++) {
		std::cout << FHA[i] << std::endl;
	}
	return 0;
}