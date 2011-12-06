//
//  pervertlayer
//
//  Created by Niels Joubert on 2011-11-30.
//

#ifndef PERVERT_APP_PERVERTLAYER_H_
#define PERVERT_APP_PERVERTLAYER_H_

#include <iostream>
#include <fstream>

#include "pervert/server/httplayer.h"
#include "utils/log.h"

namespace PerVERT {
namespace App {
	
using namespace Utils;

class PervertLayer : public Server::HTTPLayer {
public:
	PervertLayer();
	void handle(Server::Request* req, Server::Response* res);
	char* name();
private:
	Log& _log;
};


} /* namespace Server */
} /* namespace PerVERT */


#endif /* PERVERT_APP_PERVERTLAYER_H_ */ 