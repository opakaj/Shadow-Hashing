//#define _HAS_STD_BYTE 0

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <crixus.h>
#include <anti.h>
#include <cstdlib>

#include "cinatra.hpp"
#include "http_server.hpp"

using namespace cinatra;

/*int main()
{
	http_server server(std::thread::hardware_concurrency());
	server.listen("127.0.0.1", "8080");

	struct api
	{
		void password(request& req, response& res)
		{
			auto pass = req.get_query_value("pass");
			auto password = std::string(pass.data(), pass.length());
			//std::pair<string, string> p = crixus(std::move(password));

			res.render_json(nlohmann::json{ {"sha256",std::to_string(password)},{ "shadow" , "dgdsg" } });
		}
	};

	api t;

	server.set_http_handler<GET, POST>("/password", &api::password, &t);

	server.run();

	return 0;
}

*/

int main()
{
	http_server server(std::thread::hardware_concurrency());
	server.listen("127.0.0.1", "8080");

	struct api
	{
		void password(request& req, response& res)
		{
			auto pass = req.get_query_value("pass");
			auto password = std::string(pass.data(), pass.length());
			//std::pair<std::string, std::string> p = crixus(std::move(password));

			res.render_json(nlohmann::json{ {"sha256",password},{"shadow", "hfchg"} });
		}
	};

	api t;

	server.set_http_handler<GET>("/password", &api::password, &t);

	server.run();

	return 0;
}