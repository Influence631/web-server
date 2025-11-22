#include <httplib.h>
#include <iostream>


int main(){
	httplib::Client cli("0.0.0.0", 8080);
	
	if(auto res = cli.Get("/position")){
		std::cout << res->status;
		std::cout << res->body;
	}	

	return 0;
}
