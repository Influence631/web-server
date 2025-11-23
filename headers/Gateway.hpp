#include <inttypes.h>
#include <unordered_map>

class Gateway{
	public:
	uint64_t SendOrder(const BuyOrder &order){return send_order(order)};
	uint64_t SendOrder(const SellOrder &order){return send_order(order)}

	private:
	template<typename OrderT>
	send_order(const OrderT &order);
};

template<typename OrderT>
uint64_t Gateway::send_order(const OrderT &order, User &user){
	if constexpr (std::is_same_v<OrderT, BuyOrder>){
		if(user.Balance >= order.LimitPrice * order.Volume){
			//eventqueue.add order
			//user.balance -= volume * limitprice (freeze the money to prevent double buys and race conditions)
		}
		else{
			return 0;
		}
		//buy side logic
		//check sufficient funds
	}
	else{
		if(user.Portfolio[order.Item] >= order.Volume){
			//eventqueue.add order
			//user.Portfolio[order.Item] -= volume. lock the stocks being processed to avoid race con and double selling
		}
		else{
			return 0;
	}
}
