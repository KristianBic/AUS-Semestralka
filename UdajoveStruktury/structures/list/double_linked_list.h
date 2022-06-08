#pragma once

#include "linked_list.h"
#include "list.h"
namespace structures
{
    template<typename T>
    class DoubleLinkedListItem : public LinkedListItem<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        /// <param name = "data"> Data, ktore uchovava. </param>
        DoubleLinkedListItem(T data);

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Prvok jednstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
        DoubleLinkedListItem(DoubleLinkedListItem<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedListItem();

        /// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
        DoubleLinkedListItem<T>* getPrev();
        DoubleLinkedListItem<T>* getNext();
        /// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <param name´= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
        void setPrev(DoubleLinkedListItem<T>* prev);
        void setNext(DoubleLinkedListItem<T>* next);

    private:
        /// <summary> Nasledujuci prvok zretazeneho zoznamu. </summary>
        DoubleLinkedListItem<T>* prev_;
        DoubleLinkedListItem<T>* next_;

    };
    template<typename T>
    class DoubleLinkedList : public LinkedList<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        DoubleLinkedList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> DoubleLinkedList, z ktoreho sa prevezmu vlastnosti. </param>
        DoubleLinkedList(DoubleLinkedList<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedList();

        /// <summary> Vrati pocet prvkov v zozname. </summary>
        /// <returns> Pocet prvkov v zozname. </returns>
        size_t size() override;

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Porovnanie struktur. </summary>
        /// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
        /// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
        bool equals(Structure& other) override;

        /// <summary> Vrati adresou prvok na indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Adresa prvku na danom indexe. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T& at(int index) override;
        /// <summary> Prida prvok do zoznamu. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        void add(const T& data) override;

        /// <summary> Vlozi prvok do zoznamu na dany index. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        /// <param name = "index"> Index prvku. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        /// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
        void insert(const T& data, int index) override;

        /// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
        /// <param name = "data"> Odstranovany prvok. </param>
        /// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
        bool tryRemove(const T& data) override;

        /// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T removeAt(int index) override;

        /// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
        /// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
        /// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
        int getIndexOf(const T& data) override;
        std::vector<std::string> vypis();
        /// <summary> Vymaze zoznam. </summary>
        void clear() override;
        DoubleLinkedListItem<T>* getItemAtIndex(int index);
    private:
        DoubleLinkedListItem<T>* first_;
        DoubleLinkedListItem<T>* last_;
        size_t size_;

    };
    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(T data) :
        LinkedListItem<T>(data),
        prev_(nullptr),
        next_(nullptr)
    {
    };
    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(DoubleLinkedListItem<T>& other) :
        LinkedListItem<T>(other),
        prev_(other.prev_),
        next_(other.next_)
    {
    };
    template<typename T>
    inline DoubleLinkedListItem<T>::~DoubleLinkedListItem() {
        prev_=nullptr;
        next_=nullptr;
    };
    template<typename T>
    DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getPrev() {
        return this->prev_;
    };

    template<typename T>
    DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getNext() {
        return this->next_;
    };

    template<typename T>
    void DoubleLinkedListItem<T>::setPrev(DoubleLinkedListItem<T>* prev) {
        prev_ = prev;
    };

    template<typename T>
    void DoubleLinkedListItem<T>::setNext(DoubleLinkedListItem<T>* next) {
        next_ = next;
    };
   

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList() :
        size_(0),
        first_(nullptr),
        last_(nullptr)
    {
    };

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T>& other):
        DoubleLinkedList()
    {
        assign(other);
    }

    template<typename T>
    inline DoubleLinkedList<T>::~DoubleLinkedList()
    {
        clear();
    }

    template<typename T>
    inline size_t DoubleLinkedList<T>::size()
    {
        return size_;
    }

    template<typename T>
    inline Structure& DoubleLinkedList<T>::assign(Structure& other)
    {
        if (this != &other) {
            DoubleLinkedList<T>& otherList = dynamic_cast<DoubleLinkedList<T>&>(other);
            clear();
            DoubleLinkedListItem<T>* otherItem = otherList.first_;
            while (otherItem != nullptr) {
                add(otherItem->accessData());
                otherItem = otherItem->getNext();
            }
        }
        return *this;
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::equals(Structure& other)
    {
        if (this == &other) return true;
        DoubleLinkedList<T>* otherList = dynamic_cast<DoubleLinkedList<T>*>(&other);
        if (otherList == nullptr || this->size_ != otherList->size_) return false;

        DoubleLinkedListItem<T>* curThis = this->first_;
        DoubleLinkedListItem<T>* curOther = otherList->first_;
        while (curThis != nullptr) {
            if (curThis->accessData() != curOther->accessData()) return false;
            else {
                curThis = curThis->getNext();
                curOther = curOther->getNext();
            }
        }
        return true;
    }

    template<typename T>
    inline T& DoubleLinkedList<T>::at(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index");
        return getItemAtIndex(index)->accessData();
    }

    template<typename T>
    inline void DoubleLinkedList<T>::add(const T& data)
    {
        ++size_;
        DoubleLinkedListItem<T>* newItem{ new DoubleLinkedListItem<T>(data) };
        if (first_ == nullptr) first_ = newItem;
        else {
            newItem->setPrev(last_);
            last_->setNext(newItem);
        }
        last_ = newItem ;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::insert(const T& data, int index)
    {
        if (index == size_) add(data);
        else {
            Utils::rangeCheckExcept(index, size_, "Out of range!");
            DoubleLinkedListItem<T>* newList{ new DoubleLinkedListItem<T>(data) };
            if (index == 0) {
                newList->setNext(first_);
                first_->setPrev(newList);
                first_= newList ;
            }
            else {
                DoubleLinkedListItem<T>* prevList{ getItemAtIndex(index - 1) };
                DoubleLinkedListItem<T>* nextList{ prevList->getNext() };
                prevList->setNext(newList);
                newList->setNext(nextList);
                newList->setPrev(prevList);
                nextList->setPrev(newList);
            }
            ++size_;
        }
    }
    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedList<T>::getItemAtIndex(int index)
    {
        if (index == size_ - 1) return last_;
        else if (index == 0) return first_;
        else if (index <= (size_ / 2)) {
            DoubleLinkedListItem<T>* current = first_;
            for (size_t i = 0; i < index; ++i) {
                current = current->getNext();
            }
            return current;
        }
        else {
            DoubleLinkedListItem<T>* current = last_;
            for (size_t i = (size_ - 1); i > index; --i) {
                current = current->getPrev();
            }
            return current;
        }
        /*
        DoubleLinkedListItem<T>* current = first_;
        for (size_t i = 0; i < index; i++) {
            current = current->getNext();
        }
        return current;*/
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::tryRemove(const T& data)
    {
        int index = getIndexOf(data);
        if (index != -1) {
            removeAt(index);
            return true;
        }
        return false;
    }

    template<typename T>
    inline T DoubleLinkedList<T>::removeAt(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index!");
        DoubleLinkedListItem<T>* delItem;
        if (size_ == 1) {
            delItem = first_ ;
            first_ = last_ = nullptr;
        }
        else if (index == 0) {
                delItem = first_;
                first_ = first_->getNext();
        }
        else {
            DoubleLinkedListItem<T>* pred = getItemAtIndex(index - 1) ;
            delItem = pred->getNext();
            DoubleLinkedListItem<T>* dalsi = delItem->getNext();
            pred->setNext(dalsi);
            dalsi->setPrev(pred);
            if (last_ == delItem) last_ = pred;
        }
        T result = delItem->accessData();
        delete delItem;
        --size_;
        return result;
    }

    template<typename T>
    inline int DoubleLinkedList<T>::getIndexOf(const T& data)
    {
        DoubleLinkedListItem<T>* prem{ first_ };
        for (size_t i = 0; i < size_; i++) {
            if (prem->accessData() == data) return i;
            prem = prem->getNext() ;
        }
        return -1;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::clear()
    {
        DoubleLinkedListItem<T>* curr{ first_ };
        while (curr != nullptr)
        {
            curr = curr->getNext();
            delete first_;
            first_ = curr;
        }
        last_ = nullptr;
        size_ = 0;
    }


    template<typename T>
    inline std::vector<std::string> DoubleLinkedList<T>::vypis() {
        std::string text =  "Hodnota:     ";
        std::string text2 = "Umiestnenie: ";
        for (size_t i = 0; i < size_; ++i) {
            if (std::to_string(this->at(i)).length() == 1) text += " " + std::to_string(this->at(i)) + "   |";
            else text += std::to_string(this->at(i)) + " |";
            text2 += std::to_string(i) + "   |";
        }
        std::vector<std::string> pole;
        pole.push_back(text);
        pole.push_back(text2);
        return pole;
    }
}