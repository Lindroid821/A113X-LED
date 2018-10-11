#include <stdio.h>

int main(int argc,char* argv[])
{
	int i;
	printf("Hello NST ---> Happy birthday!\n");
	
	for(i = 0;i < argc;i++){
		printf("Hello: argv[%d]=%s\n",i,argv[i]);
	}
	/*
	//读取序号
	__system_property_get("ro.serialno", m_szDevID);
	LOGE("DevID : %s", m_szDevID);

	__system_property_get("ro.product.brand", m_szDevBrand);
	LOGE("Brand : %s", m_szDevBrand);
	//读取机型 
	__system_property_get("ro.product.model", m_szDevModel);
	LOGE("Model : %s", m_szDevModel);

	//读取sdk版本
	__system_property_get("ro.build.version.sdk", m_szSdkVer);
	LOGE("SDK ver : %s", m_szSdkVer);*/

	return 0;
}
