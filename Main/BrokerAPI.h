#ifndef _BROKERAPI_h
#define _BROKERAPI_h

namespace 
class BrokerAPI {
	void ubiSetup(void callback(char*, unsigned char*, unsigned int));

	void ubiConnect();
	void ubiLoop();

	void ubiSubscribe(Device* d);
	void ubiSetCallback(void callback(char*, unsigned char*, unsigned int));

	void ubiCheck(Device* d);

	int ubiCommit(Device* d, int var);
	void ubiPush(Device* d);
};

#endif

