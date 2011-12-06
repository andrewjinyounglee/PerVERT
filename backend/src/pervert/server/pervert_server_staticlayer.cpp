#include "pervert/server/staticlayer.h"
#include <sys/times.h>
#include <sys/stat.h>
#include <unistd.h>

namespace PerVERT {
namespace Server {

StaticLayer::StaticLayer(char* httproot, unsigned int maxfilesize) {
	#define MAXPATHLEN 1024
	char temp[MAXPATHLEN];
	
	getcwd(temp, MAXPATHLEN); 
	string cwd = string(temp);
	#undef MAXPATHLEN
	
	_httproot = cwd.append(string(httproot));
	_maxfilesize = maxfilesize;
}

void StaticLayer::handle(Request* req, Response* res) {
	const struct mg_request_info *request_info = req->request_info;
	
	if (strcmp(request_info->request_method,"GET") == 0) {
		
		//set up path
		string f = string(_httproot);
		string uri = string(request_info->uri);
		f.append(uri);
		if ((uri.at(uri.length() - 1)) == '/') {
			f.append("index.html");
		}
		
		//does this file exist?
		if (access(f.c_str(), R_OK) != 0) {
			return writeStatus(req,res,404);
		}
		
		struct stat status;
		stat(f.c_str(), &status);
		
		//pull file from disk
		if (status.st_size > _maxfilesize) {
			writeStatus(req,res,413);
		} else {
			char* filedata = new char[status.st_size];
			FILE* fd = fopen(f.c_str(),"r");
			size_t readstatus = fread(filedata,sizeof(char),status.st_size,fd);
			if (readstatus != status.st_size) {
				writeStatus(req,res,500);
			} else {
				writeStaticPage(req,res,filedata, readstatus);
				//close
				
			}
			delete filedata;
		}
		
	} else {
		return next(req,res);
	}
	
}

char* StaticLayer::name() {
	return "StaticLayer";
}

} /* namespace Server */
} /* namespace PerVERT */