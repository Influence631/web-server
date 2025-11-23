#include <inttypes.h>
#include <unordered_map>

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
	std::unordered_map<Stock, uint64_t> Portfolio;
};
