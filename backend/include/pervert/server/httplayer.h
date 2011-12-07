//
//  httplayer
//
//  Created by Niels Joubert on 2011-11-30.
//

#ifndef PERVERT_APP_HTTPLAYER_H_
#define PERVERT_APP_HTTPLAYER_H_

#include <iostream>
#include <fstream>

#include "pervert/server/server.h"

namespace PerVERT {
namespace Server {
	
using namespace Utils;

/* This is an intermediate layer object that provides an API to return HTTP data. */
class HTTPLayer : public Layer {
public:
	virtual void handle(Request* req, Response* res) = 0;
	virtual const char* name() = 0;

protected:
	void writeHeadersEnd(Request* req, Response* res);
	void writeStatus(Request* req, Response* res, int code);
	void writeStatusAndEnd(Request* req, Response* res, int code);
	void writeOKResponseWithContentLength(Request* req, Response* res, const char* data, size_t len);

private:

};


} /* namespace Server */
} /* namespace PerVERT */


#endif /* PERVERT_APP_HTTPLAYER_H_ */ 