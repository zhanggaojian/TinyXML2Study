#include<iostream>
#include"tinyXML2/tinyxml2.h"
using namespace std;

void createXML(){
    tinyxml2::XMLDocument xml;

    //插入声明
    tinyxml2::XMLDeclaration* dec = xml.NewDeclaration();
    xml.InsertFirstChild(dec);

    //插入根节点
    tinyxml2::XMLElement* rootNode = xml.NewElement("zhang");
    xml.InsertEndChild(rootNode);

    //插入一个name节点
    tinyxml2::XMLElement *root_1_name = xml.NewElement("name");
    tinyxml2::XMLText *text_1_name = xml.NewText("zgj");
    //将name节点和文本连接起来
    root_1_name -> InsertFirstChild(text_1_name);

    //新建一个age节点
    tinyxml2::XMLElement* root_1_age=xml.NewElement("age");
    tinyxml2::XMLText* text_1_age = xml.NewText("25");
    root_1_age -> InsertFirstChild(text_1_age);

    //链接name节点与根节点
    rootNode->InsertEndChild(root_1_name);
    rootNode->InsertEndChild(root_1_age);
    xml.SaveFile("zgj.xml");
    
}

void parseXML(){
    tinyxml2::XMLDocument xml;

    //导入xml文件
    if(xml.LoadFile("zgj.xml")!= tinyxml2::XML_SUCCESS){
        return;
    }

    //判断头文件是否为空
    tinyxml2::XMLElement *rootNode = xml.RootElement();
    if(rootNode==nullptr){
        cout<<"xml root is null!"<<endl;
        return;
    }

    //读取第一层信息 name
    tinyxml2::XMLElement* root_1_name = rootNode->FirstChildElement("name");
    //读取第一层信息 age
    tinyxml2::XMLElement* root_1_age = rootNode->FirstChildElement("age");

    //信息输出
    string text_name = root_1_name->GetText();
    std::cout<<"name is : "<<text_name<<std::endl;

    string text_age = root_1_age->GetText();
    std::cout<<"age is : "<<text_age<<std::endl;
}
int main(){
    createXML();
    parseXML();
    return 0;
}