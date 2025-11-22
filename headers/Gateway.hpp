#include <inttypes.h>

enum OrderType : uint8_t{
	Buy = 0,
	Sell = 1,
};

struct BuyOrder{
	uint32_t Volume = 0;
	int32_t LimitPrice = 0;
};

struct SellOrder{
	uint32_t Volume = 0;
	int32_t LimitPrice = 0;
};

class Gateway{
	public:
	uint64_t SendOrder(const BuyOrder &order){return send_order(order)};
	uint64_t SendOrder(const SellOrder &order){return send_order(order)}

	private:
	template<typename OrderT>
	send_order(const OrderT &order);
};

template<typename OrderT>
uint64_t Gateway::send_order(const OrderT &order, uint64_t userId){
	if constexpr (std::is_same_v<OrderT, BuyOrder>){
		//buy side logic
		//check sufficient funds
	}
	else{
		//sell side logic
		//check sufficient shares for user
	}
	
}
