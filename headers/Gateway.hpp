#include <inttypes.h>

enum OrderType : uint8_t{
	Buy = 0,
	Sell = 1,
};

enum Stock : uint8_t{
	None = 0,
	Intel = 1,
	Palantir = 2,
	NVIDIA = 3,
};

struct BuyOrder{
	uint32_t Volume = 0;
	int32_t LimitPrice = 0;
	Stock Stock = None;
};

struct SellOrder{
	uint32_t Volume = 0;
	int32_t LimitPrice = 0;
	Stock Stock = None;
};

struct Stock{
	Stock StockID;
};

struct User{
	uint64_t ID;
	int64_t Balance;
	unordered_map<Stock, uint64_t> Portfolio;
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
