#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include "../../../kriterium/KriteriumUJVekPodiel.h"

//podla podielu
namespace structures
{
	template <typename K, typename T>
	class QuickSort : public Sort<K, T>
	{
	public:
		void sort(UnsortedSequenceTable<K, T>& table) override;
		QuickSort(int vek, TypPohlavia pohlavie) : vek_(vek), pohlavie_(pohlavie) {}
	private:
		void quick(int min, int max, UnsortedSequenceTable<K, T>&table);
		int vek_;
		TypPohlavia pohlavie_;
	};


	template<typename K, typename T>
	inline void QuickSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		this->quick(0, table.size() - 1, table);
	}

	template<typename K, typename T>
	inline void QuickSort<K, T>::quick(int min, int max, UnsortedSequenceTable<K, T>& table)
	{
		KriteriumUJVekPodiel* kriteriumUJVekPodiel = new KriteriumUJVekPodiel(vek_, pohlavie_);

		double pivot = kriteriumUJVekPodiel->evaluate(dynamic_cast<UzemnaJednotka*>(table.getItemAtIndex((min + max) / 2).accessData()));
		//int lavy = 0;
		//int pravy = 1;
		int lavy = min;
		int pravy = max;
		while (lavy < pravy)
		{
			while (kriteriumUJVekPodiel->evaluate(dynamic_cast<UzemnaJednotka*>(table.getItemAtIndex(lavy).accessData())) < pivot) {
				lavy++;
			}
			while (kriteriumUJVekPodiel->evaluate(dynamic_cast<UzemnaJednotka*>(table.getItemAtIndex(pravy).accessData())) > pivot) {
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

		delete kriteriumUJVekPodiel;
	};
}