// Name: Yuan-Kai Han
// Seneca Student ID: 154477194
// Seneca email: yhan77@myseneca.ca
// Date of completion: MS3
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"

namespace sdds
{
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};


    Workstation::Workstation(const std::string& str) : Station(str) {}

    void Workstation::fill(std::ostream& os)
    {
        if (!m_orders.empty())
            m_orders.front().fillItem(*this, os);
    }

    // when we were trying to move something to next station. We're going to doing that via m_pNextStation
    //First, check that this current order at the front can it be serviced?
    // Is it filled already or is it not completely filled?
    // If it is completely filled that means the order is done. (No more processing)
    // On the orther hand, is it not completely though? Can it be filled at the particular station?

    //Based on whether it has been completely filled or not at that stage
    bool Workstation::attemptToMoveOrder()
    {
        bool moved = false;
        if (!m_orders.empty())
        {
            if (m_orders.front().isItemFilled(Station::getItemName()) || Station::getQuantity() <= 0)
            {
                if (m_pNextStation)
                {
                    *m_pNextStation += std::move(m_orders.front());
                    m_orders.pop_front();
                }
                else
                {
                    (m_orders.front().isOrderFilled()) ? g_completed.push_back(std::move(m_orders.front())) : g_incomplete.push_back(std::move(m_orders.front()));

                    m_orders.pop_front();
                }
                moved = true;
            }
        }
        return moved;
    }

    void Workstation::setNextStation(Workstation* station)
    {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const
    {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const
    {
        if (m_pNextStation)
            os << getItemName() << " --> " << getNextStation()->getItemName() << std::endl;
        else
            os << getItemName() << " --> End of Line" << "\n";
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
    {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }

}