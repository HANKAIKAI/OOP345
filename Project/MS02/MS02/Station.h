// Name: Yuan-Kai Han
// Seneca Student ID: 154477194
// Seneca email: yhan77@myseneca.ca
// Date of completion: MS1
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
namespace sdds
{
    class Station
    {
        int m_id;
        std::string m_name{};
        std::string m_desc{};
        size_t m_nextNum{ 0u };
        size_t m_stockNum{ 0u };
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const std::string& station);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}
#endif // !SDDS_STATION_H

