//
//  pervertlayer
//
//  Created by Niels Joubert on 2011-11-30.
//

#ifndef PERVERT_APP_PERVERTLAYER_H_
#define PERVERT_APP_PERVERTLAYER_H_

#include <iostream>
#include <fstream>

#include "pervert/server/server.h"

namespace PerVERT {
namespace App {
	
using namespace Utils;

class PervertLayer : public Server::Layer {
public:
	PervertLayer();
	void handle(Server::Request* req, Server::Response* res);
	char* name();
private:

};


} /* namespace Server */
} /* namespace PerVERT */


#endif /* PERVERT_APP_PERVERTLAYER_H_ */ 