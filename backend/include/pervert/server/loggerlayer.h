//
//  layer
//
//  Created by Niels Joubert on 2011-11-30.
//

#ifndef PERVERT_SERVER_LOGGER_H_
#define PERVERT_SERVER_LOGGER_H_

#include <iostream>
#include <fstream>

#include "pervert/server/server.h"

namespace PerVERT {
namespace Server {
	
using namespace Utils;

enum LoggerLayerLevel { TINY, BIG };

class LoggerLayer : public Layer {
public:
	LoggerLayer(LoggerLayerLevel l, const char* file);
	const char* name();

	void handle(Request* req, Response* res);

	void afterwards(Request* req, Response* res);
	
private:
	std::ofstream _file;
	LoggerLayerLevel _l;
	
};


} /* namespace Server */
} /* namespace PerVERT */


#endif /* PERVERT_SERVER_LOGGER_H_ */ 