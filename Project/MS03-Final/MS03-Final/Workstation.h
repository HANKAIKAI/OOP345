// Name: Yuan-Kai Han
// Seneca Student ID: 154477194
// Seneca email: yhan77@myseneca.ca
// Date of completion: MS3
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
#include"Station.h"
namespace sdds
{
    //Each queue is accessible outside this module's translation unit.
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;
    //workstation class
    class Workstation : public Station
    {
        //double ended queue
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation{ nullptr };

    public:
        Workstation(const std::string& str);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);

        //cannot be copied or moved
        Workstation(const Workstation&) = delete;
        Workstation& operator=(const Workstation&) = delete;
        Workstation(Workstation&&) = delete;
        Workstation& operator=(Workstation&&) = delete;
    };
}
#endif // !SDDS_WORKSTATION_H


