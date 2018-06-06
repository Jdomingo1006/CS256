#pragma once

//Tree class
class Tree {
private:
	static int objectCount; //Static Member Variable
public:
	//Constructor
	Tree()
	{
		objectCount++;
	}
	
	int getObjectCount() const {
		return objectCount;
	}
};

int Tree::objectCount = 0;
