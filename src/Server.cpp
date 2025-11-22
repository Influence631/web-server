#include <iostream>
#include "httplib.h"
#include <thread>

int main(){
	httplib::Server srv;

	srv.Get("/position", [](const httplib::Request&, httplib::Response &res){
		res.set_content("Hello world", "text/plain");
	});
	
	std::cout << "Starting the server\n\r";
	std::thread server_thread([&srv](){
		if(!srv.listen("0.0.0.0", 8080))
			std::cerr << "Failed to start the server\n\r";
	});
	std::cout << "Server launched in the background\n\r";
 
	server_thread.join();
	return 0;
}
