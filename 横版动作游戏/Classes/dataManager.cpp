//
//  dataManager.cpp
//  practice
//
//  Created by zwj on 16/5/26.
//
//

#include "dataManager.hpp"
#include "json/rapidjson.h"
#include "json/document.h"
using namespace rapidjson;

static dataManager *manager=nullptr;
dataManager* dataManager::getInstance()
{

    if (manager==nullptr) {
        
        manager=new dataManager();
        
    
    }
    return manager;

}
void dataManager::initWithJsonFile(const char *fileName)
{

    tollgateData=FileUtils::getInstance()->getStringFromFile(fileName);
    
   log("打印json数据 %s",tollgateData.c_str());

}

std::vector<std::string> dataManager::getLevelDataByIndex(int index)
{
    Document doc;
    doc.Parse<kParseDefaultFlags>(tollgateData.c_str());
    _levelDataArry.clear();
    rapidjson::Value &arry=doc["Tollgate"];
    if (arry.IsArray()) {
        int i=index;
        int j=0;
        for (j=0; j<arry[i]["RoleData"].Size(); j++) {
            rapidjson::Value &str=arry[i]["RoleData"][j];
            log("test str is %s",str.GetString());
            _levelDataArry.push_back(str.GetString());
        }
    }
    return _levelDataArry;
}