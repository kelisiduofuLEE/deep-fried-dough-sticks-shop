/*
 *	xml文档时树形结构的文件。一个xml文档包含element，attribute，text，
 *	element包含attribute和text和其他element，attribute包含key和value。
 *	xml必须要有关闭标签，声明不是xml文档的组成部分，不需要关闭标签。标签对大小写敏感。
 *	xml标签是一对一匹配的关系，可以嵌套，但是在一对标签内嵌套，必须包含一对。
 *	xml文档必须包含根元素。是其他元素的父亲，其他元素也可以拥有子元素。
 *	xml的attribute包含一个键值对，形如：key="val"，值必须加""
 *	xml文档中'<'，'&'是非法字符，应该用实体引用&lt;和&amp;来替代。
 *	xml的注释：形如<!-- This is a comment -->
 *	xml文档中，空格都会被保留。
 *	xml中的属性最好不要使用，属性最好事那些与数据无关的，比如元数据（描述数据的数据）
 *	<?xml version="1.0" encoding="ISO-8859-1"?> 表示版本，字符编码
 *	
 */


#pragma once



#include "strBase.h"

#ifndef	XMLCHARATERSET_HAND
#	define XMLCHARATERSET_HAND
#		define		XMLFILEHANDER		"<?xml"
#		define		COMMENTHANDER		"<!--"
#		define		DTDHANDER			"<!"
#		define		CDATAHANDER			"<![CDATA["

#endif

#ifndef	XMLCHARATERSET_END
#	define XMLCHARATERSET_END
#		define		XMLFILEEND			"?>"
#		define		COMMENTEND			"-->"
#		define		FIELDEND			">"

#endif

#ifndef	XMLLABELSET
#	define XMLLABELSET
#		define		TABLEHANDFRONT		"<"
#		define		TABLEHANDTAIL		">"
#		define		TABLEENDFRONT		"</"
#		define		TABLEENDTAIL		">"

#endif

class xmlElement;
class xmlDocument;
class xmlDocument;
class xmlNode;
class xmlAttribute;
class xmlText;

class xmlText{
public:
	xmlText();

	~xmlText();

private:
	strBase textData;

};

class xmlAttribute :
	public xmlNode {
public:
	xmlAttribute(void);

	virtual ~xmlAttribute();

	typedef unsigned int uint_t;

	bool isEnd() const {
		return end;
	}

private:
	strBase key;

	strBase value;

	uint_t attrNum;

	xmlAttribute *nextAttr;

	bool end;

};

class xmlBase {
public:
	xmlBase();

	virtual ~xmlBase();

	virtual void xmlPrint() = 0;

	virtual bool xmlParse() = 0;

	virtual void xmlRead() = 0;

private:
	
};

class xmlNode :
	public xmlBase {
public:
	xmlNode(void);

	typedef size_t size_type;
	
	virtual ~xmlNode(void);
	
private:

};

class xmlDocument{
public:
	typedef unsigned int uint_t;
	typedef size_t	size_type;

	xmlDocument(void);

	xmlDocument(char *filePath);

	virtual ~xmlDocument(void);
	
	static strBase xmlStatement;

	virtual void xmlPrint();
	
	void read();

	virtual void xmlRead();

	const char *getDocument() const{
		return document.c_str();
	}
	
	bool isFileExist(const char *fullPath);

	void open();

private:
	void setDocument(char *doc);

	bool splitting(char *fullPath);

	bool isFileExist();

	strBase document;

	strBase docPath;

	//strBase docStart;

	//strBase docEnd;

	xmlElement *rootElement;
	
};

class xmlElement :
	public xmlNode {
public:
	typedef unsigned int uint_t;

	xmlElement();

	virtual ~xmlElement();

private:
	strBase label;

	xmlText *text;

	uint_t childNum;

	xmlElement *childElementPtr;//第一个子元素

	xmlElement *nextElementPtr; //下一个兄弟元素

	xmlElement *prevElementPtr; //前一个兄弟元素

	xmlAttribute *attribute;
	
	//xmlNode *firstElement;
};