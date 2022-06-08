#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include "../../../kriterium/KriteriumUJVekovaSkupinaPocet.h"

namespace structures
{
	template <typename K, typename T>
	class QuickSortVekSkup : public Sort<K, T>
	{
	public:
		void sort(UnsortedSequenceTable<K, T>& table) override;
		QuickSortVekSkup(TypVekovejSkupiny typVekovejSkupiny) : typVekovejSkupiny_(typVekovejSkupiny) {}
	private:
		void quick(int min, int max, UnsortedSequenceTable<K, T>& table);
		TypVekovejSkupiny typVekovejSkupiny_;
	};


	template<typename K, typename T>
	inline void QuickSortVekSkup<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		this->quick(0, table.size() - 1, table);
	}

	template<typename K, typename T>
	inline void QuickSortVekSkup<K, T>::quick(int min, int max, UnsortedSequenceTable<K, T>& table)
	{
		KriteriumUJVekovaSkupinaPocet* kriteriumUJVekovaSkupinaPocet = new KriteriumUJVekovaSkupinaPocet(typVekovejSkupiny_);

		int pivot = kriteriumUJVekovaSkupinaPocet->evaluate(dynamic_cast<UzemnaJednotka*>(table.getItemAtIndex((min + max) / 2).accessData()));
		int lavy = min;
		int pravy = max;
		while (lavy < pravy)
		{
			while (kriteriumUJVekovaSkupinaPocet->evaluate(dynamic_cast<UzemnaJednotka*>(table.getItemAtIndex(lavy).accessData())) < pivot) {
				lavy++;
			}
			while (kriteriumUJVekovaSkupinaPocet->evaluate(dynamic_cast<UzemnaJednotka*>(table.getItemAtIndex(pravy).accessData())) > pivot) {
				pravy--;
			}
			if (lavy <= pravy) {
				table.swap(lavy, pravy);
				lavy++;
				pravy--;
			}
		}
		if (min < pravy)this->quick(min, pravy, table);
		if (lavy < max)this->quick(lavy, max, table);

		delete kriteriumUJVekovaSkupinaPocet;
	};
}