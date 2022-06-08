#include "vector.h"
#include "../utils.h"
#include <cstdlib>
#include <cstring>


namespace structures
{
	Vector::Vector(size_t size) :
		memory_(std::calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(Vector& other) :
		Vector(other.size_)
	{
		memcpy(memory_, other.memory_, size_);
	}

	Vector::~Vector()
	{
		free(memory_);
		memory_ = nullptr;
		size_ = 0;
	}

	size_t Vector::size()
	{
		return size_;
	}

	Structure& Vector::assign(Structure& other)
	{
		//ak vektro nie je identicky s other
		// priradit size
		// realokovat memory: realloc
		// prekopirovat prvky: memcpy
		if (this != &other) {
			Vector& otherVector = dynamic_cast<Vector&>(other);
			size_ = otherVector.size_;
			memory_ = realloc(memory_, size_);
			memcpy(memory_, otherVector.memory_, size_);
		}

		return *this;
	}

	bool Vector::equals(Structure& other)
	{

		if (this == &other) return true;
		else
		{
			Vector* otherVector = dynamic_cast<Vector*>(&other);
			if (otherVector != nullptr) return size_ == otherVector->size_ && memcmp(memory_, otherVector->memory_, size_) == 0;
			else return false;
		}
	}

	byte& Vector::operator[](int index)
	{
		return at(index);
	}

	byte& Vector::at(int index)
	{
		Utils::rangeCheckExcept(index, size_, "Invald index!");
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	void Vector::copy(Vector& src, int srcStartIndex, Vector& dest, int destStartIndex, int length)
	{
		// musime skonrolovat
		//	srcStartIndex musi patrit do <0, src.size)
		//	desStartIndex musi poatrit do <0, dest.size)
		//	srcStartIndex + length msi byt <= ako src.size
		//	destStartIndex + length msi byt <= ako dest.size
		Utils::rangeCheckExcept(srcStartIndex, src.size_, "Invalid srcStartIndex index!");
		Utils::rangeCheckExcept(destStartIndex, dest.size_, "Invalid destStartIndex index!");
		Utils::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid srcStartIndex + length index!");
		Utils::rangeCheckExcept(destStartIndex + length, dest.size_ + 1, "Invalid destStartIndex + length index!");

		// ak su vektory identickevzdialenost medzi srcStartIndex a destStartIndex < length
		//	tak: memmove
		//	inak: memcpy
		if (&src == &dest && abs(srcStartIndex - destStartIndex) < length)
		{
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else {
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
	}

	byte* Vector::getBytePointer(int index)
	{
		Utils::rangeCheckExcept(index, size_, "Invald index!");
		return reinterpret_cast<byte*>(memory_) + index;
	}
}