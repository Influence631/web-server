#include <deque>
#include <list>
#include "Order.hpp"


struct PriceLevel{
	std::list<Order*> fifo;
};

struct LimitOrderBook{
	std::map<int32_t, PriceLevel> bids;
	std::map<int32_t, PriceLevel> asks;
};
