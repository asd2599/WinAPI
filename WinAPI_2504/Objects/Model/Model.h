#pragma once

class Model
{
public:
	Model(string name);
	~Model();
	
private:
	void ReadMaterial();
	void ReadMesh();

protected:
	string name;


};